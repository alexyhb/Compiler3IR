#ifndef GOAL_H
#define GOAL_H

#include "node.h"

class Goal : public Node {
public:
    Goal();
    Goal(std::string t, std::string v);
    ~Goal() override = default;
    void* genIR(BasicBlock* BB);
    void* genIR(std::map<std::string ,ControlFlowGraph*> &cfgs);

    std::optional<std::string> generateST() override;
    std::optional<std::string> checkSemantics() override;
};

#endif