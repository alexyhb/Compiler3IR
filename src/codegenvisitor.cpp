#include "codegenvisitor.h"

#include <iostream>
#include <string>

using namespace std;

AsmFile* CodeGenVisitor::visitProgram()
{
	cout << "CodeGenVisitor::visitProgram()" << endl;

	for ( auto beg = this->root->children.begin(); beg < this->root->children.end(); beg ++) {
		if ( (*beg)->getType() == "MainClass") {
			visitMainClass( **beg );
		}
	}

	vector<Node> classList;

	for ( auto beg = this->root->children.begin(); beg < this->root->children.end(); beg ++) {
		if ( (*beg)->getType() == "ClassDeclaration" || (*beg)->getType() == "ClassnExtendsDeclaration"  )  {

			classList.push_back( **beg);
		}
	}

	for (int i = 0; i < classList.size(); i++)
	{
		visitClass(classList[i]);
	}


	return asmFile;
}

void CodeGenVisitor::visitMainClass(Node mainClassDecl)
{
	cout << "CodeGenVisitor::visitMainClass()" << endl;

	tmpClassId = mainClassDecl.getId();
	
	for ( auto beg = mainClassDecl.children.begin(); beg < mainClassDecl.children.end(); beg ++) {
		if ( (*beg)->getType() == "MethodBody") {
			tmpMethodId = (*beg)->getId();
		}
	}

	tmpFunction = tmpMethodId;

	asmFile->addFunction(new AsmFunction(tmpFunction));

	vector<Node>  varList;
	for ( auto beg = mainClassDecl.children.begin(); beg < mainClassDecl.children.end(); beg ++) {
		if ( (*beg)->getType() == "Identifier") {
			varList.push_back( *(*beg) ) ;
		}
	}

	for (int i = 0; i < varList.size(); i++)
	{
		visitVar( varList[i] );
	}

	//VarDeclaration
	vector<Node>  varAttList;
	for ( auto beg = mainClassDecl.children.begin(); beg < mainClassDecl.children.end(); beg ++) {
		if ( (*beg)->getType() == "Identifier") {
			varAttList.push_back( *(*beg) ) ;
		}
	}

	vector<Node> stmtList;
	for ( auto beg = mainClassDecl.children.begin(); beg < mainClassDecl.children.end(); beg ++) {
		if ( (*beg)->getType().find("Statement") != string::npos ) {
			stmtList.push_back( *(*beg) ) ;
		}
	}

	AsmFunction* exitFunction = asmFile->getFunction(tmpFunction);
	exitFunction->addBodyInstruction("iMov rax, 60");
	exitFunction->addBodyInstruction("iXor rdi, rdi");
	exitFunction->addBodyInstruction("syscall");
}

void CodeGenVisitor::visitClass(Node classDecl)
{
	cout << "CodeGenVisitor::visitClass()" << endl;

	tmpClassId = classDecl.getId();
	tmpMethodId = "";
	tmpFunction = "";

	vector<Node>  varList;
	for ( auto beg = classDecl.children.begin(); beg < classDecl.children.end(); beg ++) {
		if ( (*beg)->getType() == "Identifier") {
			varList.push_back( *(*beg) ) ;
		}
	}

	for (int i = 0; i < varList.size(); i++)
	{
		visitVar( varList[i] );
	}

	//MethodDeclaration
	vector<Node>  methodList;
	for ( auto beg = classDecl.children.begin(); beg < classDecl.children.end(); beg ++) {
		cout << (*beg) -> getType() << "," << (*beg) -> getId() << endl;
		if ( (*beg)->getType() == "Declarations") {
			visitDeclarations( *(*beg) ) ;
		}
	}

	vector<Node>  expressionList;
	for ( auto beg = classDecl.children.begin(); beg < classDecl.children.end(); beg ++) {
		if ( (*beg)->getType() == "MethodDeclaration") {
			expressionList.push_back( *(*beg) ) ;
		}
	}

	for (int i = 0; i < expressionList.size(); i++)
	{
		visitExpression( expressionList[i] );
	}
}

void CodeGenVisitor::visitDeclarations(Node declarations ) {

	vector<Node>  varList;
	for ( auto beg = declarations.children.begin(); beg < declarations.children.end(); beg ++) {
		if ( (*beg)->getType() == "Identifier") {
			varList.push_back( *(*beg) ) ;
		}
	}

	for (int i = 0; i < varList.size(); i++)
	{
		visitVar( varList[i] );
	}


	for ( auto beg = declarations.children.begin(); beg < declarations.children.end(); beg ++) {
		cout << (*beg) -> getType() << "," << (*beg) -> getId() << endl;
		visitMethodDeclaration( *(*beg) ) ;
	}
}

void CodeGenVisitor::visitMethodBody(Node methodBody) {
	vector<Node>  varList;
	for ( auto beg = methodBody.children.begin(); beg < methodBody.children.end(); beg ++) {
		if ( (*beg)->getType() == "Identifier") {
			varList.push_back( *(*beg) ) ;
		}
	}

	for (int i = 0; i < varList.size(); i++)
	{
		visitVar( varList[i] );
	}

	for ( auto beg = methodBody.children.begin(); beg < methodBody.children.end(); beg ++) {
		asmFile->addFunction(new AsmFunction( to_string( (*beg)->getId() ) ));
		tmpFunction =  to_string( (*beg)->getId() );
		visitStatement( *(*beg) );
	}
}

void CodeGenVisitor::visitMethodDeclaration(Node methodDeclaration)
{
	cout << "CodeGenVisitor::visitMethodDeclaration()" << endl;
	vector<Node>  varList;
	for ( auto beg = methodDeclaration.children.begin(); beg < methodDeclaration.children.end(); beg ++) {
		if ( (*beg)->getType() == "Identifier") {
			varList.push_back( *(*beg) ) ;
		}
	}

	for (int i = 0; i < varList.size(); i++)
	{
		visitVar( varList[i] );
	}

	for ( auto beg = methodDeclaration.children.begin(); beg < methodDeclaration.children.end(); beg ++) {
		visitMethodBody(* ( *beg ) );
	}
}

void CodeGenVisitor::visitVar(Node var)
{
	cout << "CodeGenVisitor::visitVar()" << endl;
	AsmCodeGen::addUninitializedVar(asmFile, var.getId(), var.getType());
}

void CodeGenVisitor::visitMethod(Node method)
{
	cout << "CodeGenVisitor::method()" << endl;

	tmpMethodId = "_" + to_string( method.getId() );
	tmpFunction = tmpMethodId;

	asmFile->addFunction(new AsmFunction(tmpFunction));

	vector<Node> varList;
	for ( auto beg = method.children.begin(); beg < method.children.end(); beg ++) {
		cout << (*beg)->getType()  << ", " << (*beg)->getId() <<endl;
		if ( (*beg)->getType() == "Identifier") {
			varList.push_back( *(*beg) ) ;
		}
	}

	for (int i = 0; i < varList.size(); i++)
	{
		visitVar( varList[i] );
	}

	vector<Node> stmtList;
	for ( auto beg = method.children.begin(); beg < method.children.end(); beg ++) {
		if ( (*beg)->getType().find("MethodBody") != string::npos ) {
			for( int i = 0; i < (*beg)->children.size(); i++ ) {
				asmFile->addFunction(new AsmFunction( to_string( (*beg)->getId() ) ));
				tmpFunction =  to_string( (*beg)->getId() );
				visitStatement( *(*beg)->children[i] );
			}
		}
	}
	AsmFunction* exitFunction = asmFile->getFunction(tmpFunction);
	exitFunction->addBodyInstruction("ret");
}

void CodeGenVisitor::visitMethodReturn(Node methodReturnDecl)
{
	cout << "visitMethodReturn()" << endl;
}

void CodeGenVisitor::visitMethodCallParams(Node methodCall)
{
	cout << "visitMethodCallParams()" << endl;
}

void CodeGenVisitor::visitStatement(Node stmt)
{	
	cout << "CodeGenVisitor::visitStatement()" << endl;
	if( stmt.children.size() < 0) {
			return;
	}
	AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);

	vector<Node>  expressionList;
	for ( auto beg = stmt.children.begin(); beg < stmt.children.end(); beg ++) {
		if ( (*beg)->getType() == "MethodDeclaration") {
			expressionList.push_back( *(*beg) ) ;
		}
	}

	for (int i = 0; i < expressionList.size(); i++)
	{
		visitExpression( expressionList[i] );
	}

	cout<< stmt.getType() << " , " << stmt.getId() << endl;

	if ( stmt.getType().find("IfStatement") != string::npos ) {
		cout<< "Process IfStatement" << endl;
		cout << "CodeGenVisitor::visitStatement::IF()" << endl;
		Node first = *stmt.children[0];
		visitStatement(first);
		string jmpIfLabel = "_" + tmpFunction + "_if_" + to_string(tmpId++);
		string jmpContLabel = "_" + tmpFunction + "_cont_" + to_string(tmpId++);

		asmFunction->addBodyInstruction("iSub rsp, 8");
		asmFunction->addBodyInstruction("iMov qword [rsp], " + jmpContLabel);
		asmFunction->addBodyInstruction("iCmp [" + to_string( first.getId() ) + "], 1");
		asmFunction->addBodyInstruction("iJe " + jmpIfLabel);
		asmFunction->addBodyInstruction("iJmp " + jmpContLabel);

		asmFile->addFunction(new AsmFunction(jmpIfLabel));
		tmpFunction = jmpIfLabel;

		visitStatement(first);

		asmFile->getFunction(jmpIfLabel)->addBodyInstruction("jmp [rsp]");

		asmFile->addFunction(new AsmFunction(jmpContLabel));
		tmpFunction = jmpContLabel;

		asmFile->getFunction(jmpContLabel)->addBodyInstruction("add rsp, 8");	
	} else if ( stmt.getType().find("ElseStatement") != string::npos ) {
		cout<< "Process ElseStatement" << endl;

		string jmpIfLabel = "_" + tmpFunction + "_if_" + to_string(tmpId++);
		string jmpElseLabel = "_" + tmpFunction + "_else_" + to_string(tmpId++);
		string jmpContLabel = "_" + tmpFunction + "_cont_" + to_string(tmpId++);
		Node first = *stmt.children[0];
		asmFunction->addBodyInstruction("iSub rsp, 8");
		asmFunction->addBodyInstruction("iMov qword [rsp], " + jmpContLabel);
		asmFunction->addBodyInstruction("iCmp [" + to_string( first.getId() ) + "], 1");
		asmFunction->addBodyInstruction("iJe " + jmpIfLabel);
		asmFunction->addBodyInstruction("ijmp " + jmpElseLabel);

		asmFile->addFunction(new AsmFunction(jmpIfLabel));
		tmpFunction = jmpIfLabel;

		visitStatement(first);

		asmFile->getFunction(jmpIfLabel)->addBodyInstruction("iJmp [rsp]");

		asmFile->addFunction(new AsmFunction(jmpElseLabel));
		tmpFunction = jmpElseLabel;

		visitStatement(first);

		asmFile->getFunction(jmpElseLabel)->addBodyInstruction("iJmp [rsp]");

		asmFile->addFunction(new AsmFunction(jmpContLabel));
		asmFile->getFunction(jmpContLabel)->addBodyInstruction("iAdd rsp, 8");
		tmpFunction = jmpContLabel;

	} else if ( stmt.getType().find("WhileStatement") != string::npos ) {
		cout<< "Process WhileStatement" << endl;

		Node first = *stmt.children[0];

		string whileLabel = "_" + tmpFunction + "_while_" + to_string(tmpId++);
		string whileBodyLabel = "_" + tmpFunction + "_while_body_" + to_string(tmpId++);
		string jmpContLabel = "_" + tmpFunction + "_cont_" + to_string(tmpId++);
		asmFunction->addBodyInstruction("iSub rsp, 8");
		asmFunction->addBodyInstruction("iMov qword [rsp], " + whileLabel);
		asmFunction->addBodyInstruction("iJmp " + whileLabel);

		asmFile->addFunction(new AsmFunction(whileLabel));
		asmFunction = asmFile->getFunction(whileLabel);
		tmpFunction = whileLabel;
		visitStatement(first);
		asmFunction->addBodyInstruction("iJmp " + whileLabel);
	} else if ( stmt.getType().find("PrintStatement") != string::npos ) {
		cout<< "Process PrintStatement" << endl;

		cout << "CodeGenVisitor::visitStatement::SOUT()" << endl;
		asmFile->addExternFunction("printf");
		asmFile->addData("msg_" + to_string(tmpId) + ": db " + stmt.getValue() + ", 0");
		AsmCodeGen::soutString(asmFunction, tmpId++);
	} else if ( stmt.getType().find("AssignStatement") != string::npos ) {
		cout<< "Process AssignStatement" << endl;

		Node first = *stmt.children[0];
		cout << "CodeGenVisitor::visitStatement::ASSIGN()" << endl;
		asmFunction->addBodyInstruction("iMov qword rdi, [rsp]");
		asmFunction->addBodyInstruction("iMov qword [" + to_string(first.getId()) + "], rdi");
		asmFunction->addBodyInstruction("iAdd rsp, 8");
	} else if ( stmt.getType().find("ArrayAssignStatement") != string::npos ) {
		cout << "CodeGenVisitor::visitStatement::ASSIGN_ARRAY()" << endl;
	} else {
		cout << "CodeGenVisitor::visitStatement::default()" << endl;
	}
}

void CodeGenVisitor::visitExpression(Node exp)
{
	cout << "CodeGenVisitor::visitExpression()" << endl;

	if( exp.getType().find( "int") != string::npos  ) {
		cout << "CodeGenVisitor::visitExpression::LiteralInteger()" << endl;
		AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);
		asmFunction->addBodyInstruction("iSub rsp, 8");
		asmFunction->addBodyInstruction("iMov qword [rsp], " + exp.getValue() );
	} else if ( exp.getType().find( "boolean") != string::npos ) {
		cout << "CodeGenVisitor::visitExpression::LiteralBoolean()" << endl;
		AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);
		asmFunction->addBodyInstruction("iSub rsp, 8");

		if ( exp.getValue().find("true") != string::npos )
		{
			asmFunction->addBodyInstruction("iMov qword [rsp], 1");
		}		

	}  else if ( exp.getType().find( "Identifier") != string::npos ) {
		cout << "CodeGenVisitor::visitExpression::IdType()" << endl;
		AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);
		asmFunction->addBodyInstruction("iMov qword rdi, [" + exp.getValue() + "]");
		asmFunction->addBodyInstruction("iSub rsp, 8");
		asmFunction->addBodyInstruction("iMov qword [rsp], rdi");
	} else if (   exp.getType().find( "ArithExpression") != string::npos ) {
		cout << "CodeGenVisitor::visitExpression::Arithmetic()" << endl;

		string op = exp.getValue();
		
		visitExpression(*exp.children[0]);
		visitExpression(*exp.children[1]);

		AsmFunction* asmFunction = asmFile->getFunction(tmpFunction);
		
		if ( op == "/" )
		{
			asmFunction->addBodyInstruction("iXor edx, edx");
			asmFunction->addBodyInstruction("iMov ecx, [rsp]");
			asmFunction->addBodyInstruction("iAdd rsp, 8");
			asmFunction->addBodyInstruction("iMov eax, [rsp]");
		}
		else
		{
			asmFunction->addBodyInstruction("iMov qword rsi, [rsp]");
			asmFunction->addBodyInstruction("iAdd rsp, 8");
			asmFunction->addBodyInstruction("iMov rdi, [rsp]");
		}

		if ( op == "+" ) {
			asmFunction->addBodyInstruction("iAdd rdi, rsi");
		} else if ( op == "-" ) {
			asmFunction->addBodyInstruction("iSub rdi, rsi");
		} else if ( op == "*" ) {
			asmFunction->addBodyInstruction("iMul rdi, rsi");
		} else if ( op == "/") {
			asmFunction->addBodyInstruction("divecx");
		}

		if ( op == "/" )
		{
			asmFunction->addBodyInstruction("iMov [rsp], eax");
		}
		else
		{
			asmFunction->addBodyInstruction("iMov qword [rsp], rdi");
		}
	} else {
		cout << "CodeGenVisitor::visitExpression::default()" << endl;
	}
}