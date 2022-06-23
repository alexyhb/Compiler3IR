#include "irGen.h"

using namespace ir;
IrGen::IrGen(std::shared_ptr<Node> codeStruct)
{
  this->root = codeStruct;
  entry_point = new ControlFlowGraph;
}

void IrGen::generateIr()
{
  LOG_INFO("entry_point = "<<entry_point->get_id());
  for (const auto &child : root->children)
  {
    child->genIR(cfgs);
  }
}

void IrGen::write_cfg(std::ostream &stream) const
{
  LOG_INFO("START WRTING!_________-----------------------___________________________-----------------____________");
  stream << "digraph {" << std::endl;
  stream << "graph [splines=ortho]" << std::endl;
  stream << "node [shape=box];" << std::endl;
  // for(const auto &class_node : this->root->children){
  // std::cout << class_node->getId()<<std::endl;
  for (const auto &[key, cfg] : this->cfgs)
  {
    if (this->entry_point==cfg)
    {
      LOG_INFO("THIS_is the entry point");
      /* code */
    }
    
    LOG_INFO("NOW is writing the cfg "<< key);
    stream << "subgraph \"cluster" << key << "\" {" << std::endl;
    stream << "label = \"" << key << "\";" << std::endl;
    cfg->write(stream);
    stream << "}" << std::endl;
  }
   stream << "}" << std::endl;
  LOG_INFO("END WRTING!_________-----------------------___________________________-----------------____________");
}
    //  if( cfg->entry_point->identifier==this->entry_point->entry_point->identifier){
    //     stream << "entrypoint[shape=box label=\"Entry Point\"];" << std::endl;
    //     stream << "entrypoint -> " << cfg->entry_point->get_id() << ";" << std::endl;
   
    // cfg->entry_point->write(stream,visited);
    //  LOG_INFO("key:"<< key);
  

    //    if (cfg->entry_point->id == this->entry_point->entry_point->id) {
    //     LOG_INFO("!@$@##@!!%!@%@#%!%#@%!@%@#sKey: "<<cfg->entry_point->identifier  );
    //     //  LOG_INFO("key:"<< key);
    // //     stream << "entrypoint[shape=box label=\"Entry Point\"];" << std::endl;
    // //     stream << "entrypoint -> " << cfg->entry_point->get_id() << ";" << std::endl;
    //     stream << "subgraph \"cluster" << key << "\" {" << std::endl;
    //     stream << "label = \"" << cfg->entry_point->identifier << "\";" << std::endl;
    //     std::map<long, bool> visited;
    //     cfg->entry_point->write(stream,visited);
    //     // LOG_INFO("key:"<< key);
    //     stream << "}" << std::endl;
    //    }
    //   // stream << "subgraph \"cluster" << key << "\" {" << std::endl;
    // stream << "label = \"" << cfg->entry_point->identifier << "\";" << std::endl;
    // cfg->write(stream);
    // // LOG_INFO("key:"<< key);
    // stream << "}" << std::endl;
  

 

void IrGen::write_bytecode(std::ostream &stream) const
{
  for (const auto &[key, cfg] : this->cfgs)
  {

    cfg->write_bytecode(stream);
  }
}