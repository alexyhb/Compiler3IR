#include "class_declaration.h"
using std::size_t;
using std::string;

ClassDeclaration::ClassDeclaration() : Declarations() {}
ClassDeclaration::ClassDeclaration(string t, string v) : Declarations(std::move(t), std::move(v)) {}
// void ClassDeclaration::generateIR(std::map<std::string ,ControlFlowGraph*> &cfgs) 
// {
//     ControlFlowGraph *CFG = new ControlFlowGraph;
//     cfgs[children.at(0)->getValue()] = CFG;
// }

std::optional<string> ClassDeclaration::generateST() {
    string class_name, class_type;
    class_name = class_type = this->children.at(0)->generateST().value_or("Unknown");
    ClassDeclaration::st.setScopeTitle("Class: " + class_name);  // Set the current scope title
    std::shared_ptr<Variable> variable_this_ptr = std::make_shared<Variable>("this", class_type);
    ClassDeclaration::st.addRecord("this", variable_this_ptr);

    std::shared_ptr<STClass> class_ptr = std::make_shared<STClass>(class_name, class_type);
    class_ptr->addVariable(variable_this_ptr);
    ClassDeclaration::st.getParentScope()->addRecord(class_name, class_ptr);

    for (size_t i = 1; i < this->children.size(); ++i) {
        this->children.at(i)->generateST();
    }

    return std::nullopt;
}

std::optional<string> ClassDeclaration::checkSemantics() {
    for (size_t i = 1; i < this->children.size(); ++i) {
        this->children.at(i)->checkSemantics();
    }

    return std::nullopt;
}

void* ClassDeclaration::genIR(BasicBlock *currentBlock)
{
    for(auto &child: children){
   // LOG_INFO("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Declarations override the GENIR, value="<<value<<"type:"<<type<< "children size"<< children.size());
        child->genIR(currentBlock);
    }
    // Address* result = Address::getAddressFromType();
    // Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);
    // Address* addrRhs =(Address*)children.at(1)->genIR(currentBlock);
    // std::string operatorString = getValue();
    // ThreeAddressCode* in = new ExpressionIr(result,addrLhs,addrRhs,operatorString);
    // currentBlock->add_code(in);
    //return (void*)result;
}