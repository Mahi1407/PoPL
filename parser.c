
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lexer.c"
    #include "calc3.h"
    void yyerror(const char *s);
    int yylex();
    int yywrap();
    int add(char);
    void insert_type();
    int search(char *);
	void insert_type();
	void print_tree(struct node*);
	void print_inorder(struct node *);
    int check_declaration(char *);
	int get_index(char *);
	void check_return_type(char *);
	int check_types(char *, char *);
	char *get_type(char *);
	struct node* mknode(struct node *left, struct node *right, char *name);
    int count=0;
	int syn_error=0;
    int q;
	char type[10];
    extern int countn;
	struct node *head;
	int sem_errors=0;
	int label=0;
	char buff[100];
	char errors[10][100];
	char reserved[20][10] = {"numeric", "decimal", "char", "back", "when", "other_wise", "loop", "main", "back", "include","case","default"};
	int gg;



/* Line 189 of yacc.c  */
#line 111 "parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VOID = 258,
     CHARACTER = 259,
     PRINTFF = 260,
     SCANFF = 261,
     INT = 262,
     FLOAT = 263,
     CHAR = 264,
     FOR = 265,
     IF = 266,
     ELSE = 267,
     TRUE = 268,
     FALSE = 269,
     NUMBER = 270,
     FLOAT_NUM = 271,
     ID = 272,
     LE = 273,
     GE = 274,
     EQ = 275,
     NE = 276,
     GT = 277,
     LT = 278,
     AND = 279,
     OR = 280,
     STR = 281,
     ADD = 282,
     MULTIPLY = 283,
     DIVIDE = 284,
     SUBTRACT = 285,
     UNARY = 286,
     INCLUDE = 287,
     RETURN = 288,
     WHILE = 289,
     SWITCH = 290,
     CASE = 291,
     BREAK = 292,
     DEFAULT = 293,
     ELSEIF = 294
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 38 "parser.y"
 
		struct var_name { 
			char name[100]; 
			struct node* nd;
		} nd_obj;
		struct var_name2 { 
			char name[100]; 
			struct node* nd;
			char type[5];
		} nd_obj2; 
		
	


/* Line 214 of yacc.c  */
#line 201 "parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 213 "parser.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   428

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  155

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,     2,
      40,    41,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    46,
       2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    12,    15,    16,    19,    22,    24,    26,
      28,    30,    32,    33,    34,    47,    48,    57,    58,    67,
      68,    78,    81,    83,    84,    94,    95,    96,   100,   101,
     108,   111,   112,   118,   121,   122,   132,   133,   139,   140,
     144,   146,   148,   150,   151,   152,   158,   163,   168,   172,
     176,   177,   178,   184,   185,   190,   193,   194,   198,   200,
     202,   204,   206,   208,   210,   212,   214,   216,   218,   220,
     222,   224,   226,   228,   229
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    53,    40,    41,    42,    56,    84,
      43,    -1,    51,    51,    -1,    -1,    32,    52,    -1,    54,
      17,    -1,     7,    -1,     8,    -1,     9,    -1,     3,    -1,
      74,    -1,    -1,    -1,    10,    57,    40,    55,    73,    72,
      73,    55,    41,    42,    56,    43,    -1,    -1,    35,    58,
      40,    83,    41,    42,    68,    43,    -1,    -1,    34,    59,
      40,    72,    41,    42,    56,    43,    -1,    -1,    11,    60,
      40,    72,    41,    42,    56,    43,    69,    -1,    56,    56,
      -1,    74,    -1,    -1,     6,    61,    40,    26,    44,    45,
      17,    41,    46,    -1,    -1,    -1,    37,    63,    46,    -1,
      -1,    36,    65,    83,    47,    56,    62,    -1,    64,    64,
      -1,    -1,    38,    67,    47,    56,    62,    -1,    64,    66,
      -1,    -1,    39,    70,    40,    72,    41,    42,    56,    43,
      69,    -1,    -1,    12,    71,    42,    56,    43,    -1,    -1,
      80,    82,    80,    -1,    13,    -1,    14,    -1,    46,    -1,
      -1,    -1,    54,    17,    75,    79,    73,    -1,    17,    48,
      80,    73,    -1,    80,    82,    80,    46,    -1,    17,    31,
      73,    -1,    31,    17,    73,    -1,    -1,    -1,     5,    76,
      17,    77,    46,    -1,    -1,     5,    78,    83,    46,    -1,
      48,    83,    -1,    -1,    80,    81,    80,    -1,    83,    -1,
      27,    -1,    30,    -1,    28,    -1,    29,    -1,    23,    -1,
      22,    -1,    18,    -1,    19,    -1,    20,    -1,    21,    -1,
      15,    -1,    16,    -1,     4,    -1,    17,    -1,    -1,    33,
      85,    83,    46,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    59,    59,    61,    62,    62,    65,    68,    69,    70,
      71,    74,    75,    78,    78,    83,    83,    86,    86,    89,
      89,    93,    94,    95,    95,    96,    99,    99,   101,   101,
     105,   108,   108,   113,   116,   116,   120,   120,   121,   125,
     126,   127,   133,   134,   137,   137,   173,   223,   224,   237,
     247,   247,   247,   256,   256,   261,   262,   265,   303,   306,
     307,   308,   309,   312,   313,   314,   315,   316,   317,   320,
     321,   322,   323,   337,   337
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "CHARACTER", "PRINTFF", "SCANFF",
  "INT", "FLOAT", "CHAR", "FOR", "IF", "ELSE", "TRUE", "FALSE", "NUMBER",
  "FLOAT_NUM", "ID", "LE", "GE", "EQ", "NE", "GT", "LT", "AND", "OR",
  "STR", "ADD", "MULTIPLY", "DIVIDE", "SUBTRACT", "UNARY", "INCLUDE",
  "RETURN", "WHILE", "SWITCH", "CASE", "BREAK", "DEFAULT", "ELSEIF", "'('",
  "')'", "'{'", "'}'", "','", "'&'", "';'", "':'", "'='", "$accept",
  "program", "headers", "$@1", "main", "datatype", "temp1", "body", "$@2",
  "$@3", "$@4", "$@5", "$@6", "break", "$@7", "case", "$@8", "default",
  "$@9", "caselist", "elseif", "$@10", "$@11", "condition", "temp2",
  "statement", "$@12", "$@13", "$@14", "$@15", "init", "expression",
  "arithmetic", "relop", "value", "return", "$@16", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      40,    41,   123,   125,    44,    38,    59,    58,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    52,    51,    53,    54,    54,    54,
      54,    55,    55,    57,    56,    58,    56,    59,    56,    60,
      56,    56,    56,    61,    56,    56,    63,    62,    65,    64,
      64,    67,    66,    68,    70,    69,    71,    69,    69,    72,
      72,    72,    73,    73,    75,    74,    74,    74,    74,    74,
      76,    77,    74,    78,    74,    79,    79,    80,    80,    81,
      81,    81,    81,    82,    82,    82,    82,    82,    82,    83,
      83,    83,    83,    85,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     8,     2,     0,     2,     2,     1,     1,     1,
       1,     1,     0,     0,    12,     0,     8,     0,     8,     0,
       9,     2,     1,     0,     9,     0,     0,     3,     0,     6,
       2,     0,     5,     2,     0,     9,     0,     5,     0,     3,
       1,     1,     1,     0,     0,     5,     4,     4,     3,     3,
       0,     0,     5,     0,     4,     2,     0,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     0,     5,     1,    10,     7,     8,     9,
       3,     0,     0,     0,     6,     0,    25,    71,    53,    23,
      13,    19,    69,    70,    72,     0,    17,    15,     0,     0,
      22,     0,    58,     0,     0,     0,     0,     0,    43,     0,
      43,     0,     0,    44,    73,    21,     0,    65,    66,    67,
      68,    64,    63,    59,    61,    62,    60,     0,     0,    51,
      72,     0,     0,    12,     0,    42,    48,    43,    49,     0,
       0,    56,     0,     2,    57,     0,     0,    54,     0,    43,
      11,    40,    41,     0,     0,    46,     0,     0,     0,    43,
       0,    47,    52,     0,     0,     0,     0,     0,     0,    55,
      45,    74,     0,    43,    25,    39,    25,     0,     0,    12,
       0,     0,    28,     0,     0,     0,     0,    38,    18,     0,
      31,    30,    33,    16,    24,     0,    36,    34,    20,     0,
       0,    25,     0,     0,    25,    25,     0,    25,     0,     0,
       0,    14,     0,     0,    26,    29,    32,    37,     0,     0,
      25,    27,     0,    38,    35
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    10,     4,    11,    28,    79,    45,    36,    42,
      41,    37,    35,   145,   149,   121,   119,   122,   130,   114,
     128,   133,   132,    83,    66,    30,    71,    33,    76,    34,
      89,    31,    57,    58,    32,    46,    72
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const yytype_int16 yypact[] =
{
     -14,   -68,    21,     0,   -68,   -68,   -68,   -68,   -68,   -68,
     -14,   -11,    23,    -3,   -68,     1,   393,   -68,    34,   -68,
     -68,   -68,   -68,   -68,   -26,    36,   -68,   -68,    37,   360,
     -68,    74,   -68,    38,    59,    22,    25,    32,    15,    59,
      15,    41,    42,   -68,   -68,   393,    40,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,    59,    59,   -68,
     -68,    39,    58,     8,    53,   -68,   -68,     6,   -68,    53,
      59,    51,    59,   -68,    50,    18,    43,   -68,    54,    15,
     -68,   -68,   -68,    45,    74,   -68,    46,    64,    59,    15,
      60,   -68,   -68,    62,    53,    66,    59,    67,    68,   -68,
     -68,   -68,    94,    15,   393,    50,   393,    76,    72,     8,
     120,   161,   -68,    -8,    71,    70,    79,     2,   -68,    59,
     -68,    76,   -68,   -68,   -68,    75,   -68,   -68,   -68,    85,
      86,   393,    80,    98,   393,   393,   202,   393,    53,   325,
     325,   -68,   243,    99,   -68,   -68,   -68,   -68,    97,    95,
     393,   -68,   284,     2,   -68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   142,   -68,   -68,   140,    35,   -16,   -68,   -68,
     -68,   -68,   -68,     5,   -68,    49,   -68,   -68,   -68,   -68,
      -7,   -68,   -68,   -67,   -30,   -59,   -68,   -68,   -68,   -68,
     -68,   -38,   -68,    63,   -28,   -68,   -68
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -51
static const yytype_int16 yytable[] =
{
      29,    67,    86,     6,    80,    38,    61,     7,     8,     9,
      68,     6,    17,    18,   126,     7,     8,     9,     1,    74,
      75,     5,    39,    22,    23,    24,    84,   103,   112,    13,
     120,    84,     1,    53,    54,    55,    56,    85,    15,    25,
      14,   127,    87,    16,    90,    53,    54,    55,    56,    94,
      80,   -50,    65,    40,    43,    59,    84,    17,   105,   100,
      99,    65,    62,    17,    91,    63,    81,    82,    22,    23,
      60,   143,    64,   109,    22,    23,    60,    53,    54,    55,
      56,    69,    70,    73,    78,    77,    95,    97,   110,    92,
     111,   129,    47,    48,    49,    50,    51,    52,    93,    88,
      84,    53,    54,    55,    56,    98,   101,   102,   104,   106,
     107,   108,   112,   115,   123,   136,   124,   131,   139,   140,
     125,   142,   137,     6,    17,    18,    19,     7,     8,     9,
      20,    21,   134,   135,   152,    22,    23,    24,   138,   150,
     148,   151,     3,    12,   116,   146,   154,    96,     0,     0,
       0,    25,     0,     0,    26,    27,   113,     0,     0,     0,
       0,     0,     0,   117,     6,    17,    18,    19,     7,     8,
       9,    20,    21,     0,     0,     0,    22,    23,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,     0,    26,    27,     0,     0,     0,
       0,     0,     0,     0,   118,     6,    17,    18,    19,     7,
       8,     9,    20,    21,     0,     0,     0,    22,    23,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,     0,     0,    26,    27,     0,     0,
       0,     0,     0,     0,     0,   141,     6,    17,    18,    19,
       7,     8,     9,    20,    21,     0,     0,     0,    22,    23,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,     0,    26,    27,     0,
       0,     0,     0,     0,     0,     0,   147,     6,    17,    18,
      19,     7,     8,     9,    20,    21,     0,     0,     0,    22,
      23,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,     0,     0,    26,    27,
       0,     0,     0,     0,     0,     0,     0,   153,     6,    17,
      18,    19,     7,     8,     9,    20,    21,     0,     0,     0,
      22,    23,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,     0,    26,
      27,     0,   144,     6,    17,    18,    19,     7,     8,     9,
      20,    21,     0,     0,     0,    22,    23,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    44,    26,    27,     6,    17,    18,    19,
       7,     8,     9,    20,    21,     0,     0,     0,    22,    23,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,     0,     0,    26,    27
};

static const yytype_int16 yycheck[] =
{
      16,    39,    69,     3,    63,    31,    34,     7,     8,     9,
      40,     3,     4,     5,    12,     7,     8,     9,    32,    57,
      58,     0,    48,    15,    16,    17,    64,    94,    36,    40,
      38,    69,    32,    27,    28,    29,    30,    67,    41,    31,
      17,    39,    70,    42,    72,    27,    28,    29,    30,    79,
     109,    17,    46,    17,    17,    17,    94,     4,    96,    89,
      88,    46,    40,     4,    46,    40,    13,    14,    15,    16,
      17,   138,    40,   103,    15,    16,    17,    27,    28,    29,
      30,    40,    40,    43,    26,    46,    41,    41,   104,    46,
     106,   119,    18,    19,    20,    21,    22,    23,    44,    48,
     138,    27,    28,    29,    30,    41,    46,    45,    42,    42,
      42,    17,    36,    41,    43,   131,    46,    42,   134,   135,
      41,   137,    42,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    47,    47,   150,    15,    16,    17,    40,    42,
      41,    46,     0,     3,   109,   140,   153,    84,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,   107,    -1,    -1,    -1,
      -1,    -1,    -1,    43,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    -1,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    -1,    37,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,    34,    35,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    32,    50,    51,    52,     0,     3,     7,     8,     9,
      51,    53,    54,    40,    17,    41,    42,     4,     5,     6,
      10,    11,    15,    16,    17,    31,    34,    35,    54,    56,
      74,    80,    83,    76,    78,    61,    57,    60,    31,    48,
      17,    59,    58,    17,    33,    56,    84,    18,    19,    20,
      21,    22,    23,    27,    28,    29,    30,    81,    82,    17,
      17,    83,    40,    40,    40,    46,    73,    80,    73,    40,
      40,    75,    85,    43,    80,    80,    77,    46,    26,    55,
      74,    13,    14,    72,    80,    73,    72,    83,    48,    79,
      83,    46,    46,    44,    73,    41,    82,    41,    41,    83,
      73,    46,    45,    72,    42,    80,    42,    42,    17,    73,
      56,    56,    36,    64,    68,    41,    55,    43,    43,    65,
      38,    64,    66,    43,    46,    41,    12,    39,    69,    83,
      67,    42,    71,    70,    47,    47,    56,    42,    40,    56,
      56,    43,    56,    72,    37,    62,    62,    43,    41,    63,
      42,    46,    56,    43,    69
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 59 "parser.y"
    { (yyvsp[(2) - (8)].nd_obj).nd = mknode((yyvsp[(6) - (8)].nd_obj).nd, (yyvsp[(7) - (8)].nd_obj).nd, "main"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (8)].nd_obj).nd, (yyvsp[(2) - (8)].nd_obj).nd, "program");head = (yyval.nd_obj).nd;;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 61 "parser.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "headers"); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 62 "parser.y"
    { add('H'); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 62 "parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (2)].nd_obj).name); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 65 "parser.y"
    { add('F');  ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 68 "parser.y"
    { insert_type(); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 69 "parser.y"
    { insert_type(); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 70 "parser.y"
    { insert_type(); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 71 "parser.y"
    { insert_type(); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 74 "parser.y"
    {printf("ef \n");(yyval.nd_obj).nd=(yyvsp[(1) - (1)].nd_obj).nd;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 75 "parser.y"
    {printf("eef \n");(yyval.nd_obj).nd=NULL;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    { add('K'); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    { 
	struct node *temp = mknode((yyvsp[(6) - (12)].nd_obj).nd, (yyvsp[(8) - (12)].nd_obj).nd, "CONDITION"); 
	struct node *temp2 = mknode((yyvsp[(4) - (12)].nd_obj).nd, temp, "CONDITION"); 
	(yyval.nd_obj).nd = mknode(temp2, (yyvsp[(11) - (12)].nd_obj).nd, (yyvsp[(1) - (12)].nd_obj).name); 
;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    { add('K'); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    {
	(yyval.nd_obj).nd = mknode((yyvsp[(4) - (8)].nd_obj2).nd, (yyvsp[(7) - (8)].nd_obj).nd, (yyvsp[(1) - (8)].nd_obj).name); 
;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 86 "parser.y"
    { add('K'); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 86 "parser.y"
    { 
	(yyval.nd_obj).nd = mknode((yyvsp[(4) - (8)].nd_obj).nd, (yyvsp[(7) - (8)].nd_obj).nd, (yyvsp[(1) - (8)].nd_obj).name); 
;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    { add('K'); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    { 
	struct node *iff = mknode((yyvsp[(4) - (9)].nd_obj).nd, (yyvsp[(7) - (9)].nd_obj).nd, (yyvsp[(1) - (9)].nd_obj).name);
	(yyval.nd_obj).nd = mknode(iff, (yyvsp[(9) - (9)].nd_obj).nd, "when-other_wise");
;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    {(yyval.nd_obj).nd = mknode((yyvsp[(1) - (2)].nd_obj).nd, (yyvsp[(2) - (2)].nd_obj).nd, "statements");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    {(yyval.nd_obj).nd=(yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    { add('K'); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    { (yyval.nd_obj).nd = mknode(NULL, NULL, "scanf"); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    {(yyval.nd_obj).nd=NULL;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    { add('K'); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    {(yyval.nd_obj).nd=mknode(NULL,NULL,"break");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    { add('K'); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 101 "parser.y"
    {
	struct node *temp=mknode((yyvsp[(5) - (6)].nd_obj).nd,(yyvsp[(6) - (6)].nd_obj).nd,"case_body");
	(yyval.nd_obj).nd=mknode((yyvsp[(3) - (6)].nd_obj2).nd,temp,(yyvsp[(1) - (6)].nd_obj).name);
;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    {(yyval.nd_obj).nd=mknode((yyvsp[(1) - (2)].nd_obj).nd,(yyvsp[(2) - (2)].nd_obj).nd,"cases");}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {add('K');}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {
	struct node *temp=mknode((yyvsp[(4) - (5)].nd_obj).nd,(yyvsp[(5) - (5)].nd_obj).nd,"case_body");
	(yyval.nd_obj).nd=mknode(NULL,temp,(yyvsp[(1) - (5)].nd_obj).name)
;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {(yyval.nd_obj).nd=mknode((yyvsp[(1) - (2)].nd_obj).nd,(yyvsp[(2) - (2)].nd_obj).nd,"caselist");}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    { add('K'); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 116 "parser.y"
    {
	struct node *elif = mknode((yyvsp[(4) - (9)].nd_obj).nd, (yyvsp[(7) - (9)].nd_obj).nd, (yyvsp[(1) - (9)].nd_obj).name); 
	(yyval.nd_obj).nd = mknode(elif, (yyvsp[(9) - (9)].nd_obj).nd,"when-other_wise");
;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    { add('K'); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(4) - (5)].nd_obj).nd,NULL, (yyvsp[(1) - (5)].nd_obj).name); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 121 "parser.y"
    { (yyval.nd_obj).nd =NULL;;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    { (yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj2).nd, (yyvsp[(3) - (3)].nd_obj2).nd, (yyvsp[(2) - (3)].nd_obj).nd->name);  ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    { add('K'); (yyval.nd_obj).nd = NULL; ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 127 "parser.y"
    { add('K'); (yyval.nd_obj).nd = NULL; ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    {(yyval.nd_obj).nd = NULL; ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    { printf("bbb came\n");(yyval.nd_obj).nd = NULL ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    {add('V'); gg=get_index((yyvsp[(2) - (2)].nd_obj).name);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    { 
	(yyvsp[(2) - (5)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(2) - (5)].nd_obj).name); 
	(yyvsp[(2) - (5)].nd_obj).nd->index=gg;
	(yyvsp[(2) - (5)].nd_obj).nd->name="Variable";
	(yyvsp[(2) - (5)].nd_obj).nd->id_name=(yyvsp[(1) - (5)].nd_obj).name;
	int t = check_types((yyvsp[(1) - (5)].nd_obj).name, (yyvsp[(4) - (5)].nd_obj2).type);
	if(t>0) { 
		if(t == 1) {
			struct node *temp = mknode(NULL, (yyvsp[(4) - (5)].nd_obj2).nd, "decimal_to_numeric"); 
			(yyval.nd_obj).nd = mknode((yyvsp[(2) - (5)].nd_obj).nd, temp, "declaration"); 
		} 
		else if(t == 2) { 
			struct node *temp = mknode(NULL, (yyvsp[(4) - (5)].nd_obj2).nd, "numeric_to_decimal"); 
			(yyval.nd_obj).nd = mknode((yyvsp[(2) - (5)].nd_obj).nd, temp, "declaration"); 
		} 
		else if(t == 3) { 
			struct node *temp = mknode(NULL, (yyvsp[(4) - (5)].nd_obj2).nd, "char_to_numeric"); 
			(yyval.nd_obj).nd = mknode((yyvsp[(2) - (5)].nd_obj).nd, temp, "declaration"); 
		} 
		else if(t == 4) { 
			struct node *temp = mknode(NULL, (yyvsp[(4) - (5)].nd_obj2).nd, "numeric_to_char"); 
			(yyval.nd_obj).nd = mknode((yyvsp[(2) - (5)].nd_obj).nd, temp, "declaration"); 
		} 
		else if(t == 5) { 
			struct node *temp = mknode(NULL, (yyvsp[(4) - (5)].nd_obj2).nd, "char_to_decimal"); 
			(yyval.nd_obj).nd = mknode((yyvsp[(2) - (5)].nd_obj).nd, temp, "declaration"); 
		} 
		else{
			struct node *temp = mknode(NULL, (yyvsp[(4) - (5)].nd_obj2).nd, "decimal_to_char"); 
			(yyval.nd_obj).nd = mknode((yyvsp[(2) - (5)].nd_obj).nd, temp, "declaration"); 
		}
	} 
	else { 
		(yyval.nd_obj).nd = mknode((yyvsp[(2) - (5)].nd_obj).nd, (yyvsp[(4) - (5)].nd_obj2).nd, "declaration"); 
	} 
;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 173 "parser.y"
    {
	int u=check_declaration((yyvsp[(1) - (4)].nd_obj).name);
	(yyvsp[(1) - (4)].nd_obj).nd = mknode(NULL, NULL,(yyvsp[(1) - (4)].nd_obj).name);
	gg=get_index((yyvsp[(1) - (4)].nd_obj).name);
	(yyvsp[(1) - (4)].nd_obj).nd->index=gg;
	(yyvsp[(1) - (4)].nd_obj).nd->id_name=(yyvsp[(1) - (4)].nd_obj).name;
	(yyvsp[(1) - (4)].nd_obj).nd->name="Variable";
	if(u){
		printf("enter\n");
		char *id_type = get_type((yyvsp[(1) - (4)].nd_obj).name);
	
		if(strcmp(id_type, (yyvsp[(3) - (4)].nd_obj2).type)) {
			if(!strcmp(id_type, "numeric")) {
				if(!strcmp((yyvsp[(3) - (4)].nd_obj2).type, "float")){
					struct node *temp = mknode(NULL, (yyvsp[(3) - (4)].nd_obj2).nd, "decimal_to_numeric");
					(yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, temp, "assignment"); 
				}
				else{
					struct node *temp = mknode(NULL, (yyvsp[(3) - (4)].nd_obj2).nd, "char_to_numeric");
					(yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, temp, "assignment"); 
				}
				
			}
			else if(!strcmp(id_type, "float")) {
				if(!strcmp((yyvsp[(3) - (4)].nd_obj2).type, "numeric")){
					struct node *temp = mknode(NULL, (yyvsp[(3) - (4)].nd_obj2).nd, "numeric_to_decimal");
					(yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, temp, "assignment"); 
				}
				else{
					struct node *temp = mknode(NULL, (yyvsp[(3) - (4)].nd_obj2).nd, "char_to_decimal");
					(yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, temp, "assignment"); 
				}
				
			}
			else{
				if(!strcmp((yyvsp[(3) - (4)].nd_obj2).type, "numeric")){
					struct node *temp = mknode(NULL, (yyvsp[(3) - (4)].nd_obj2).nd, "numeric_to_char");
					(yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, temp, "assignment"); 
				}
				else{
					struct node *temp = mknode(NULL, (yyvsp[(3) - (4)].nd_obj2).nd, "decimal_to_char");
					(yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, temp, "assignment"); 
				}
			}
		}
	}
	else {
		(yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, (yyvsp[(3) - (4)].nd_obj2).nd, "assignment"); 
	}
;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 223 "parser.y"
    {  (yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj2).nd, (yyvsp[(3) - (4)].nd_obj2).nd, (yyvsp[(2) - (4)].nd_obj).nd->name); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    { 
	 
	check_declaration((yyvsp[(1) - (3)].nd_obj).name);
	(yyvsp[(1) - (3)].nd_obj).nd = mknode(NULL, NULL,(yyvsp[(1) - (3)].nd_obj).name);
	gg=get_index((yyvsp[(1) - (3)].nd_obj).name);
	(yyvsp[(1) - (3)].nd_obj).nd->index=gg;
	(yyvsp[(1) - (3)].nd_obj).nd->id_name=(yyvsp[(1) - (3)].nd_obj).name;
	(yyvsp[(1) - (3)].nd_obj).nd->name="Variable";
	printf("www %s %s\n",(yyvsp[(1) - (3)].nd_obj).name,(yyvsp[(2) - (3)].nd_obj).name);
	(yyvsp[(2) - (3)].nd_obj).nd=mknode(NULL,NULL,(yyvsp[(2) - (3)].nd_obj).name);
	(yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).nd,"post_inc"); 
	printf("wwf %s %s\n",(yyvsp[(1) - (3)].nd_obj).name,(yyvsp[(2) - (3)].nd_obj).name);
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    { 
	check_declaration((yyvsp[(2) - (3)].nd_obj).name); 
	(yyvsp[(1) - (3)].nd_obj).nd = mknode(NULL, NULL,(yyvsp[(1) - (3)].nd_obj).name);
	(yyvsp[(2) - (3)].nd_obj).nd = mknode(NULL, NULL,(yyvsp[(2) - (3)].nd_obj).name);
	gg=get_index((yyvsp[(2) - (3)].nd_obj).name);
	(yyvsp[(2) - (3)].nd_obj).nd->index=gg;
	(yyvsp[(2) - (3)].nd_obj).nd->id_name=(yyvsp[(2) - (3)].nd_obj).name;
	(yyvsp[(2) - (3)].nd_obj).nd->name="Variable";
	(yyval.nd_obj).nd = mknode((yyvsp[(1) - (3)].nd_obj).nd, (yyvsp[(2) - (3)].nd_obj).nd, "pre_inc"); 
;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    { add('K'); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    {gg=get_index((yyvsp[(3) - (3)].nd_obj).name);}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    {
	 (yyvsp[(3) - (5)].nd_obj).nd = mknode(NULL, NULL,"Variable");
	 (yyvsp[(3) - (5)].nd_obj).nd->index=gg;
	 (yyvsp[(3) - (5)].nd_obj).nd->ty=symbol_table[gg].data_type;
	 (yyvsp[(3) - (5)].nd_obj).nd->i=symbol_table[gg].i;
	 (yyvsp[(3) - (5)].nd_obj).nd->f=symbol_table[gg].i;
	 (yyvsp[(3) - (5)].nd_obj).nd->c=symbol_table[gg].i;
	 (yyval.nd_obj).nd = mknode((yyvsp[(3) - (5)].nd_obj).nd, NULL, "printf");
;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    { add('K'); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 256 "parser.y"
    {
	(yyval.nd_obj).nd = mknode((yyvsp[(3) - (4)].nd_obj2).nd, NULL, "printf");
;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 261 "parser.y"
    {(yyval.nd_obj2).nd = (yyvsp[(2) - (2)].nd_obj2).nd; sprintf((yyval.nd_obj2).type, (yyvsp[(2) - (2)].nd_obj2).type); strcpy((yyval.nd_obj2).name, (yyvsp[(2) - (2)].nd_obj2).nd->name); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 262 "parser.y"
    {  (yyval.nd_obj2).nd = NULL ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 265 "parser.y"
    { 
	if(!strcmp((yyvsp[(1) - (3)].nd_obj2).type, (yyvsp[(3) - (3)].nd_obj2).type)) {
		sprintf((yyval.nd_obj2).type, (yyvsp[(1) - (3)].nd_obj2).type);
		(yyval.nd_obj2).nd = mknode((yyvsp[(1) - (3)].nd_obj2).nd, (yyvsp[(3) - (3)].nd_obj2).nd, (yyvsp[(2) - (3)].nd_obj).nd->name); 
	}
	else {
		if(!strcmp((yyvsp[(1) - (3)].nd_obj2).type, "numeric") && !strcmp((yyvsp[(3) - (3)].nd_obj2).type, "float")) {
			struct node *temp = mknode(NULL, (yyvsp[(1) - (3)].nd_obj2).nd, "numeric_to_ofloat");
			sprintf((yyval.nd_obj2).type, (yyvsp[(3) - (3)].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[(3) - (3)].nd_obj2).nd, (yyvsp[(2) - (3)].nd_obj).name);
		}
		else if(!strcmp((yyvsp[(1) - (3)].nd_obj2).type, "float") && !strcmp((yyvsp[(3) - (3)].nd_obj2).type, "numeric")) {
			struct node *temp = mknode(NULL, (yyvsp[(3) - (3)].nd_obj2).nd, "numeric_to_float");
			sprintf((yyval.nd_obj2).type, (yyvsp[(1) - (3)].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[(1) - (3)].nd_obj2).nd, temp, (yyvsp[(2) - (3)].nd_obj).name);
		}
		else if(!strcmp((yyvsp[(1) - (3)].nd_obj2).type, "numeric") && !strcmp((yyvsp[(3) - (3)].nd_obj2).type, "char")) {
			struct node *temp = mknode(NULL, (yyvsp[(3) - (3)].nd_obj2).nd, "char_to_numeric");
			sprintf((yyval.nd_obj2).type, (yyvsp[(1) - (3)].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[(1) - (3)].nd_obj2).nd, temp, (yyvsp[(2) - (3)].nd_obj).name);
		}
		else if(!strcmp((yyvsp[(1) - (3)].nd_obj2).type, "char") && !strcmp((yyvsp[(3) - (3)].nd_obj2).type, "numeric")) {
			struct node *temp = mknode(NULL, (yyvsp[(1) - (3)].nd_obj2).nd, "char_to_numeric");
			sprintf((yyval.nd_obj2).type, (yyvsp[(3) - (3)].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[(3) - (3)].nd_obj2).nd, (yyvsp[(2) - (3)].nd_obj).name);
		}
		else if(!strcmp((yyvsp[(1) - (3)].nd_obj2).type, "decimal") && !strcmp((yyvsp[(3) - (3)].nd_obj2).type, "char")) {
			struct node *temp = mknode(NULL, (yyvsp[(3) - (3)].nd_obj2).nd, "char_to_decimal");
			sprintf((yyval.nd_obj2).type, (yyvsp[(1) - (3)].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[(1) - (3)].nd_obj2).nd, temp, (yyvsp[(2) - (3)].nd_obj).name);
		}
		else {
			struct node *temp = mknode(NULL, (yyvsp[(1) - (3)].nd_obj2).nd, "chartofloat");
			sprintf((yyval.nd_obj2).type, (yyvsp[(3) - (3)].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[(3) - (3)].nd_obj2).nd, (yyvsp[(2) - (3)].nd_obj).name);
		}
	}
;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 303 "parser.y"
    {strcpy((yyval.nd_obj2).name, (yyvsp[(1) - (1)].nd_obj2).name); sprintf((yyval.nd_obj2).type, (yyvsp[(1) - (1)].nd_obj2).type); (yyval.nd_obj2).nd = (yyvsp[(1) - (1)].nd_obj2).nd; ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 306 "parser.y"
    {(yyvsp[(1) - (1)].nd_obj).nd=mknode(NULL,NULL,"ADD");(yyval.nd_obj).nd=(yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 307 "parser.y"
    {(yyvsp[(1) - (1)].nd_obj).nd=mknode(NULL,NULL,"SUB");(yyval.nd_obj).nd=(yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 308 "parser.y"
    {(yyvsp[(1) - (1)].nd_obj).nd=mknode(NULL,NULL,"MUL");(yyval.nd_obj).nd=(yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
    {(yyvsp[(1) - (1)].nd_obj).nd=mknode(NULL,NULL,"DIV");(yyval.nd_obj).nd=(yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 312 "parser.y"
    {(yyvsp[(1) - (1)].nd_obj).nd=mknode(NULL,NULL,"LT");(yyval.nd_obj).nd=(yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 313 "parser.y"
    {(yyvsp[(1) - (1)].nd_obj).nd=mknode(NULL,NULL,"GT");(yyval.nd_obj).nd=(yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 314 "parser.y"
    {(yyvsp[(1) - (1)].nd_obj).nd=mknode(NULL,NULL,"LE");(yyval.nd_obj).nd=(yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 315 "parser.y"
    {(yyvsp[(1) - (1)].nd_obj).nd=mknode(NULL,NULL,"GE");(yyval.nd_obj).nd=(yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 316 "parser.y"
    {(yyvsp[(1) - (1)].nd_obj).nd=mknode(NULL,NULL,"EQ");(yyval.nd_obj).nd=(yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 317 "parser.y"
    {(yyvsp[(1) - (1)].nd_obj).nd=mknode(NULL,NULL,"NE");(yyval.nd_obj).nd=(yyvsp[(1) - (1)].nd_obj).nd;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    { (yyvsp[(1) - (1)].nd_obj).nd=mknode(NULL,NULL,"const");(yyvsp[(1) - (1)].nd_obj).nd->name="const";(yyvsp[(1) - (1)].nd_obj).nd->ty="numeric";(yyvsp[(1) - (1)].nd_obj).nd->i=atoi((yyvsp[(1) - (1)].nd_obj).name); strcpy((yyval.nd_obj2).name, (yyvsp[(1) - (1)].nd_obj).name); sprintf((yyval.nd_obj2).type, "numeric"); add('C');(yyval.nd_obj2).nd=(yyvsp[(1) - (1)].nd_obj).nd;  ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    { (yyvsp[(1) - (1)].nd_obj).nd=mknode(NULL,NULL,"const");(yyvsp[(1) - (1)].nd_obj).nd->name="const";(yyvsp[(1) - (1)].nd_obj).nd->ty="float";(yyvsp[(1) - (1)].nd_obj).nd->i=atoi((yyvsp[(1) - (1)].nd_obj).name); strcpy((yyval.nd_obj2).name, (yyvsp[(1) - (1)].nd_obj).name); sprintf((yyval.nd_obj2).type, "float"); add('C');(yyval.nd_obj2).nd=(yyvsp[(1) - (1)].nd_obj).nd;  ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 322 "parser.y"
    { (yyvsp[(1) - (1)].nd_obj).nd=mknode(NULL,NULL,"const");(yyvsp[(1) - (1)].nd_obj).nd->name="const";(yyvsp[(1) - (1)].nd_obj).nd->ty="char";(yyvsp[(1) - (1)].nd_obj).nd->i=atoi((yyvsp[(1) - (1)].nd_obj).name); strcpy((yyval.nd_obj2).name, (yyvsp[(1) - (1)].nd_obj).name); sprintf((yyval.nd_obj2).type, "char"); add('C');(yyval.nd_obj2).nd=(yyvsp[(1) - (1)].nd_obj).nd;  ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    {
	gg=get_index((yyvsp[(1) - (1)].nd_obj).name);
	(yyvsp[(1) - (1)].nd_obj).nd = mknode(NULL, NULL, (yyvsp[(1) - (1)].nd_obj).name);
	(yyvsp[(1) - (1)].nd_obj).nd->id_name=(yyvsp[(1) - (1)].nd_obj).name;
	(yyvsp[(1) - (1)].nd_obj).nd->index=gg;
	(yyvsp[(1) - (1)].nd_obj).nd->name="Variable";
	strcpy((yyval.nd_obj2).name, (yyvsp[(1) - (1)].nd_obj).name); 
	char *id_type = get_type((yyvsp[(1) - (1)].nd_obj).name); 
	sprintf((yyval.nd_obj2).type, id_type); 
	check_declaration((yyvsp[(1) - (1)].nd_obj).name);
	(yyval.nd_obj2).nd=(yyvsp[(1) - (1)].nd_obj).nd;
;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 337 "parser.y"
    { add('K'); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 337 "parser.y"
    { check_return_type((yyvsp[(3) - (4)].nd_obj2).name); (yyvsp[(1) - (4)].nd_obj).nd = mknode(NULL, NULL, "back"); (yyval.nd_obj).nd = mknode((yyvsp[(1) - (4)].nd_obj).nd, (yyvsp[(3) - (4)].nd_obj2).nd, "RETURN"); ;}
    break;



/* Line 1455 of yacc.c  */
#line 2287 "parser.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 341 "parser.y"


int main() {
    yyparse();
    printf("\n\n\n\n\n");
	
	printf("STEP 1: LEXICAL ANALYSIS  \n\n\n");
	
	printf("Processing....\n");
	printf("\nLexical analysis completed with no errors\n");

	printf("\n\n\t\t\t\t\t SYMBOL TABLE \n");
	printf("\n\nSYMBOL   \t\t\t\tDATATYPE   \t\t\t\tTYPE   \t\t\t\t\tLINE NUMBER \n");
	printf("____________________________________________________________________________________________________________________________________________\n\n");
	int i=0;
	
	for(i=0; i<count; i++) {
		printf("%s\t\t\t\t\t%s\t\t\t\t\t%s\t\t\t\t\t%d\t\t\t\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	
	

	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
	printf("\t\t\t\t STEP 2: SYNTAX ANALYSIS \n\n");
	printf("Processing....\n\n");
	if(syn_error){
		printf("Syntax error found at %d ",countn+1);
	}else{
		printf("Syntax analysis is completed with no errors\n\n");

		print_tree(head); 
		printf("\n\n\n\n");
		printf("\t\t\t\t STEP 3: SEMANTIC ANALYSIS \n\n");
		if(sem_errors>0) {
			printf("Semantic analysis completed with %d errors\n", sem_errors);
			for(int i=0; i<sem_errors; i++){
				printf("\t - %s", errors[i]);
			}
		} else {
			printf("Semantic analysis completed with no errors\n\n\n");
		}
	}
	printf("OUTPUT \n\n");
	ex(head);
}

int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, type)==0) {
			return -i;
			break;
		}
	}
	return 0;
}
int  get_index(char *c) {
    q = search(c);
	int u=-q;
    if(!q) {
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", countn+1, c);
		sem_errors++;
		return 1;
    }
	return u;
}

int  check_declaration(char *c) {
    q = search(c);
    if(!q) {
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", countn+1, c);
		sem_errors++;
		return 1;
    }
	return 0;
}

void check_return_type(char *value) {
	char *main_datatype = get_type("main");
	char *return_datatype = get_type(value);
	if((!strcmp(main_datatype, "numeric") && !strcmp(return_datatype, "CONST")) || !strcmp(main_datatype, return_datatype)){
		return ;
	}
	else {
		sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", countn+1);
		sem_errors++;
	}
}

int check_types(char *type1, char *type2){
	// declaration with no init
	if(!strcmp(type2, "null"))
		return -1;
	// both datatypes are same
	if(!strcmp(type1, type2))
		return 0;
	// both datatypes are different
	if(!strcmp(type1, "numeric") && !strcmp(type2, "decimal"))
		return 1;
	if(!strcmp(type1, "decimal") && !strcmp(type2, "numeric"))
		return 2;
	if(!strcmp(type1, "numeric") && !strcmp(type2, "char"))
		return 3;
	if(!strcmp(type1, "char") && !strcmp(type2, "numeric"))
		return 4;
	if(!strcmp(type1, "decimal") && !strcmp(type2, "char"))
		return 5;
	if(!strcmp(type1, "char") && !strcmp(type2, "decimal"))
		return 6;
}

char *get_type(char *var){
	for(int i=0; i<count; i++) {
		// Handle case of use before declaration
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
}

int add(char c) {
	if(c == 'V'){
		for(int i=0; i<sizeof(reserved); i++){
			if(!strcmp(reserved[i], strdup(yytext))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword!\n", countn+1, yytext);
				sem_errors++;
				return -1;
			}
		}
	}
    q=search(yytext);
	if(!q) {
		if(c == 'H') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Header");
			count++;
			return -1;
		}
		else if(c == 'K') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("N/A");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Keyword\t");
			count++;
			return -1;
		}
		else if(c == 'V') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Variable");
			count++;
			return count-1;
		}
		else if(c == 'C') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("CONST");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Constant");
			count++;
			return -1;
		}
		else if(c == 'F') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Function");
			count++;
			return -1;
		}
    }
    else if(c == 'V' && q) {
        sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed!\n", countn+1, yytext);
		sem_errors++;
		return -1;
    }
}

struct node* mknode(struct node *left, struct node *right, char *name) {	
	struct node *newnode = (struct node *) malloc(sizeof(struct node));
	char *newstr = (char *) malloc(strlen(name)+1);
	strcpy(newstr, name);
	newnode->left = left;
	newnode->right = right;
	newnode->name = newstr;
	return(newnode);
}

void print_tree(struct node* tree) {
	printf("\n\nInorder traversal of the Parse Tree is: \n\n");
	print_inorder(tree);
}

void print_inorder(struct node *tree) {
	int i;
	if (tree->left) {
		print_inorder(tree->left);
	}
	printf("%s, ", tree->name);
	if (tree->right) {
		print_inorder(tree->right);
	}
	
}

void insert_type() {
	strcpy(type, yytext);
}

void yyerror(const char* msg) {
	printf("\n\n");
    fprintf(stdout, "%s\n",msg);
	syn_error++;
}
