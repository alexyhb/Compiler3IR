#include "expression.h"
using std::size_t;
using std::string;

Expression::Expression() : Node() {}
Expression::Expression(string t, string v) : Node(std::move(t), std::move(v)) {}

std::optional<string> Expression::generateST() {
    return std::nullopt;
}

void* Expression::genIR(BasicBlock* currentBlock) {

    

    size_t size = children.size();
    
    
    //LOG_INFO("Size of experession!!!!!!!!!!!!!!!!!!!!!!!!!! : " << children.size());
    if(size==1){
        
        string type = this->children.at(0)->getType();
        
        string value= this->children.at(0)->getValue();
        if(type=="PrimaryExpression"||type=="UnaryExpression"||type=="CompareExpression"||type=="ArithExpression"||type=="ArraySearchExpression"||type=="ArrayLengthExpression"||type=="keyword"){
            Address* result =(Address*) children.at(0)->genIR(currentBlock);
            return (void*)result;
        }else{
            LOG_INFO("here"<<type<<value);
            Address *address =  Address::getAddressFromType(type,value);
            return (void*) address;
        }
    }
    if(size==3){
        LOG_INFO("Method call 3: "<<value<< "type "<<type<<" child size: ");
        Address* result = Address::getAddressFromType(type,value);
        Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);
        LOG_INFO("Children0:" << children.at(0)->getValue());
        Address* addrRhs =(Address*)children.at(1)->genIR(currentBlock);
        LOG_INFO("Children1:" << children.at(1)->getValue()<<children.at(1)->getType() );
        Address* params =(Address*)children.at(2)->genIR(currentBlock);
        LOG_INFO("Children2:" << children.at(2)->getValue());

    // //     Address* result = (Address*)children.at(0)->genIR(currentBlock);
    // //     Address* addrLhs = (Address*)children.at(1)->genIR(currentBlock);
    // //     Address* addrRhs =(Address*)children.at(2)->genIR(currentBlock);
        ThreeAddressCode* in = new MethodCallIr(result,addrLhs,addrRhs,params);
        currentBlock->add_code(in);
        return (void*)result;
    }
    if(size==2){
        LOG_INFO("Method call 2: "<<value<< "type "<<type<<" child size: ");
        LOG_INFO("Children0:" << children.at(0)->getValue());
        LOG_INFO("Children1:" << children.at(1)->getValue());
        Address* result = Address::getAddressFromType();

        Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);
        Address* addrRhs =(Address*)children.at(1)->genIR(currentBlock);
        ThreeAddressCode* in = new MethodCallIr(result,addrLhs,addrRhs);
        currentBlock->add_code(in);
    }
    // else if(size==3 && (type == "AllocExpression"|| type == "PrimaryExpression"||type == "keyword")){
    //      LOG_INFO("Method call 1 : ");
        
    //     Address* result = (Address*)children.at(0)->genIR(currentBlock);
    //     Address* addrLhs = (Address*)children.at(1)->genIR(currentBlock);
    //     Address* addrRhs =(Address*)children.at(2)->genIR(currentBlock);
    //     ThreeAddressCode* in = new MethodCallIr(result,addrLhs,addrRhs);
    // currentBlock->add_code(in);

    // }else if(size == 2 &&(type == "AllocExpression"|| type == "PrimaryExpression"||type == "keyword")){
    //      LOG_INFO("Method call 2: ");
        
    //     Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);
    //     Address* addrRhs =(Address*)children.at(1)->genIR(currentBlock);
    //     ThreeAddressCode* in = new MethodCallIr(addrLhs,addrRhs);
    // currentBlock->add_code(in);

    // }else
    // {
    //     LOG_INFO("THIS IS FAULT"<< size);
    //     for(auto&child:children)
    //     {
    //     child->genIR(currentBlock);
    //     }
    // }
}
std::optional<string> Expression::checkSemantics() {
    string class_name;
    string method_name;
    string var_name;
    std::shared_ptr<Record> c_record_ptr;
    std::shared_ptr<Record> v_record_ptr;
    std::shared_ptr<Record> m_record_ptr;
    std::shared_ptr<STClass> class_ptr;

    size_t size = this->children.size();
    string type = this->children.at(0)->getType();

    if (size == 1 && type == "PrimaryExpression") {
        // Check parameters
        var_name = this->children.at(0)->checkSemantics().value_or("");
        if (var_name == "int" || var_name == "boolean") {
            return var_name;
        }
        v_record_ptr = Expression::st.lookupRecord(var_name).value_or(nullptr);
        if (v_record_ptr && (v_record_ptr->getRecord() == "Variable" || v_record_ptr->getRecord() == "Parameter")) {
            return v_record_ptr->getType();
        } else {
            string msg = "[Semantic Analysis] - Error: Variable \"" + var_name + "\" does not exist in scope \"" +
                         Expression::st.getScopeTitle() + "\"!";
            Expression::printErrMsg(msg);
        }
    }
    else if (size == 1 && (type == "AllocExpression" || type == "ArrayAllocExpression" || type == "UnaryExpression")) {
        return this->children.at(0)->checkSemantics();
    }
    else if (size == 1) {
        if (type == "keyword") {
            v_record_ptr = Expression::st.lookupRecord(this->children.at(0)->getValue()).value_or(nullptr);
            if (v_record_ptr) {
                return v_record_ptr->getType();
            }
        }
        else {
            return type;
        }
    }
    else if (size <= 3 && type == "AllocExpression") {
        class_name = this->children.at(0)->checkSemantics().value_or("");
        method_name = this->children.at(1)->checkSemantics().value_or("");

        c_record_ptr = Expression::st.lookupRecordInRoot(class_name).value_or(nullptr);
        class_ptr = std::dynamic_pointer_cast<STClass>(c_record_ptr);

        m_record_ptr = class_ptr->lookupMethod(method_name).value_or(nullptr);
        if (!m_record_ptr) {
            string msg = "[Semantic Analysis] - Error: Method \"" + method_name + "\" does not exist in scope \"" +
                         class_ptr->getType() + "\"!";
            Expression::printErrMsg(msg);
        }

        this->checkParameters(m_record_ptr);

        return m_record_ptr->getType();
    }
    else if (size <= 3 && type == "PrimaryExpression") {
        var_name = this->children.at(0)->checkSemantics().value_or("");
        method_name = this->children.at(1)->checkSemantics().value_or("");

        v_record_ptr = Expression::st.lookupRecord(var_name).value_or(nullptr);
        if (!v_record_ptr) {
            string msg = "[Semantic Analysis] - Error: Variable \"" + var_name + "\" does not exist in scope \"" +
                         Expression::st.getScopeTitle() + "\"!";
            Expression::printErrMsg(msg);
        }

        class_name = v_record_ptr->getType();
        c_record_ptr = Expression::st.lookupRecordInRoot(class_name).value_or(nullptr);
        class_ptr = std::dynamic_pointer_cast<STClass>(c_record_ptr);

        if (!class_ptr) {
            string msg = "[Semantic Analysis] - Error: Class \"" + class_name + "\" does not exist!";
            Expression::printErrMsg(msg);
        } else {
            m_record_ptr = class_ptr->lookupMethod(method_name).value_or(nullptr);
            if (!m_record_ptr) {
                string msg = "[Semantic Analysis] - Error: Method \"" + method_name + "\" does not exist in scope \"" +
                             Expression::st.getScopeTitle() + "\"!";
                Expression::printErrMsg(msg);
            }
        }

        this->checkParameters(m_record_ptr);

        return m_record_ptr->getType();
    }
    else if (size <= 3 && type == "keyword") {
        method_name = this->children.at(1)->checkSemantics().value_or("");
        m_record_ptr = Expression::st.lookupRecord(method_name).value_or(nullptr);
        if (!m_record_ptr) {
            string msg = "[Semantic Analysis] - Error: Method \"" + method_name + "\" does not exist in scope \"" +
                         Expression::st.getScopeTitle() + "\"!";
            Expression::printErrMsg(msg);
        }

        this->checkParameters(m_record_ptr);

        return m_record_ptr->getType();
    }

    return std::nullopt;
}

void Expression::checkParameters(const std::shared_ptr<Record> &m_record_ptr) {
    std::shared_ptr<Method> method_ptr;
    std::deque<string> p_deque;

    if (this->children.size() == 3 && this->children.at(2)->getType() == "ExpressionList") {
        method_ptr = std::dynamic_pointer_cast<Method>(m_record_ptr);

        string parameter_type_list = this->children.at(2)->checkSemantics().value_or("");
        Expression::strSplit(p_deque, parameter_type_list, " ");

        if (p_deque.size() != method_ptr->getParameters().size()) {
            string msg = "[Semantic Analysis] - Error: Parameter numbers do not match in scope \"" +
                         Expression::st.getScopeTitle() + "\"!";
            Expression::printErrMsg(msg);
        }

        for (size_t i = 0; i < method_ptr->getParameters().size(); ++i) {
            string type_from_m = method_ptr->getParameters().at(i)->getType();
            string type_from_p = p_deque.at(i);

            if (type_from_p != type_from_m) {
                auto c_record_ptr = Expression::st.lookupRecordInRoot(type_from_p).value_or(nullptr);

                if (!c_record_ptr || c_record_ptr->getType().find(type_from_m) == string::npos) {
                    string msg = "[Semantic Analysis] - Error: Parameter types (\"";
                    msg += type_from_m + "\" - \"";
                    msg += type_from_p + "\") do not match in scope \"";
                    msg += Expression::st.getScopeTitle() + "\"!";
                    Expression::printErrMsg(msg);
                }
            }
        }
    }
}

void Expression::strSplit(std::deque<std::string> &deque, std::string &text, const std::string &delimiter) {
    size_t pos;

    if (text.rfind(delimiter) != (text.length() - delimiter.length())) {
        text += delimiter;
    }

    while ((pos = text.find(delimiter)) != string::npos) {
        deque.push_back(text.substr(0, pos));
        text.erase(0, pos + delimiter.length());
    }
}
