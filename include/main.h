#ifndef MAIN_H
#define MAIN_H

#include "nodes.h"
#include "parser.tab.hh"

#define YY_DECL yy::parser::symbol_type yylex()
YY_DECL;

#endif
