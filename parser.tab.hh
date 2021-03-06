// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file parser.tab.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_PARSER_TAB_HH_INCLUDED
# define YY_YY_PARSER_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 52 "src/parser.yy"

  #include "nodes.h"

#line 52 "parser.tab.hh"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif


#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

namespace yy {
#line 186 "parser.tab.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // AllocExpression
      char dummy1[sizeof (std::shared_ptr<AllocExpression>)];

      // ArithExpression
      char dummy2[sizeof (std::shared_ptr<ArithExpression>)];

      // ArrayAllocExpression
      char dummy3[sizeof (std::shared_ptr<ArrayAllocExpression>)];

      // ArrayAssignStatement
      char dummy4[sizeof (std::shared_ptr<ArrayAssignStatement>)];

      // ArrayLengthExpression
      char dummy5[sizeof (std::shared_ptr<ArrayLengthExpression>)];

      // ArraySearchExpression
      char dummy6[sizeof (std::shared_ptr<ArraySearchExpression>)];

      // AssignStatement
      char dummy7[sizeof (std::shared_ptr<AssignStatement>)];

      // ClassDeclaration
      char dummy8[sizeof (std::shared_ptr<ClassDeclaration>)];

      // ClassExtendsDeclaration
      char dummy9[sizeof (std::shared_ptr<ClassExtendsDeclaration>)];

      // CompareExpression
      char dummy10[sizeof (std::shared_ptr<CompareExpression>)];

      // Declarations
      char dummy11[sizeof (std::shared_ptr<Declarations>)];

      // ElseStatement
      char dummy12[sizeof (std::shared_ptr<ElseStatement>)];

      // Expression
      char dummy13[sizeof (std::shared_ptr<Expression>)];

      // ExpressionList
      char dummy14[sizeof (std::shared_ptr<ExpressionList>)];

      // FormalParameter
      char dummy15[sizeof (std::shared_ptr<FormalParameter>)];

      // FormalParameterList
      char dummy16[sizeof (std::shared_ptr<FormalParameterList>)];

      // Goal
      char dummy17[sizeof (std::shared_ptr<Goal>)];

      // Identifier
      char dummy18[sizeof (std::shared_ptr<Identifier>)];

      // IfStatement
      char dummy19[sizeof (std::shared_ptr<IfStatement>)];

      // LogicExpression
      char dummy20[sizeof (std::shared_ptr<LogicExpression>)];

      // MainClass
      char dummy21[sizeof (std::shared_ptr<MainClass>)];

      // MethodBody
      char dummy22[sizeof (std::shared_ptr<MethodBody>)];

      // MethodDeclaration
      char dummy23[sizeof (std::shared_ptr<MethodDeclaration>)];

      // ClassDeclarations
      char dummy24[sizeof (std::shared_ptr<Node>)];

      // PrimaryExpression
      char dummy25[sizeof (std::shared_ptr<PrimaryExpression>)];

      // PrintStatement
      char dummy26[sizeof (std::shared_ptr<PrintStatement>)];

      // Return
      char dummy27[sizeof (std::shared_ptr<Return>)];

      // Statements
      // Statement
      char dummy28[sizeof (std::shared_ptr<Statement>)];

      // Type
      char dummy29[sizeof (std::shared_ptr<Type>)];

      // UnaryExpression
      char dummy30[sizeof (std::shared_ptr<UnaryExpression>)];

      // VarDeclaration
      char dummy31[sizeof (std::shared_ptr<VarDeclaration>)];

      // WhileStatement
      char dummy32[sizeof (std::shared_ptr<WhileStatement>)];

      // CLASS
      // PUBLIC
      // STATIC
      // VOID
      // MAIN
      // STRING
      // EXTENDS
      // LENGTH
      // NEW
      // THIS
      // RETURN
      // IF
      // ELSE
      // WHILE
      // SOPRINTLN
      // INT
      // BOOLEAN
      // AND
      // OR
      // NOT
      // EQUAL
      // NOTEQUAL
      // TRUE
      // FALSE
      // LT
      // LET
      // GT
      // GET
      // ADD
      // SUB
      // MUL
      // DIV
      // LPARENTHESE
      // RPARENTHESE
      // LBRACKET
      // RBRACKET
      // LBRACE
      // RBRACE
      // SEMI
      // COMMA
      // ASSIGN
      // DOT
      // NUM
      // IDENTIFIER
      char dummy33[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END = 0,
        CLASS = 258,
        PUBLIC = 259,
        STATIC = 260,
        VOID = 261,
        MAIN = 262,
        STRING = 263,
        EXTENDS = 264,
        LENGTH = 265,
        NEW = 266,
        THIS = 267,
        RETURN = 268,
        IF = 269,
        ELSE = 270,
        WHILE = 271,
        SOPRINTLN = 272,
        INT = 273,
        BOOLEAN = 274,
        AND = 275,
        OR = 276,
        NOT = 277,
        EQUAL = 278,
        NOTEQUAL = 279,
        TRUE = 280,
        FALSE = 281,
        LT = 282,
        LET = 283,
        GT = 284,
        GET = 285,
        ADD = 286,
        SUB = 287,
        MUL = 288,
        DIV = 289,
        LPARENTHESE = 290,
        RPARENTHESE = 291,
        LBRACKET = 292,
        RBRACKET = 293,
        LBRACE = 294,
        RBRACE = 295,
        SEMI = 296,
        COMMA = 297,
        ASSIGN = 298,
        DOT = 299,
        NUM = 300,
        IDENTIFIER = 301
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef signed char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<AllocExpression>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<AllocExpression>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ArithExpression>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ArithExpression>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ArrayAllocExpression>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ArrayAllocExpression>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ArrayAssignStatement>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ArrayAssignStatement>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ArrayLengthExpression>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ArrayLengthExpression>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ArraySearchExpression>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ArraySearchExpression>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<AssignStatement>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<AssignStatement>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ClassDeclaration>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ClassDeclaration>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ClassExtendsDeclaration>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ClassExtendsDeclaration>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<CompareExpression>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<CompareExpression>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Declarations>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Declarations>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ElseStatement>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ElseStatement>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Expression>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Expression>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<ExpressionList>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<ExpressionList>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<FormalParameter>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<FormalParameter>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<FormalParameterList>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<FormalParameterList>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Goal>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Goal>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Identifier>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Identifier>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<IfStatement>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<IfStatement>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<LogicExpression>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<LogicExpression>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<MainClass>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<MainClass>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<MethodBody>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<MethodBody>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<MethodDeclaration>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<MethodDeclaration>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Node>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Node>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<PrimaryExpression>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<PrimaryExpression>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<PrintStatement>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<PrintStatement>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Return>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Return>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Statement>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Statement>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<Type>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<Type>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<UnaryExpression>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<UnaryExpression>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<VarDeclaration>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<VarDeclaration>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::shared_ptr<WhileStatement>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::shared_ptr<WhileStatement>& v)
        : Base (t)
        , value (v)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
    {
      case 78: // AllocExpression
        value.template destroy< std::shared_ptr<AllocExpression> > ();
        break;

      case 72: // ArithExpression
        value.template destroy< std::shared_ptr<ArithExpression> > ();
        break;

      case 77: // ArrayAllocExpression
        value.template destroy< std::shared_ptr<ArrayAllocExpression> > ();
        break;

      case 64: // ArrayAssignStatement
        value.template destroy< std::shared_ptr<ArrayAssignStatement> > ();
        break;

      case 74: // ArrayLengthExpression
        value.template destroy< std::shared_ptr<ArrayLengthExpression> > ();
        break;

      case 73: // ArraySearchExpression
        value.template destroy< std::shared_ptr<ArraySearchExpression> > ();
        break;

      case 63: // AssignStatement
        value.template destroy< std::shared_ptr<AssignStatement> > ();
        break;

      case 51: // ClassDeclaration
        value.template destroy< std::shared_ptr<ClassDeclaration> > ();
        break;

      case 52: // ClassExtendsDeclaration
        value.template destroy< std::shared_ptr<ClassExtendsDeclaration> > ();
        break;

      case 71: // CompareExpression
        value.template destroy< std::shared_ptr<CompareExpression> > ();
        break;

      case 53: // Declarations
        value.template destroy< std::shared_ptr<Declarations> > ();
        break;

      case 66: // ElseStatement
        value.template destroy< std::shared_ptr<ElseStatement> > ();
        break;

      case 69: // Expression
        value.template destroy< std::shared_ptr<Expression> > ();
        break;

      case 75: // ExpressionList
        value.template destroy< std::shared_ptr<ExpressionList> > ();
        break;

      case 59: // FormalParameter
        value.template destroy< std::shared_ptr<FormalParameter> > ();
        break;

      case 58: // FormalParameterList
        value.template destroy< std::shared_ptr<FormalParameterList> > ();
        break;

      case 48: // Goal
        value.template destroy< std::shared_ptr<Goal> > ();
        break;

      case 80: // Identifier
        value.template destroy< std::shared_ptr<Identifier> > ();
        break;

      case 65: // IfStatement
        value.template destroy< std::shared_ptr<IfStatement> > ();
        break;

      case 70: // LogicExpression
        value.template destroy< std::shared_ptr<LogicExpression> > ();
        break;

      case 49: // MainClass
        value.template destroy< std::shared_ptr<MainClass> > ();
        break;

      case 56: // MethodBody
        value.template destroy< std::shared_ptr<MethodBody> > ();
        break;

      case 55: // MethodDeclaration
        value.template destroy< std::shared_ptr<MethodDeclaration> > ();
        break;

      case 50: // ClassDeclarations
        value.template destroy< std::shared_ptr<Node> > ();
        break;

      case 76: // PrimaryExpression
        value.template destroy< std::shared_ptr<PrimaryExpression> > ();
        break;

      case 68: // PrintStatement
        value.template destroy< std::shared_ptr<PrintStatement> > ();
        break;

      case 57: // Return
        value.template destroy< std::shared_ptr<Return> > ();
        break;

      case 61: // Statements
      case 62: // Statement
        value.template destroy< std::shared_ptr<Statement> > ();
        break;

      case 60: // Type
        value.template destroy< std::shared_ptr<Type> > ();
        break;

      case 79: // UnaryExpression
        value.template destroy< std::shared_ptr<UnaryExpression> > ();
        break;

      case 54: // VarDeclaration
        value.template destroy< std::shared_ptr<VarDeclaration> > ();
        break;

      case 67: // WhileStatement
        value.template destroy< std::shared_ptr<WhileStatement> > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type(token_type (tok))
      {
        YY_ASSERT (tok == token::END);
      }
#else
      symbol_type (int tok)
        : super_type(token_type (tok))
      {
        YY_ASSERT (tok == token::END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type(token_type (tok), std::move (v))
      {
        YY_ASSERT (tok == token::CLASS || tok == token::PUBLIC || tok == token::STATIC || tok == token::VOID || tok == token::MAIN || tok == token::STRING || tok == token::EXTENDS || tok == token::LENGTH || tok == token::NEW || tok == token::THIS || tok == token::RETURN || tok == token::IF || tok == token::ELSE || tok == token::WHILE || tok == token::SOPRINTLN || tok == token::INT || tok == token::BOOLEAN || tok == token::AND || tok == token::OR || tok == token::NOT || tok == token::EQUAL || tok == token::NOTEQUAL || tok == token::TRUE || tok == token::FALSE || tok == token::LT || tok == token::LET || tok == token::GT || tok == token::GET || tok == token::ADD || tok == token::SUB || tok == token::MUL || tok == token::DIV || tok == token::LPARENTHESE || tok == token::RPARENTHESE || tok == token::LBRACKET || tok == token::RBRACKET || tok == token::LBRACE || tok == token::RBRACE || tok == token::SEMI || tok == token::COMMA || tok == token::ASSIGN || tok == token::DOT || tok == token::NUM || tok == token::IDENTIFIER);
      }
#else
      symbol_type (int tok, const std::string& v)
        : super_type(token_type (tok), v)
      {
        YY_ASSERT (tok == token::CLASS || tok == token::PUBLIC || tok == token::STATIC || tok == token::VOID || tok == token::MAIN || tok == token::STRING || tok == token::EXTENDS || tok == token::LENGTH || tok == token::NEW || tok == token::THIS || tok == token::RETURN || tok == token::IF || tok == token::ELSE || tok == token::WHILE || tok == token::SOPRINTLN || tok == token::INT || tok == token::BOOLEAN || tok == token::AND || tok == token::OR || tok == token::NOT || tok == token::EQUAL || tok == token::NOTEQUAL || tok == token::TRUE || tok == token::FALSE || tok == token::LT || tok == token::LET || tok == token::GT || tok == token::GET || tok == token::ADD || tok == token::SUB || tok == token::MUL || tok == token::DIV || tok == token::LPARENTHESE || tok == token::RPARENTHESE || tok == token::LBRACKET || tok == token::RBRACKET || tok == token::LBRACE || tok == token::RBRACE || tok == token::SEMI || tok == token::COMMA || tok == token::ASSIGN || tok == token::DOT || tok == token::NUM || tok == token::IDENTIFIER);
      }
#endif
    };

    /// Build a parser object.
    parser ();
    virtual ~parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END ()
      {
        return symbol_type (token::END);
      }
#else
      static
      symbol_type
      make_END ()
      {
        return symbol_type (token::END);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CLASS (std::string v)
      {
        return symbol_type (token::CLASS, std::move (v));
      }
#else
      static
      symbol_type
      make_CLASS (const std::string& v)
      {
        return symbol_type (token::CLASS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUBLIC (std::string v)
      {
        return symbol_type (token::PUBLIC, std::move (v));
      }
#else
      static
      symbol_type
      make_PUBLIC (const std::string& v)
      {
        return symbol_type (token::PUBLIC, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STATIC (std::string v)
      {
        return symbol_type (token::STATIC, std::move (v));
      }
#else
      static
      symbol_type
      make_STATIC (const std::string& v)
      {
        return symbol_type (token::STATIC, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID (std::string v)
      {
        return symbol_type (token::VOID, std::move (v));
      }
#else
      static
      symbol_type
      make_VOID (const std::string& v)
      {
        return symbol_type (token::VOID, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAIN (std::string v)
      {
        return symbol_type (token::MAIN, std::move (v));
      }
#else
      static
      symbol_type
      make_MAIN (const std::string& v)
      {
        return symbol_type (token::MAIN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v)
      {
        return symbol_type (token::STRING, std::move (v));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v)
      {
        return symbol_type (token::STRING, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXTENDS (std::string v)
      {
        return symbol_type (token::EXTENDS, std::move (v));
      }
#else
      static
      symbol_type
      make_EXTENDS (const std::string& v)
      {
        return symbol_type (token::EXTENDS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LENGTH (std::string v)
      {
        return symbol_type (token::LENGTH, std::move (v));
      }
#else
      static
      symbol_type
      make_LENGTH (const std::string& v)
      {
        return symbol_type (token::LENGTH, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEW (std::string v)
      {
        return symbol_type (token::NEW, std::move (v));
      }
#else
      static
      symbol_type
      make_NEW (const std::string& v)
      {
        return symbol_type (token::NEW, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THIS (std::string v)
      {
        return symbol_type (token::THIS, std::move (v));
      }
#else
      static
      symbol_type
      make_THIS (const std::string& v)
      {
        return symbol_type (token::THIS, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETURN (std::string v)
      {
        return symbol_type (token::RETURN, std::move (v));
      }
#else
      static
      symbol_type
      make_RETURN (const std::string& v)
      {
        return symbol_type (token::RETURN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (std::string v)
      {
        return symbol_type (token::IF, std::move (v));
      }
#else
      static
      symbol_type
      make_IF (const std::string& v)
      {
        return symbol_type (token::IF, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (std::string v)
      {
        return symbol_type (token::ELSE, std::move (v));
      }
#else
      static
      symbol_type
      make_ELSE (const std::string& v)
      {
        return symbol_type (token::ELSE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (std::string v)
      {
        return symbol_type (token::WHILE, std::move (v));
      }
#else
      static
      symbol_type
      make_WHILE (const std::string& v)
      {
        return symbol_type (token::WHILE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SOPRINTLN (std::string v)
      {
        return symbol_type (token::SOPRINTLN, std::move (v));
      }
#else
      static
      symbol_type
      make_SOPRINTLN (const std::string& v)
      {
        return symbol_type (token::SOPRINTLN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (std::string v)
      {
        return symbol_type (token::INT, std::move (v));
      }
#else
      static
      symbol_type
      make_INT (const std::string& v)
      {
        return symbol_type (token::INT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOLEAN (std::string v)
      {
        return symbol_type (token::BOOLEAN, std::move (v));
      }
#else
      static
      symbol_type
      make_BOOLEAN (const std::string& v)
      {
        return symbol_type (token::BOOLEAN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (std::string v)
      {
        return symbol_type (token::AND, std::move (v));
      }
#else
      static
      symbol_type
      make_AND (const std::string& v)
      {
        return symbol_type (token::AND, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (std::string v)
      {
        return symbol_type (token::OR, std::move (v));
      }
#else
      static
      symbol_type
      make_OR (const std::string& v)
      {
        return symbol_type (token::OR, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (std::string v)
      {
        return symbol_type (token::NOT, std::move (v));
      }
#else
      static
      symbol_type
      make_NOT (const std::string& v)
      {
        return symbol_type (token::NOT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL (std::string v)
      {
        return symbol_type (token::EQUAL, std::move (v));
      }
#else
      static
      symbol_type
      make_EQUAL (const std::string& v)
      {
        return symbol_type (token::EQUAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOTEQUAL (std::string v)
      {
        return symbol_type (token::NOTEQUAL, std::move (v));
      }
#else
      static
      symbol_type
      make_NOTEQUAL (const std::string& v)
      {
        return symbol_type (token::NOTEQUAL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE (std::string v)
      {
        return symbol_type (token::TRUE, std::move (v));
      }
#else
      static
      symbol_type
      make_TRUE (const std::string& v)
      {
        return symbol_type (token::TRUE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE (std::string v)
      {
        return symbol_type (token::FALSE, std::move (v));
      }
#else
      static
      symbol_type
      make_FALSE (const std::string& v)
      {
        return symbol_type (token::FALSE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LT (std::string v)
      {
        return symbol_type (token::LT, std::move (v));
      }
#else
      static
      symbol_type
      make_LT (const std::string& v)
      {
        return symbol_type (token::LT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LET (std::string v)
      {
        return symbol_type (token::LET, std::move (v));
      }
#else
      static
      symbol_type
      make_LET (const std::string& v)
      {
        return symbol_type (token::LET, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GT (std::string v)
      {
        return symbol_type (token::GT, std::move (v));
      }
#else
      static
      symbol_type
      make_GT (const std::string& v)
      {
        return symbol_type (token::GT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GET (std::string v)
      {
        return symbol_type (token::GET, std::move (v));
      }
#else
      static
      symbol_type
      make_GET (const std::string& v)
      {
        return symbol_type (token::GET, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ADD (std::string v)
      {
        return symbol_type (token::ADD, std::move (v));
      }
#else
      static
      symbol_type
      make_ADD (const std::string& v)
      {
        return symbol_type (token::ADD, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUB (std::string v)
      {
        return symbol_type (token::SUB, std::move (v));
      }
#else
      static
      symbol_type
      make_SUB (const std::string& v)
      {
        return symbol_type (token::SUB, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MUL (std::string v)
      {
        return symbol_type (token::MUL, std::move (v));
      }
#else
      static
      symbol_type
      make_MUL (const std::string& v)
      {
        return symbol_type (token::MUL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIV (std::string v)
      {
        return symbol_type (token::DIV, std::move (v));
      }
#else
      static
      symbol_type
      make_DIV (const std::string& v)
      {
        return symbol_type (token::DIV, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LPARENTHESE (std::string v)
      {
        return symbol_type (token::LPARENTHESE, std::move (v));
      }
#else
      static
      symbol_type
      make_LPARENTHESE (const std::string& v)
      {
        return symbol_type (token::LPARENTHESE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RPARENTHESE (std::string v)
      {
        return symbol_type (token::RPARENTHESE, std::move (v));
      }
#else
      static
      symbol_type
      make_RPARENTHESE (const std::string& v)
      {
        return symbol_type (token::RPARENTHESE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACKET (std::string v)
      {
        return symbol_type (token::LBRACKET, std::move (v));
      }
#else
      static
      symbol_type
      make_LBRACKET (const std::string& v)
      {
        return symbol_type (token::LBRACKET, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACKET (std::string v)
      {
        return symbol_type (token::RBRACKET, std::move (v));
      }
#else
      static
      symbol_type
      make_RBRACKET (const std::string& v)
      {
        return symbol_type (token::RBRACKET, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBRACE (std::string v)
      {
        return symbol_type (token::LBRACE, std::move (v));
      }
#else
      static
      symbol_type
      make_LBRACE (const std::string& v)
      {
        return symbol_type (token::LBRACE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBRACE (std::string v)
      {
        return symbol_type (token::RBRACE, std::move (v));
      }
#else
      static
      symbol_type
      make_RBRACE (const std::string& v)
      {
        return symbol_type (token::RBRACE, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SEMI (std::string v)
      {
        return symbol_type (token::SEMI, std::move (v));
      }
#else
      static
      symbol_type
      make_SEMI (const std::string& v)
      {
        return symbol_type (token::SEMI, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA (std::string v)
      {
        return symbol_type (token::COMMA, std::move (v));
      }
#else
      static
      symbol_type
      make_COMMA (const std::string& v)
      {
        return symbol_type (token::COMMA, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (std::string v)
      {
        return symbol_type (token::ASSIGN, std::move (v));
      }
#else
      static
      symbol_type
      make_ASSIGN (const std::string& v)
      {
        return symbol_type (token::ASSIGN, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (std::string v)
      {
        return symbol_type (token::DOT, std::move (v));
      }
#else
      static
      symbol_type
      make_DOT (const std::string& v)
      {
        return symbol_type (token::DOT, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUM (std::string v)
      {
        return symbol_type (token::NUM, std::move (v));
      }
#else
      static
      symbol_type
      make_NUM (const std::string& v)
      {
        return symbol_type (token::NUM, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v)
      {
        return symbol_type (token::IDENTIFIER, std::move (v));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v)
      {
        return symbol_type (token::IDENTIFIER, v);
      }
#endif


  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    /// In theory \a t should be a token_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static token_number_type yytranslate_ (int t);

    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
    static const signed char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      std::ptrdiff_t
      ssize () const YY_NOEXCEPT
      {
        return std::ptrdiff_t (size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Some specific tokens.
    static const token_number_type yy_error_token_ = 1;
    static const token_number_type yy_undef_token_ = 2;

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 531,     ///< Last index in yytable_.
      yynnts_ = 34,  ///< Number of nonterminal symbols.
      yyfinal_ = 7, ///< Termination state number.
      yyntokens_ = 47  ///< Number of tokens.
    };


  };

  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
    };
    const int user_token_number_max_ = 301;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
  {
    switch (this->type_get ())
    {
      case 78: // AllocExpression
        value.move< std::shared_ptr<AllocExpression> > (std::move (that.value));
        break;

      case 72: // ArithExpression
        value.move< std::shared_ptr<ArithExpression> > (std::move (that.value));
        break;

      case 77: // ArrayAllocExpression
        value.move< std::shared_ptr<ArrayAllocExpression> > (std::move (that.value));
        break;

      case 64: // ArrayAssignStatement
        value.move< std::shared_ptr<ArrayAssignStatement> > (std::move (that.value));
        break;

      case 74: // ArrayLengthExpression
        value.move< std::shared_ptr<ArrayLengthExpression> > (std::move (that.value));
        break;

      case 73: // ArraySearchExpression
        value.move< std::shared_ptr<ArraySearchExpression> > (std::move (that.value));
        break;

      case 63: // AssignStatement
        value.move< std::shared_ptr<AssignStatement> > (std::move (that.value));
        break;

      case 51: // ClassDeclaration
        value.move< std::shared_ptr<ClassDeclaration> > (std::move (that.value));
        break;

      case 52: // ClassExtendsDeclaration
        value.move< std::shared_ptr<ClassExtendsDeclaration> > (std::move (that.value));
        break;

      case 71: // CompareExpression
        value.move< std::shared_ptr<CompareExpression> > (std::move (that.value));
        break;

      case 53: // Declarations
        value.move< std::shared_ptr<Declarations> > (std::move (that.value));
        break;

      case 66: // ElseStatement
        value.move< std::shared_ptr<ElseStatement> > (std::move (that.value));
        break;

      case 69: // Expression
        value.move< std::shared_ptr<Expression> > (std::move (that.value));
        break;

      case 75: // ExpressionList
        value.move< std::shared_ptr<ExpressionList> > (std::move (that.value));
        break;

      case 59: // FormalParameter
        value.move< std::shared_ptr<FormalParameter> > (std::move (that.value));
        break;

      case 58: // FormalParameterList
        value.move< std::shared_ptr<FormalParameterList> > (std::move (that.value));
        break;

      case 48: // Goal
        value.move< std::shared_ptr<Goal> > (std::move (that.value));
        break;

      case 80: // Identifier
        value.move< std::shared_ptr<Identifier> > (std::move (that.value));
        break;

      case 65: // IfStatement
        value.move< std::shared_ptr<IfStatement> > (std::move (that.value));
        break;

      case 70: // LogicExpression
        value.move< std::shared_ptr<LogicExpression> > (std::move (that.value));
        break;

      case 49: // MainClass
        value.move< std::shared_ptr<MainClass> > (std::move (that.value));
        break;

      case 56: // MethodBody
        value.move< std::shared_ptr<MethodBody> > (std::move (that.value));
        break;

      case 55: // MethodDeclaration
        value.move< std::shared_ptr<MethodDeclaration> > (std::move (that.value));
        break;

      case 50: // ClassDeclarations
        value.move< std::shared_ptr<Node> > (std::move (that.value));
        break;

      case 76: // PrimaryExpression
        value.move< std::shared_ptr<PrimaryExpression> > (std::move (that.value));
        break;

      case 68: // PrintStatement
        value.move< std::shared_ptr<PrintStatement> > (std::move (that.value));
        break;

      case 57: // Return
        value.move< std::shared_ptr<Return> > (std::move (that.value));
        break;

      case 61: // Statements
      case 62: // Statement
        value.move< std::shared_ptr<Statement> > (std::move (that.value));
        break;

      case 60: // Type
        value.move< std::shared_ptr<Type> > (std::move (that.value));
        break;

      case 79: // UnaryExpression
        value.move< std::shared_ptr<UnaryExpression> > (std::move (that.value));
        break;

      case 54: // VarDeclaration
        value.move< std::shared_ptr<VarDeclaration> > (std::move (that.value));
        break;

      case 67: // WhileStatement
        value.move< std::shared_ptr<WhileStatement> > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->type_get ())
    {
      case 78: // AllocExpression
        value.copy< std::shared_ptr<AllocExpression> > (YY_MOVE (that.value));
        break;

      case 72: // ArithExpression
        value.copy< std::shared_ptr<ArithExpression> > (YY_MOVE (that.value));
        break;

      case 77: // ArrayAllocExpression
        value.copy< std::shared_ptr<ArrayAllocExpression> > (YY_MOVE (that.value));
        break;

      case 64: // ArrayAssignStatement
        value.copy< std::shared_ptr<ArrayAssignStatement> > (YY_MOVE (that.value));
        break;

      case 74: // ArrayLengthExpression
        value.copy< std::shared_ptr<ArrayLengthExpression> > (YY_MOVE (that.value));
        break;

      case 73: // ArraySearchExpression
        value.copy< std::shared_ptr<ArraySearchExpression> > (YY_MOVE (that.value));
        break;

      case 63: // AssignStatement
        value.copy< std::shared_ptr<AssignStatement> > (YY_MOVE (that.value));
        break;

      case 51: // ClassDeclaration
        value.copy< std::shared_ptr<ClassDeclaration> > (YY_MOVE (that.value));
        break;

      case 52: // ClassExtendsDeclaration
        value.copy< std::shared_ptr<ClassExtendsDeclaration> > (YY_MOVE (that.value));
        break;

      case 71: // CompareExpression
        value.copy< std::shared_ptr<CompareExpression> > (YY_MOVE (that.value));
        break;

      case 53: // Declarations
        value.copy< std::shared_ptr<Declarations> > (YY_MOVE (that.value));
        break;

      case 66: // ElseStatement
        value.copy< std::shared_ptr<ElseStatement> > (YY_MOVE (that.value));
        break;

      case 69: // Expression
        value.copy< std::shared_ptr<Expression> > (YY_MOVE (that.value));
        break;

      case 75: // ExpressionList
        value.copy< std::shared_ptr<ExpressionList> > (YY_MOVE (that.value));
        break;

      case 59: // FormalParameter
        value.copy< std::shared_ptr<FormalParameter> > (YY_MOVE (that.value));
        break;

      case 58: // FormalParameterList
        value.copy< std::shared_ptr<FormalParameterList> > (YY_MOVE (that.value));
        break;

      case 48: // Goal
        value.copy< std::shared_ptr<Goal> > (YY_MOVE (that.value));
        break;

      case 80: // Identifier
        value.copy< std::shared_ptr<Identifier> > (YY_MOVE (that.value));
        break;

      case 65: // IfStatement
        value.copy< std::shared_ptr<IfStatement> > (YY_MOVE (that.value));
        break;

      case 70: // LogicExpression
        value.copy< std::shared_ptr<LogicExpression> > (YY_MOVE (that.value));
        break;

      case 49: // MainClass
        value.copy< std::shared_ptr<MainClass> > (YY_MOVE (that.value));
        break;

      case 56: // MethodBody
        value.copy< std::shared_ptr<MethodBody> > (YY_MOVE (that.value));
        break;

      case 55: // MethodDeclaration
        value.copy< std::shared_ptr<MethodDeclaration> > (YY_MOVE (that.value));
        break;

      case 50: // ClassDeclarations
        value.copy< std::shared_ptr<Node> > (YY_MOVE (that.value));
        break;

      case 76: // PrimaryExpression
        value.copy< std::shared_ptr<PrimaryExpression> > (YY_MOVE (that.value));
        break;

      case 68: // PrintStatement
        value.copy< std::shared_ptr<PrintStatement> > (YY_MOVE (that.value));
        break;

      case 57: // Return
        value.copy< std::shared_ptr<Return> > (YY_MOVE (that.value));
        break;

      case 61: // Statements
      case 62: // Statement
        value.copy< std::shared_ptr<Statement> > (YY_MOVE (that.value));
        break;

      case 60: // Type
        value.copy< std::shared_ptr<Type> > (YY_MOVE (that.value));
        break;

      case 79: // UnaryExpression
        value.copy< std::shared_ptr<UnaryExpression> > (YY_MOVE (that.value));
        break;

      case 54: // VarDeclaration
        value.copy< std::shared_ptr<VarDeclaration> > (YY_MOVE (that.value));
        break;

      case 67: // WhileStatement
        value.copy< std::shared_ptr<WhileStatement> > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 78: // AllocExpression
        value.move< std::shared_ptr<AllocExpression> > (YY_MOVE (s.value));
        break;

      case 72: // ArithExpression
        value.move< std::shared_ptr<ArithExpression> > (YY_MOVE (s.value));
        break;

      case 77: // ArrayAllocExpression
        value.move< std::shared_ptr<ArrayAllocExpression> > (YY_MOVE (s.value));
        break;

      case 64: // ArrayAssignStatement
        value.move< std::shared_ptr<ArrayAssignStatement> > (YY_MOVE (s.value));
        break;

      case 74: // ArrayLengthExpression
        value.move< std::shared_ptr<ArrayLengthExpression> > (YY_MOVE (s.value));
        break;

      case 73: // ArraySearchExpression
        value.move< std::shared_ptr<ArraySearchExpression> > (YY_MOVE (s.value));
        break;

      case 63: // AssignStatement
        value.move< std::shared_ptr<AssignStatement> > (YY_MOVE (s.value));
        break;

      case 51: // ClassDeclaration
        value.move< std::shared_ptr<ClassDeclaration> > (YY_MOVE (s.value));
        break;

      case 52: // ClassExtendsDeclaration
        value.move< std::shared_ptr<ClassExtendsDeclaration> > (YY_MOVE (s.value));
        break;

      case 71: // CompareExpression
        value.move< std::shared_ptr<CompareExpression> > (YY_MOVE (s.value));
        break;

      case 53: // Declarations
        value.move< std::shared_ptr<Declarations> > (YY_MOVE (s.value));
        break;

      case 66: // ElseStatement
        value.move< std::shared_ptr<ElseStatement> > (YY_MOVE (s.value));
        break;

      case 69: // Expression
        value.move< std::shared_ptr<Expression> > (YY_MOVE (s.value));
        break;

      case 75: // ExpressionList
        value.move< std::shared_ptr<ExpressionList> > (YY_MOVE (s.value));
        break;

      case 59: // FormalParameter
        value.move< std::shared_ptr<FormalParameter> > (YY_MOVE (s.value));
        break;

      case 58: // FormalParameterList
        value.move< std::shared_ptr<FormalParameterList> > (YY_MOVE (s.value));
        break;

      case 48: // Goal
        value.move< std::shared_ptr<Goal> > (YY_MOVE (s.value));
        break;

      case 80: // Identifier
        value.move< std::shared_ptr<Identifier> > (YY_MOVE (s.value));
        break;

      case 65: // IfStatement
        value.move< std::shared_ptr<IfStatement> > (YY_MOVE (s.value));
        break;

      case 70: // LogicExpression
        value.move< std::shared_ptr<LogicExpression> > (YY_MOVE (s.value));
        break;

      case 49: // MainClass
        value.move< std::shared_ptr<MainClass> > (YY_MOVE (s.value));
        break;

      case 56: // MethodBody
        value.move< std::shared_ptr<MethodBody> > (YY_MOVE (s.value));
        break;

      case 55: // MethodDeclaration
        value.move< std::shared_ptr<MethodDeclaration> > (YY_MOVE (s.value));
        break;

      case 50: // ClassDeclarations
        value.move< std::shared_ptr<Node> > (YY_MOVE (s.value));
        break;

      case 76: // PrimaryExpression
        value.move< std::shared_ptr<PrimaryExpression> > (YY_MOVE (s.value));
        break;

      case 68: // PrintStatement
        value.move< std::shared_ptr<PrintStatement> > (YY_MOVE (s.value));
        break;

      case 57: // Return
        value.move< std::shared_ptr<Return> > (YY_MOVE (s.value));
        break;

      case 61: // Statements
      case 62: // Statement
        value.move< std::shared_ptr<Statement> > (YY_MOVE (s.value));
        break;

      case 60: // Type
        value.move< std::shared_ptr<Type> > (YY_MOVE (s.value));
        break;

      case 79: // UnaryExpression
        value.move< std::shared_ptr<UnaryExpression> > (YY_MOVE (s.value));
        break;

      case 54: // VarDeclaration
        value.move< std::shared_ptr<VarDeclaration> > (YY_MOVE (s.value));
        break;

      case 67: // WhileStatement
        value.move< std::shared_ptr<WhileStatement> > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

} // yy
#line 3005 "parser.tab.hh"



// "%code provides" blocks.
#line 56 "src/parser.yy"

  extern FILE *yyin;

#line 3014 "parser.tab.hh"


#endif // !YY_YY_PARSER_TAB_HH_INCLUDED
