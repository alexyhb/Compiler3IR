#include "else_statement.h"
using std::string;

ElseStatement::ElseStatement() : Node() {}
ElseStatement::ElseStatement(string t, string v) : Node(std::move(t), std::move(v)) {}

void* ElseStatement::genIR(BasicBlock *currentBlock)
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