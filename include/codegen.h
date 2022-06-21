

#include <string>
#include <vector>

#include "codegenvisitor.h"
#include "../ast/node.h"

class CodeGen
{
	private:
		Node* root;
	public:
		CodeGen(Node* codeStruct);
		void generateCode();
};