#include "expression_list.h"
using std::string;

ExpressionList::ExpressionList() : Node() {}
ExpressionList::ExpressionList(string t, string v) : Node(std::move(t), std::move(v)) {}

std::optional<string> ExpressionList::checkSemantics() {
    string parameter_type_list;

    for (const auto &child : this->children) {
        parameter_type_list += child->checkSemantics().value_or("") + " ";
    }

    return parameter_type_list;
}
void* ExpressionList::genIR(BasicBlock* BB) {
    LOG_INFO("??????????????????????????????????????ExpressionList override the GENIR, value="<<value<<"type:"<<type<< "children size"<< children.size());
    if(children.size()==1){
            Address* result =(Address*) children.at(0)->genIR(BB);

        return (void*) result;
    }
     for(auto &child: children){
         child->genIR(BB);
         
 //   LOG_INFO("??????????????????????????????????????~~~~~~~~~~~~~~~~~~~~~ExpressionList done");
     }
  
}