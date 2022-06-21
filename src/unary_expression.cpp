#include "unary_expression.h"
using std::string;

UnaryExpression::UnaryExpression() : PrimaryExpression() {}
UnaryExpression::UnaryExpression(string t, string v) : PrimaryExpression(std::move(t), std::move(v)) {}

std::optional<string> UnaryExpression::checkSemantics() {
    string type = this->children.at(0)->checkSemantics().value_or("");
    if (type != "boolean") {
        string msg = R"([Semantic Analysis] - Error: Unary expression condition should be "boolean" in scope ")" +
                     UnaryExpression::st.getScopeTitle() + "\"!";
        UnaryExpression::printErrMsg(msg);
    }
    return type;
}

void* UnaryExpression::genIR(BasicBlock *currentBlock)
{
    LOG_INFO(" UnaryExpression size=0 type = "<<type<<", value = "<<value<<"size="<<children.size());

    Address* result =Address::getAddressFromType(type,value);
    Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);
    std::string operatorString = getValue();

    ThreeAddressCode* in = new UnaryExpressionIr(result,addrLhs,value);
    currentBlock->add_code(in);
     return (void*)result;
}