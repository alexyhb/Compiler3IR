#include "alloc_expression.h"
using std::string;

AllocExpression::AllocExpression() : PrimaryExpression() {}
AllocExpression::AllocExpression(string t, string v) : PrimaryExpression(std::move(t), std::move(v)) {}

std::optional<string> AllocExpression::checkSemantics() {
    string class_name = this->children.at(0)->checkSemantics().value_or("");
    std::shared_ptr<Record> c_record_ptr = AllocExpression::st.lookupRecordInRoot(class_name).value_or(nullptr);
    if (c_record_ptr && c_record_ptr->getRecord() == "Class") {
        return c_record_ptr->getType();
    } else {
        string msg = "[Semantic Analysis] - Error: Class \"" + class_name + "\" does not exist!";
        AllocExpression::printErrMsg(msg);
    }

    return std::nullopt;
}
void* AllocExpression::genIR(BasicBlock* currentBasicBlock)
{
   // LOG_INFO("ALLOC"<<children.at(0)->getType()<<","<<children.at(0)->getValue());
    Address *tmpVar = Address::getAddressFromType();
    Address *tmp = (Address*)children.at(0)->genIR(currentBasicBlock);
    ThreeAddressCode *newIR = new NewIr(tmpVar,tmp);
    currentBasicBlock->add_code(newIR);

    return (void*) tmpVar;
}