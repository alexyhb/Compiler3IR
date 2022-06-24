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
    // LOG_INFO("IF statment");
     if(currentBlock->positive_branch==nullptr){
        // LOG_INFO("? pos branch");
    }    
    if(currentBlock->negative_branch==nullptr){
        // LOG_INFO("?neg branch");
    }
    Address *condition=(Address*)children.at(0)->genIR(currentBlock);
    //Address* result = Address::getAddressFromType(type,value);
    BasicBlock* jumpBrunch = new BasicBlock();
    BasicBlock* trueBrunch = new BasicBlock(jumpBrunch);
    Address* trueAddress = (Address*)children.at(1)->genIR(trueBrunch);
    BasicBlock* falseBrunch = new BasicBlock(jumpBrunch);
    Address* falseAddress = (Address*)children.at(2)->genIR(falseBrunch);
    currentBlock->positive_branch = trueBrunch;
    currentBlock->negative_branch = falseBrunch;
    ThreeAddressCode *in=new ConditionalJumpIr(condition,trueBrunch->identifier);
    // ThreeAddressCode *in2=new UnconditionalJumpIr(falseAddress);
    currentBlock->set_condition(in);
    if(currentBlock->positive_branch==nullptr){
        // LOG_INFO("fail set pos branch");
    }else{
        // LOG_INFO("success set pos branch");

    }
    if(currentBlock->negative_branch==nullptr){
        // LOG_INFO("fail set neg branch");
    }else{
        // LOG_INFO("success set neg branch");

    }
    currentBlock->add_code(in);
    //currentBlock->add_code(in2);
    return (void*)jumpBrunch;
}