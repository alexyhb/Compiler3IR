#include "ir.h"
#include "node.h"
using namespace ir;

 std::ostream &operator<<(std::ostream &stream, const Address *address) {
  if (address == nullptr){
    stream << "null";
  }else{
    address->write(stream);
  }
  { 
    if(address->type=="var"|| address->type=="const"|| address->type=="temp"){
      
    }  
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
      return new VariableIr(valueString);
  else if(type=="int")
  {
     LOG_INFO("return constant IR: "<<valueString);
    return new ConstantIr(std::stoi(valueString));

  }
  else if(type=="boolean")
  { 
    bool flag=(valueString=="true");
    
    int i;
    if(flag)
      i=1;
    else{
      i=0;  
    }
    return new ConstantIr(i);
  }
  else{
    return new TemporaryVariableIr();
    LOG_INFO(" WHY ???????????????????????????????????????????????????????????????????????????????????????????????????   "<<type<<" "<<valueString);

  }
      
}


VariableIr:: VariableIr(std::string identifier)
    : identifier(identifier) {
}

void VariableIr::write(std::ostream &stream) const {
  LOG_INFO("VariableIr SU"<<identifier);
  stream << this->identifier;
}


ConstantIr::ConstantIr(int value)
    : value(value) {
}

void ConstantIr::write(std::ostream &stream) const {

  LOG_INFO("ConstantIr SU"<<value);
  
    stream << "$" << this->value;

  
  LOG_INFO(" THIS IS THE CONST size=0 type =, value = "<<"11"<< this->value);
}
unsigned long long TemporaryVariableIr::idGlobal = 0;
TemporaryVariableIr::TemporaryVariableIr()
    : id(idGlobal++) {
}
TemporaryVariableIr::TemporaryVariableIr(unsigned long long id)
    : id(id) {
}

void TemporaryVariableIr::write(std::ostream &stream) const {
  LOG_INFO("TemporaryVariableIr SU "<< id);

  stream << "_t" << this-> id;
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

void ExpressionIr::write(std::ostream &stream) const {

  stream << this->result << " := " << this->left << " " << this->ir_operator << " " << this->right;
  LOG_INFO("ExpressionIr SU");
}

UnaryExpressionIr::UnaryExpressionIr(Address *result, Address *operand, std::string ir_operator)
    : ThreeAddressCode(result, operand, nullptr), ir_operator(ir_operator) {
}
UnaryExpressionIr::UnaryExpressionIr(Address *operand, std::string ir_operator)
    : UnaryExpressionIr(nullptr, operand, ir_operator) {
}

void UnaryExpressionIr::write(std::ostream &stream) const {
  
  stream << this->result << " := " << this->ir_operator << " " << this->left;
  LOG_INFO("UnaryExpressionIr SU");
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
