#ifndef ELSE_STATEMENT_H
#define ELSE_STATEMENT_H

#include "node.h"

class ElseStatement : public Node {
public:
    ElseStatement();
    void* genIR(BasicBlock *currentBlock);
    ElseStatement(std::string t, std::string v);
    ~ElseStatement() override = default;
};

#endif
