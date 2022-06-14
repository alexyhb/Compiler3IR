#include "formal_parameter.h"
using std::string;

FormalParameter::FormalParameter() : FormalParameterList() {}
FormalParameter::FormalParameter(string t, string v) : FormalParameterList(std::move(t), std::move(v)) {}

std::optional<string> FormalParameter::generateST() {
    string parameter_type = this->children.at(0)->generateST().value_or("Unknown");
    string parameter_name = this->children.at(1)->generateST().value_or("Unknown");
    std::shared_ptr<Parameter> parameter_ptr = std::make_shared<Parameter>(parameter_name, parameter_type);
    FormalParameter::st.addRecord(parameter_name, parameter_ptr);

    string scope_name = FormalParameter::st.getScopeTitle();
    string scope_type = FormalParameter::st.getScopeType();
    auto record_ptr = FormalParameter::st.lookupRecord(scope_name).value_or(nullptr);
    if (scope_type == "Method" && record_ptr) {
        auto method_ptr = std::dynamic_pointer_cast<Method>(record_ptr);
        method_ptr->addParameter(parameter_ptr);
    }

    return std::nullopt;
}
