#include "cfg.h"

uint BasicBlock::id = 0;

BasicBlock::BasicBlock(std::string identifier)
    : positive_branch(nullptr), negative_branch(nullptr), identifier(identifier),condition(nullptr) {
      
}

BasicBlock::BasicBlock()
    : positive_branch(nullptr), negative_branch(nullptr),condition(nullptr) {
  this->identifier = "block_"+std::to_string(this->getId());
}
BasicBlock::BasicBlock(BasicBlock *positive_branch)
    : positive_branch(positive_branch), negative_branch(nullptr),condition(nullptr) {
      this->identifier = "block_"+std::to_string(this->getId());
}
BasicBlock::BasicBlock(BasicBlock *positive_branch, BasicBlock *negative_branch)
    : positive_branch(positive_branch), negative_branch(negative_branch),condition(nullptr) {
      this->identifier = "block_"+std::to_string(this->getId());
}

intptr_t BasicBlock::get_id() const {
  return reinterpret_cast<intptr_t>(this);
}
int BasicBlock::getBlockId() const{
  return (int)(BasicBlock::id);
}
uint BasicBlock::getId() const {
  return (BasicBlock::id)++;
}
void BasicBlock::add_code(ir::ThreeAddressCode *code) {
  this->codes.push_back(code);
}

void BasicBlock::set_identifier(std::string identifier, Address *result) {
  this->identifiers[identifier] = result;
}
void BasicBlock::set_condition(ir::ThreeAddressCode *condition)
{
  this->condition = condition;
}

void BasicBlock::write(std::ostream &stream, std::map<long, bool> &visited) const {
  // Recursion guard
 
  // if (visited.count(this->getId()) > 0)
  //   return;
  // visited[this->getId()] = true;

  //stream << this->getId() << "[shape=box xlabel=\"" << this->identifier << "\", label=\"";
  stream << this->identifier << "[shape=box label=\""<<this->identifier<<"\n";
  
  for (const auto &code : this->codes) {
   
    //LOG_INFO("CODE "<< i <<"reulst: "<< code->result << "left : "<< code->left <<" right:  " << code->right);
    code->write(stream);
    stream << "\\n";

  }

  stream << "\"];" << std::endl;

  if (this->positive_branch != nullptr) {
   //LOG_INFO("here");
    stream << this->identifier<< " -> " << this->positive_branch->identifier << "[xlabel=\"true\"];" << std::endl;
    this->positive_branch->write(stream, visited);
  }

  if (this->negative_branch != nullptr) {
   
    stream << this->identifier << " -> " << this->negative_branch->identifier << "[xlabel=\"false\"];" << std::endl;
    this->negative_branch->write(stream, visited);
  }
}
void BasicBlock::genByteCode(std::ostream &stream,std::map<long, bool> &visited){
    if (visited.count(this->getId()) > 0)
    return;
  visited[this->getId()] = true;

  for (const auto &code : this->codes) {
   
    //LOG_INFO("CODE "<< i <<"reulst: "<< code->result << "left : "<< code->left <<" right:  " << code->right);
    code->genByteCode(stream);
    

  }
}
BasicBlock* BasicBlock::findJoinBlock(BasicBlock *BB){
  if(BB->negative_branch==nullptr && BB->positive_branch==nullptr){
    return BB;
  }else{
    return BB->positive_branch->findJoinBlock(BB->positive_branch);
  }
}
ControlFlowGraph::ControlFlowGraph() {
  this->entry_point = new BasicBlock();
}
ControlFlowGraph::ControlFlowGraph(const std::string& identifier) {
  this->entry_point = new BasicBlock(identifier);
}
void ControlFlowGraph::write_standalone(std::ostream &stream) const {
  stream << "digraph {" << std::endl;

  stream << "graph [splines=ortho]" << std::endl;

  this->write(stream);

  stream << "}" << std::endl;
}

void ControlFlowGraph::write(std::ostream &stream) const {
  std::map<long, bool> visited;
  this->entry_point->write(stream, visited);
}
void ControlFlowGraph::write_bytecode(std::ostream &stream) const {
  std::map<long, bool> visited;
  
  this->entry_point->genByteCode(stream,visited);
}
intptr_t ControlFlowGraph::get_id() const {
  return reinterpret_cast<intptr_t>(this);
}