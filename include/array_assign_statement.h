#ifndef ARRAY_ASSIGN_STATEMENT_H
#define ARRAY_ASSIGN_STATEMENT_H

#include "statement.h"

class ArrayAssignStatement : public Statement {
public:
    ArrayAssignStatement();
    ArrayAssignStatement(std::string t, std::string v);
    ~ArrayAssignStatement() override = default;

    std::optional<std::string> checkSemantics() final;
    void* genIR(BasicBlock *currentBlock) final;


};

#endif
