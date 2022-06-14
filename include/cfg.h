#ifndef CFG_H
#define CFG_H

#include <list>
#include <map>
#include <ostream>

#include "ir.h"

using namespace ir;

class BasicBlock {
public:
  std::map<std::string, ir::Address *> identifiers;
  std::list<ir::ThreeAddressCode *> codes;
  ir::ThreeAddressCode* condition;
  BasicBlock *positive_branch;
  BasicBlock *negative_branch;
  std::string identifier;
  static uint id;
  BasicBlock();
  BasicBlock(std::string identifier);
  BasicBlock(BasicBlock *positive_branch);
  BasicBlock(BasicBlock *positive_branch, BasicBlock *negative_branch);

  void add_code(ir::ThreeAddressCode *code);
  void set_identifier(std::string identifier, ir::Address *result);
  void set_condition(ir::ThreeAddressCode *condition);

  void write(std::ostream &stream, std::map<long, bool> &visited) const;

  intptr_t get_id() const;
  uint getId() const;
};
class ControlFlowGraph {
public:
  BasicBlock *entry_point;

  ControlFlowGraph();
  ControlFlowGraph(const std::string &identifier);

  void write(std::ostream &stream) const;
  void write_standalone(std::ostream &stream) const;

  intptr_t get_id() const;
};

#endif
