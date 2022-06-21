#include "class_extends_declaration.h"
using std::string;

ClassExtendsDeclaration::ClassExtendsDeclaration() : Declarations() {}
ClassExtendsDeclaration::ClassExtendsDeclaration(string t, string v) : Declarations(std::move(t), std::move(v)) {}

std::optional<string> ClassExtendsDeclaration::generateST() {
    string class_name, class_type;
    class_name = class_type = this->children.at(0)->generateST().value_or("Unknown");
    ClassExtendsDeclaration::st.setScopeTitle("Class: " + class_name);  // Set the current scope title
    std::shared_ptr<Variable> variable_this_ptr = std::make_shared<Variable>("this", class_type);
    ClassExtendsDeclaration::st.addRecord("this", variable_this_ptr);

    std::shared_ptr<STClass> class_ptr = std::make_shared<STClass>(class_name, class_type);
    class_ptr->addVariable(variable_this_ptr);
    ClassExtendsDeclaration::st.getParentScope()->addRecord(class_name, class_ptr);

    for (size_t i = 2; i < this->children.size(); ++i) {
        this->children.at(i)->generateST();
    }

    string parent_class_name = this->children.at(1)->generateST().value_or("Unknown");
    class_ptr->setType(class_type + " " + parent_class_name);

    auto c_record_ptr = ClassExtendsDeclaration::st.lookupRecord(parent_class_name).value_or(nullptr);
    if (c_record_ptr) {
        std::shared_ptr<STClass> parent_class_ptr = std::dynamic_pointer_cast<STClass>(c_record_ptr);

        for (const auto &pair : parent_class_ptr->getVariables()) {
            if (pair.first != "this" && !ClassExtendsDeclaration::st.lookupRecord(pair.first).has_value()) {
                std::shared_ptr<Variable> variable_ptr = std::make_shared<Variable>(*(pair.second));
                ClassExtendsDeclaration::st.addRecord(variable_ptr->getName(), variable_ptr);
                class_ptr->addVariable(variable_ptr);
            }
        }

        for (const auto &pair : parent_class_ptr->getMethods()) {
            if (!ClassExtendsDeclaration::st.lookupChildScope(pair.first).value_or(nullptr)) {
                std::shared_ptr<Method> method_ptr =
                    std::make_shared<Method>(pair.first, pair.second->getType());
                ClassExtendsDeclaration::st.addRecord(method_ptr->getName(), method_ptr);
                class_ptr->addMethod(method_ptr);
                ClassExtendsDeclaration::st.enterScope();
                ClassExtendsDeclaration::st.setScopeTitle("Method: " + method_ptr->getName());
                for (const auto &var_pair : pair.second->getVariables()) {
                    std::shared_ptr<Variable> v_ptr =
                        std::make_shared<Variable>(var_pair.first, var_pair.second->getType());
                    method_ptr->addVariable(v_ptr);
                    ClassExtendsDeclaration::st.addRecord(v_ptr->getName(), v_ptr);
                }
                for (const auto &par_ptr : pair.second->getParameters()) {
                    std::shared_ptr<Parameter> p_ptr =
                        std::make_shared<Parameter>(par_ptr->getName(), par_ptr->getType());
                    method_ptr->addParameter(p_ptr);
                    ClassExtendsDeclaration::st.addRecord(p_ptr->getName(), p_ptr);
                }
                ClassExtendsDeclaration::st.exitScope();
            }
        }
    }

    return std::nullopt;
}

std::optional<string> ClassExtendsDeclaration::checkSemantics() {
    if (this->children.size() >= 2 && this->children.at(1)->getType() == "Identifier") {
        for (size_t i = 2; i < this->children.size(); ++i) {
            this->children.at(i)->checkSemantics();
        }
    }

    return std::nullopt;
}
void* ClassExtendsDeclaration::genIR(BasicBlock *currentBlock)
{
    //LOG_INFO("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ClassExtendsDeclaration override the GENIR, value="<<value<<"type:"<<type<< "children size"<< children.size());
    
    for(auto &child: children){
        //LOG_INFO("ClassExtent YES");
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