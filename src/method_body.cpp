#include "method_body.h"
using std::string;

MethodBody::MethodBody() : Node() {}
MethodBody::MethodBody(string t, string v) : Node(std::move(t), std::move(v)) {}

std::optional<string> MethodBody::generateST() {
    for (const auto &child : this->children) {
        if (child->getType() == "VarDeclaration") {
            child->generateST();
        }
    }
    return std::nullopt;
}
void* MethodBody::genIR(BasicBlock* BB) {
    for (const auto &child : this->children) {
            //LOG_INFO("METHOD BODY IR");
            

        if(child->getType()=="Return"){
            BasicBlock *jointBlock= BB->findJoinBlock(BB);
        child->genIR(jointBlock);
          //  LOG_INFO("Now return");
        }else{
            child->genIR(BB);
        }
    }
   
}