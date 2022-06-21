#ifndef BYTECODE_H
#define BYTECODE_H

#include <list>
#include <map>
#include <ostream>

#include "ir.h"
#include "cfg.h"
#include "irGen.h"

class Bytecode {
public:

    BasicBlock *entry_point;
    Bytecode();
    Bytecode(irGen* irGen);
};




#endif
