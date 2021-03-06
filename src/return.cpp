#include "return.h"
using std::string;

Return::Return() : Node() {}
Return::Return(string t, string v) : Node(std::move(t), std::move(v)) {}

std::optional<string> Return::generateST() {
    return std::nullopt;
}

std::optional<string> Return::checkSemantics() {
    string return_type = this->children.at(0)->checkSemantics().value_or("");
    string method_name = Return::st.getScopeTitle();
    auto record_ptr = Return::st.lookupRecord(method_name).value_or(nullptr);
    if (record_ptr) {
        string record_ptr_type = record_ptr->getType();
        if (record_ptr_type != return_type) {
            string msg = "[Semantic Analysis] - Error: return type \"" + return_type +
                         "\" does not match the declaration (\"" + record_ptr_type + "\")!";
            Return::printErrMsg(msg);
        }
    } else {
        string msg = "[Semantic Analysis] - Error: Can not find \"" + method_name + "\"!";
        Return::printErrMsg(msg);
    }

    return std::nullopt;
}
void* Return::genIR(BasicBlock *currentBlock)
{
    LOG_INFO(" Return has override genIR function, type = "<<type<<", value = "<<value<<"size"<<children.size());
    
    Address* result = (Address*)children.at(0)->genIR(currentBlock);
    ThreeAddressCode* in = new ReturnIr(result);
    currentBlock->add_code(in);
    // if(children.size()>0){
    //    // LOG_INFO(" PrimaryExpression type = "<<type<<", value = "<<value);
    //      return children.at(0)->genIR(currentBlock);

        
    // }else{
    //    // LOG_INFO(" PrimaryExpression size=0 type = "<<type<<", value = "<<value);
    //     result =  Address::getAddressFromType(type,value);
        
    // }
    // //  Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);
    // // //Address* addrRhs = (Address*)children.at(1)->genIR(currentBlock);
    // // std::string operatorString = getValue();
    // //  ThreeAddressCode* in = new ExpressionIr(addrLhs,nullptr,operatorString);
    // //  currentBlock->add_code(in);
    
    // return (void*)result;
}