#ifndef METHOD_CALL_H
#define METHOD_CALL_H

#include "node.h"

class MethodCall : public Node {
public:
    MethodCall();
    MethodCall(std::string t, std::string v);
    ~MethodCall() override = default;
    void* genIR(BasicBlock* BB);
    std::optional<std::string> generateST() override;
    std::optional<std::string> checkSemantics() final;

};

#endif
