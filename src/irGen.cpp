#include "irGen.h"

using namespace ir;
IrGen::IrGen(std::shared_ptr<Node> codeStruct)
{
    this->root = codeStruct;
    entry_point = new ControlFlowGraph;
    
    // for(auto&child:root->children)
    // {
    //   child->genIR(cfgs);
    // }
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
  LOG_INFO("START GENIR!_________-----------------------___________________________-----------------____________");

  LOG_INFO("entry_point->entry_point = "<<entry_point->entry_point);
  int i = 0;
      for (const auto &child : root->children) {
        std::string str =child->getType();

        LOG_INFO("start gentIr"<< str);
        child->genIR(cfgs);
        i++;
    }
    
  LOG_INFO("finish GENIR"<<i<<"-----------------------------------------------");
}

void IrGen::write_cfg(std::ostream &stream) const {
  LOG_INFO("START WRTING!_________-----------------------___________________________-----------------____________");
  stream << "digraph {" << std::endl;
  stream << "graph [splines=ortho]" << std::endl;
  stream << "node [shape=box];" << std::endl;
// for(const auto &class_node : this->root->children){
    // std::cout << class_node->getId()<<std::endl;


  for (const auto &[key, cfg] : this->cfgs) {
     std::cout <<"cfg number"<< cfg->entry_point<<"   "<<this->entry_point<<std::endl;
     
     LOG_INFO("Key: "<<cfg->entry_point->identifier  );
     if (cfg == this->entry_point) {
       LOG_INFO("key:"<< key);
  //     stream << "entrypoint[shape=box label=\"Entry Point\"];" << std::endl;
  //     stream << "entrypoint -> " << cfg->entry_point->get_id() << ";" << std::endl;
     }

    stream << "subgraph \"cluster" << key << "\" {" << std::endl;
    stream << "label = \"" << cfg->entry_point->identifier << "\";" << std::endl;
    cfg->write(stream);
    LOG_INFO("key:"<< key);
    stream << "}" << std::endl;

   }
  
  stream << "}" << std::endl;
  LOG_INFO("END WRTING!_________-----------------------___________________________-----------------____________");


}
