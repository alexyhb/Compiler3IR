#include "arith_expression.h"
using std::string;

ArithExpression::ArithExpression() : Expression() {}
ArithExpression::ArithExpression(string t, string v) : Expression(std::move(t), std::move(v)) {}
void* ArithExpression::genIR(BasicBlock *currentBlock)
{
   // LOG_INFO(" ArithExpression has override genIR function, type = "<<type<<", value = "<<value);
    Address* result = Address::getAddressFromType();

    Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);
    Address* addrRhs =(Address*)children.at(1)->genIR(currentBlock);
    std::string operatorString = getValue();
    ThreeAddressCode* in = new ExpressionIr(result,addrLhs,addrRhs,operatorString);
    currentBlock->add_code(in);
    return (void*)result;
}

std::optional<std::string> ArithExpression::checkSemantics() {
    string lhs = this->children.at(0)->checkSemantics().value_or("");
    string rhs = this->children.at(1)->checkSemantics().value_or("");
    if (!lhs.empty() && !rhs.empty() && lhs == rhs) {
        return lhs;
    } else {
        string msg = "[Semantic Analysis] - Error: lhs (\"" + lhs + "\") and rhs (\"" + rhs +
                     "\") variable types are different in scope \"" + ArithExpression::st.getScopeTitle() + "\"!";
        ArithExpression::printErrMsg(msg);
    }

    return std::nullopt;
}
