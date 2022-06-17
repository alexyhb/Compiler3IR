#include "goal.h"
using std::string;

Goal::Goal() : Node() {}
Goal::Goal(string t, string v) : Node(std::move(t), std::move(v)) {}

std::optional<string> Goal::generateST() {
    Goal::st.setScopeTitle("Program");

    for (const auto &child : this->children) {
        Goal::st.enterScope();
        child->generateST();
        Goal::st.exitScope();
    }

    return std::nullopt;
}

void* Goal::genIR(BasicBlock* BB) {
    for(auto &child: children){
   // LOG_INFO("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Goal override the GENIR, value="<<value<<"type:"<<type<< "children size"<< children.size());
        child->genIR(BB);
    }
   
}
std::optional<string> Goal::checkSemantics() {
    for (const auto &child : this->children) {
        Goal::st.enterScope();
        child->checkSemantics();
        Goal::st.exitScope();
    }
    return std::nullopt;
}
