#ifndef PROGRAM_H
#define PROGRAM_H

#include "cfg.h"
#include "nodes.h"
// #include "../bytecode.h"



class Program {
private:
  const Node *program_node;
  std::map<std::string, ControlFlowGraph *> cfgs;
  ControlFlowGraph *entry_point;
//   Bytecode *bytecode;

public:
  Program(const Node *program_node);
  void write_cfg(std::ostream &stream) const;
//   void write_bytecode(std::ostream &stream) const;
//   void execute() const;
};

#endif
