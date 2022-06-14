#include "if_statement.h"
using std::string;

IfStatement::IfStatement() : Statement() {}
IfStatement::IfStatement(string t, string v) : Statement(std::move(t), std::move(v)) {}

std::optional<string> IfStatement::checkSemantics() {
    string type = this->children.at(0)->checkSemantics().value_or("");
    if (type != "boolean") {
        string msg = R"([Semantic Analysis] - Error: IF condition should be "boolean" in scope ")" +
                     IfStatement::st.getScopeTitle() + "\"!";
        IfStatement::printErrMsg(msg);
    }

    for (std::size_t i = 1; i < this->children.size(); ++i) {
        this->children.at(i)->checkSemantics();
    }

    return std::nullopt;
}

void* IfStatement::genIR(BasicBlock *currentBlock)
{
    LOG_INFO("IF statment");
    children.at(0)->genIR(currentBlock);
    Address* result = Address::getAddressFromType();
    BasicBlock* trueBrunch = new BasicBlock();
    Address* trueAddress = (Address*)children.at(1)->genIR(trueBrunch);
    BasicBlock* falseBrunch = new BasicBlock();
    Address* falseAddress = (Address*)children.at(2)->genIR(falseBrunch);
    BasicBlock* jumpBrunch = new BasicBlock();
    trueBrunch->positive_branch = jumpBrunch;
    falseBrunch->positive_branch = jumpBrunch;
    currentBlock->positive_branch = trueBrunch;
    currentBlock->negative_branch = falseBrunch;
    return jumpBrunch;
}