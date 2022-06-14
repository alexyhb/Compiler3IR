#ifndef IRGEN_H
#define IRGEN_H
#include "node.h"
#include "cfg.h"
#include <string>
#include <vector> 
#include <list>

namespace ir
{
class IrGen{
private:
    std::shared_ptr<Node>  root;
    ControlFlowGraph *entry_point;
    std::map<std::string ,ControlFlowGraph*> cfgs;
public:
    IrGen(std::shared_ptr<Node> codeStruct);
    void generateIr(std::ostream &stream);
    void write_cfg(std::ostream &stream) const;
};
} // namespace I

#endif





