#include "type.h"
using std::string;

Type::Type() : Node() {}
Type::Type(string t, string v) : Node(std::move(t), std::move(v)) {}

std::optional<string> Type::generateST() {
    if (!this->getValue().empty() && this->children.empty()) {
        return this->getValue();
    }
    else if (this->getValue().empty() && this->children.size() == 1) {
        return this->children.at(0)->generateST().value_or("Unknown");
    }

    return std::nullopt;
}
void* Type::genIR(BasicBlock *currentBlock)
{
    LOG_INFO("TYPE CLASS, type = "<<type<<", value = "<<value);
    Address* result = Address::getAddressFromType();
    // Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);
    //Address* addrRhs = (Address*)children.at(1)->genIR(currentBlock);
    //  std::string operatorString = getValue();
    // ThreeAddressCode* in = new ExpressionIr(addrLhs,nullptr,operatorString);
    //  currentBlock->add_code(in);
    return (void*)result;
}
std::optional<string> Type::checkSemantics() {
    if (this->children.size() == 1 && this->getValue().empty()) {
        return this->children.at(0)->checkSemantics();
    }
    else if (this->children.empty() && !this->getValue().empty()) {
        return this->getValue();
    }

    return std::nullopt;
}
