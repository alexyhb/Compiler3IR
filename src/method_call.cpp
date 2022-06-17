#include "method_call.h"
using std::size_t;
using std::string;

MethodCall::MethodCall() : Node() {}
MethodCall::MethodCall(string t, string v) : Node(std::move(t), std::move(v)) {}

std::optional<string> MethodCall::generateST() {
    return std::nullopt;
}

void* MethodCall::genIR(BasicBlock* BB) {
    //LOG_INFO("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ClassExtendsDeclaration override the GENIR, value="<<value<<"type:"<<type<< "children size"<< children.size());

    //return children.at(0)->genIR(BB);
}
std::optional<string> MethodCall::checkSemantics() {
    // string class_name;
    // string method_name;
    // string var_name;
    // std::shared_ptr<Record> c_record_ptr;
    // std::shared_ptr<Record> v_record_ptr;
    // std::shared_ptr<Record> m_record_ptr;
    // std::shared_ptr<STClass> class_ptr;

    size_t size = this->children.size();
    string type = this->children.at(0)->getType();
   // LOG_INFO("METHODCALL CHECK size:"<< size<< " type: "<< type );
 

    return std::nullopt;
}

// void MethodCall::checkParameters(const std::shared_ptr<Record> &m_record_ptr) {
//     std::shared_ptr<Method> method_ptr;
//     std::deque<string> p_deque;

//     if (this->children.size() == 3 && this->children.at(2)->getType() == "MethodCallList") {
//         method_ptr = std::dynamic_pointer_cast<Method>(m_record_ptr);

//         string parameter_type_list = this->children.at(2)->checkSemantics().value_or("");
//         MethodCall::strSplit(p_deque, parameter_type_list, " ");

//         if (p_deque.size() != method_ptr->getParameters().size()) {
//             string msg = "[Semantic Analysis] - Error: Parameter numbers do not match in scope \"" +
//                          MethodCall::st.getScopeTitle() + "\"!";
//             MethodCall::printErrMsg(msg);
//         }

//         for (size_t i = 0; i < method_ptr->getParameters().size(); ++i) {
//             string type_from_m = method_ptr->getParameters().at(i)->getType();
//             string type_from_p = p_deque.at(i);

//             if (type_from_p != type_from_m) {
//                 auto c_record_ptr = MethodCall::st.lookupRecordInRoot(type_from_p).value_or(nullptr);

//                 if (!c_record_ptr || c_record_ptr->getType().find(type_from_m) == string::npos) {
//                     string msg = "[Semantic Analysis] - Error: Parameter types (\"";
//                     msg += type_from_m + "\" - \"";
//                     msg += type_from_p + "\") do not match in scope \"";
//                     msg += MethodCall::st.getScopeTitle() + "\"!";
//                     MethodCall::printErrMsg(msg);
//                 }
//             }
//         }
//     }
// }

// void MethodCall::strSplit(std::deque<std::string> &deque, std::string &text, const std::string &delimiter) {
//     size_t pos;

//     if (text.rfind(delimiter) != (text.length() - delimiter.length())) {
//         text += delimiter;
//     }

//     while ((pos = text.find(delimiter)) != string::npos) {
//         deque.push_back(text.substr(0, pos));
//         text.erase(0, pos + delimiter.length());
//     }
// }
