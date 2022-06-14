#include "ir.h"
#include "node.h"
using namespace ir;

std::ostream &operator<<(std::ostream &stream, const Address *address) {
  if (address == nullptr)
    stream << "null";
  else
    address->write(stream);
  return stream;
}

intptr_t Address::get_id() const {
  return reinterpret_cast<intptr_t>(this);
}
Address* Address::getAddressFromType(const std::string &type,const std::string& valueString)
{
  std::string value=valueString;
  if(type.empty())
    return new TemporaryVariableIr();
  if(type=="Identifier")
      return new VariableIr(valueString);
  if(type=="int")
  {
     LOG_INFO("return constant IR: "<<value);
    return new ConstantIr(value);
  }
  if(type=="boolean")
  {
     LOG_INFO("return constant IR: "<<value);
    return new ConstantIr(value);
  }
      
}


VariableIr:: VariableIr(std::string identifier)
    : identifier(identifier) {
}

void VariableIr::write(std::ostream &stream) const {
  stream << this->identifier;
}

ConstantIr::ConstantIr(const std::string valueString)
    : valueString(valueString) {
}
ConstantIr::ConstantIr(long value)
    : value(value) {
}

void ConstantIr::write(std::ostream &stream) const {
  // LOG_INFO(" THIS IS THE CONST!!!!!!!= "<<this->valueString<<"   "<< this->value);
  stream << "$" << this->valueString;
}
unsigned long long TemporaryVariableIr::idGlobal = 0;
TemporaryVariableIr::TemporaryVariableIr()
    : id(idGlobal++) {
}
TemporaryVariableIr::TemporaryVariableIr(unsigned long long id)
    : id(id) {
}

void TemporaryVariableIr::write(std::ostream &stream) const {
  stream << "_t" << this->id;
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
}

UnaryExpressionIr::UnaryExpressionIr(Address *result, Address *operand, std::string ir_operator)
    : ThreeAddressCode(result, operand, nullptr), ir_operator(ir_operator) {
}
UnaryExpressionIr::UnaryExpressionIr(Address *operand, std::string ir_operator)
    : UnaryExpressionIr(nullptr, operand, ir_operator) {
}

void UnaryExpressionIr::write(std::ostream &stream) const {
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
}

ArrayAccessIr::ArrayAccessIr(Address *left, Address *right)
    : ThreeAddressCode(left, right) {
}

void ArrayAccessIr::write(std::ostream &stream) const {
  stream << this->result << " := " << this->left << "[" << this->right << "]";
}

NewIr::NewIr(Address *result, Address *operand)
    : ThreeAddressCode(result,nullptr,operand) {
}

void NewIr::write(std::ostream &stream) const {
  stream << this->result << " := new " << this->right;
}

NewArrayIr::NewArrayIr(Address *left, Address *right)
    : ThreeAddressCode(left, right) {
}

void NewArrayIr::write(std::ostream &stream) const {
  stream << this->result << " := new " << this->left << "[" << this->right << "]";
}

PushIr::PushIr(Address *operand)
    : ThreeAddressCode(operand, nullptr) {
}

void PushIr::write(std::ostream &stream) const {
  stream << "push " << this->left;
}

ParameterIr::ParameterIr(Address *operand)
    : ThreeAddressCode(operand, nullptr) {
}

void ParameterIr::write(std::ostream &stream) const {
  stream << "param " << this->left;
}

MethodCallIr::MethodCallIr(Address *result, Address *left, Address *right)
    : ThreeAddressCode(result, left, right) {
}

MethodCallIr::MethodCallIr(Address *left, Address *right)
    : MethodCallIr(nullptr, left, right) {
}

void MethodCallIr::write(std::ostream &stream) const {
  if (this->result == nullptr)
    stream << "call " << this->left << ", " << this->right;
  else
    stream << this->result << " := call " << this->left << ", " << this->right;
}

ReturnIr::ReturnIr(Address *operand)
    : ThreeAddressCode(operand, nullptr) {
}

ReturnIr::ReturnIr()
    : ReturnIr(nullptr) {
}

void ReturnIr::write(std::ostream &stream) const {
  stream << "return " << this->left;
}

UnconditionalJumpIr::UnconditionalJumpIr(Address *operand)
    : ThreeAddressCode(operand, nullptr) {
}

void UnconditionalJumpIr::write(std::ostream &stream) const {
  stream << "goto " << this->left;
}

ConditionalJumpIr::ConditionalJumpIr(Address *condition, Address *target)
    : ThreeAddressCode(condition, target) {
}

void ConditionalJumpIr::write(std::ostream &stream) const {
  stream << "iffalse " << this->left << " goto " << this->right;
}
