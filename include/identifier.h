#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "node.h"

class Identifier : public Node {
public:
    Identifier();
    Identifier(std::string t, std::string v);
    ~Identifier() override = default;
    
    std::optional<std::string> generateST() override;
    std::optional<std::string> checkSemantics() override;
    void* genIR(BasicBlock *currentBlock) override;
};

#endif
