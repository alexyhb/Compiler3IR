#include "variable.h"
using std::string;

Variable::Variable() : Record() {}
Variable::Variable(string name, string type)
    : Record(std::move(name), std::move(type), "Variable") {}
Variable::Variable(string name, string type, string record)
    : Record(std::move(name), std::move(type), std::move(record)) {}

std::unordered_map<std::string, std::shared_ptr<Variable>> Variable::getVariables() const {
    return this->variables;
}

void Variable::addVariable(const std::shared_ptr<Variable> &variable) {
    auto variable_pair = this->variables.insert({variable->getName(), variable});
    if (!variable_pair.second) {
        std::cerr << "The variable " << variable->getName() << " already exists!" << std::endl;
    }
}

std::optional<std::shared_ptr<Variable>> Variable::lookupVariable(const string &name) const {
    auto iterator = this->variables.find(name);
    if (iterator != this->variables.end()) {
        return iterator->second;
    } else {
        return std::nullopt;
    }
}
