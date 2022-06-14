#include "array_alloc_expression.h"
using std::string;

ArrayAllocExpression::ArrayAllocExpression() : PrimaryExpression() {}
ArrayAllocExpression::ArrayAllocExpression(string t, string v) : PrimaryExpression(std::move(t), std::move(v)) {}

std::optional<string> ArrayAllocExpression::checkSemantics() {
    string type = this->children.at(0)->checkSemantics().value_or("");
    if (type != "int") {
        string msg = R"([Semantic Analysis] - Error: Array size should be "int" in scope ")" +
                     ArrayAllocExpression::st.getScopeType() + "\"!";
        ArrayAllocExpression::printErrMsg(msg);
    }

    return "int[]";
}
void* ArrayAllocExpression::genIR(BasicBlock *currentBlock)
{
    //LOG_INFO("here");
    Address* result = Address::getAddressFromType();
    Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);
    Address* addrRhs =(Address*)children.at(1)->genIR(currentBlock);
    std::string operatorString = getValue();
    ThreeAddressCode* in = new ExpressionIr(result,addrLhs,addrRhs,operatorString);
    currentBlock->add_code(in);
    return (void*)result;
}