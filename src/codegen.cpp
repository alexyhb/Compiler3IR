#include "codegen.h"
#include "codegenvisitor.h"
#include "asm_filewriter.h"

using namespace std;

CodeGen::CodeGen(Node* codeStruct)
{
	this->root = codeStruct;
}

void CodeGen::generateCode()
{
	cout << "CodeGen::generateCode()" << endl;
	CodeGenVisitor codeGenVisitor(root);
	AsmFile* asmFile = codeGenVisitor.visitProgram();

	AsmFileWriter asmFileWriter(asmFile);
	asmFileWriter.saveFile("output.asm");
}