#include "expression_list.h"
using std::string;

ExpressionList::ExpressionList() : Node() {}
ExpressionList::ExpressionList(string t, string v) : Node(std::move(t), std::move(v)) {}

std::optional<string> ExpressionList::checkSemantics() {
    string parameter_type_list;

    for (const auto &child : this->children) {
        parameter_type_list += child->checkSemantics().value_or("") + " ";
    }

    return parameter_type_list;
}