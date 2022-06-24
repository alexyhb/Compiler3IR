#include "expression_list.h"
#include <vector> 
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
    if(children.size()==1){
            Address* result =(Address*) children.at(0)->genIR(BB);

        return (void*) result;
    }
    else{

    std::vector<Address*> addressList;
    for(auto &child: children){
         Address* result=(Address*)child->genIR(BB);
         addressList.push_back(result);
 //   LOG_INFO("??????????????????????????????????????~~~~~~~~~~~~~~~~~~~~~ExpressionList done");
    }
    LOG_INFO(addressList.size());
    ThreeAddressCode *in=new ParamListIr(addressList);
    BB->add_code(in);
    return (void*)in;
    }
}