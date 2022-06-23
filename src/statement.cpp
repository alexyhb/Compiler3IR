#include "statement.h"
using std::string;

Statement::Statement() : Node() {}
Statement::Statement(string t, string v) : Node(std::move(t), std::move(v)) {}

std::optional<string> Statement::generateST() {
    return std::nullopt;
}
void* Statement::genIR(BasicBlock* BB) {
    //LOG_INFO("statements or statement:"<<value <<" "<< children.size());
    for( auto &child: children){
        child->genIR(BB);
    }
}