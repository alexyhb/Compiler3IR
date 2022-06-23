#include "main.h"
#include "goal.h"
#include "identifier.h"
#include "main_class.h"
#include "method_body.h"
#include "node.h"
#include "return.h"
#include "type.h"

#include "class_declaration.h"
#include "class_extends_declaration.h"
#include "declarations.h"
#include "variable_declaration.h"
#include "method_declaration.h"

#include "formal_parameter_list.h"
#include "formal_parameter.h"
#include "codegen.h"
#include "expression.h"
#include "expression_list.h"
#include "logic_expression.h"
#include "compare_expression.h"
#include "arith_expression.h"
#include "array_search_expression.h"
#include "array_length_expression.h"

#include "primary_expression.h"
#include "array_alloc_expression.h"
#include "alloc_expression.h"
#include "unary_expression.h"

#include "statement.h"
#include "assign_statement.h"
#include "array_assign_statement.h"
#include "if_statement.h"
#include "else_statement.h"
#include "while_statement.h"
#include "print_statement.h"

#include "method.h"
#include "parameter.h"
#include "record.h"
#include "scope.h"
#include "st_class.h"
#include "symbol_table.h"
#include "variable.h"

#include "irGen.h"
#include <iostream>
#include <vm.h>
using std::cout;
using std::endl;
using std::size_t;
using std::string;

extern std::shared_ptr<Node> root;

void yy::parser::error(const string &err) {
    std::cerr << "Cannot generate a syntax tree for this input: " << err << endl;
}

int main(int argc, char *argv[]) {
    
    if (argc > 1) {
        FILE *file = std::fopen(argv[1], "r");
        if (file) {
            yyin = file;
        } else {
            std::cerr << "The file path is wrong." << endl;
            return EXIT_FAILURE;
        }

        yy::parser parser;
        parser.parse();
        std::fclose(file);
    } else {
        std::cerr << "No input file." << endl;
        return EXIT_FAILURE;
    }
    std::ofstream ast_dot_stream;
    ast_dot_stream.open("ast.dot", std::ios::out);
    size_t ast_count = 0;
    ast_dot_stream << "digraph {" << endl;
    root->generateAST(&ast_dot_stream, ast_count);
    ast_dot_stream << "}" << endl;
    ast_dot_stream.close();

    std::ofstream st_dot_stream;
    st_dot_stream.open("st.dot", std::ios::out);
    st_dot_stream << "graph {" << endl;
    root->buildST(&st_dot_stream);
    st_dot_stream << "}" << endl;
    st_dot_stream.close();

    root->semanticAnalysis();
    IrGen irGen(root);
    irGen.generateIr();
    std::ofstream st_cfg_stream;
    st_cfg_stream.open("cfg.dot", std::ios::out);
    LOG_INFO("WRITING START");
    irGen.write_cfg(st_cfg_stream);
    LOG_INFO("WRITING END");
    st_dot_stream.close();

    // CodeGen* gen = new CodeGen( &(*root) );
    // gen->generateCode();
    // return EXIT_SUCCESS;

    std::ofstream bytecode_stream;
    LOG_INFO("BYTE START");

    bytecode_stream.open("out.class", std::ios::out);
    irGen.write_bytecode(bytecode_stream);
    bytecode_stream.close();
    LOG_INFO("BYTE END");


    VM *vm1=new VM();
    vm1->translate();
}
