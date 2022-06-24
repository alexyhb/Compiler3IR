#include "method_declaration.h"
using std::size_t;
using std::string;

MethodDeclaration::MethodDeclaration() : Declarations() {}
MethodDeclaration::MethodDeclaration(std::string t, std::string v) : Declarations(std::move(t), std::move(v)) {}
void* MethodDeclaration::genIR(BasicBlock* currentBlock)
{
   // LOG_INFO("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!MethodDeclaration override the GENIR, value="<<value<<"type:"<<type<< "children size"<< children.size());
    for(auto &child: children){
      //  LOG_INFO("-----------------------"<<child->getId());
        child->genIR(currentBlock);
    }
    // Address* result = Address::getAddressFromType();
    // Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);
    // Address* addrRhs =(Address*)children.at(1)->genIR(currentBlock);
    // std::string operatorString = getValue();
    // ThreeAddressCode* in = new ExpressionIr(result,addrLhs,addrRhs,operatorString);
    // currentBlock->add_code(in);
    //return (void*)result;
    //ControlFlowGraph * controlFlowGraph = new ControlFlowGraph();
    //TODO
   
}
std::optional<string> MethodDeclaration::generateST() {
    string method_name, method_type;
    method_type = this->children.at(0)->generateST().value_or("Unknown");
    method_name = this->children.at(1)->generateST().value_or("Unknown");
    std::shared_ptr<Method> method_ptr = std::make_shared<Method>(method_name, method_type);
    MethodDeclaration::st.addRecord(method_name, method_ptr);

    string scope_name = MethodDeclaration::st.getScopeTitle();
    string scope_type = MethodDeclaration::st.getScopeType();
    auto record_ptr = MethodDeclaration::st.lookupRecord(scope_name).value_or(nullptr);
    if (scope_type == "Class" && record_ptr) {
        auto class_ptr = std::dynamic_pointer_cast<STClass>(record_ptr);
        class_ptr->addMethod(method_ptr);
    }

    MethodDeclaration::st.enterScope();
    MethodDeclaration::st.setScopeTitle("Method: " + method_name);
    for (size_t i = 2; i < this->children.size(); ++i) {
        this->children.at(i)->generateST();
    }
    MethodDeclaration::st.exitScope();

    return std::nullopt;
}

std::optional<string> MethodDeclaration::checkSemantics() {
    MethodDeclaration::st.enterScope();
    for (const auto &child : this->children) {
        if (child->getType() == "MethodBody" || child->getType() == "Return") {
            child->checkSemantics();
        }
    }
    MethodDeclaration::st.exitScope();

    return std::nullopt;
}

void* MethodDeclaration::genIR(std::map<std::string ,ControlFlowGraph*> &cfgs)
{
     string scope_name = MethodDeclaration::st.getScopeTitle();
     //LOG_INFO(scope_name<<" " <<children.at(1)->getValue());
    ControlFlowGraph * controlFlowGraph = new ControlFlowGraph();
     //LOG_INFO("!!!!!!!!!!!!!"<<children.at(0)->getValue());
    cfgs[children.at(1)->getValue()] = controlFlowGraph;
    for(auto &child: children){
        child->genIR(controlFlowGraph->entry_point);

    }
    return nullptr;
}