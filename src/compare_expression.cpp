#include "compare_expression.h"
using std::string;

CompareExpression::CompareExpression() : Expression() {}
CompareExpression::CompareExpression(string t, string v) : Expression(std::move(t), std::move(v)) {}

std::optional<string> CompareExpression::checkSemantics() {
    string lhs = this->children.at(0)->checkSemantics().value_or("");
    string rhs = this->children.at(1)->checkSemantics().value_or("");
    if (!lhs.empty() && !rhs.empty() && lhs == rhs) {
        return "boolean";
    } else {
        string msg = "[Semantic Analysis] - Error: lhs (\"" + lhs + "\") and rhs (\"" + rhs +
                     "\") variable types are different in scope \"" + CompareExpression::st.getScopeTitle() + "\"!";
        CompareExpression::printErrMsg(msg);
    }

    return std::nullopt;
}
void* CompareExpression::genIR(BasicBlock *currentBlock)
{
    //LOG_INFO(" CompareExpression has override genIR function, type = "<<type<<", value = "<<value);

    Address* result = Address::getAddressFromType();
    Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);;
    Address* addrRhs = (Address*)children.at(1)->genIR(currentBlock);;
    std::string operatorString = getValue();

    ThreeAddressCode* in = new ExpressionIr(result,addrLhs,addrRhs,operatorString);
    currentBlock->codes.push_back(in);
    return (void*)result;
}