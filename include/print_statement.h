#ifndef PRINT_STATEMENT_H
#define PRINT_STATEMENT_H

#include "statement.h"

class PrintStatement : public Statement {
public:
    PrintStatement();
    PrintStatement(std::string t, std::string v);
    ~PrintStatement() override = default;

    void* genIR(BasicBlock *currentBlock) final;

    std::optional<std::string> checkSemantics() final;
};

#endif
