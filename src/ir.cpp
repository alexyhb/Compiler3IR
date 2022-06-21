#include "ir.h"
#include "node.h"
using namespace ir;

 std::ostream &operator<<(std::ostream &stream, const Address *address) {
  if (address == nullptr){
    stream << "null";
  // }else{
  //   address->write(stream);
  // }
  }
  else if(address->type=="var"|| address->type=="const"|| address->type=="temp"){
    address->write(stream);
  }  
 
  return stream;
}

intptr_t Address::get_id() const {
  return reinterpret_cast<intptr_t>(this);
}

Address* Address::getAddressFromType(const std::string &type,const std::string& valueString)
{
  
  if(type.empty()){

    LOG_INFO("The tmep REWROTE-end");

    return new TemporaryVariableIr();
  }
  else if(type=="Identifier")
      return new VariableIr(valueString,"var");
  else if(type=="int")
  {
     LOG_INFO("return constant IR: "<<valueString);
    return new ConstantIr(valueString,"const");

  }
  else if(type=="boolean")
  { 

    return new ConstantIr(valueString,"const");
  }
  else{
    LOG_INFO(" WHY ???????????????????????????????????????????????????????????????????????????????????????????????????   "<<type<<" "<<valueString);
    return new TemporaryVariableIr();

  }
      
}

Address:: Address(std::string type)
    : type(type){

}
VariableIr:: VariableIr(std::string identifier,std::string type)
    : Address(type),identifier(identifier) {
      
}

void VariableIr::write(std::ostream &stream) const {
  LOG_INFO("VariableIr SU"<<identifier);
  stream << this->identifier;
}


ConstantIr::ConstantIr(std::string value,std::string type)
    :Address(type), value(value){
}

void ConstantIr::write(std::ostream &stream) const {

  LOG_INFO("ConstantIr SU"<<value);
  
    stream << "$" << this->value;

  
  LOG_INFO(" THIS IS THE CONST size=0 type =, value = "<<"  "<< this->value<<"\n");
}
unsigned long long TemporaryVariableIr::idGlobal = 0;
TemporaryVariableIr::TemporaryVariableIr()
    :Address("temp"), id(idGlobal++) {
      LOG_INFO("TemporaryVariableIr GEN SUCCUSSE"<<idGlobal<<"\n");
}
TemporaryVariableIr::TemporaryVariableIr(unsigned long long id)
    : Address("temp"),id(id) {
}

void TemporaryVariableIr::write(std::ostream &stream) const {
 

  stream << "_t" << id;
  LOG_INFO("TemporaryVariableIr WRITE SUCCUSSE: _t"<<id<<"\n");
}

ThreeAddressCode::ThreeAddressCode(Address *left, Address *right)
    : result(nullptr), left(left), right(right) {
}

ThreeAddressCode::ThreeAddressCode(Address *result, Address *left, Address *right)
    : result(result), left(left), right(right) {
}

ExpressionIr::ExpressionIr(Address *result, Address *left, Address *right, std::string ir_operator)
    : ThreeAddressCode(result, left, right), ir_operator(ir_operator) {
}

ExpressionIr::ExpressionIr(Address *left, Address *right, std::string ir_operator)
    : ExpressionIr(nullptr, left, right, ir_operator) {
}
// void ExpressionIr::genByteCode(std::ostream &stream){
//   stream<< "iload " << this->left<<"\n";
//   stream<< "iload " << this->right<<"\n";
//   if(ir_operator=="+"){
//     stream<< "iadd " <<"\n";
//   }else if(ir_operator=="-"){
//     stream<< "isub " <<"\n";
//   }
//   else if(ir_operator=="*"){
//     stream<< "imul " <<"\n";
//   }
//   else if(ir_operator=="/"){
//     stream<< "idiv " <<"\n";
//   }else if(ir_operator=="&&"){
//     stream<< "iand " <<"\n";
//   }else if(ir_operator=="<"){
//     stream<< "ilt " <<"\n";
//   }else if(ir_operator==">"){
//     stream<< "iadd " <<"\n";
//   }else if(ir_operator=="||"){
//     stream<< "iadd " <<"\n";
//   }else if(ir_operator=="!"){
//     stream<< "inot " <<"\n";
//   }
//   if(this->result!=nullptr){
//     stream<<"istore "<<this->result;
//   }

// }

void ExpressionIr::write(std::ostream &stream) const {

  stream << this->result << " := " << this->left << " " << this->ir_operator << " " << this->right;
  LOG_INFO("ExpressionIr SU "<<this->result << " := " << this->left << " " << this->ir_operator << " " << this->right<<"\n");
}
// void ExpressionIr::genBytecode(BasicBlock *currentBlock,std::ostream &stream)const{
  
// }

UnaryExpressionIr::UnaryExpressionIr(Address *result, Address *operand, std::string ir_operator)
    : ThreeAddressCode(result, operand, nullptr), ir_operator(ir_operator) {
}
UnaryExpressionIr::UnaryExpressionIr(Address *operand, std::string ir_operator)
    : UnaryExpressionIr(nullptr, operand, ir_operator) {
}

void UnaryExpressionIr::write(std::ostream &stream) const {
  
  LOG_INFO("UnaryExpressionIr SU "<<this->result << " := " << this->ir_operator << " " <<"\n");
  stream << this->result << " := " << this->ir_operator << " " << this->left;
}

CopyIr::CopyIr(Address *operand)
    : ThreeAddressCode(operand, nullptr) {
}

CopyIr::CopyIr(Address *target, Address *operand)
    : ThreeAddressCode(target, operand, nullptr) {
}

void CopyIr::write(std::ostream &stream) const {
  
  stream << this->result << " := " << this->left;
  LOG_INFO("CopyIr SU");
}

ArrayAccessIr::ArrayAccessIr(Address *result, Address *left, Address *right)
    : ThreeAddressCode(result,left, right) {
}

void ArrayAccessIr::write(std::ostream &stream) const {

  stream << this->result << " [ "<< this->left<<"]:= "  << this->right ;
  LOG_INFO("ArrayAccessIr SU");

}


NewIr::NewIr(Address *result,Address *operand) 
    : ThreeAddressCode(result,operand,nullptr){
}
NewIr::NewIr(Address *result)
    : ThreeAddressCode(result,nullptr,nullptr) {
}


void NewIr::write(std::ostream &stream) const {
  stream << " := new " << this->result;
  LOG_INFO("NewIr SU");
  
}

NewArrayIr::NewArrayIr(Address *left, Address *right)
    : ThreeAddressCode(left, right) {
}

void NewArrayIr::write(std::ostream &stream) const {
  stream << this->result << " := new " << this->left << "[" << this->right << "]";
  LOG_INFO("NewArrayIr SU");

}

PushIr::PushIr(Address *operand)
    : ThreeAddressCode(operand, nullptr) {
}

void PushIr::write(std::ostream &stream) const {
  stream << "push " << this->left;
  LOG_INFO("PushIr SU");

}

ParameterIr::ParameterIr(Address *operand)
    : ThreeAddressCode(operand, nullptr) {
}

void ParameterIr::write(std::ostream &stream) const {
  stream << "param " << this->left;
  LOG_INFO("ParameterIr SU");
  
}

MethodCallIr::MethodCallIr(Address *result, Address *left, Address *right)
    : ThreeAddressCode(result, left, right) {
}

MethodCallIr::MethodCallIr(Address *left, Address *right)
    : MethodCallIr(nullptr, left, right) {
}
void MethodCallIr::write(std::ostream &stream) const {
  if (this->result == nullptr)
    stream << "call " << this->left << "("<< this->right<<")";
  else
    stream << this->result << " := call " << this->left << "(" << this->right<<")";
}

ReturnIr::ReturnIr(Address *operand)
    : ThreeAddressCode(operand, nullptr) {
}

ReturnIr::ReturnIr()
    : ReturnIr(nullptr) {
}

void ReturnIr::write(std::ostream &stream) const {
  stream << "return " << this->left;
    LOG_INFO("ReturnIr SU");

}

UnconditionalJumpIr::UnconditionalJumpIr(Address *operand)
    : ThreeAddressCode(operand, nullptr) {
}

void UnconditionalJumpIr::write(std::ostream &stream) const {
  stream << "goto " << this->left;
    LOG_INFO("UnconditionalJumpIr SU");
  
}

ConditionalJumpIr::ConditionalJumpIr(Address *condition, Address *target)
    : ThreeAddressCode(condition, target) {
}

void ConditionalJumpIr::write(std::ostream &stream) const {
  stream << "iffalse " << this->left << " goto " << this->right;
    LOG_INFO("ConditionalJumpIr SU");

}

 PrintCallIr::PrintCallIr(Address *target)
        :ThreeAddressCode(target,nullptr){
}
// void PrintCallIr::genByteCode(std::ostream &stream){
//   stream<<"print "<< this->left;
// }
void PrintCallIr::write(std::ostream &stream) const {
  stream << "call print " <<this->left;
    LOG_INFO("PrintCallIr SU");

}
// void UnaryExpressionIr::genByteCode(std::ostream &stream){
// }
// void CopyIr::genByteCode(std::ostream &stream){
// }
// void ArrayAccessIr::genByteCode(std::ostream &stream){
// }
// void NewIr::genByteCode(std::ostream &stream){
// }
// void NewArrayIr::genByteCode(std::ostream &stream){
// }
// void PushIr::genByteCode(std::ostream &stream){
// }
// void MethodCallIr::genByteCode(std::ostream &stream){
// }
// void ReturnIr::genByteCode(std::ostream &stream){
// }
// void UnconditionalJumpIr::genByteCode(std::ostream &stream){
// }

// void ConditionalJumpIr::genByteCode(std::ostream &stream){
// }
