#include "symbol_table.h"
using std::endl;
using std::string;

SymbolTable::SymbolTable() {
    this->root = std::make_shared<Scope>();
    this->current = this->root;
}

void SymbolTable::enterScope() {
    this->current = this->current->getNextChild();
}

void SymbolTable::exitScope() {
    if (this->current) {
        this->current = this->current->getParentScope();
    }
}

void SymbolTable::setScopeTitle(const std::string &title) {
    this->current->setScopeTitle(title);
}

string SymbolTable::getScopeTitle() const {
    return this->current->getScopeTitle();
}

string SymbolTable::getScopeType() const {
    return this->current->getScopeType();
}

std::shared_ptr<Scope> SymbolTable::getParentScope() const {
    return this->current->getParentScope();
}

void SymbolTable::addRecord(const string &key, const std::shared_ptr<Record> &item) {
    this->current->addRecord(key, item);
}

std::optional<std::shared_ptr<Record>> SymbolTable::lookupRecord(const string &key) const {
    return this->current->lookupRecord(key);
}

std::optional<std::shared_ptr<Record>> SymbolTable::lookupRecordInRoot(const std::string &key) const {
    return this->root->lookupRecord(key);
}

std::optional<std::shared_ptr<Scope>> SymbolTable::lookupChildScope(const string &key) const {
    return this->current->lookupChildScope(key);
}

void SymbolTable::printST(std::ofstream *outStream) {
    *outStream << "label=\"Symbol Table\";" << endl;
    *outStream << "labelloc=\"t\";\n" << endl;
    *outStream << "node [shape=rect, fontname=Arial, width=5];\n" << endl;

    std::size_t index = 0;
    this->root->printST(index, outStream);
}

void SymbolTable::resetTable() {
    this->root->resetScope();
    this->current = this->root;
}
