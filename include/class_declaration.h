#ifndef CLASS_DECLARATION_H
#define CLASS_DECLARATION_H

#include "declarations.h"

class ClassDeclaration : public Declarations {
public:
    ClassDeclaration();
    ClassDeclaration(std::string t, std::string v);
    ~ClassDeclaration() override = default;
    void* genIR(BasicBlock* BB);
    void* genIR(std::map<std::string ,ControlFlowGraph*> &cfgs);

    std::optional<std::string> generateST() final;
    std::optional<std::string> checkSemantics() final;
};

#endif