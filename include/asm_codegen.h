#pragma once

#include <string>

#include "asm_function.h"
#include "asm_file.h"
using namespace std;

class AsmCodeGen
{
	public:
		static void addUninitializedVar(AsmFile* asmFile, int varId, string varType)
		{	
			if (varType == "int") {
				asmFile->addBss(varId + ": resb 8");
			} else if (varType == "boolean") {
				asmFile->addBss(varId + ": resb 1");
			}
		}

		static void soutString(AsmFunction* asmFunction, int msgId)
		{
			asmFunction->addBodyInstruction("iMov rdi, string_format");
			asmFunction->addBodyInstruction("iMov rsi, msg_" + to_string(msgId));
			asmFunction->addBodyInstruction("iXor rax, rax");
			asmFunction->addBodyInstruction("call printf");
		}

		static void soutInteger(AsmFunction* asmFunction, int value)
		{
			asmFunction->addBodyInstruction("iMov rdi, number_format");
			asmFunction->addBodyInstruction("iMov rsi, " + to_string(value));
			asmFunction->addBodyInstruction("iXor rax, rax");
			asmFunction->addBodyInstruction("call printf");
		}

		static void soutVar(AsmFunction* asmFunction, std::string varId, std::string varType)
		{
			if (varType == "String")
			{
				asmFunction->addBodyInstruction("iMov rdi, string_format");
				asmFunction->addBodyInstruction("iMov rsi, " + varId);
			}
			else if((varType == "int") || varType == "boolean")
			{
				asmFunction->addBodyInstruction("iMov rdi, number_format");
				asmFunction->addBodyInstruction("iMov rsi, [" + varId + "]");
			}
			
			asmFunction->addBodyInstruction("iXor rax, rax");
			asmFunction->addBodyInstruction("call printf");
		}

		static void attArithmeticIntegerOp(AsmFunction* asmFunction, std::string varId, string op, int firstVal, int secondVal)
		{
			int resExp = 0;
			
			if ( op == "+" ) {
				resExp = firstVal + secondVal;
			} else if ( op == "-" ) {
				resExp = firstVal - secondVal;
			} else if (op == "*") {
				resExp = firstVal * secondVal;
			} else if ( op == "/") {
				resExp = firstVal / secondVal;
			}

			asmFunction->addBodyInstruction("iMov qword [" + varId + "], " + to_string(resExp));
		}

		static void attArithmeticTwoVarOp(AsmFunction* asmFunction, std::string varId, string op, std::string firstVarId, std::string secondVarId)
		{
			if( op == "+ ") {
				asmFunction->addBodyInstruction("iMov rdi, [" + firstVarId + "]");
				asmFunction->addBodyInstruction("iMov rsi, [" + secondVarId + "]");
				asmFunction->addBodyInstruction("iAdd rdi, rsi");
				asmFunction->addBodyInstruction("iMov [" + varId + "], rdi");
			} else if ( op == "-" ) {
				asmFunction->addBodyInstruction("iMov rdi, [" + firstVarId + "]");
				asmFunction->addBodyInstruction("iMov rsi, [" + secondVarId + "]");
				asmFunction->addBodyInstruction("iSub rdi, rsi");
				asmFunction->addBodyInstruction("iMov [" + varId + "], rdi");
			} else if ( op == "*" ) {
				asmFunction->addBodyInstruction("iMov rdi, [" + firstVarId + "]");
				asmFunction->addBodyInstruction("iMov rsi, [" + secondVarId + "]");
				asmFunction->addBodyInstruction("iMul rdi, rsi");
				asmFunction->addBodyInstruction("iMov [" + varId + "], rdi");
			} else if ( op == "/") {
				asmFunction->addBodyInstruction("iXor edx, edx");
				asmFunction->addBodyInstruction("iMov eax, [" + firstVarId + "]");
				asmFunction->addBodyInstruction("iMov ecx, [" + secondVarId + "]");
				asmFunction->addBodyInstruction("iDiv ecx");
				asmFunction->addBodyInstruction("iMov [" + varId + "], eax");
			}
		}
};