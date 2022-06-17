#include "assign_statement.h"
using std::string;

AssignStatement::AssignStatement() : Statement() {}
AssignStatement::AssignStatement(string t, string v) : Statement(std::move(t), std::move(v)) {}

std::optional<string> AssignStatement::checkSemantics() {
    string lhs_name = this->children.at(0)->checkSemantics().value_or("");
    string rhs_type = this->children.at(1)->checkSemantics().value_or("");

    auto record_ptr = AssignStatement::st.lookupRecord(lhs_name).value_or(nullptr);
    if (record_ptr) {
        string lhs_record_type = record_ptr->getType();
        if (lhs_record_type != rhs_type && rhs_type.find(lhs_record_type) == string::npos) {
            string msg = "[Semantic Analysis] - Error: Can not assign \"" + rhs_type + "\" (rhs) to \"" +
                         lhs_record_type + "\" (lhs) in the scope \"" + AssignStatement::st.getScopeTitle() + "\"!";
            AssignStatement::printErrMsg(msg);
        }
    } else {
        string msg = "[Semantic Analysis] - Error: Variable \"" + lhs_name + "\" does not exist in scope \"" +
                     AssignStatement::st.getScopeTitle() + "\"!";
        AssignStatement::printErrMsg(msg);
    }

    return std::nullopt;
}
void* AssignStatement::genIR(BasicBlock *currentBlock)
{
    
    // Address* result = Address::getAddressFromType();/
    Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);
    Address* addrRhs =(Address*)children.at(1)->genIR(currentBlock);
    std::string operatorString = getValue();
    ThreeAddressCode* in = new NewIr(addrLhs,addrRhs);
    currentBlock->add_code(in);
    
}