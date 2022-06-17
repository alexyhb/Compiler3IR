#include "primary_expression.h"
using std::string;

PrimaryExpression::PrimaryExpression() : Node() {}
PrimaryExpression::PrimaryExpression(string t, string v) : Node(std::move(t), std::move(v)) {}

std::optional<string> PrimaryExpression::generateST() {
    return std::nullopt;
}
void* PrimaryExpression::genIR(BasicBlock *currentBlock)
{
//LOG_INFO(" PrimaryExpression has override genIR function, type = "<<type<<", value = "<<value<<"size"<<children.size());

    Address* result;
    if(children.size()==1){
        //LOG_INFO(" PrimaryExpression0 type = "<<type<<", value = "<<value);

         children.at(0)->genIR(currentBlock);
        //LOG_INFO(" PrimaryExpression1 type = "<<type<<", value = "<<value);

        
    }else if(children.size()==0){
        //LOG_INFO(" PrimaryExpression2  type = "<<type<<", value = "<<value);

        result =  Address::getAddressFromType(type,value);
        return (void*)result;
    }
    //  Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);
    // //Address* addrRhs = (Address*)children.at(1)->genIR(currentBlock);
    // std::string operatorString = getValue();
    //  ThreeAddressCode* in = new ExpressionIr(addrLhs,nullptr,operatorString);
    //  currentBlock->add_code(in);
    
    return (void*)result;
}
std::optional<string> PrimaryExpression::checkSemantics() {
    if (this->children.size() == 1) {
        return this->children.at(0)->checkSemantics();
    }

    return std::nullopt;
}
