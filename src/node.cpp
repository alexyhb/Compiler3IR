#include "node.h"
using std::cout;
using std::endl;
using std::size_t;
using std::string;

Node::Node() {
    this->type = "uninitialised";
    this->value = "uninitialised";
}

Node::Node(string t, string v) : type(std::move(t)), value(std::move(v)) {}

void Node::setId(size_t n_id) {
    this->id = n_id;
}

void Node::setType(string n_type) {
    this->type = std::move(n_type);
}

void Node::setValue(string n_value) {
    this->value = std::move(n_value);
}

size_t Node::getId() const {
    return this->id;
}

string Node::getType() const {
    return this->type;
}

string Node::getValue() const {
    return this->value;
}
//genIR interface maybe different for statment and expression
void* Node::genIR(BasicBlock *currentBlock)
{
   // LOG_INFO("drived class should override genIR function, type = "<<type<<", value = "<<value);
   // LOG_INFO("children size = "<<children.size());
    void* result = nullptr;
    if(type=="boolean"||type=="int"){
    //    LOG_INFO("this is"<< type<<" and value is "<< value );
    }
    for (const auto &child : children) {
            child->printInf();
            result = child->genIR(currentBlock);
        }
    if(result!=nullptr&&getValue().size()>0)
        return result;
   // LOG_INFO("return null pointer, shouldn't be like this 1"<<type);
    return NULL;
}
void* Node::genIR(std::map<std::string ,ControlFlowGraph*> &cfgs)
{
    printInf();
    if(children.size()>0)
        return children.at(0)->genIR(cfgs);
   // LOG_INFO("return null pointer, shouldn't be like this 2");
    return NULL;
}
void Node::printInf()
{
    LOG_INFO("type = "<<type<<", value = "<<value);
}
void Node::generateAST(std::ofstream *outStream, size_t &count) {
    this->setId(count++);
    if (!this->getValue().empty()) {
        *outStream << "n" << this->getId() << " [label=\"" << this->getType() << ":" << this->getValue() << "\"];"
                   << endl;
    } else {
        *outStream << "n" << this->getId() << " [label=\"" << this->getType() << "\"];" << endl;
    }
    for (const auto &child : this->children) {
        child->generateAST(outStream, count);
        *outStream << "n" << this->getId() << " -> n" << child->getId() << ";" << endl;
    }
}

void Node::buildST(std::ofstream *outStream) {
    this->generateST();
    Node::st.resetTable();
    Node::st.printST(outStream);
}

std::optional<string> Node::generateST() {
    for (const auto &child : this->children) {
        child->generateST();
    }
    return std::nullopt;
}

void Node::semanticAnalysis() {
    this->checkSemantics();
    Node::st.resetTable();
}

std::optional<string> Node::checkSemantics() {
    for (const auto &child : this->children) {
        child->checkSemantics();
    }
    return std::nullopt;
}

void Node::printErrMsg(const string &message) {
    std::cerr << message << endl;
    std::exit(EXIT_FAILURE);
}
