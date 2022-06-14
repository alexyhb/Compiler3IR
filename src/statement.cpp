#include "statement.h"
using std::string;

Statement::Statement() : Node() {}
Statement::Statement(string t, string v) : Node(std::move(t), std::move(v)) {}

std::optional<string> Statement::generateST() {
    return std::nullopt;
}
void* Statement::genIR(BasicBlock* BB) {
    LOG_INFO("statements or statement"<< children.size());
    if(children.size()==1){
        children.at(0)->genIR(BB);

    }
    if(children.size()==2){
        children.at(0)->genIR(BB);
        children.at(1)->genIR(BB);

    }
}