#include "variable_declaration.h"
using std::string;

VarDeclaration::VarDeclaration() : Declarations() {}
VarDeclaration::VarDeclaration(string t, string v) : Declarations(std::move(t), std::move(v)) {}

std::optional<string> VarDeclaration::generateST() {
    string variable_type = this->children.at(0)->generateST().value_or("Unknown");
    string variable_name = this->children.at(1)->generateST().value_or("Unknown");
    std::shared_ptr<Variable> variable_ptr = std::make_shared<Variable>(variable_name, variable_type);
    VarDeclaration::st.addRecord(variable_name, variable_ptr);

    string scope_name = VarDeclaration::st.getScopeTitle();
    string scope_type = VarDeclaration::st.getScopeType();
    auto record_ptr = VarDeclaration::st.lookupRecord(scope_name).value_or(nullptr);
    if (scope_type == "Class" && record_ptr) {
        auto class_ptr = std::dynamic_pointer_cast<STClass>(record_ptr);
        class_ptr->addVariable(variable_ptr);
    } else if (scope_type == "Method" && record_ptr) {
        auto method_ptr = std::dynamic_pointer_cast<Method>(record_ptr);
        method_ptr->addVariable(variable_ptr);
    }

    return std::nullopt;
}

std::optional<string> VarDeclaration::checkSemantics() {
    string type_name = this->children.at(0)->checkSemantics().value_or("");
    if (type_name != "int" && type_name != "boolean" && type_name != "int[]") {
        auto c_record_ptr = VarDeclaration::st.lookupRecordInRoot(type_name).value_or(nullptr);
        if (!c_record_ptr) {
            string msg = "[Semantic Analysis] - Error: Class \"" + type_name + "\" does not exist!";
            VarDeclaration::printErrMsg(msg);
        }
    }

    return std::nullopt;
}
void* VarDeclaration::genIR(BasicBlock* BB) {
    for (const auto &child : this->children) {
            child->genIR(BB);
    }
   
}