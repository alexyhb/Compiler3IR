#ifndef STATEMENT_H
#define STATEMENT_H

#include "node.h"

class Statement : public Node {
public:
    Statement();
    Statement(std::string t, std::string v);
    ~Statement() override = default;
    
    void* genIR(BasicBlock *currentBlock);

    std::optional<std::string> generateST() final;
};

#endif