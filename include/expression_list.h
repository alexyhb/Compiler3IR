#ifndef EXPRESSION_LIST_H
#define EXPRESSION_LIST_H

#include "node.h"

class ExpressionList : public Node {
public:
    ExpressionList();
    ExpressionList(std::string t, std::string v);
    ~ExpressionList() override = default;
    void* genIR(BasicBlock* BB);

    std::optional<std::string> checkSemantics() final;
};

#endif
