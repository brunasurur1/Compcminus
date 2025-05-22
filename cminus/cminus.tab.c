/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "cminus.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"
#include "ast.h"

/* Variável global para armazenar a raiz da AST */
ASTNode* arvoreAST = NULL;

/* Declaração de yylineno, definida pelo Flex (%option yylineno) */
extern int yylineno;

/* Funções externas do Flex */
int yylex(void);
void yyerror(const char *s);

/* Variável para controlar o escopo atual (inicialmente "global") */
static char escopoAtual[64] = "global";

#line 92 "cminus.tab.c"

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

#include "cminus.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_ID = 4,                         /* ID  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_LE = 11,                        /* LE  */
  YYSYMBOL_GE = 12,                        /* GE  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_NE = 14,                        /* NE  */
  YYSYMBOL_15_ = 15,                       /* '+'  */
  YYSYMBOL_16_ = 16,                       /* '-'  */
  YYSYMBOL_17_ = 17,                       /* '*'  */
  YYSYMBOL_18_ = 18,                       /* '/'  */
  YYSYMBOL_19_ = 19,                       /* '='  */
  YYSYMBOL_20_ = 20,                       /* ';'  */
  YYSYMBOL_21_ = 21,                       /* '['  */
  YYSYMBOL_22_ = 22,                       /* ']'  */
  YYSYMBOL_23_ = 23,                       /* '('  */
  YYSYMBOL_24_ = 24,                       /* ')'  */
  YYSYMBOL_25_ = 25,                       /* ','  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_program = 31,                   /* program  */
  YYSYMBOL_declaration_list = 32,          /* declaration_list  */
  YYSYMBOL_declaration = 33,               /* declaration  */
  YYSYMBOL_var_declaration = 34,           /* var_declaration  */
  YYSYMBOL_fun_signature = 35,             /* fun_signature  */
  YYSYMBOL_fun_declaration = 36,           /* fun_declaration  */
  YYSYMBOL_params = 37,                    /* params  */
  YYSYMBOL_param_list = 38,                /* param_list  */
  YYSYMBOL_param = 39,                     /* param  */
  YYSYMBOL_compound_decl = 40,             /* compound_decl  */
  YYSYMBOL_local_declarations = 41,        /* local_declarations  */
  YYSYMBOL_statement_list = 42,            /* statement_list  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_selection_decl = 44,            /* selection_decl  */
  YYSYMBOL_iteration_decl = 45,            /* iteration_decl  */
  YYSYMBOL_return_decl = 46,               /* return_decl  */
  YYSYMBOL_expression_decl = 47,           /* expression_decl  */
  YYSYMBOL_expression = 48,                /* expression  */
  YYSYMBOL_var = 49,                       /* var  */
  YYSYMBOL_activation = 50,                /* activation  */
  YYSYMBOL_args = 51,                      /* args  */
  YYSYMBOL_arg_list = 52,                  /* arg_list  */
  YYSYMBOL_simple_expression = 53,         /* simple_expression  */
  YYSYMBOL_relop = 54,                     /* relop  */
  YYSYMBOL_additive_expression = 55,       /* additive_expression  */
  YYSYMBOL_term = 56,                      /* term  */
  YYSYMBOL_factor = 57,                    /* factor  */
  YYSYMBOL_type_specifier = 58             /* type_specifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   99

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   269


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      23,    24,    17,    15,    25,    16,     2,    18,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
      28,    19,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    21,     2,    22,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    57,    57,    70,    76,    84,    85,    89,   101,   118,
     136,   146,   147,   151,   157,   165,   177,   192,   201,   208,
     214,   221,   227,   228,   229,   230,   231,   235,   241,   251,
     260,   264,   272,   274,   279,   285,   289,   302,   320,   334,
     335,   339,   345,   350,   351,   360,   361,   362,   363,   364,
     365,   369,   375,   381,   385,   391,   397,   401,   402,   403,
     404,   408,   409
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "ID", "INT",
  "VOID", "IF", "ELSE", "WHILE", "RETURN", "LE", "GE", "EQ", "NE", "'+'",
  "'-'", "'*'", "'/'", "'='", "';'", "'['", "']'", "'('", "')'", "','",
  "'{'", "'}'", "'<'", "'>'", "$accept", "program", "declaration_list",
  "declaration", "var_declaration", "fun_signature", "fun_declaration",
  "params", "param_list", "param", "compound_decl", "local_declarations",
  "statement_list", "statement", "selection_decl", "iteration_decl",
  "return_decl", "expression_decl", "expression", "var", "activation",
  "args", "arg_list", "simple_expression", "relop", "additive_expression",
  "term", "factor", "type_specifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-63)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      45,   -33,   -33,    14,    45,   -33,   -33,   -20,   -33,    13,
     -33,   -33,   -33,   -33,    -2,    45,   -33,    17,    48,   -33,
       6,    30,    15,    36,    19,    51,   -33,    75,   -33,   -18,
      57,    58,     8,   -33,     4,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,    62,    64,   -33,   -33,    33,    39,   -33,    52,
      65,   -33,    45,    63,     4,     4,     4,     4,   -33,    66,
      67,   -33,     4,   -33,   -33,   -33,   -33,     4,     4,   -33,
     -33,     4,     4,     4,   -33,   -33,    68,    70,   -33,    69,
      71,    73,    74,   -33,   -33,   -33,   -33,    39,    39,    44,
     -33,   -33,   -33,   -33,   -33,     4,    32,    32,   -33,    79,
     -33,    32,   -33
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    61,    62,     0,     2,     4,     5,     0,     6,     0,
       1,     3,    19,    10,     0,    21,     7,     0,     0,    18,
       0,     0,     0,    12,     0,    11,    14,     0,    60,    36,
       0,     0,     0,    33,     0,    17,    23,    20,    24,    25,
      26,    22,     0,    59,    58,    35,    43,    53,    56,     0,
       0,     9,     0,    15,     0,    40,     0,     0,    30,     0,
       0,    32,     0,    47,    49,    45,    46,     0,     0,    48,
      50,     0,     0,     0,     8,    13,     0,     0,    42,     0,
      39,     0,     0,    31,    57,    34,    59,    51,    52,    44,
      54,    55,    16,    37,    38,     0,     0,     0,    41,    27,
      29,     0,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,   -33,    84,    80,   -33,   -33,   -33,   -33,    37,
      87,   -33,   -33,   -30,   -33,   -33,   -33,   -33,   -32,    -3,
     -33,   -33,   -33,   -33,   -33,    28,     7,     5,   -14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    24,    25,    26,
      36,    15,    20,    37,    38,    39,    40,    41,    42,    43,
      44,    79,    80,    45,    71,    46,    47,    48,     9
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      59,    21,    60,    54,    27,    55,    12,    28,    29,    28,
      29,    28,    29,    30,    10,    31,    32,    14,    16,    17,
      22,    18,    77,    78,    81,    82,    33,    34,    58,    34,
      85,    34,    12,    35,    49,    28,    29,    50,    27,    30,
     -62,    31,    32,    51,    63,    64,    65,    66,    67,    68,
       1,     2,    33,     1,    23,    34,    72,    73,    12,    67,
      68,    69,    70,    98,    86,    86,    99,   100,    86,    86,
      86,   102,    16,    17,    87,    88,    52,    90,    91,    53,
      56,    57,    61,    62,    76,    74,    83,   101,    11,    75,
      92,    84,    93,    94,    13,    19,    95,    96,    97,    89
};

static const yytype_int8 yycheck[] =
{
      32,    15,    34,    21,    18,    23,    26,     3,     4,     3,
       4,     3,     4,     7,     0,     9,    10,     4,    20,    21,
       3,    23,    54,    55,    56,    57,    20,    23,    20,    23,
      62,    23,    26,    27,     4,     3,     4,    22,    52,     7,
       4,     9,    10,    24,    11,    12,    13,    14,    15,    16,
       5,     6,    20,     5,     6,    23,    17,    18,    26,    15,
      16,    28,    29,    95,    67,    68,    96,    97,    71,    72,
      73,   101,    20,    21,    67,    68,    25,    72,    73,     4,
      23,    23,    20,    19,    21,    20,    20,     8,     4,    52,
      22,    24,    22,    24,     7,    15,    25,    24,    24,    71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,    31,    32,    33,    34,    35,    36,    58,
       0,    33,    26,    40,     4,    41,    20,    21,    23,    34,
      42,    58,     3,     6,    37,    38,    39,    58,     3,     4,
       7,     9,    10,    20,    23,    27,    40,    43,    44,    45,
      46,    47,    48,    49,    50,    53,    55,    56,    57,     4,
      22,    24,    25,     4,    21,    23,    23,    23,    20,    48,
      48,    20,    19,    11,    12,    13,    14,    15,    16,    28,
      29,    54,    17,    18,    20,    39,    21,    48,    48,    51,
      52,    48,    48,    20,    24,    48,    49,    56,    56,    55,
      57,    57,    22,    22,    24,    25,    24,    24,    48,    43,
      43,     8,    43
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    32,    33,    33,    34,    34,    35,
      36,    37,    37,    38,    38,    39,    39,    40,    41,    41,
      42,    42,    43,    43,    43,    43,    43,    44,    44,    45,
      46,    46,    47,    47,    48,    48,    49,    49,    50,    51,
      51,    52,    52,    53,    53,    54,    54,    54,    54,    54,
      54,    55,    55,    55,    56,    56,    56,    57,    57,    57,
      57,    58,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     5,
       2,     1,     1,     3,     1,     2,     4,     4,     2,     0,
       2,     0,     1,     1,     1,     1,     1,     5,     7,     5,
       2,     3,     2,     1,     3,     1,     1,     4,     4,     1,
       0,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     1,     3,     1,     1,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration_list  */
#line 58 "cminus.y"
    {
      (yyval.ast) = newASTNode(NODE_PROGRAM, "program", 0);
      addChild((yyval.ast), (yyvsp[0].ast));
      arvoreAST = (yyval.ast);
      imprimeTabela();
      printf("\nArvore Sintatica:\n");
      printAST((yyval.ast), 0, 1);
      printf("\nCompilacao encerrada com sucesso.\n");
    }
#line 1210 "cminus.tab.c"
    break;

  case 3: /* declaration_list: declaration_list declaration  */
#line 71 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_DECLARATION_LIST, "declList", 0);
       addChild((yyval.ast), (yyvsp[-1].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1220 "cminus.tab.c"
    break;

  case 4: /* declaration_list: declaration  */
#line 77 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_DECLARATION_LIST, "declList", 0);
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1229 "cminus.tab.c"
    break;

  case 5: /* declaration: var_declaration  */
#line 84 "cminus.y"
                    { (yyval.ast) = (yyvsp[0].ast); }
#line 1235 "cminus.tab.c"
    break;

  case 6: /* declaration: fun_declaration  */
#line 85 "cminus.y"
                      { (yyval.ast) = (yyvsp[0].ast); }
#line 1241 "cminus.tab.c"
    break;

  case 7: /* var_declaration: type_specifier ID ';'  */
#line 90 "cminus.y"
    {
       if ((yyvsp[-2].tipoToken) == TIPO_VOID) {
           fprintf(stderr, "ERRO SEMANTICO: Variavel \"%s\" nao pode ter tipo void. Linha: %d\n", (yyvsp[-1].id), yylineno);
           exit(1);
           (yyval.ast) = newASTNode(NODE_VAR_DECL, "var_decl", 0);
       } else {
           insereSimbolo((yyvsp[-1].id), (yyvsp[-2].tipoToken), escopoAtual);
           (yyval.ast) = newASTNode(NODE_VAR_DECL, (yyvsp[-1].id), 0);
       }
       free((yyvsp[-1].id));
    }
#line 1257 "cminus.tab.c"
    break;

  case 8: /* var_declaration: type_specifier ID '[' NUM ']' ';'  */
#line 102 "cminus.y"
    {
       if ((yyvsp[-5].tipoToken) == TIPO_VOID) {
           fprintf(stderr, "ERRO SEMANTICO: Array \"%s\" nao pode ter tipo void. Linha: %d\n", (yyvsp[-4].id), yylineno);
           exit(1);
           (yyval.ast) = newASTNode(NODE_VAR_DECL, "array_decl", 0);
       } else {
           insereSimbolo((yyvsp[-4].id), (yyvsp[-5].tipoToken), escopoAtual);
           (yyval.ast) = newASTNode(NODE_VAR_DECL, (yyvsp[-4].id), 0);
           addChild((yyval.ast), newASTNode(NODE_NUM, NULL, (yyvsp[-2].num)));
       }
       free((yyvsp[-4].id));
    }
#line 1274 "cminus.tab.c"
    break;

  case 9: /* fun_signature: type_specifier ID '(' params ')'  */
#line 119 "cminus.y"
    {
         insereSimbolo((yyvsp[-3].id), (yyvsp[-4].tipoToken), "global");
         strcpy(escopoAtual, (yyvsp[-3].id));
         (yyval.ast) = newASTNode(NODE_FUN_DECL, (yyvsp[-3].id), 0);
         {
             char buffer[16];
             sprintf(buffer, "%s", ((yyvsp[-4].tipoToken)==TIPO_INT ? "int" : "void"));
             addChild((yyval.ast), newASTNode(NODE_TYPE_SPECIFIER, buffer, 0));
         }
         addChild((yyval.ast), newASTNode(NODE_ID, (yyvsp[-3].id), 0));
         addChild((yyval.ast), (yyvsp[-1].ast)); /* AST dos parâmetros */
         free((yyvsp[-3].id));
    }
#line 1292 "cminus.tab.c"
    break;

  case 10: /* fun_declaration: fun_signature compound_decl  */
#line 137 "cminus.y"
    {
         (yyval.ast) = newASTNode(NODE_FUN_DECL, "fun_decl", 0);
         addChild((yyval.ast), (yyvsp[-1].ast));  /* assinatura */
         addChild((yyval.ast), (yyvsp[0].ast));  /* corpo */
         strcpy(escopoAtual, "global");
    }
#line 1303 "cminus.tab.c"
    break;

  case 11: /* params: param_list  */
#line 146 "cminus.y"
               { (yyval.ast) = (yyvsp[0].ast); }
#line 1309 "cminus.tab.c"
    break;

  case 12: /* params: VOID  */
#line 147 "cminus.y"
           { (yyval.ast) = newASTNode(NODE_PARAMS, "void", 0); }
#line 1315 "cminus.tab.c"
    break;

  case 13: /* param_list: param_list ',' param  */
#line 152 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_PARAM_LIST, "param_list", 0);
       addChild((yyval.ast), (yyvsp[-2].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1325 "cminus.tab.c"
    break;

  case 14: /* param_list: param  */
#line 158 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_PARAM_LIST, "param_list", 0);
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1334 "cminus.tab.c"
    break;

  case 15: /* param: type_specifier ID  */
#line 166 "cminus.y"
    {
      if ((yyvsp[-1].tipoToken) == TIPO_VOID) {
          fprintf(stderr, "ERRO SEMANTICO: Parametro \"%s\" nao pode ter tipo void. Linha: %d\n", (yyvsp[0].id), yylineno);
          exit(1);
          (yyval.ast) = newASTNode(NODE_PARAM, "param", 0);
      } else {
          insereSimbolo((yyvsp[0].id), (yyvsp[-1].tipoToken), escopoAtual);
          (yyval.ast) = newASTNode(NODE_PARAM, (yyvsp[0].id), 0);
      }
      free((yyvsp[0].id));
    }
#line 1350 "cminus.tab.c"
    break;

  case 16: /* param: type_specifier ID '[' ']'  */
#line 178 "cminus.y"
    {
      if ((yyvsp[-3].tipoToken) == TIPO_VOID) {
          fprintf(stderr, "ERRO SEMANTICO: Parametro array \"%s\" nao pode ter tipo void. Linha: %d\n", (yyvsp[-2].id), yylineno);
          exit(1);
          (yyval.ast) = newASTNode(NODE_PARAM, "param_array", 0);
      } else {
          insereSimbolo((yyvsp[-2].id), (yyvsp[-3].tipoToken), escopoAtual);
          (yyval.ast) = newASTNode(NODE_PARAM, (yyvsp[-2].id), 0);
      }
      free((yyvsp[-2].id));
    }
#line 1366 "cminus.tab.c"
    break;

  case 17: /* compound_decl: '{' local_declarations statement_list '}'  */
#line 193 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_COMPOUND_DECL, "compound", 0);
       addChild((yyval.ast), (yyvsp[-2].ast));
       addChild((yyval.ast), (yyvsp[-1].ast));
    }
#line 1376 "cminus.tab.c"
    break;

  case 18: /* local_declarations: local_declarations var_declaration  */
#line 202 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_LOCAL_DECLS, "local_decls", 0);
       addChild((yyval.ast), (yyvsp[-1].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1386 "cminus.tab.c"
    break;

  case 19: /* local_declarations: %empty  */
#line 208 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_LOCAL_DECLS, "local_decls", 0);
    }
#line 1394 "cminus.tab.c"
    break;

  case 20: /* statement_list: statement_list statement  */
#line 215 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_STATEMENT_LIST, "stmt_list", 0);
       addChild((yyval.ast), (yyvsp[-1].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1404 "cminus.tab.c"
    break;

  case 21: /* statement_list: %empty  */
#line 221 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_STATEMENT_LIST, "stmt_list", 0);
    }
#line 1412 "cminus.tab.c"
    break;

  case 22: /* statement: expression_decl  */
#line 227 "cminus.y"
                    { (yyval.ast) = (yyvsp[0].ast); }
#line 1418 "cminus.tab.c"
    break;

  case 23: /* statement: compound_decl  */
#line 228 "cminus.y"
                    { (yyval.ast) = (yyvsp[0].ast); }
#line 1424 "cminus.tab.c"
    break;

  case 24: /* statement: selection_decl  */
#line 229 "cminus.y"
                     { (yyval.ast) = (yyvsp[0].ast); }
#line 1430 "cminus.tab.c"
    break;

  case 25: /* statement: iteration_decl  */
#line 230 "cminus.y"
                     { (yyval.ast) = (yyvsp[0].ast); }
#line 1436 "cminus.tab.c"
    break;

  case 26: /* statement: return_decl  */
#line 231 "cminus.y"
                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1442 "cminus.tab.c"
    break;

  case 27: /* selection_decl: IF '(' expression ')' statement  */
#line 236 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_OP, "if", 0);
       addChild((yyval.ast), (yyvsp[-2].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1452 "cminus.tab.c"
    break;

  case 28: /* selection_decl: IF '(' expression ')' statement ELSE statement  */
#line 242 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_OP, "if-else", 0);
       addChild((yyval.ast), (yyvsp[-4].ast));
       addChild((yyval.ast), (yyvsp[-2].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1463 "cminus.tab.c"
    break;

  case 29: /* iteration_decl: WHILE '(' expression ')' statement  */
#line 252 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_OP, "while", 0);
       addChild((yyval.ast), (yyvsp[-2].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1473 "cminus.tab.c"
    break;

  case 30: /* return_decl: RETURN ';'  */
#line 261 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_OP, "return", 0);
    }
#line 1481 "cminus.tab.c"
    break;

  case 31: /* return_decl: RETURN expression ';'  */
#line 265 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_OP, "return", 0);
       addChild((yyval.ast), (yyvsp[-1].ast));
    }
#line 1490 "cminus.tab.c"
    break;

  case 32: /* expression_decl: expression ';'  */
#line 273 "cminus.y"
    { (yyval.ast) = newASTNode(NODE_EXPRESSION_DECL, "expr_decl", 0); addChild((yyval.ast), (yyvsp[-1].ast)); }
#line 1496 "cminus.tab.c"
    break;

  case 33: /* expression_decl: ';'  */
#line 275 "cminus.y"
    { (yyval.ast) = newASTNode(NODE_EXPRESSION_DECL, "empty_expr", 0); }
#line 1502 "cminus.tab.c"
    break;

  case 34: /* expression: var '=' expression  */
#line 280 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_OP, "=", 0);
       addChild((yyval.ast), (yyvsp[-2].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1512 "cminus.tab.c"
    break;

  case 35: /* expression: simple_expression  */
#line 285 "cminus.y"
                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1518 "cminus.tab.c"
    break;

  case 36: /* var: ID  */
#line 290 "cminus.y"
    {
      Simbolo *s = buscaSimbolo((yyvsp[0].id), escopoAtual);
      if (!s) {
          s = buscaSimbolo((yyvsp[0].id), "global");
      }
      if (!s) {
          fprintf(stderr, "ERRO SEMANTICO: Variavel \"%s\" nao declarada. Linha: %d\n", (yyvsp[0].id), yylineno);
          exit(1);
      }
      (yyval.ast) = newASTNode(NODE_ID, (yyvsp[0].id), 0);
      free((yyvsp[0].id));
    }
#line 1535 "cminus.tab.c"
    break;

  case 37: /* var: ID '[' expression ']'  */
#line 303 "cminus.y"
    {
      Simbolo *s = buscaSimbolo((yyvsp[-3].id), escopoAtual);
      if (!s) {
          s = buscaSimbolo((yyvsp[-3].id), "global");
      }
      if (!s) {
          fprintf(stderr, "ERRO SEMANTICO: Array \"%s\" nao declarado. Linha: %d\n", (yyvsp[-3].id), yylineno);
          exit(1);
      }
      (yyval.ast) = newASTNode(NODE_OP, "array", 0);
      addChild((yyval.ast), newASTNode(NODE_ID, (yyvsp[-3].id), 0));
      addChild((yyval.ast), (yyvsp[-1].ast));
      free((yyvsp[-3].id));
    }
#line 1554 "cminus.tab.c"
    break;

  case 38: /* activation: ID '(' args ')'  */
#line 321 "cminus.y"
    {
         Simbolo *s = buscaSimbolo((yyvsp[-3].id), "global");
         if (!s) {
             fprintf(stderr, "ERRO SEMANTICO: Funcao \"%s\" nao declarada. Linha: %d\n", (yyvsp[-3].id), yylineno);
             exit(1);
         }
         (yyval.ast) = newASTNode(NODE_ACTIVATION, (yyvsp[-3].id), 0);
         addChild((yyval.ast), (yyvsp[-1].ast));
         free((yyvsp[-3].id));
    }
#line 1569 "cminus.tab.c"
    break;

  case 39: /* args: arg_list  */
#line 334 "cminus.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1575 "cminus.tab.c"
    break;

  case 40: /* args: %empty  */
#line 335 "cminus.y"
                  { (yyval.ast) = newASTNode(NODE_ARGS, "args", 0); }
#line 1581 "cminus.tab.c"
    break;

  case 41: /* arg_list: arg_list ',' expression  */
#line 340 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_ARG_LIST, "arg_list", 0);
       addChild((yyval.ast), (yyvsp[-2].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1591 "cminus.tab.c"
    break;

  case 42: /* arg_list: expression  */
#line 346 "cminus.y"
    { (yyval.ast) = newASTNode(NODE_ARG_LIST, "arg_list", 0); addChild((yyval.ast), (yyvsp[0].ast)); }
#line 1597 "cminus.tab.c"
    break;

  case 43: /* simple_expression: additive_expression  */
#line 350 "cminus.y"
                        { (yyval.ast) = (yyvsp[0].ast); }
#line 1603 "cminus.tab.c"
    break;

  case 44: /* simple_expression: additive_expression relop additive_expression  */
#line 352 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_OP, (yyvsp[-1].id), 0);
       addChild((yyval.ast), (yyvsp[-2].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1613 "cminus.tab.c"
    break;

  case 45: /* relop: EQ  */
#line 360 "cminus.y"
       { (yyval.id) = strdup("=="); }
#line 1619 "cminus.tab.c"
    break;

  case 46: /* relop: NE  */
#line 361 "cminus.y"
         { (yyval.id) = strdup("!="); }
#line 1625 "cminus.tab.c"
    break;

  case 47: /* relop: LE  */
#line 362 "cminus.y"
         { (yyval.id) = strdup("<="); }
#line 1631 "cminus.tab.c"
    break;

  case 48: /* relop: '<'  */
#line 363 "cminus.y"
          { (yyval.id) = strdup("<"); }
#line 1637 "cminus.tab.c"
    break;

  case 49: /* relop: GE  */
#line 364 "cminus.y"
         { (yyval.id) = strdup(">="); }
#line 1643 "cminus.tab.c"
    break;

  case 50: /* relop: '>'  */
#line 365 "cminus.y"
          { (yyval.id) = strdup(">"); }
#line 1649 "cminus.tab.c"
    break;

  case 51: /* additive_expression: additive_expression '+' term  */
#line 370 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_OP, "+", 0);
       addChild((yyval.ast), (yyvsp[-2].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1659 "cminus.tab.c"
    break;

  case 52: /* additive_expression: additive_expression '-' term  */
#line 376 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_OP, "-", 0);
       addChild((yyval.ast), (yyvsp[-2].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1669 "cminus.tab.c"
    break;

  case 53: /* additive_expression: term  */
#line 381 "cminus.y"
           { (yyval.ast) = (yyvsp[0].ast); }
#line 1675 "cminus.tab.c"
    break;

  case 54: /* term: term '*' factor  */
#line 386 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_OP, "*", 0);
       addChild((yyval.ast), (yyvsp[-2].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1685 "cminus.tab.c"
    break;

  case 55: /* term: term '/' factor  */
#line 392 "cminus.y"
    {
       (yyval.ast) = newASTNode(NODE_OP, "/", 0);
       addChild((yyval.ast), (yyvsp[-2].ast));
       addChild((yyval.ast), (yyvsp[0].ast));
    }
#line 1695 "cminus.tab.c"
    break;

  case 56: /* term: factor  */
#line 397 "cminus.y"
             { (yyval.ast) = (yyvsp[0].ast); }
#line 1701 "cminus.tab.c"
    break;

  case 57: /* factor: '(' expression ')'  */
#line 401 "cminus.y"
                       { (yyval.ast) = (yyvsp[-1].ast); }
#line 1707 "cminus.tab.c"
    break;

  case 58: /* factor: activation  */
#line 402 "cminus.y"
                 { (yyval.ast) = (yyvsp[0].ast); }
#line 1713 "cminus.tab.c"
    break;

  case 59: /* factor: var  */
#line 403 "cminus.y"
          { (yyval.ast) = (yyvsp[0].ast); }
#line 1719 "cminus.tab.c"
    break;

  case 60: /* factor: NUM  */
#line 404 "cminus.y"
          { (yyval.ast) = newASTNode(NODE_NUM, NULL, (yyvsp[0].num)); }
#line 1725 "cminus.tab.c"
    break;

  case 61: /* type_specifier: INT  */
#line 408 "cminus.y"
        { (yyval.tipoToken) = TIPO_INT; }
#line 1731 "cminus.tab.c"
    break;

  case 62: /* type_specifier: VOID  */
#line 409 "cminus.y"
           { (yyval.tipoToken) = TIPO_VOID; }
#line 1737 "cminus.tab.c"
    break;


#line 1741 "cminus.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 412 "cminus.y"


void yyerror(const char *s) {
    fprintf(stderr, "ERRO SINTATICO: %s na linha %d\n", s, yylineno);
    exit(1);
}

ASTNode* parsear(void) {
    initSymbolTable();

    insereSimbolo("input", TIPO_INT, "global");
    insereSimbolo("output", TIPO_VOID, "global");
    strcpy(escopoAtual, "global");

    if (!yyparse())
        return arvoreAST;
    else
        return NULL;
}
