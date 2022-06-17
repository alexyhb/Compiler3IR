#include "print_statement.h"
using std::string;

PrintStatement::PrintStatement() : Statement() {}
PrintStatement::PrintStatement(string t, string v) : Statement(std::move(t), std::move(v)) {}

std::optional<string> PrintStatement::checkSemantics() {
    string type = this->children.at(0)->checkSemantics().value_or("");
    // if (type != "int") {
    //     string msg = R"([Semantic Analysis] - Error: only "int" can be print in scope ")" +
    //                  PrintStatement::st.getScopeTitle() + "\"!";
    //     PrintStatement::printErrMsg(msg);
    // }
    return std::nullopt;
}

void* PrintStatement::genIR(BasicBlock *currentBlock)
{
   // LOG_INFO("PrintStatement override the GENIR, value="<<value<<"type:"<<type);
    
    return children.at(0)->genIR(currentBlock);
}