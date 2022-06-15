#ifndef VARIABLE_DECLARATION_H
#define VARIABLE_DECLARATION_H

#include "declarations.h"

class VarDeclaration : public Declarations {
public:
    VarDeclaration();
    VarDeclaration(std::string t, std::string v);
    ~VarDeclaration() override = default;

    void* genIR(BasicBlock* BB);

    std::optional<std::string> generateST() final;
    std::optional<std::string> checkSemantics() final;
};

#endif