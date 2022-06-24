#include "identifier.h"
using std::string;

Identifier::Identifier() : Node() {}
Identifier::Identifier(string t, string v) : Node(std::move(t), std::move(v)) {}

std::optional<string> Identifier::generateST() {
    return this->getValue();
}

std::optional<string> Identifier::checkSemantics() {
    return this->getValue();
}



void* Identifier::genIR(BasicBlock *currentBlock) {
    LOG_INFO("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Identifier genIR function, type = "<<type<<", value = "<<value);
    this->st.lookupRecord(getValue());
    return (void*)Address::getAddressFromType(getType(),getValue());
}