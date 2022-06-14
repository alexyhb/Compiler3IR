#include "main_class.h"
using std::size_t;
using std::string;

MainClass::MainClass() : Node() {}
MainClass::MainClass(string t, string v) : Node(std::move(t), std::move(v)) {}
void* MainClass::genIR(std::map<std::string ,ControlFlowGraph*> &cfgs)
{
    ControlFlowGraph * controlFlowGraph = new ControlFlowGraph();
    cfgs[children.at(0)->getValue()] = controlFlowGraph;
    children.at(2)->genIR(controlFlowGraph->entry_point);
    return nullptr;
}

std::optional<string> MainClass::generateST() {
    string class_name, class_type;
    class_name = class_type = this->children.at(0)->generateST().value_or("Unknown");
    MainClass::st.setScopeTitle("Class: " + class_name);
    std::shared_ptr<Variable> variable_this_ptr = std::make_shared<Variable>("this", class_type);
    std::shared_ptr<Method> method_main_ptr = std::make_shared<Method>("main", "void");
    MainClass::st.addRecord("this", variable_this_ptr);
    MainClass::st.addRecord("main", method_main_ptr);

    std::shared_ptr<STClass> class_ptr = std::make_shared<STClass>(class_name, class_type);
    class_ptr->addVariable(variable_this_ptr);
    class_ptr->addMethod(method_main_ptr);
    MainClass::st.getParentScope()->addRecord(class_name, class_ptr);

    MainClass::st.enterScope();
    MainClass::st.setScopeTitle("Method: main");
    string parameter_name = this->children.at(1)->generateST().value_or("Unknown");
    std::shared_ptr<Parameter> parameter_ptr = std::make_shared<Parameter>(parameter_name, "String[]");
    method_main_ptr->addParameter(parameter_ptr);
    MainClass::st.addRecord(parameter_name, parameter_ptr);
    for (size_t i = 2; i < this->children.size(); ++i) {
        this->children.at(i)->generateST();
    }
    MainClass::st.exitScope();

    return std::nullopt;
}

std::optional<string> MainClass::checkSemantics() {
    MainClass::st.enterScope();
    for (size_t i = 2; i < this->children.size(); ++i) {
        this->children.at(i)->checkSemantics();
    }
    MainClass::st.exitScope();
    return std::nullopt;
}
