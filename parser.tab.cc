// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 60 "src/parser.yy"

  #include "main.h"

  std::shared_ptr<Node> root;

#line 51 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 123 "parser.tab.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.type_get ())
    {
      case 78: // AllocExpression
        value.YY_MOVE_OR_COPY< std::shared_ptr<AllocExpression> > (YY_MOVE (that.value));
        break;

      case 72: // ArithExpression
        value.YY_MOVE_OR_COPY< std::shared_ptr<ArithExpression> > (YY_MOVE (that.value));
        break;

      case 77: // ArrayAllocExpression
        value.YY_MOVE_OR_COPY< std::shared_ptr<ArrayAllocExpression> > (YY_MOVE (that.value));
        break;

      case 64: // ArrayAssignStatement
        value.YY_MOVE_OR_COPY< std::shared_ptr<ArrayAssignStatement> > (YY_MOVE (that.value));
        break;

      case 74: // ArrayLengthExpression
        value.YY_MOVE_OR_COPY< std::shared_ptr<ArrayLengthExpression> > (YY_MOVE (that.value));
        break;

      case 73: // ArraySearchExpression
        value.YY_MOVE_OR_COPY< std::shared_ptr<ArraySearchExpression> > (YY_MOVE (that.value));
        break;

      case 63: // AssignStatement
        value.YY_MOVE_OR_COPY< std::shared_ptr<AssignStatement> > (YY_MOVE (that.value));
        break;

      case 51: // ClassDeclaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<ClassDeclaration> > (YY_MOVE (that.value));
        break;

      case 52: // ClassExtendsDeclaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<ClassExtendsDeclaration> > (YY_MOVE (that.value));
        break;

      case 71: // CompareExpression
        value.YY_MOVE_OR_COPY< std::shared_ptr<CompareExpression> > (YY_MOVE (that.value));
        break;

      case 53: // Declarations
        value.YY_MOVE_OR_COPY< std::shared_ptr<Declarations> > (YY_MOVE (that.value));
        break;

      case 66: // ElseStatement
        value.YY_MOVE_OR_COPY< std::shared_ptr<ElseStatement> > (YY_MOVE (that.value));
        break;

      case 69: // Expression
        value.YY_MOVE_OR_COPY< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case 75: // ExpressionList
        value.YY_MOVE_OR_COPY< std::shared_ptr<ExpressionList> > (YY_MOVE (that.value));
        break;

      case 59: // FormalParameter
        value.YY_MOVE_OR_COPY< std::shared_ptr<FormalParameter> > (YY_MOVE (that.value));
        break;

      case 58: // FormalParameterList
        value.YY_MOVE_OR_COPY< std::shared_ptr<FormalParameterList> > (YY_MOVE (that.value));
        break;

      case 48: // Goal
        value.YY_MOVE_OR_COPY< std::shared_ptr<Goal> > (YY_MOVE (that.value));
        break;

      case 80: // Identifier
        value.YY_MOVE_OR_COPY< std::shared_ptr<Identifier> > (YY_MOVE (that.value));
        break;

      case 65: // IfStatement
        value.YY_MOVE_OR_COPY< std::shared_ptr<IfStatement> > (YY_MOVE (that.value));
        break;

      case 70: // LogicExpression
        value.YY_MOVE_OR_COPY< std::shared_ptr<LogicExpression> > (YY_MOVE (that.value));
        break;

      case 49: // MainClass
        value.YY_MOVE_OR_COPY< std::shared_ptr<MainClass> > (YY_MOVE (that.value));
        break;

      case 56: // MethodBody
        value.YY_MOVE_OR_COPY< std::shared_ptr<MethodBody> > (YY_MOVE (that.value));
        break;

      case 55: // MethodDeclaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<MethodDeclaration> > (YY_MOVE (that.value));
        break;

      case 50: // ClassDeclarations
        value.YY_MOVE_OR_COPY< std::shared_ptr<Node> > (YY_MOVE (that.value));
        break;

      case 76: // PrimaryExpression
        value.YY_MOVE_OR_COPY< std::shared_ptr<PrimaryExpression> > (YY_MOVE (that.value));
        break;

      case 68: // PrintStatement
        value.YY_MOVE_OR_COPY< std::shared_ptr<PrintStatement> > (YY_MOVE (that.value));
        break;

      case 57: // Return
        value.YY_MOVE_OR_COPY< std::shared_ptr<Return> > (YY_MOVE (that.value));
        break;

      case 61: // Statements
      case 62: // Statement
        value.YY_MOVE_OR_COPY< std::shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case 60: // Type
        value.YY_MOVE_OR_COPY< std::shared_ptr<Type> > (YY_MOVE (that.value));
        break;

      case 79: // UnaryExpression
        value.YY_MOVE_OR_COPY< std::shared_ptr<UnaryExpression> > (YY_MOVE (that.value));
        break;

      case 54: // VarDeclaration
        value.YY_MOVE_OR_COPY< std::shared_ptr<VarDeclaration> > (YY_MOVE (that.value));
        break;

      case 67: // WhileStatement
        value.YY_MOVE_OR_COPY< std::shared_ptr<WhileStatement> > (YY_MOVE (that.value));
        break;

      case 3: // CLASS
      case 4: // PUBLIC
      case 5: // STATIC
      case 6: // VOID
      case 7: // MAIN
      case 8: // STRING
      case 9: // EXTENDS
      case 10: // LENGTH
      case 11: // NEW
      case 12: // THIS
      case 13: // RETURN
      case 14: // IF
      case 15: // ELSE
      case 16: // WHILE
      case 17: // SOPRINTLN
      case 18: // INT
      case 19: // BOOLEAN
      case 20: // AND
      case 21: // OR
      case 22: // NOT
      case 23: // EQUAL
      case 24: // NOTEQUAL
      case 25: // TRUE
      case 26: // FALSE
      case 27: // LT
      case 28: // LET
      case 29: // GT
      case 30: // GET
      case 31: // ADD
      case 32: // SUB
      case 33: // MUL
      case 34: // DIV
      case 35: // LPARENTHESE
      case 36: // RPARENTHESE
      case 37: // LBRACKET
      case 38: // RBRACKET
      case 39: // LBRACE
      case 40: // RBRACE
      case 41: // SEMI
      case 42: // COMMA
      case 43: // ASSIGN
      case 44: // DOT
      case 45: // NUM
      case 46: // IDENTIFIER
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.type_get ())
    {
      case 78: // AllocExpression
        value.move< std::shared_ptr<AllocExpression> > (YY_MOVE (that.value));
        break;

      case 72: // ArithExpression
        value.move< std::shared_ptr<ArithExpression> > (YY_MOVE (that.value));
        break;

      case 77: // ArrayAllocExpression
        value.move< std::shared_ptr<ArrayAllocExpression> > (YY_MOVE (that.value));
        break;

      case 64: // ArrayAssignStatement
        value.move< std::shared_ptr<ArrayAssignStatement> > (YY_MOVE (that.value));
        break;

      case 74: // ArrayLengthExpression
        value.move< std::shared_ptr<ArrayLengthExpression> > (YY_MOVE (that.value));
        break;

      case 73: // ArraySearchExpression
        value.move< std::shared_ptr<ArraySearchExpression> > (YY_MOVE (that.value));
        break;

      case 63: // AssignStatement
        value.move< std::shared_ptr<AssignStatement> > (YY_MOVE (that.value));
        break;

      case 51: // ClassDeclaration
        value.move< std::shared_ptr<ClassDeclaration> > (YY_MOVE (that.value));
        break;

      case 52: // ClassExtendsDeclaration
        value.move< std::shared_ptr<ClassExtendsDeclaration> > (YY_MOVE (that.value));
        break;

      case 71: // CompareExpression
        value.move< std::shared_ptr<CompareExpression> > (YY_MOVE (that.value));
        break;

      case 53: // Declarations
        value.move< std::shared_ptr<Declarations> > (YY_MOVE (that.value));
        break;

      case 66: // ElseStatement
        value.move< std::shared_ptr<ElseStatement> > (YY_MOVE (that.value));
        break;

      case 69: // Expression
        value.move< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case 75: // ExpressionList
        value.move< std::shared_ptr<ExpressionList> > (YY_MOVE (that.value));
        break;

      case 59: // FormalParameter
        value.move< std::shared_ptr<FormalParameter> > (YY_MOVE (that.value));
        break;

      case 58: // FormalParameterList
        value.move< std::shared_ptr<FormalParameterList> > (YY_MOVE (that.value));
        break;

      case 48: // Goal
        value.move< std::shared_ptr<Goal> > (YY_MOVE (that.value));
        break;

      case 80: // Identifier
        value.move< std::shared_ptr<Identifier> > (YY_MOVE (that.value));
        break;

      case 65: // IfStatement
        value.move< std::shared_ptr<IfStatement> > (YY_MOVE (that.value));
        break;

      case 70: // LogicExpression
        value.move< std::shared_ptr<LogicExpression> > (YY_MOVE (that.value));
        break;

      case 49: // MainClass
        value.move< std::shared_ptr<MainClass> > (YY_MOVE (that.value));
        break;

      case 56: // MethodBody
        value.move< std::shared_ptr<MethodBody> > (YY_MOVE (that.value));
        break;

      case 55: // MethodDeclaration
        value.move< std::shared_ptr<MethodDeclaration> > (YY_MOVE (that.value));
        break;

      case 50: // ClassDeclarations
        value.move< std::shared_ptr<Node> > (YY_MOVE (that.value));
        break;

      case 76: // PrimaryExpression
        value.move< std::shared_ptr<PrimaryExpression> > (YY_MOVE (that.value));
        break;

      case 68: // PrintStatement
        value.move< std::shared_ptr<PrintStatement> > (YY_MOVE (that.value));
        break;

      case 57: // Return
        value.move< std::shared_ptr<Return> > (YY_MOVE (that.value));
        break;

      case 61: // Statements
      case 62: // Statement
        value.move< std::shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case 60: // Type
        value.move< std::shared_ptr<Type> > (YY_MOVE (that.value));
        break;

      case 79: // UnaryExpression
        value.move< std::shared_ptr<UnaryExpression> > (YY_MOVE (that.value));
        break;

      case 54: // VarDeclaration
        value.move< std::shared_ptr<VarDeclaration> > (YY_MOVE (that.value));
        break;

      case 67: // WhileStatement
        value.move< std::shared_ptr<WhileStatement> > (YY_MOVE (that.value));
        break;

      case 3: // CLASS
      case 4: // PUBLIC
      case 5: // STATIC
      case 6: // VOID
      case 7: // MAIN
      case 8: // STRING
      case 9: // EXTENDS
      case 10: // LENGTH
      case 11: // NEW
      case 12: // THIS
      case 13: // RETURN
      case 14: // IF
      case 15: // ELSE
      case 16: // WHILE
      case 17: // SOPRINTLN
      case 18: // INT
      case 19: // BOOLEAN
      case 20: // AND
      case 21: // OR
      case 22: // NOT
      case 23: // EQUAL
      case 24: // NOTEQUAL
      case 25: // TRUE
      case 26: // FALSE
      case 27: // LT
      case 28: // LET
      case 29: // GT
      case 30: // GET
      case 31: // ADD
      case 32: // SUB
      case 33: // MUL
      case 34: // DIV
      case 35: // LPARENTHESE
      case 36: // RPARENTHESE
      case 37: // LBRACKET
      case 38: // RBRACKET
      case 39: // LBRACE
      case 40: // RBRACE
      case 41: // SEMI
      case 42: // COMMA
      case 43: // ASSIGN
      case 44: // DOT
      case 45: // NUM
      case 46: // IDENTIFIER
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 78: // AllocExpression
        value.copy< std::shared_ptr<AllocExpression> > (that.value);
        break;

      case 72: // ArithExpression
        value.copy< std::shared_ptr<ArithExpression> > (that.value);
        break;

      case 77: // ArrayAllocExpression
        value.copy< std::shared_ptr<ArrayAllocExpression> > (that.value);
        break;

      case 64: // ArrayAssignStatement
        value.copy< std::shared_ptr<ArrayAssignStatement> > (that.value);
        break;

      case 74: // ArrayLengthExpression
        value.copy< std::shared_ptr<ArrayLengthExpression> > (that.value);
        break;

      case 73: // ArraySearchExpression
        value.copy< std::shared_ptr<ArraySearchExpression> > (that.value);
        break;

      case 63: // AssignStatement
        value.copy< std::shared_ptr<AssignStatement> > (that.value);
        break;

      case 51: // ClassDeclaration
        value.copy< std::shared_ptr<ClassDeclaration> > (that.value);
        break;

      case 52: // ClassExtendsDeclaration
        value.copy< std::shared_ptr<ClassExtendsDeclaration> > (that.value);
        break;

      case 71: // CompareExpression
        value.copy< std::shared_ptr<CompareExpression> > (that.value);
        break;

      case 53: // Declarations
        value.copy< std::shared_ptr<Declarations> > (that.value);
        break;

      case 66: // ElseStatement
        value.copy< std::shared_ptr<ElseStatement> > (that.value);
        break;

      case 69: // Expression
        value.copy< std::shared_ptr<Expression> > (that.value);
        break;

      case 75: // ExpressionList
        value.copy< std::shared_ptr<ExpressionList> > (that.value);
        break;

      case 59: // FormalParameter
        value.copy< std::shared_ptr<FormalParameter> > (that.value);
        break;

      case 58: // FormalParameterList
        value.copy< std::shared_ptr<FormalParameterList> > (that.value);
        break;

      case 48: // Goal
        value.copy< std::shared_ptr<Goal> > (that.value);
        break;

      case 80: // Identifier
        value.copy< std::shared_ptr<Identifier> > (that.value);
        break;

      case 65: // IfStatement
        value.copy< std::shared_ptr<IfStatement> > (that.value);
        break;

      case 70: // LogicExpression
        value.copy< std::shared_ptr<LogicExpression> > (that.value);
        break;

      case 49: // MainClass
        value.copy< std::shared_ptr<MainClass> > (that.value);
        break;

      case 56: // MethodBody
        value.copy< std::shared_ptr<MethodBody> > (that.value);
        break;

      case 55: // MethodDeclaration
        value.copy< std::shared_ptr<MethodDeclaration> > (that.value);
        break;

      case 50: // ClassDeclarations
        value.copy< std::shared_ptr<Node> > (that.value);
        break;

      case 76: // PrimaryExpression
        value.copy< std::shared_ptr<PrimaryExpression> > (that.value);
        break;

      case 68: // PrintStatement
        value.copy< std::shared_ptr<PrintStatement> > (that.value);
        break;

      case 57: // Return
        value.copy< std::shared_ptr<Return> > (that.value);
        break;

      case 61: // Statements
      case 62: // Statement
        value.copy< std::shared_ptr<Statement> > (that.value);
        break;

      case 60: // Type
        value.copy< std::shared_ptr<Type> > (that.value);
        break;

      case 79: // UnaryExpression
        value.copy< std::shared_ptr<UnaryExpression> > (that.value);
        break;

      case 54: // VarDeclaration
        value.copy< std::shared_ptr<VarDeclaration> > (that.value);
        break;

      case 67: // WhileStatement
        value.copy< std::shared_ptr<WhileStatement> > (that.value);
        break;

      case 3: // CLASS
      case 4: // PUBLIC
      case 5: // STATIC
      case 6: // VOID
      case 7: // MAIN
      case 8: // STRING
      case 9: // EXTENDS
      case 10: // LENGTH
      case 11: // NEW
      case 12: // THIS
      case 13: // RETURN
      case 14: // IF
      case 15: // ELSE
      case 16: // WHILE
      case 17: // SOPRINTLN
      case 18: // INT
      case 19: // BOOLEAN
      case 20: // AND
      case 21: // OR
      case 22: // NOT
      case 23: // EQUAL
      case 24: // NOTEQUAL
      case 25: // TRUE
      case 26: // FALSE
      case 27: // LT
      case 28: // LET
      case 29: // GT
      case 30: // GET
      case 31: // ADD
      case 32: // SUB
      case 33: // MUL
      case 34: // DIV
      case 35: // LPARENTHESE
      case 36: // RPARENTHESE
      case 37: // LBRACKET
      case 38: // RBRACKET
      case 39: // LBRACE
      case 40: // RBRACE
      case 41: // SEMI
      case 42: // COMMA
      case 43: // ASSIGN
      case 44: // DOT
      case 45: // NUM
      case 46: // IDENTIFIER
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 78: // AllocExpression
        value.move< std::shared_ptr<AllocExpression> > (that.value);
        break;

      case 72: // ArithExpression
        value.move< std::shared_ptr<ArithExpression> > (that.value);
        break;

      case 77: // ArrayAllocExpression
        value.move< std::shared_ptr<ArrayAllocExpression> > (that.value);
        break;

      case 64: // ArrayAssignStatement
        value.move< std::shared_ptr<ArrayAssignStatement> > (that.value);
        break;

      case 74: // ArrayLengthExpression
        value.move< std::shared_ptr<ArrayLengthExpression> > (that.value);
        break;

      case 73: // ArraySearchExpression
        value.move< std::shared_ptr<ArraySearchExpression> > (that.value);
        break;

      case 63: // AssignStatement
        value.move< std::shared_ptr<AssignStatement> > (that.value);
        break;

      case 51: // ClassDeclaration
        value.move< std::shared_ptr<ClassDeclaration> > (that.value);
        break;

      case 52: // ClassExtendsDeclaration
        value.move< std::shared_ptr<ClassExtendsDeclaration> > (that.value);
        break;

      case 71: // CompareExpression
        value.move< std::shared_ptr<CompareExpression> > (that.value);
        break;

      case 53: // Declarations
        value.move< std::shared_ptr<Declarations> > (that.value);
        break;

      case 66: // ElseStatement
        value.move< std::shared_ptr<ElseStatement> > (that.value);
        break;

      case 69: // Expression
        value.move< std::shared_ptr<Expression> > (that.value);
        break;

      case 75: // ExpressionList
        value.move< std::shared_ptr<ExpressionList> > (that.value);
        break;

      case 59: // FormalParameter
        value.move< std::shared_ptr<FormalParameter> > (that.value);
        break;

      case 58: // FormalParameterList
        value.move< std::shared_ptr<FormalParameterList> > (that.value);
        break;

      case 48: // Goal
        value.move< std::shared_ptr<Goal> > (that.value);
        break;

      case 80: // Identifier
        value.move< std::shared_ptr<Identifier> > (that.value);
        break;

      case 65: // IfStatement
        value.move< std::shared_ptr<IfStatement> > (that.value);
        break;

      case 70: // LogicExpression
        value.move< std::shared_ptr<LogicExpression> > (that.value);
        break;

      case 49: // MainClass
        value.move< std::shared_ptr<MainClass> > (that.value);
        break;

      case 56: // MethodBody
        value.move< std::shared_ptr<MethodBody> > (that.value);
        break;

      case 55: // MethodDeclaration
        value.move< std::shared_ptr<MethodDeclaration> > (that.value);
        break;

      case 50: // ClassDeclarations
        value.move< std::shared_ptr<Node> > (that.value);
        break;

      case 76: // PrimaryExpression
        value.move< std::shared_ptr<PrimaryExpression> > (that.value);
        break;

      case 68: // PrintStatement
        value.move< std::shared_ptr<PrintStatement> > (that.value);
        break;

      case 57: // Return
        value.move< std::shared_ptr<Return> > (that.value);
        break;

      case 61: // Statements
      case 62: // Statement
        value.move< std::shared_ptr<Statement> > (that.value);
        break;

      case 60: // Type
        value.move< std::shared_ptr<Type> > (that.value);
        break;

      case 79: // UnaryExpression
        value.move< std::shared_ptr<UnaryExpression> > (that.value);
        break;

      case 54: // VarDeclaration
        value.move< std::shared_ptr<VarDeclaration> > (that.value);
        break;

      case 67: // WhileStatement
        value.move< std::shared_ptr<WhileStatement> > (that.value);
        break;

      case 3: // CLASS
      case 4: // PUBLIC
      case 5: // STATIC
      case 6: // VOID
      case 7: // MAIN
      case 8: // STRING
      case 9: // EXTENDS
      case 10: // LENGTH
      case 11: // NEW
      case 12: // THIS
      case 13: // RETURN
      case 14: // IF
      case 15: // ELSE
      case 16: // WHILE
      case 17: // SOPRINTLN
      case 18: // INT
      case 19: // BOOLEAN
      case 20: // AND
      case 21: // OR
      case 22: // NOT
      case 23: // EQUAL
      case 24: // NOTEQUAL
      case 25: // TRUE
      case 26: // FALSE
      case 27: // LT
      case 28: // LET
      case 29: // GT
      case 30: // GET
      case 31: // ADD
      case 32: // SUB
      case 33: // MUL
      case 34: // DIV
      case 35: // LPARENTHESE
      case 36: // RPARENTHESE
      case 37: // LBRACKET
      case 38: // RBRACKET
      case 39: // LBRACE
      case 40: // RBRACE
      case 41: // SEMI
      case 42: // COMMA
      case 43: // ASSIGN
      case 44: // DOT
      case 45: // NUM
      case 46: // IDENTIFIER
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 78: // AllocExpression
        yylhs.value.emplace< std::shared_ptr<AllocExpression> > ();
        break;

      case 72: // ArithExpression
        yylhs.value.emplace< std::shared_ptr<ArithExpression> > ();
        break;

      case 77: // ArrayAllocExpression
        yylhs.value.emplace< std::shared_ptr<ArrayAllocExpression> > ();
        break;

      case 64: // ArrayAssignStatement
        yylhs.value.emplace< std::shared_ptr<ArrayAssignStatement> > ();
        break;

      case 74: // ArrayLengthExpression
        yylhs.value.emplace< std::shared_ptr<ArrayLengthExpression> > ();
        break;

      case 73: // ArraySearchExpression
        yylhs.value.emplace< std::shared_ptr<ArraySearchExpression> > ();
        break;

      case 63: // AssignStatement
        yylhs.value.emplace< std::shared_ptr<AssignStatement> > ();
        break;

      case 51: // ClassDeclaration
        yylhs.value.emplace< std::shared_ptr<ClassDeclaration> > ();
        break;

      case 52: // ClassExtendsDeclaration
        yylhs.value.emplace< std::shared_ptr<ClassExtendsDeclaration> > ();
        break;

      case 71: // CompareExpression
        yylhs.value.emplace< std::shared_ptr<CompareExpression> > ();
        break;

      case 53: // Declarations
        yylhs.value.emplace< std::shared_ptr<Declarations> > ();
        break;

      case 66: // ElseStatement
        yylhs.value.emplace< std::shared_ptr<ElseStatement> > ();
        break;

      case 69: // Expression
        yylhs.value.emplace< std::shared_ptr<Expression> > ();
        break;

      case 75: // ExpressionList
        yylhs.value.emplace< std::shared_ptr<ExpressionList> > ();
        break;

      case 59: // FormalParameter
        yylhs.value.emplace< std::shared_ptr<FormalParameter> > ();
        break;

      case 58: // FormalParameterList
        yylhs.value.emplace< std::shared_ptr<FormalParameterList> > ();
        break;

      case 48: // Goal
        yylhs.value.emplace< std::shared_ptr<Goal> > ();
        break;

      case 80: // Identifier
        yylhs.value.emplace< std::shared_ptr<Identifier> > ();
        break;

      case 65: // IfStatement
        yylhs.value.emplace< std::shared_ptr<IfStatement> > ();
        break;

      case 70: // LogicExpression
        yylhs.value.emplace< std::shared_ptr<LogicExpression> > ();
        break;

      case 49: // MainClass
        yylhs.value.emplace< std::shared_ptr<MainClass> > ();
        break;

      case 56: // MethodBody
        yylhs.value.emplace< std::shared_ptr<MethodBody> > ();
        break;

      case 55: // MethodDeclaration
        yylhs.value.emplace< std::shared_ptr<MethodDeclaration> > ();
        break;

      case 50: // ClassDeclarations
        yylhs.value.emplace< std::shared_ptr<Node> > ();
        break;

      case 76: // PrimaryExpression
        yylhs.value.emplace< std::shared_ptr<PrimaryExpression> > ();
        break;

      case 68: // PrintStatement
        yylhs.value.emplace< std::shared_ptr<PrintStatement> > ();
        break;

      case 57: // Return
        yylhs.value.emplace< std::shared_ptr<Return> > ();
        break;

      case 61: // Statements
      case 62: // Statement
        yylhs.value.emplace< std::shared_ptr<Statement> > ();
        break;

      case 60: // Type
        yylhs.value.emplace< std::shared_ptr<Type> > ();
        break;

      case 79: // UnaryExpression
        yylhs.value.emplace< std::shared_ptr<UnaryExpression> > ();
        break;

      case 54: // VarDeclaration
        yylhs.value.emplace< std::shared_ptr<VarDeclaration> > ();
        break;

      case 67: // WhileStatement
        yylhs.value.emplace< std::shared_ptr<WhileStatement> > ();
        break;

      case 3: // CLASS
      case 4: // PUBLIC
      case 5: // STATIC
      case 6: // VOID
      case 7: // MAIN
      case 8: // STRING
      case 9: // EXTENDS
      case 10: // LENGTH
      case 11: // NEW
      case 12: // THIS
      case 13: // RETURN
      case 14: // IF
      case 15: // ELSE
      case 16: // WHILE
      case 17: // SOPRINTLN
      case 18: // INT
      case 19: // BOOLEAN
      case 20: // AND
      case 21: // OR
      case 22: // NOT
      case 23: // EQUAL
      case 24: // NOTEQUAL
      case 25: // TRUE
      case 26: // FALSE
      case 27: // LT
      case 28: // LET
      case 29: // GT
      case 30: // GET
      case 31: // ADD
      case 32: // SUB
      case 33: // MUL
      case 34: // DIV
      case 35: // LPARENTHESE
      case 36: // RPARENTHESE
      case 37: // LBRACKET
      case 38: // RBRACKET
      case 39: // LBRACE
      case 40: // RBRACE
      case 41: // SEMI
      case 42: // COMMA
      case 43: // ASSIGN
      case 44: // DOT
      case 45: // NUM
      case 46: // IDENTIFIER
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 132 "src/parser.yy"
                              { yylhs.value.as < std::shared_ptr<Goal> > () = std::make_shared<Goal>("Goal", ""); yylhs.value.as < std::shared_ptr<Goal> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<MainClass> > ()); root = yylhs.value.as < std::shared_ptr<Goal> > (); }
#line 1417 "parser.tab.cc"
    break;

  case 3:
#line 133 "src/parser.yy"
                              { yylhs.value.as < std::shared_ptr<Goal> > () = yystack_[1].value.as < std::shared_ptr<Goal> > (); yylhs.value.as < std::shared_ptr<Goal> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Node> > ()); root = yylhs.value.as < std::shared_ptr<Goal> > (); }
#line 1423 "parser.tab.cc"
    break;

  case 4:
#line 134 "src/parser.yy"
                              { yylhs.value.as < std::shared_ptr<Goal> > () = std::make_shared<Goal>("Goal", "EOF"); root = yylhs.value.as < std::shared_ptr<Goal> > (); }
#line 1429 "parser.tab.cc"
    break;

  case 5:
#line 138 "src/parser.yy"
              { yylhs.value.as < std::shared_ptr<MainClass> > () = std::make_shared<MainClass>("MainClass", ""); yylhs.value.as < std::shared_ptr<MainClass> > ()->children.push_back(yystack_[14].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<MainClass> > ()->children.push_back(yystack_[4].value.as < std::shared_ptr<Identifier> > ()); }
#line 1435 "parser.tab.cc"
    break;

  case 6:
#line 140 "src/parser.yy"
              { yylhs.value.as < std::shared_ptr<MainClass> > () = std::make_shared<MainClass>("MainClass", ""); yylhs.value.as < std::shared_ptr<MainClass> > ()->children.push_back(yystack_[15].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<MainClass> > ()->children.push_back(yystack_[5].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<MainClass> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<MethodBody> > ()); }
#line 1441 "parser.tab.cc"
    break;

  case 7:
#line 143 "src/parser.yy"
                                            { yylhs.value.as < std::shared_ptr<Node> > () = yystack_[0].value.as < std::shared_ptr<ClassDeclaration> > (); }
#line 1447 "parser.tab.cc"
    break;

  case 8:
#line 144 "src/parser.yy"
                                            { yylhs.value.as < std::shared_ptr<Node> > () = yystack_[0].value.as < std::shared_ptr<ClassExtendsDeclaration> > (); }
#line 1453 "parser.tab.cc"
    break;

  case 9:
#line 147 "src/parser.yy"
                                                               { yylhs.value.as < std::shared_ptr<ClassDeclaration> > () = std::make_shared<ClassDeclaration>("ClassDeclaration", ""); yylhs.value.as < std::shared_ptr<ClassDeclaration> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Identifier> > ()); }
#line 1459 "parser.tab.cc"
    break;

  case 10:
#line 148 "src/parser.yy"
                                                               { yylhs.value.as < std::shared_ptr<ClassDeclaration> > () = std::make_shared<ClassDeclaration>("ClassDeclaration", ""); yylhs.value.as < std::shared_ptr<ClassDeclaration> > ()->children.push_back(yystack_[3].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<ClassDeclaration> > ()->children.push_back(yystack_[1].value.as < std::shared_ptr<Declarations> > ()); }
#line 1465 "parser.tab.cc"
    break;

  case 11:
#line 151 "src/parser.yy"
                                                                                         { yylhs.value.as < std::shared_ptr<ClassExtendsDeclaration> > () = std::make_shared<ClassExtendsDeclaration>("ClassExtendsDeclaration", ""); yylhs.value.as < std::shared_ptr<ClassExtendsDeclaration> > ()->children.push_back(yystack_[4].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<ClassExtendsDeclaration> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Identifier> > ()); }
#line 1471 "parser.tab.cc"
    break;

  case 12:
#line 152 "src/parser.yy"
                                                                                         { yylhs.value.as < std::shared_ptr<ClassExtendsDeclaration> > () = std::make_shared<ClassExtendsDeclaration>("ClassExtendsDeclaration", ""); yylhs.value.as < std::shared_ptr<ClassExtendsDeclaration> > ()->children.push_back(yystack_[5].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<ClassExtendsDeclaration> > ()->children.push_back(yystack_[3].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<ClassExtendsDeclaration> > ()->children.push_back(yystack_[1].value.as < std::shared_ptr<Declarations> > ()); }
#line 1477 "parser.tab.cc"
    break;

  case 13:
#line 155 "src/parser.yy"
                                              { yylhs.value.as < std::shared_ptr<Declarations> > () = std::make_shared<Declarations>("Declarations", ""); yylhs.value.as < std::shared_ptr<Declarations> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<VarDeclaration> > ()); }
#line 1483 "parser.tab.cc"
    break;

  case 14:
#line 156 "src/parser.yy"
                                              { yylhs.value.as < std::shared_ptr<Declarations> > () = std::make_shared<Declarations>("Declarations", ""); yylhs.value.as < std::shared_ptr<Declarations> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<MethodDeclaration> > ()); }
#line 1489 "parser.tab.cc"
    break;

  case 15:
#line 157 "src/parser.yy"
                                              { yylhs.value.as < std::shared_ptr<Declarations> > () = yystack_[1].value.as < std::shared_ptr<Declarations> > (); yylhs.value.as < std::shared_ptr<Declarations> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<VarDeclaration> > ()); }
#line 1495 "parser.tab.cc"
    break;

  case 16:
#line 158 "src/parser.yy"
                                              { yylhs.value.as < std::shared_ptr<Declarations> > () = yystack_[1].value.as < std::shared_ptr<Declarations> > (); yylhs.value.as < std::shared_ptr<Declarations> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<MethodDeclaration> > ()); }
#line 1501 "parser.tab.cc"
    break;

  case 17:
#line 161 "src/parser.yy"
                                      { yylhs.value.as < std::shared_ptr<VarDeclaration> > () = std::make_shared<VarDeclaration>("VarDeclaration", ""); yylhs.value.as < std::shared_ptr<VarDeclaration> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Type> > ()); yylhs.value.as < std::shared_ptr<VarDeclaration> > ()->children.push_back(yystack_[1].value.as < std::shared_ptr<Identifier> > ()); }
#line 1507 "parser.tab.cc"
    break;

  case 18:
#line 165 "src/parser.yy"
                    { yylhs.value.as < std::shared_ptr<MethodDeclaration> > () = std::make_shared<MethodDeclaration>("MethodDeclaration", ""); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[7].value.as < std::shared_ptr<Type> > ()); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[6].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Return> > ()); }
#line 1513 "parser.tab.cc"
    break;

  case 19:
#line 167 "src/parser.yy"
                    { yylhs.value.as < std::shared_ptr<MethodDeclaration> > () = std::make_shared<MethodDeclaration>("MethodDeclaration", ""); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[8].value.as < std::shared_ptr<Type> > ()); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[7].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[5].value.as < std::shared_ptr<FormalParameterList> > ()); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Return> > ()); }
#line 1519 "parser.tab.cc"
    break;

  case 20:
#line 169 "src/parser.yy"
                    { yylhs.value.as < std::shared_ptr<MethodDeclaration> > () = std::make_shared<MethodDeclaration>("MethodDeclaration", ""); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[7].value.as < std::shared_ptr<Type> > ()); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[6].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<MethodBody> > ()); }
#line 1525 "parser.tab.cc"
    break;

  case 21:
#line 171 "src/parser.yy"
                    { yylhs.value.as < std::shared_ptr<MethodDeclaration> > () = std::make_shared<MethodDeclaration>("MethodDeclaration", ""); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[8].value.as < std::shared_ptr<Type> > ()); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[7].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[5].value.as < std::shared_ptr<FormalParameterList> > ()); yylhs.value.as < std::shared_ptr<MethodDeclaration> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<MethodBody> > ()); }
#line 1531 "parser.tab.cc"
    break;

  case 22:
#line 174 "src/parser.yy"
                                       { yylhs.value.as < std::shared_ptr<MethodBody> > () = std::make_shared<MethodBody>("MethodBody", ""); yylhs.value.as < std::shared_ptr<MethodBody> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<VarDeclaration> > ()); }
#line 1537 "parser.tab.cc"
    break;

  case 23:
#line 175 "src/parser.yy"
                                       { yylhs.value.as < std::shared_ptr<MethodBody> > () = std::make_shared<MethodBody>("MethodBody", ""); yylhs.value.as < std::shared_ptr<MethodBody> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 1543 "parser.tab.cc"
    break;

  case 24:
#line 176 "src/parser.yy"
                                       { yylhs.value.as < std::shared_ptr<MethodBody> > () = yystack_[1].value.as < std::shared_ptr<MethodBody> > (); yylhs.value.as < std::shared_ptr<MethodBody> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<VarDeclaration> > ()); }
#line 1549 "parser.tab.cc"
    break;

  case 25:
#line 177 "src/parser.yy"
                                       { yylhs.value.as < std::shared_ptr<MethodBody> > () = yystack_[1].value.as < std::shared_ptr<MethodBody> > (); yylhs.value.as < std::shared_ptr<MethodBody> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 1555 "parser.tab.cc"
    break;

  case 26:
#line 178 "src/parser.yy"
                                       { yylhs.value.as < std::shared_ptr<MethodBody> > () = yystack_[1].value.as < std::shared_ptr<MethodBody> > (); yylhs.value.as < std::shared_ptr<MethodBody> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Return> > ()); }
#line 1561 "parser.tab.cc"
    break;

  case 27:
#line 181 "src/parser.yy"
                           { yylhs.value.as < std::shared_ptr<Return> > () = std::make_shared<Return>("Return", ""); yylhs.value.as < std::shared_ptr<Return> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1567 "parser.tab.cc"
    break;

  case 28:
#line 184 "src/parser.yy"
                                                                { yylhs.value.as < std::shared_ptr<FormalParameterList> > () = std::make_shared<FormalParameterList>("FormalParameterList", ""); yylhs.value.as < std::shared_ptr<FormalParameterList> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<FormalParameter> > ()); }
#line 1573 "parser.tab.cc"
    break;

  case 29:
#line 185 "src/parser.yy"
                                                                { yylhs.value.as < std::shared_ptr<FormalParameterList> > () = yystack_[2].value.as < std::shared_ptr<FormalParameterList> > (); yylhs.value.as < std::shared_ptr<FormalParameterList> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<FormalParameter> > ()); }
#line 1579 "parser.tab.cc"
    break;

  case 30:
#line 188 "src/parser.yy"
                                  { yylhs.value.as < std::shared_ptr<FormalParameter> > () = std::make_shared<FormalParameter>("FormalParameter", ""); yylhs.value.as < std::shared_ptr<FormalParameter> > ()->children.push_back(yystack_[1].value.as < std::shared_ptr<Type> > ()); yylhs.value.as < std::shared_ptr<FormalParameter> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Identifier> > ()); }
#line 1585 "parser.tab.cc"
    break;

  case 31:
#line 191 "src/parser.yy"
                             { yylhs.value.as < std::shared_ptr<Type> > () = std::make_shared<Type>("Type", yystack_[2].value.as < std::string > ()+yystack_[1].value.as < std::string > ()+yystack_[0].value.as < std::string > ()); }
#line 1591 "parser.tab.cc"
    break;

  case 32:
#line 192 "src/parser.yy"
                             { yylhs.value.as < std::shared_ptr<Type> > () = std::make_shared<Type>("Type", yystack_[0].value.as < std::string > ()); }
#line 1597 "parser.tab.cc"
    break;

  case 33:
#line 193 "src/parser.yy"
                             { yylhs.value.as < std::shared_ptr<Type> > () = std::make_shared<Type>("Type", yystack_[0].value.as < std::string > ()); }
#line 1603 "parser.tab.cc"
    break;

  case 34:
#line 194 "src/parser.yy"
                             { yylhs.value.as < std::shared_ptr<Type> > () = std::make_shared<Type>("Type", ""); yylhs.value.as < std::shared_ptr<Type> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Identifier> > ()); }
#line 1609 "parser.tab.cc"
    break;

  case 35:
#line 197 "src/parser.yy"
                                  { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<Statement>("Statements", ""); yylhs.value.as < std::shared_ptr<Statement> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 1615 "parser.tab.cc"
    break;

  case 36:
#line 198 "src/parser.yy"
                                  { yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[1].value.as < std::shared_ptr<Statement> > (); yylhs.value.as < std::shared_ptr<Statement> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 1621 "parser.tab.cc"
    break;

  case 37:
#line 201 "src/parser.yy"
                                       { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<Statement>("Statement", "EMPTY"); }
#line 1627 "parser.tab.cc"
    break;

  case 38:
#line 202 "src/parser.yy"
                                       { yylhs.value.as < std::shared_ptr<Statement> > () = std::make_shared<Statement>("Statement", ""); yylhs.value.as < std::shared_ptr<Statement> > ()->children.push_back(yystack_[1].value.as < std::shared_ptr<Statement> > ()); }
#line 1633 "parser.tab.cc"
    break;

  case 39:
#line 203 "src/parser.yy"
                                       { yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[0].value.as < std::shared_ptr<AssignStatement> > (); }
#line 1639 "parser.tab.cc"
    break;

  case 40:
#line 204 "src/parser.yy"
                                       { yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[0].value.as < std::shared_ptr<ArrayAssignStatement> > (); }
#line 1645 "parser.tab.cc"
    break;

  case 41:
#line 205 "src/parser.yy"
                                       { yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[0].value.as < std::shared_ptr<IfStatement> > (); }
#line 1651 "parser.tab.cc"
    break;

  case 42:
#line 206 "src/parser.yy"
                                       { yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[0].value.as < std::shared_ptr<WhileStatement> > (); }
#line 1657 "parser.tab.cc"
    break;

  case 43:
#line 207 "src/parser.yy"
                                       { yylhs.value.as < std::shared_ptr<Statement> > () = yystack_[0].value.as < std::shared_ptr<PrintStatement> > (); }
#line 1663 "parser.tab.cc"
    break;

  case 44:
#line 210 "src/parser.yy"
                                                                                      { yylhs.value.as < std::shared_ptr<AssignStatement> > () = std::make_shared<AssignStatement>("AssignStatement", yystack_[2].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<AssignStatement> > ()->children.push_back(yystack_[3].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<AssignStatement> > ()->children.push_back(yystack_[1].value.as < std::shared_ptr<Expression> > ()); }
#line 1669 "parser.tab.cc"
    break;

  case 45:
#line 213 "src/parser.yy"
                                                                                      { yylhs.value.as < std::shared_ptr<ArrayAssignStatement> > () = std::make_shared<ArrayAssignStatement>("ArrayAssignStatement", yystack_[5].value.as < std::string > ()+yystack_[3].value.as < std::string > ()+yystack_[2].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<ArrayAssignStatement> > ()->children.push_back(yystack_[6].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<ArrayAssignStatement> > ()->children.push_back(yystack_[4].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<ArrayAssignStatement> > ()->children.push_back(yystack_[1].value.as < std::shared_ptr<Expression> > ()); }
#line 1675 "parser.tab.cc"
    break;

  case 46:
#line 216 "src/parser.yy"
                                                                                      { yylhs.value.as < std::shared_ptr<IfStatement> > () = std::make_shared<IfStatement>("IfStatement", ""); yylhs.value.as < std::shared_ptr<IfStatement> > ()->children.push_back(yystack_[3].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<IfStatement> > ()->children.push_back(yystack_[1].value.as < std::shared_ptr<Statement> > ()); yylhs.value.as < std::shared_ptr<IfStatement> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<ElseStatement> > ()); }
#line 1681 "parser.tab.cc"
    break;

  case 47:
#line 219 "src/parser.yy"
                               { yylhs.value.as < std::shared_ptr<ElseStatement> > () = std::make_shared<ElseStatement>("ElseStatement", ""); yylhs.value.as < std::shared_ptr<ElseStatement> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 1687 "parser.tab.cc"
    break;

  case 48:
#line 222 "src/parser.yy"
                                                                                      { yylhs.value.as < std::shared_ptr<WhileStatement> > () = std::make_shared<WhileStatement>("WhileStatement", ""); yylhs.value.as < std::shared_ptr<WhileStatement> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<WhileStatement> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Statement> > ()); }
#line 1693 "parser.tab.cc"
    break;

  case 49:
#line 225 "src/parser.yy"
                                                                                      { yylhs.value.as < std::shared_ptr<PrintStatement> > () = std::make_shared<PrintStatement>("PrintStatement", yystack_[4].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<PrintStatement> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); }
#line 1699 "parser.tab.cc"
    break;

  case 50:
#line 228 "src/parser.yy"
                                                                              { yylhs.value.as < std::shared_ptr<Expression> > () = std::make_shared<Expression>("Expression", ""); yylhs.value.as < std::shared_ptr<Expression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<PrimaryExpression> > ()); }
#line 1705 "parser.tab.cc"
    break;

  case 51:
#line 229 "src/parser.yy"
                                                                              { yylhs.value.as < std::shared_ptr<Expression> > () = yystack_[0].value.as < std::shared_ptr<LogicExpression> > (); }
#line 1711 "parser.tab.cc"
    break;

  case 52:
#line 230 "src/parser.yy"
                                                                              { yylhs.value.as < std::shared_ptr<Expression> > () = yystack_[0].value.as < std::shared_ptr<CompareExpression> > (); }
#line 1717 "parser.tab.cc"
    break;

  case 53:
#line 231 "src/parser.yy"
                                                                              { yylhs.value.as < std::shared_ptr<Expression> > () = yystack_[0].value.as < std::shared_ptr<ArithExpression> > (); }
#line 1723 "parser.tab.cc"
    break;

  case 54:
#line 232 "src/parser.yy"
                                                                              { yylhs.value.as < std::shared_ptr<Expression> > () = yystack_[0].value.as < std::shared_ptr<ArraySearchExpression> > (); }
#line 1729 "parser.tab.cc"
    break;

  case 55:
#line 233 "src/parser.yy"
                                                                              { yylhs.value.as < std::shared_ptr<Expression> > () = yystack_[0].value.as < std::shared_ptr<ArrayLengthExpression> > (); }
#line 1735 "parser.tab.cc"
    break;

  case 56:
#line 234 "src/parser.yy"
                                                                              { yylhs.value.as < std::shared_ptr<Expression> > () = yystack_[4].value.as < std::shared_ptr<Expression> > (); yylhs.value.as < std::shared_ptr<Expression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Identifier> > ());  }
#line 1741 "parser.tab.cc"
    break;

  case 57:
#line 235 "src/parser.yy"
                                                                              { yylhs.value.as < std::shared_ptr<Expression> > () = yystack_[5].value.as < std::shared_ptr<Expression> > (); yylhs.value.as < std::shared_ptr<Expression> > ()->children.push_back(yystack_[3].value.as < std::shared_ptr<Identifier> > ()); yylhs.value.as < std::shared_ptr<Expression> > ()->children.push_back(yystack_[1].value.as < std::shared_ptr<ExpressionList> > ()); }
#line 1747 "parser.tab.cc"
    break;

  case 58:
#line 238 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<LogicExpression> > () = std::make_shared<LogicExpression>("LogicExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<LogicExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<LogicExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1753 "parser.tab.cc"
    break;

  case 59:
#line 239 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<LogicExpression> > () = std::make_shared<LogicExpression>("LogicExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<LogicExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<LogicExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1759 "parser.tab.cc"
    break;

  case 60:
#line 242 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<CompareExpression> > () = std::make_shared<CompareExpression>("CompareExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<CompareExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<CompareExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1765 "parser.tab.cc"
    break;

  case 61:
#line 243 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<CompareExpression> > () = std::make_shared<CompareExpression>("CompareExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<CompareExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<CompareExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1771 "parser.tab.cc"
    break;

  case 62:
#line 244 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<CompareExpression> > () = std::make_shared<CompareExpression>("CompareExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<CompareExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<CompareExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1777 "parser.tab.cc"
    break;

  case 63:
#line 245 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<CompareExpression> > () = std::make_shared<CompareExpression>("CompareExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<CompareExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<CompareExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1783 "parser.tab.cc"
    break;

  case 64:
#line 246 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<CompareExpression> > () = std::make_shared<CompareExpression>("CompareExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<CompareExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<CompareExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1789 "parser.tab.cc"
    break;

  case 65:
#line 247 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<CompareExpression> > () = std::make_shared<CompareExpression>("CompareExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<CompareExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<CompareExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1795 "parser.tab.cc"
    break;

  case 66:
#line 250 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<ArithExpression> > () = std::make_shared<ArithExpression>("ArithExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<ArithExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<ArithExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1801 "parser.tab.cc"
    break;

  case 67:
#line 251 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<ArithExpression> > () = std::make_shared<ArithExpression>("ArithExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<ArithExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<ArithExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1807 "parser.tab.cc"
    break;

  case 68:
#line 252 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<ArithExpression> > () = std::make_shared<ArithExpression>("ArithExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<ArithExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<ArithExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1813 "parser.tab.cc"
    break;

  case 69:
#line 253 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<ArithExpression> > () = std::make_shared<ArithExpression>("ArithExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<ArithExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<ArithExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1819 "parser.tab.cc"
    break;

  case 70:
#line 256 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<ArraySearchExpression> > () = std::make_shared<ArraySearchExpression>("ArraySearchExpression", yystack_[2].value.as < std::string > ()+yystack_[0].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<ArraySearchExpression> > ()->children.push_back(yystack_[3].value.as < std::shared_ptr<Expression> > ()); yylhs.value.as < std::shared_ptr<ArraySearchExpression> > ()->children.push_back(yystack_[1].value.as < std::shared_ptr<Expression> > ()); }
#line 1825 "parser.tab.cc"
    break;

  case 71:
#line 259 "src/parser.yy"
                                                                  { yylhs.value.as < std::shared_ptr<ArrayLengthExpression> > () = std::make_shared<ArrayLengthExpression>("ArrayLengthExpression", yystack_[1].value.as < std::string > ()+yystack_[0].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<ArrayLengthExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Expression> > ()); }
#line 1831 "parser.tab.cc"
    break;

  case 72:
#line 262 "src/parser.yy"
                                                 { yylhs.value.as < std::shared_ptr<ExpressionList> > () = std::make_shared<ExpressionList>("ExpressionList", ""); yylhs.value.as < std::shared_ptr<ExpressionList> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1837 "parser.tab.cc"
    break;

  case 73:
#line 263 "src/parser.yy"
                                                 { yylhs.value.as < std::shared_ptr<ExpressionList> > () = yystack_[2].value.as < std::shared_ptr<ExpressionList> > (); yylhs.value.as < std::shared_ptr<ExpressionList> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1843 "parser.tab.cc"
    break;

  case 74:
#line 266 "src/parser.yy"
                                                           { yylhs.value.as < std::shared_ptr<PrimaryExpression> > () = std::make_shared<PrimaryExpression>("PrimaryExpression", ""); yylhs.value.as < std::shared_ptr<PrimaryExpression> > ()->children.push_back(yystack_[1].value.as < std::shared_ptr<Expression> > ()); }
#line 1849 "parser.tab.cc"
    break;

  case 75:
#line 267 "src/parser.yy"
                                                           { yylhs.value.as < std::shared_ptr<PrimaryExpression> > () = std::make_shared<PrimaryExpression>("PrimaryExpression", ""); yylhs.value.as < std::shared_ptr<PrimaryExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Identifier> > ()); }
#line 1855 "parser.tab.cc"
    break;

  case 76:
#line 268 "src/parser.yy"
                                                           { yylhs.value.as < std::shared_ptr<PrimaryExpression> > () = yystack_[0].value.as < std::shared_ptr<ArrayAllocExpression> > (); }
#line 1861 "parser.tab.cc"
    break;

  case 77:
#line 269 "src/parser.yy"
                                                           { yylhs.value.as < std::shared_ptr<PrimaryExpression> > () = yystack_[0].value.as < std::shared_ptr<AllocExpression> > (); }
#line 1867 "parser.tab.cc"
    break;

  case 78:
#line 270 "src/parser.yy"
                                                           { yylhs.value.as < std::shared_ptr<PrimaryExpression> > () = yystack_[0].value.as < std::shared_ptr<UnaryExpression> > (); }
#line 1873 "parser.tab.cc"
    break;

  case 79:
#line 271 "src/parser.yy"
                                                           { yylhs.value.as < std::shared_ptr<PrimaryExpression> > () = std::make_shared<PrimaryExpression>("int", yystack_[0].value.as < std::string > ()); }
#line 1879 "parser.tab.cc"
    break;

  case 80:
#line 272 "src/parser.yy"
                                                           { yylhs.value.as < std::shared_ptr<PrimaryExpression> > () = std::make_shared<PrimaryExpression>("boolean", yystack_[0].value.as < std::string > ()); }
#line 1885 "parser.tab.cc"
    break;

  case 81:
#line 273 "src/parser.yy"
                                                           { yylhs.value.as < std::shared_ptr<PrimaryExpression> > () = std::make_shared<PrimaryExpression>("boolean", yystack_[0].value.as < std::string > ()); }
#line 1891 "parser.tab.cc"
    break;

  case 82:
#line 274 "src/parser.yy"
                                                           { yylhs.value.as < std::shared_ptr<PrimaryExpression> > () = std::make_shared<PrimaryExpression>("keyword", yystack_[0].value.as < std::string > ()); }
#line 1897 "parser.tab.cc"
    break;

  case 83:
#line 277 "src/parser.yy"
                                                              { yylhs.value.as < std::shared_ptr<ArrayAllocExpression> > () = std::make_shared<ArrayAllocExpression>("ArrayAllocExpression", yystack_[4].value.as < std::string > ()+" "+yystack_[3].value.as < std::string > ()+yystack_[2].value.as < std::string > ()+yystack_[0].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<ArrayAllocExpression> > ()->children.push_back(yystack_[1].value.as < std::shared_ptr<Expression> > ()); }
#line 1903 "parser.tab.cc"
    break;

  case 84:
#line 280 "src/parser.yy"
                                                              { yylhs.value.as < std::shared_ptr<AllocExpression> > () = std::make_shared<AllocExpression>("AllocExpression", yystack_[3].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<AllocExpression> > ()->children.push_back(yystack_[2].value.as < std::shared_ptr<Identifier> > ()); }
#line 1909 "parser.tab.cc"
    break;

  case 85:
#line 283 "src/parser.yy"
                                                              { yylhs.value.as < std::shared_ptr<UnaryExpression> > () = std::make_shared<UnaryExpression>("UnaryExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<UnaryExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1915 "parser.tab.cc"
    break;

  case 86:
#line 284 "src/parser.yy"
                                                              { yylhs.value.as < std::shared_ptr<UnaryExpression> > () = std::make_shared<UnaryExpression>("UnaryExpression", yystack_[1].value.as < std::string > ()); yylhs.value.as < std::shared_ptr<UnaryExpression> > ()->children.push_back(yystack_[0].value.as < std::shared_ptr<Expression> > ()); }
#line 1921 "parser.tab.cc"
    break;

  case 87:
#line 287 "src/parser.yy"
                        { yylhs.value.as < std::shared_ptr<Identifier> > () = std::make_shared<Identifier>("Identifier", yystack_[0].value.as < std::string > ()); }
#line 1927 "parser.tab.cc"
    break;


#line 1931 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state, yyla));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    std::ptrdiff_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */
    if (!yyla.empty ())
      {
        symbol_number_type yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];

        int yyn = yypact_[+yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yy_error_token_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -71;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      83,   -71,   -44,    93,   -71,   -71,    -6,   -71,   -44,   -71,
     -71,   -71,    22,     2,    39,   -44,    16,    55,     6,    11,
      31,   -71,   -71,    19,   -71,   -71,   -44,   -71,    69,    48,
     -44,    47,   -71,   -71,   -71,    50,    57,   -71,    71,    66,
     -71,   -71,    98,   -71,    63,    75,    74,   -24,   -71,   -44,
      76,   219,    77,    11,   -71,   -44,    52,    80,    84,    85,
     227,   -71,   175,    86,   -71,   -71,   -71,   -71,   -71,   -71,
      36,   219,   -71,    82,   -14,   -71,    52,   -71,   -71,    52,
      52,   -71,   433,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,    52,    52,    52,   -71,   245,   -71,    36,
      88,   -71,   -71,   -71,    89,    52,    52,   188,    90,    91,
      87,    97,   -29,   133,   266,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    -3,   284,
     302,   320,   -71,   -71,   -71,   -71,   338,   357,    95,    96,
     237,    52,   101,   -71,   469,   451,   487,   487,   238,   238,
     238,   238,   133,   133,   -29,   -29,   376,   -71,   105,   125,
     125,   115,   116,   -71,   -71,   -71,   123,   206,   395,   -71,
     -71,   150,   153,   -71,   -71,    52,   -71,   134,   -71,   -71,
     433,    12,   125,   -71,   414,   -71,   -71,    52,   -71,   -71,
     433
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     4,     0,     0,     2,    87,     0,     1,     0,     3,
       7,     8,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    32,     9,     0,    13,    14,     0,    34,     0,     0,
       0,     0,    10,    15,    16,     0,     0,    11,     0,     0,
      31,    17,     0,    12,     0,     0,     0,     0,    28,     0,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,    22,     0,     0,    23,    39,    40,    41,    42,    43,
      34,     0,    29,     0,     0,    82,     0,    80,    81,     0,
       0,    79,    27,    51,    52,    53,    54,    55,    50,    76,
      77,    78,    75,     0,     0,     0,    37,     0,    35,     0,
       0,    24,    26,    25,     0,     0,     0,     0,     0,     0,
       0,     0,    85,    86,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    36,    20,    18,     0,     0,     0,     0,
       0,     0,     0,    74,    58,    59,    64,    65,    60,    61,
      62,    63,    66,    67,    68,    69,     0,    71,     0,     0,
       0,     0,     0,    44,    21,    19,     0,     0,     0,    84,
      70,     0,     0,    48,    49,     0,     5,     0,    83,    56,
      72,     0,     0,    46,     0,     6,    57,     0,    47,    45,
      73
  };

  const short
  parser::yypgoto_[] =
  {
     -71,   -71,   -71,   -71,   -71,   -71,   144,    -7,   -13,   -70,
     -32,   -71,   126,    27,   -71,   -57,   -71,   -71,   -71,   -71,
     -71,   -71,    28,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,    -2
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     3,     4,     9,    10,    11,    23,    61,    25,    62,
     102,    47,    48,    26,    97,    64,    65,    66,    67,   183,
      68,    69,    82,    83,    84,    85,    86,    87,   181,    88,
      89,    90,    91,    92
  };

  const unsigned char
  parser::yytable_[] =
  {
       6,   107,     5,    98,   110,   103,    13,   157,   127,    24,
      34,    15,    52,    18,    27,   128,    33,    27,    53,    63,
      19,    27,    24,    19,    35,    34,    14,    27,    39,    20,
      21,    33,     5,    12,    20,    21,    27,    20,    21,   108,
     133,    16,    27,     5,    17,    29,    30,    54,   186,    70,
     103,    27,    19,    73,   187,   101,    22,     5,    99,    32,
      70,    28,     5,    74,    75,     5,    20,    21,    31,    70,
     167,    49,   111,   105,    76,    19,    36,    77,    78,   106,
      49,    20,    21,     1,    79,    40,     2,    80,    37,    20,
      21,    41,    42,     7,     5,    99,     8,    81,     5,    46,
     101,    44,   172,   173,   112,    70,    45,   113,   114,     5,
     103,    43,    50,    51,    55,    93,    71,     5,   109,    94,
      95,   129,   130,   131,   141,   188,   158,   104,   134,   135,
     140,   139,   142,   136,   137,   164,   165,   169,    70,    57,
     171,    58,    59,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   174,    99,    99,   175,
     101,    74,    75,   176,    60,    70,   125,   126,   182,   168,
     127,     5,    76,    38,   185,    77,    78,   128,     0,    72,
      99,     0,    79,     0,     0,    80,   179,     0,    56,    57,
       0,    58,    59,    20,    21,    81,     5,     0,     0,   180,
       0,    56,    57,   184,    58,    59,    20,    21,     0,     0,
       0,     0,     0,     0,    60,   190,   100,     0,     0,    56,
      57,     5,    58,    59,    20,    21,     0,    60,     0,   138,
       0,     0,    56,    57,     5,    58,    59,    20,    21,     0,
       0,    57,     0,    58,    59,    60,   177,     0,     0,     0,
       0,    57,     5,    58,    59,    20,    21,     0,    60,    57,
       0,    58,    59,     0,     0,     5,    60,    96,     0,   123,
     124,   125,   126,     5,     0,   127,    60,   166,     0,     0,
       0,     0,   128,     5,    60,   132,   115,   116,     0,   117,
     118,     5,     0,   119,   120,   121,   122,   123,   124,   125,
     126,     0,   143,   127,   115,   116,     0,   117,   118,     0,
     128,   119,   120,   121,   122,   123,   124,   125,   126,     0,
     159,   127,   115,   116,     0,   117,   118,     0,   128,   119,
     120,   121,   122,   123,   124,   125,   126,     0,   160,   127,
     115,   116,     0,   117,   118,     0,   128,   119,   120,   121,
     122,   123,   124,   125,   126,     0,   161,   127,   115,   116,
       0,   117,   118,     0,   128,   119,   120,   121,   122,   123,
     124,   125,   126,     0,     0,   127,   162,   115,   116,     0,
     117,   118,   128,     0,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,   127,     0,   115,   116,   163,   117,
     118,   128,     0,   119,   120,   121,   122,   123,   124,   125,
     126,     0,     0,   127,   170,   115,   116,     0,   117,   118,
     128,     0,   119,   120,   121,   122,   123,   124,   125,   126,
       0,     0,   127,   178,   115,   116,     0,   117,   118,   128,
       0,   119,   120,   121,   122,   123,   124,   125,   126,     0,
       0,   127,     0,   115,   116,   189,   117,   118,   128,     0,
     119,   120,   121,   122,   123,   124,   125,   126,     0,     0,
     127,   115,     0,     0,   117,   118,     0,   128,   119,   120,
     121,   122,   123,   124,   125,   126,     0,     0,   127,     0,
       0,     0,   117,   118,     0,   128,   119,   120,   121,   122,
     123,   124,   125,   126,     0,     0,   127,     0,     0,     0,
       0,     0,     0,   128,   119,   120,   121,   122,   123,   124,
     125,   126,     0,     0,   127,     0,     0,     0,     0,     0,
       0,   128
  };

  const short
  parser::yycheck_[] =
  {
       2,    71,    46,    60,    18,    62,     8,    10,    37,    16,
      23,     9,    36,    15,    16,    44,    23,    19,    42,    51,
       4,    23,    29,     4,    26,    38,     4,    29,    30,    18,
      19,    38,    46,    39,    18,    19,    38,    18,    19,    71,
      97,    39,    44,    46,     5,    39,    19,    49,    36,    51,
     107,    53,     4,    55,    42,    62,    40,    46,    60,    40,
      62,     6,    46,    11,    12,    46,    18,    19,    37,    71,
     140,    44,    74,    37,    22,     4,     7,    25,    26,    43,
      53,    18,    19,     0,    32,    38,     3,    35,    40,    18,
      19,    41,    35,     0,    46,    97,     3,    45,    46,    36,
     107,    35,   159,   160,    76,   107,     8,    79,    80,    46,
     167,    40,    37,    39,    38,    35,    39,    46,    36,    35,
      35,    93,    94,    95,    37,   182,   128,    41,    40,    40,
      39,    41,    35,   105,   106,    40,    40,    36,   140,    14,
      35,    16,    17,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,    41,   159,   160,    43,
     167,    11,    12,    40,    39,   167,    33,    34,    15,   141,
      37,    46,    22,    29,    40,    25,    26,    44,    -1,    53,
     182,    -1,    32,    -1,    -1,    35,    36,    -1,    13,    14,
      -1,    16,    17,    18,    19,    45,    46,    -1,    -1,   171,
      -1,    13,    14,   175,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    39,   187,    41,    -1,    -1,    13,
      14,    46,    16,    17,    18,    19,    -1,    39,    -1,    41,
      -1,    -1,    13,    14,    46,    16,    17,    18,    19,    -1,
      -1,    14,    -1,    16,    17,    39,    40,    -1,    -1,    -1,
      -1,    14,    46,    16,    17,    18,    19,    -1,    39,    14,
      -1,    16,    17,    -1,    -1,    46,    39,    40,    -1,    31,
      32,    33,    34,    46,    -1,    37,    39,    40,    -1,    -1,
      -1,    -1,    44,    46,    39,    40,    20,    21,    -1,    23,
      24,    46,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    36,    37,    20,    21,    -1,    23,    24,    -1,
      44,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    20,    21,    -1,    23,    24,    -1,    44,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      20,    21,    -1,    23,    24,    -1,    44,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    36,    37,    20,    21,
      -1,    23,    24,    -1,    44,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    37,    38,    20,    21,    -1,
      23,    24,    44,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    37,    -1,    20,    21,    41,    23,
      24,    44,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    37,    38,    20,    21,    -1,    23,    24,
      44,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    37,    38,    20,    21,    -1,    23,    24,    44,
      -1,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    37,    -1,    20,    21,    41,    23,    24,    44,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      37,    20,    -1,    -1,    23,    24,    -1,    44,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    37,    -1,
      -1,    -1,    23,    24,    -1,    44,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    37,    -1,    -1,    -1,    -1,    -1,
      -1,    44
  };

  const signed char
  parser::yystos_[] =
  {
       0,     0,     3,    48,    49,    46,    80,     0,     3,    50,
      51,    52,    39,    80,     4,     9,    39,     5,    80,     4,
      18,    19,    40,    53,    54,    55,    60,    80,     6,    39,
      60,    37,    40,    54,    55,    80,     7,    40,    53,    80,
      38,    41,    35,    40,    35,     8,    36,    58,    59,    60,
      37,    39,    36,    42,    80,    38,    13,    14,    16,    17,
      39,    54,    56,    57,    62,    63,    64,    65,    67,    68,
      80,    39,    59,    80,    11,    12,    22,    25,    26,    32,
      35,    45,    69,    70,    71,    72,    73,    74,    76,    77,
      78,    79,    80,    35,    35,    35,    40,    61,    62,    80,
      41,    54,    57,    62,    41,    37,    43,    56,    57,    36,
      18,    80,    69,    69,    69,    20,    21,    23,    24,    27,
      28,    29,    30,    31,    32,    33,    34,    37,    44,    69,
      69,    69,    40,    62,    40,    40,    69,    69,    41,    41,
      39,    37,    35,    36,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    10,    80,    36,
      36,    36,    38,    41,    40,    40,    40,    56,    69,    36,
      38,    35,    62,    62,    41,    43,    40,    40,    38,    36,
      69,    75,    15,    66,    69,    40,    36,    42,    62,    41,
      69
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    47,    48,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    54,    55,    55,
      55,    55,    56,    56,    56,    56,    56,    57,    58,    58,
      59,    60,    60,    60,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    63,    64,    65,    66,    67,    68,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      71,    71,    71,    71,    71,    71,    72,    72,    72,    72,
      73,    74,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    77,    78,    79,    79,    80
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,    16,    17,     1,     1,     4,
       5,     6,     7,     1,     1,     2,     2,     3,     9,    10,
       9,    10,     1,     1,     2,     2,     2,     2,     1,     3,
       2,     3,     1,     1,     1,     1,     2,     2,     3,     1,
       1,     1,     1,     1,     4,     7,     6,     2,     5,     5,
       1,     1,     1,     1,     1,     1,     5,     6,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       4,     3,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     2,     2,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "CLASS", "PUBLIC", "STATIC",
  "VOID", "MAIN", "STRING", "EXTENDS", "LENGTH", "NEW", "THIS", "RETURN",
  "IF", "ELSE", "WHILE", "SOPRINTLN", "INT", "BOOLEAN", "AND", "OR", "NOT",
  "EQUAL", "NOTEQUAL", "TRUE", "FALSE", "LT", "LET", "GT", "GET", "ADD",
  "SUB", "MUL", "DIV", "LPARENTHESE", "RPARENTHESE", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "SEMI", "COMMA", "ASSIGN", "DOT", "NUM",
  "IDENTIFIER", "$accept", "Goal", "MainClass", "ClassDeclarations",
  "ClassDeclaration", "ClassExtendsDeclaration", "Declarations",
  "VarDeclaration", "MethodDeclaration", "MethodBody", "Return",
  "FormalParameterList", "FormalParameter", "Type", "Statements",
  "Statement", "AssignStatement", "ArrayAssignStatement", "IfStatement",
  "ElseStatement", "WhileStatement", "PrintStatement", "Expression",
  "LogicExpression", "CompareExpression", "ArithExpression",
  "ArraySearchExpression", "ArrayLengthExpression", "ExpressionList",
  "PrimaryExpression", "ArrayAllocExpression", "AllocExpression",
  "UnaryExpression", "Identifier", YY_NULLPTR
  };

#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   132,   132,   133,   134,   137,   139,   143,   144,   147,
     148,   151,   152,   155,   156,   157,   158,   161,   164,   166,
     168,   170,   174,   175,   176,   177,   178,   181,   184,   185,
     188,   191,   192,   193,   194,   197,   198,   201,   202,   203,
     204,   205,   206,   207,   210,   213,   216,   219,   222,   225,
     228,   229,   230,   231,   232,   233,   234,   235,   238,   239,
     242,   243,   244,   245,   246,   247,   250,   251,   252,   253,
     256,   259,   262,   263,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   277,   280,   283,   284,   287
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2512 "parser.tab.cc"

#line 289 "src/parser.yy"
