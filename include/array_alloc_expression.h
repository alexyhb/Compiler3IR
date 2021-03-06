#ifndef ARRAY_ALLOC_EXPRESSION_H
#define ARRAY_ALLOC_EXPRESSION_H

#include "primary_expression.h"

class ArrayAllocExpression : public PrimaryExpression {
public:
    ArrayAllocExpression();
    ArrayAllocExpression(std::string t, std::string v);
    ~ArrayAllocExpression() override = default;
    void* genIR(BasicBlock *currentBlock) final;

    std::optional<std::string> checkSemantics() final;
    
};

#endif
