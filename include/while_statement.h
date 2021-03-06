#ifndef WHILE_STATEMENT_H
#define WHILE_STATEMENT_H

#include "statement.h"

class WhileStatement : public Statement {
public:
    WhileStatement();
    WhileStatement(std::string t, std::string v);
    ~WhileStatement() override = default;
    void* genIR(BasicBlock *currentBlock);
    std::optional<std::string> checkSemantics() final;
};

#endif
