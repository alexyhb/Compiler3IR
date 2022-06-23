#ifndef METHOD_DECLARATION_H
#define METHOD_DECLARATION_H

#include "declarations.h"

class MethodDeclaration : public Declarations {
public:
    MethodDeclaration();
    MethodDeclaration(std::string t, std::string v);
    ~MethodDeclaration() override = default;
    void* genIR(BasicBlock* currentBB);
    void* genIR(std::map<std::string ,ControlFlowGraph*> &cfgs);

    std::optional<std::string> generateST() final;
    std::optional<std::string> checkSemantics() final;
};

#endif