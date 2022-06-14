#include "irGen.h"

using namespace ir;
IrGen::IrGen(std::shared_ptr<Node> codeStruct)
{
    this->root = codeStruct;
    entry_point = new ControlFlowGraph;
    for(auto&child:root->children)
    {
      child->genIR(cfgs);
    }
    //遍历子节点，收集CFG数据
    // for(const auto &class_node : this->root->astTree){
    //     std::cout << class_node->getId()<<std::endl;
    // }
    // for(auto beg=this->root->astTree.begin(); beg!=this->root->astTree.end();beg++){
    //     std::cout<< *beg<<std::endl;
    // }
    
}

void IrGen::generateIr(std::ostream &stream)
{
  LOG_INFO("entry_point->entry_point = "<<entry_point->entry_point);
      for (const auto &child : root->children) {
        child->genIR(entry_point->entry_point);
    }
}

void IrGen::write_cfg(std::ostream &stream) const {
  stream << "digraph {" << std::endl;
  stream << "graph [splines=ortho]" << std::endl;
  stream << "compound=true;" << std::endl;
// for(const auto &class_node : this->root->children){
    // std::cout << class_node->getId()<<std::endl;


  for (const auto &[key, cfg] : this->cfgs) {
    // std::cout <<"cfg number"<< cfg->get_id()<<std::endl;
    if (cfg == this->entry_point) {
      stream << "entrypoint[shape=box label=\"Entry Point\"];" << std::endl;
      stream << "entrypoint -> " << cfg->entry_point->get_id() << ";" << std::endl;
    }
    stream << "subgraph \"cluster" << key << "\" {" << std::endl;
    stream << "label = \"" << cfg->entry_point->identifier << "\";" << std::endl;
    cfg->write(stream);
    
  // }
  stream << "}" << std::endl;

  stream << "}" << std::endl;

}
}
