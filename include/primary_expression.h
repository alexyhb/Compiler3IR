#ifndef PRIMARY_EXPRESSION_H
#define PRIMARY_EXPRESSION_H

#include "node.h"

class PrimaryExpression : public Node {
public:
    PrimaryExpression();
    PrimaryExpression(std::string t, std::string v);
    ~PrimaryExpression() override = default;
    void* genIR(BasicBlock *currentBlock);

    std::optional<std::string> generateST() final;
    std::optional<std::string> checkSemantics() override;
};

#endif
