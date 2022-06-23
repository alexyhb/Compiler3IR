#include "array_assign_statement.h"
using std::string;

ArrayAssignStatement::ArrayAssignStatement() : Statement() {}
ArrayAssignStatement::ArrayAssignStatement(string t, string v) : Statement(std::move(t), std::move(v)) {}

std::optional<string> ArrayAssignStatement::checkSemantics() {
    string lhs_name = this->children.at(0)->checkSemantics().value_or("");
    string pos_type = this->children.at(1)->checkSemantics().value_or("");
    string rhs_type = this->children.at(2)->checkSemantics().value_or("");

    auto record_ptr = Statement::st.lookupRecord(lhs_name).value_or(nullptr);
    if (record_ptr) {
        if (pos_type != "int") {
            string msg =
                R"([Semantic Analysis] - Error: only "int" can be used to access array's position in scope ")" +
                ArrayAssignStatement::st.getScopeTitle() + "\"!";
            ArrayAssignStatement::printErrMsg(msg);
        }
        string lhs_record_type = record_ptr->getType();
        if (lhs_record_type != "int[]" || rhs_type != "int") {
            string msg = "[Semantic Analysis] - Error: Can not assign \"" + rhs_type + "\" (rhs) to \"" +
                         lhs_record_type + "\" (lhs) in the scope \"" + Statement::st.getScopeTitle() + "\"!";
            ArrayAssignStatement::printErrMsg(msg);
        }
    } else {
        string msg = "[Semantic Analysis] - Error: Variable \"" + lhs_name + "\" does not exist in scope \"" +
                     ArrayAssignStatement::st.getScopeTitle() + "\"!";
        ArrayAssignStatement::printErrMsg(msg);
    }

    return std::nullopt;
}
void* ArrayAssignStatement::genIR(BasicBlock *currentBlock)
{
    if(value=="[]="){
    //LOG_INFO("ArrayAssignStatement1 override the GENIR, value="<<value<<"type:"<<type<< " size:" << children.size());
        Address* result = (Address*)children.at(0)->genIR(currentBlock);
        Address* addrLhs = (Address*)children.at(1)->genIR(currentBlock);
        Address* addrRhs =(Address*)children.at(2)->genIR(currentBlock);
        std::string operatorString = getValue();
        ThreeAddressCode* in = new ArrayAccessIr(result,addrLhs,addrRhs,value);
        currentBlock->add_code(in);

    }
    if(value=="=[]"){
    //LOG_INFO("ArrayAssignStatement2 override the GENIR, value="<<value<<"type:"<<type<< " size:" << children.size());

        Address* result = (Address*)children.at(0)->genIR(currentBlock);
        Address* addrLhs = (Address*)children.at(1)->genIR(currentBlock);
        Address* addrRhs =(Address*)children.at(2)->genIR(currentBlock);
        std::string operatorString = getValue();
        ThreeAddressCode* in = new ArrayAccessIr(result,addrLhs,addrRhs,value);
        currentBlock->add_code(in);
    }
    
}