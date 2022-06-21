#ifndef IR_H
#define IR_H
#include <iostream>
#include <cstdlib>
#include <fstream>
namespace ir{
    
class Address {
public:
  std::string type;
  Address(std::string type);
  intptr_t get_id() const;
  virtual void write(std::ostream &stream) const = 0;
  static Address* getAddressFromType(const std::string &type="",const std::string& valueString="");
};

class VariableIr : public Address {
public:
  std::string identifier;
  std::string type;

  VariableIr(std::string identifier,std::string type);
  void write(std::ostream &stream) const;
};

class ConstantIr : public Address {
public:
  // Long to enable storage of intptr_t, not only ints
  std::string value;
  std::string type;

  ConstantIr(const std::string valueString,std::string type);
  //ConstantIr(int value);
  void write(std::ostream &stream) const;
};

class TemporaryVariableIr : public Address {
public:
  static unsigned long long idGlobal;
  unsigned long long id;
  std::string type="temp";

  TemporaryVariableIr();
  TemporaryVariableIr(unsigned long long id);
  void write(std::ostream &stream) const;
};

class ThreeAddressCode {
public:
  Address *result;
  Address *left;
  Address *right;

  ThreeAddressCode(Address *left, Address *right);
  ThreeAddressCode(Address *result, Address *left, Address *right);
  virtual void genByteCode(std::ostream &stream) const=0;
  virtual void write(std::ostream &stream) const = 0;
};

class ExpressionIr: public ThreeAddressCode {
public:
  std::string ir_operator;

  ExpressionIr(Address *target, Address *left, Address *right, std::string ir_operator);
  ExpressionIr(Address *left, Address *right, std::string ir_operator);
  void write(std::ostream &stream) const;
  void genByteCode(std::ostream &stream) const;
};

class UnaryExpressionIr : public ThreeAddressCode {
public:
  std::string ir_operator;

  UnaryExpressionIr(Address *target, Address *left, std::string ir_operator);
  UnaryExpressionIr(Address *left, std::string ir_operator);
  void write(std::ostream &stream) const;
  void genByteCode(std::ostream &stream) const;

  
};

class CopyIr : public ThreeAddressCode {
public:
  CopyIr(Address *operand);
  CopyIr(Address *target, Address *operand);
  void write(std::ostream &stream) const;
  void genByteCode(std::ostream &stream) const;

  
};

class ArrayAccessIr : public ThreeAddressCode {
public:
  ArrayAccessIr(Address *result,Address *left, Address *right);
  void write(std::ostream &stream) const;
  void genByteCode(std::ostream &stream) const;

  
};

class NewIr : public ThreeAddressCode {
public:
  NewIr(Address *result,Address *operand);
  NewIr(Address *result);
  void write(std::ostream &stream) const;
  void genByteCode(std::ostream &stream) const;

  
};

class NewArrayIr : public ThreeAddressCode {
public:
  NewArrayIr(Address *left, Address *right);
  void write(std::ostream &stream) const;
  void genByteCode(std::ostream &stream) const;

  
};

class PushIr : public ThreeAddressCode {
public:
  PushIr(Address *operand);
  void write(std::ostream &stream) const;
  void genByteCode(std::ostream &stream) const;

  
};

class ParameterIr : public ThreeAddressCode {
public:
  ParameterIr(Address *operand);
  void write(std::ostream &stream) const;
  void genByteCode(std::ostream &stream) const;

  
};

class MethodCallIr : public ThreeAddressCode {
public:
 
  MethodCallIr(Address *result, Address *left, Address *right);
  MethodCallIr(Address *left, Address *right);
  void write(std::ostream &stream) const;
  void genByteCode(std::ostream &stream) const;

  
};

class ReturnIr : public ThreeAddressCode {
public:
  ReturnIr(Address *operand);
  ReturnIr();
  void write(std::ostream &stream) const;
  void genByteCode(std::ostream &stream) const;

  
};

class UnconditionalJumpIr : public ThreeAddressCode {
public:
  UnconditionalJumpIr(Address *target);
  void write(std::ostream &stream) const;
  void genByteCode(std::ostream &stream) const;

  
};

class ConditionalJumpIr : public ThreeAddressCode {
public:
  ConditionalJumpIr(Address *condition, Address *target);
  void write(std::ostream &stream) const;
  void genByteCode(std::ostream &stream) const;

  
};

class PrintCallIr: public ThreeAddressCode{
public:
  PrintCallIr(Address *target);
  void write(std::ostream &stream) const;
  void genByteCode(std::ostream &stream) const;

 
  
  
};
} // namespace IR
#endif