#ifndef MAIN_CLASS_H
#define MAIN_CLASS_H

#include "node.h"

class MainClass : public Node {
public:
    MainClass();
    MainClass(std::string t, std::string v);
    ~MainClass() override = default;
    void* genIR(std::map<std::string ,ControlFlowGraph*> &cfgs);
    void* genIR(BasicBlock *currentBlock);

    std::optional<std::string> generateST() override;
    std::optional<std::string> checkSemantics() override;
};

#endif