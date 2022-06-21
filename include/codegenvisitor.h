#pragma once

#include <string>
#include <vector>

#include "nodes.h"
#include "asm_file.h"
#include "asm_codegen.h"

class CodeGenVisitor
{
private:
	AsmFile* asmFile;

	std::string tmpClassId;
	std::string tmpMethodId;

	std::string tmpFunction;
	int tmpId;
	Node* root;

	void visitMainClass(Node mainClassDecl);
	void visitClass(Node classDecl);

	void visitVar(Node var);

	void visitMethod(Node methodDecl);
	void visitMethodReturn(Node methodReturnDecl);
	void visitMethodCallParams(Node methodCall);

	void visitStatement(Node stmt);
	void visitExpression(Node exp);
	void visitMethodDeclaration( Node stmt);
	void visitMethodBody(Node methodBody); 
	void visitDeclarations(Node declarations );
public:
	CodeGenVisitor(Node* astProgram)
	{
		this->root = astProgram;
		this->asmFile = new AsmFile();

		this->tmpClassId = "";
		this->tmpMethodId = "";

		this->tmpId = 0;
	}

	AsmFile* visitProgram();
};