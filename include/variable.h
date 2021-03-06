#ifndef VARIABLE_H
#define VARIABLE_H

#include <optional>
#include <unordered_map>
#include "record.h"

class Variable : public Record {
protected:
    std::unordered_map<std::string, std::shared_ptr<Variable>> variables;

public:
    Variable();
    Variable(std::string name, std::string type);
    Variable(std::string name, std::string type, std::string record);
    ~Variable() override = default;

    std::unordered_map<std::string, std::shared_ptr<Variable>> getVariables() const;

    void addVariable(const std::shared_ptr<Variable> &variable);
    std::optional<std::shared_ptr<Variable>> lookupVariable(const std::string &name) const;
};

#endif