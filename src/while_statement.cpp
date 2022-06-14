#include "while_statement.h"
using std::string;

WhileStatement::WhileStatement() : Statement() {}
WhileStatement::WhileStatement(string t, string v) : Statement(std::move(t), std::move(v)) {}

std::optional<string> WhileStatement::checkSemantics() {
    string type = this->children.at(0)->checkSemantics().value_or("");
    if (type != "boolean") {
        string msg = R"([Semantic Analysis] - Error: WHILE condition should be "boolean" in scope ")" +
                     Statement::st.getScopeTitle() + "\"!";
        Statement::printErrMsg(msg);
    }

    for (std::size_t i = 1; i < this->children.size(); ++i) {
        this->children.at(i)->checkSemantics();
    }

    return std::nullopt;
}
void* WhileStatement::genIR(BasicBlock *currentBlock)
{
    BasicBlock* headerBlock = new BasicBlock();
    children.at(0)->genIR(headerBlock);
    BasicBlock* bodayBlock = new BasicBlock();
    children.at(1)->genIR(bodayBlock);
    BasicBlock* jumpBrunch = new BasicBlock();

    headerBlock->positive_branch = bodayBlock;
    headerBlock->negative_branch = jumpBrunch;
    bodayBlock->positive_branch = jumpBrunch;
    currentBlock->positive_branch = headerBlock;
    return (void*)jumpBrunch;
}