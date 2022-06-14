#include "scope.h"
using std::endl;
using std::size_t;
using std::string;

Scope::Scope() {
    this->next = 0;
    this->parentScope = nullptr;
}

Scope::Scope(std::shared_ptr<Scope> parent) {
    this->next = 0;
    this->parentScope = std::move(parent);
}

void Scope::setScopeTitle(const std::string &title) {
    this->scope_title = title;
}

string Scope::getScopeTitle() const {
    size_t pos = this->scope_title.find(' ');
    if (pos != string::npos) {
        return this->scope_title.substr(pos + 1);
    } else {
        return this->scope_title;
    }
}

string Scope::getScopeType() const {
    size_t pos = this->scope_title.find(' ');
    if (pos != string::npos) {
        return this->scope_title.substr(0, pos - 1);
    } else {
        return this->scope_title;
    }
}

std::shared_ptr<Scope> Scope::getNextChild() {
    std::shared_ptr<Scope> nextChild;
    if (this->next == this->childrenScopes.size()) {
        nextChild = std::make_shared<Scope>(shared_from_this());
        this->childrenScopes.push_back(nextChild);
    } else {
        nextChild = this->childrenScopes.at(this->next); 
    }
    ++(this->next);
    return nextChild;
}

std::shared_ptr<Scope> Scope::getParentScope() const {
    return this->parentScope;
}

std::optional<std::shared_ptr<Record>> Scope::lookupRecord(const string &key) const {
    auto iterator = this->records.find(key);
    if (iterator != this->records.end()) {
        return iterator->second;
    }
    else if (this->parentScope) {
        return this->parentScope->lookupRecord(key);
    } else {
        return std::nullopt;
    }
}

void Scope::addRecord(const string &key, const std::shared_ptr<Record> &item) {
    auto ret = this->records.insert({key, item});
    if (!ret.second) {
        std::cerr << "The record " << key << " already exists in the scope!" << endl;
    }
}

std::optional<std::shared_ptr<Scope>> Scope::lookupChildScope(const string &key) const {
    auto iterator = std::find_if(this->childrenScopes.begin(), this->childrenScopes.end(),
                                 [&key](const std::shared_ptr<Scope> &scope_ptr) {
                                     return scope_ptr->getScopeTitle() == key;
                                 });
    if (iterator != this->childrenScopes.end()) {
        return *iterator;
    }

    return std::nullopt;
}

void Scope::resetScope() {
    for (const auto &childScope_ptr : this->childrenScopes) {
        childScope_ptr->resetScope();
    }
    this->next = 0;
}

void Scope::printST(std::size_t index, std::ofstream *outStream) {
    static size_t count = index;
    string content = "<U><B>" + this->scope_title + "</B></U><BR/><BR/>\n";
    for (const auto &record_pair : this->records) {
        content += record_pair.second->printRecord() + "<BR/>\n";
    }

    *outStream << "n" << index << " [label=<" << content << ">];" << endl;
    for (const auto &childScope_ptr : this->childrenScopes) {
        *outStream << "n" << index << " -- n" << count + 1 << ";" << endl;
        childScope_ptr->printST(++count, outStream);
    }
}
