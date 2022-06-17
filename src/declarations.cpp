#include "declarations.h"

Declarations::Declarations() : Node() {}
Declarations::Declarations(std::string t, std::string v) : Node(std::move(t), std::move(v)) {}
void* Declarations::genIR(BasicBlock *currentBlock)
{
    for(auto &child: children){
 //   LOG_INFO("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Declarations override the GENIR, value="<<value<<"type:"<<type<< "children size"<< children.size());
        child->genIR(currentBlock);
    }
    // Address* result = Address::getAddressFromType();
    // Address* addrLhs = (Address*)children.at(0)->genIR(currentBlock);
    // Address* addrRhs =(Address*)children.at(1)->genIR(currentBlock);
    // std::string operatorString = getValue();
    // ThreeAddressCode* in = new ExpressionIr(result,addrLhs,addrRhs,operatorString);
    // currentBlock->add_code(in);
    //return (void*)result;
}