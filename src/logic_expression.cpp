#include "logic_expression.h"
using std::string;

LogicExpression::LogicExpression() : Expression() {}
LogicExpression::LogicExpression(string t, string v) : Expression(std::move(t), std::move(v)) {}
void* LogicExpression::genIR(BasicBlock *currentBlock)
{
  // LOG_INFO("LogicExpression override genIR function, type = "<<type<<", value = "<<value);

    Address* result = Address::getAddressFromType(type,value);
    Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);;
    Address* addrRhs = (Address*)children.at(1)->genIR(currentBlock);;
    std::string operatorString = getValue();

    ThreeAddressCode* in = new ExpressionIr(result,addrLhs,addrRhs,operatorString);
    currentBlock->codes.push_back(in);
    return (void*)result;
}
std::optional<string> LogicExpression::checkSemantics() {
    string lhs = this->children.at(0)->checkSemantics().value_or("");
    string rhs = this->children.at(1)->checkSemantics().value_or("");
    if (!lhs.empty() && !rhs.empty() && lhs == rhs) {
        return "boolean";
    } else {
        string msg = "[Semantic Analysis] - Error: lhs (\"" + lhs + "\") and rhs (\"" + rhs +
                     "\") variable types are different in scope \"" + LogicExpression::st.getScopeTitle() + "\"!";
        LogicExpression::printErrMsg(msg);
    }

    return std::nullopt;
}
