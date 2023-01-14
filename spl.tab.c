
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
#line 1 "spl.y"

/* declare some standard headers to be used to import declarations
   and libraries into the parser. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* make forward declarations to avoid compiler warnings */
int yylex (void);
void yyerror (char *);

/* 
   Some constants.
*/

  /* These constants are used later in the code */
#define SYMTABSIZE     50
#define IDLENGTH       15
#define NOTHING        -1
#define INDENTOFFSET    2

	int MAX_INT_RANGE = 2147483647;
	int MIN_INT_RANGE = -2147483647;
	int boolConstant = 0;
	char currentDeclarationType ='\0';
	char prev ='\0';
	int forLoopCounter = 0;
	int inLoop = 0;
	
	enum ParseTreeNodeType {PROGRAM, BLOCK_1, BLOCK_2, DECLARATION_BLOCK_1, DECLARATION_BLOCK_2, DECLARATION_1, 
  				DECLARATION_2, TYPE, TYPE_INT, TYPE_REAL, STATEMENT_LIST_1,STATEMENT_LIST_2,
				STATEMENT, STATEMENT_ASS, ASSIGMENT_STATMENT, STATEMENT_IF, STATEMENT_DO, STATEMENT_WHILE, 
			    DO_STATEMENT, WHILE_STATEMENT, STATEMENT_FOR, STATEMENT_WRITE, STATEMENT_READ,
				FOR_STATEMENT, WRITE_STATEMENT_1, WRITE_STATEMENT_2, READ_STATEMENT, OUTPUT_LIST_1, OUTPUT_LIST_2, CONDITIONAL_1, 
				CONDITIONAL_2, CONDITIONAL_3,TERM_1, TERM_2, TERM_3,
				CONDITION_1, CONDITION_2,COMPAROTOR_1, COMPAROTOR_2, COMPAROTOR_3, COMPAROTOR_4, COMPAROTOR_5, COMPAROTOR_6,
				EXPRESSION_1 ,EXPRESSION_2,EXPRESSION_3, TERM, VALUE, CONSTANT, NUMBER_CONSTANT,
				MINUS_NUMBER_CONSTANT, 
				RESULT_NUMBER, VALUE_ID, VALUE_CONSTANT, VALUE_EX, CHAR_CONSTANT, RESULT_NUMBER_INT, 
				RESULT_NUMBER_FLO, IF_STATEMENT_1, IF_STATEMENT_2};  
                          /* Add more types here, as more nodes
                                           added to tree */
  char *NodeName[] = {"PROGRAM", "BLOCK_1", "BLOCK_2","DECLARATION_BLOCK_1", "DECLARATION_BLOCK_2", "DECLARATION_1", 
  					"DECLARATION_2" , "TYPE", "TYPE_INT", "TYPE_REAL", "STATEMENT_LIST_1","STATEMENT_LIST_2",
					"STATEMENT", "STATEMENT_ASS","ASSIGMENT_STATMENT", "STATEMENT_IF", "STATEMENT_DO","DO_STATEMENT", 
					"STATEMENT_WHILE","WHILE_STATEMENT", "STATEMENT_FOR", "STATEMENT_WRITE", "STATEMENT_READ",
					"FOR_STATEMENT", "WRITE_STATEMENT_1","WRITE_STATEMENT_2", "READ_STATEMENT", "OUTPUT_LIST_1", "OUTPUT_LIST_2", "CONDITIONAL_1",
					"CONDITIONAL_1", "CONDITIONAL_2","CONDITIONAL_3","TERM_1", "TERM_2", "TERM_3",  
					"CONDITION_1", "CONDITION_2","COMPAROTOR_1", "COMPAROTOR_2", "COMPAROTOR_3", "COMPAROTOR_4", "COMPAROTOR_5", "COMPAROTOR_6",
					"EXPRESSION_1", "EXPRESSION_2", "EXPRESSION_3","TERM", "VALUE", "CONSTANT", "NUMBER_CONSTANT",
					"MINUS_NUMBER_CONSTANT", 
					"RESULT_NUMBER", "VALUE_ID", "VALUE_CONSTANT", "VALUE_EX", "CHAR_CONSTANT", "RESULT_NUMBER_INT", 
					"RESULT_NUMBER_FLO", "IF_STATEMENT_1", "IF_STATEMENT_2"};
					
	char *CKeyWords[] = {"auto","else","long","switch","break","enum","register","typedef","case","extern",
						"return","union","char","float","short","unsigned","const","for","signed","void","continue",
						"goto","sizeof","volatile","default","if","static","while","do","int","struct","_Packed","double"};

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

/* ------------- parse tree definition --------------------------- */

struct treeNode {
    int  item;
    int  nodeIdentifier;
    struct treeNode *first;
    struct treeNode *second;
    struct treeNode *third;
	struct treeNode *four;
  };

typedef  struct treeNode TREE_NODE;
typedef  TREE_NODE        *TERNARY_TREE;

/* ------------- forward declarations --------------------------- */

TERNARY_TREE create_node(int,int,TERNARY_TREE,TERNARY_TREE,TERNARY_TREE, TERNARY_TREE);
#ifdef DEBUG
	void PrintTree(TERNARY_TREE, int);
#endif
	int CheckForUnusedVariables();
	void WriteCode(TERNARY_TREE);
	int CheckFloat(TERNARY_TREE);
	int ContainsLetter(char*);
	int FindCKeywords(char*);
/* ------------- symbol table definition --------------------------- */

struct symTabNode {
    char identifier[IDLENGTH];
	char type;
	char state; /*variable to keep track the declaration and initialization of identifiers*/
	char declared;
	int reservedID;
};

typedef  struct symTabNode SYMTABNODE;
typedef  SYMTABNODE        *SYMTABNODEPTR;

SYMTABNODEPTR  symTab[SYMTABSIZE]; 

int currentSymTabSize = 0;



/* Line 189 of yacc.c  */
#line 189 "spl.tab.c"

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
     identifier_key = 258,
     INTERGER_NUM = 259,
     CHARACTER_CONSTANT = 260,
     FLOAT_NUM = 261,
     SEMICOLON = 262,
     PERIOD = 263,
     COMMA = 264,
     COLON = 265,
     ASSIGN = 266,
     OPEN_BRACKET = 267,
     CLOSE_BRACKET = 268,
     EQUAL = 269,
     NOT_EQUAL = 270,
     LESS_THAN = 271,
     GREATER_THAN = 272,
     LESS_THAN_OR_EQUAL = 273,
     GREATER_THAN_OR_EQUAL = 274,
     PLUS = 275,
     MINUS = 276,
     TIMES = 277,
     DIVIDE = 278,
     ENDP = 279,
     CODE = 280,
     DECLARATIONS = 281,
     OF = 282,
     TYPE_KEY = 283,
     IF = 284,
     ENDIF = 285,
     THEN = 286,
     ELSE = 287,
     DO = 288,
     WHILE = 289,
     ENDDO = 290,
     FOR = 291,
     IS = 292,
     BY = 293,
     TO = 294,
     ENDFOR = 295,
     ENDWHILE = 296,
     WRITE = 297,
     NEWLINE = 298,
     READ = 299,
     NOT = 300,
     AND = 301,
     OR = 302,
     CHARACTER = 303,
     INTEGER = 304,
     REAL = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 126 "spl.y"

    int iVal;
    TERNARY_TREE  tVal;



/* Line 214 of yacc.c  */
#line 282 "spl.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 294 "spl.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,    10,    15,    18,    24,    31,    33,    37,
      39,    41,    43,    47,    49,    51,    53,    55,    57,    59,
      61,    63,    67,    75,    81,    87,    99,   105,   110,   112,
     117,   121,   123,   127,   131,   133,   137,   140,   142,   144,
     146,   148,   150,   152,   156,   160,   162,   166,   170,   172,
     174,   176,   180,   182,   184,   186,   189,   191
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,     3,    10,    53,    24,     3,     8,    -1,
      26,    54,    25,    57,    -1,    25,    57,    -1,    55,    27,
      28,    56,     7,    -1,    55,    27,    28,    56,     7,    54,
      -1,     3,    -1,     3,     9,    55,    -1,    48,    -1,    49,
      -1,    50,    -1,    58,     7,    57,    -1,    58,    -1,    59,
      -1,    60,    -1,    61,    -1,    63,    -1,    62,    -1,    64,
      -1,    65,    -1,    70,    11,     3,    -1,    29,    67,    31,
      57,    32,    57,    30,    -1,    29,    67,    31,    57,    30,
      -1,    33,    57,    34,    67,    35,    -1,    36,     3,    37,
      70,    38,    70,    39,    70,    33,    57,    40,    -1,    34,
      67,    33,    57,    41,    -1,    42,    12,    66,    13,    -1,
      43,    -1,    44,    12,     3,    13,    -1,    72,     9,    66,
      -1,    72,    -1,    67,    46,    68,    -1,    67,    47,    68,
      -1,    68,    -1,    70,    69,    70,    -1,    45,    68,    -1,
      14,    -1,    15,    -1,    16,    -1,    17,    -1,    18,    -1,
      19,    -1,    70,    20,    71,    -1,    70,    21,    71,    -1,
      71,    -1,    71,    22,    72,    -1,    71,    23,    72,    -1,
      72,    -1,     3,    -1,    73,    -1,    12,    70,    13,    -1,
      74,    -1,     5,    -1,    75,    -1,    21,    75,    -1,     4,
      -1,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   160,   164,   169,   173,   178,   182,   187,
     191,   195,   200,   204,   209,   210,   211,   212,   213,   214,
     215,   217,   222,   226,   231,   235,   239,   244,   248,   253,
     258,   262,   267,   271,   275,   280,   284,   289,   293,   297,
     301,   305,   309,   314,   318,   322,   327,   331,   335,   340,
     344,   348,   353,   357,   362,   366,   371,   375
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "identifier_key", "INTERGER_NUM",
  "CHARACTER_CONSTANT", "FLOAT_NUM", "SEMICOLON", "PERIOD", "COMMA",
  "COLON", "ASSIGN", "OPEN_BRACKET", "CLOSE_BRACKET", "EQUAL", "NOT_EQUAL",
  "LESS_THAN", "GREATER_THAN", "LESS_THAN_OR_EQUAL",
  "GREATER_THAN_OR_EQUAL", "PLUS", "MINUS", "TIMES", "DIVIDE", "ENDP",
  "CODE", "DECLARATIONS", "OF", "TYPE_KEY", "IF", "ENDIF", "THEN", "ELSE",
  "DO", "WHILE", "ENDDO", "FOR", "IS", "BY", "TO", "ENDFOR", "ENDWHILE",
  "WRITE", "NEWLINE", "READ", "NOT", "AND", "OR", "CHARACTER", "INTEGER",
  "REAL", "$accept", "program", "block", "declaration_block",
  "identifiers", "type", "statement_list", "statement",
  "assignment_statement", "if_statement", "do_statement", "for_statement",
  "while_statement", "write_statement", "read_statement", "output_list",
  "conditional", "condition", "comparator", "expression", "term", "value",
  "constant", "number_constant", "result_number", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    56,    57,    57,    58,    58,    58,    58,    58,    58,
      58,    59,    60,    60,    61,    62,    63,    64,    64,    65,
      66,    66,    67,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    70,    70,    70,    71,    71,    71,    72,
      72,    72,    73,    73,    74,    74,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     4,     2,     5,     6,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     7,     5,     5,    11,     5,     4,     1,     4,
       3,     1,     3,     3,     1,     3,     2,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     3,     1,     1,
       1,     3,     1,     1,     1,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,    49,    56,
      53,    57,     0,     0,     0,     0,     0,     0,     0,    28,
       0,     4,    13,    14,    15,    16,    18,    17,    19,    20,
       0,    45,    48,    50,    52,    54,     7,     0,     0,     0,
       0,    55,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,    36,     0,     0,     0,    37,    38,    39,    40,
      41,    42,     0,     0,     0,     0,     0,    31,     0,    12,
      21,    43,    44,    46,    47,     8,     3,     0,     2,     0,
      32,    33,    35,     0,     0,     0,    27,     0,    29,     9,
      10,    11,     0,    23,     0,    24,    26,     0,    30,     5,
       0,     0,     6,    22,     0,     0,     0,     0,    25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,    37,    38,   102,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    76,    43,    44,    72,    30,
      31,    32,    33,    34,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -47
static const yytype_int8 yypact[] =
{
      10,    21,     8,    42,   -47,    36,    51,    35,   -47,   -47,
     -47,   -47,    70,    43,    11,    36,    11,    82,    59,   -47,
      78,   -47,    87,   -47,   -47,   -47,   -47,   -47,   -47,   -47,
      66,    61,   -47,   -47,   -47,   -47,    90,    75,    74,   100,
      68,   -47,    11,   -25,   -47,    95,    71,   -13,    67,    70,
     103,    36,   104,    70,    70,    70,    70,    51,    36,    89,
     110,   -47,   -47,    36,    11,    11,   -47,   -47,   -47,   -47,
     -47,   -47,    70,    11,    36,    70,   106,   111,   108,   -47,
     -47,    61,    61,   -47,   -47,   -47,   -47,    -4,   -47,    32,
     -47,   -47,    72,   -11,    81,    -9,   -47,    70,   -47,   -47,
     -47,   -47,   116,   -47,    36,   -47,   -47,    70,   -47,    51,
      94,    -2,   -47,   -47,    70,     5,    36,    85,   -47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -47,   -47,   -47,    17,    73,   -47,    -8,   -47,   -47,   -47,
     -47,   -47,   -47,   -47,   -47,    30,   -15,   -37,   -47,   -12,
      44,   -46,   -47,   -47,   115
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      40,    47,    45,    77,    45,    62,    63,    46,     4,    83,
      84,    53,    54,     1,     8,     9,    10,    11,    53,    54,
      74,    64,    65,    12,   105,    53,    54,    90,    91,   107,
      45,     3,    13,    64,    65,    64,    65,   114,   116,     8,
       9,    10,    11,    79,    99,   100,   101,     9,    12,    11,
      86,    77,    45,    45,    36,    89,    42,    13,    93,    39,
      92,    45,   103,    95,   104,    14,    94,     5,     6,    15,
      16,    49,    17,     8,     9,    10,    11,    52,    18,    19,
      20,    61,    12,    55,    56,    48,    53,    54,    53,    54,
      50,    13,    53,    54,    51,   111,   110,    81,    82,    57,
      58,    59,   115,    60,    75,    73,    78,    80,   117,    66,
      67,    68,    69,    70,    71,    53,    54,    87,    88,    96,
      97,    98,   106,   109,   113,   118,   112,   108,    41,     0,
      85
};

static const yytype_int8 yycheck[] =
{
      12,    16,    14,    49,    16,    42,    31,    15,     0,    55,
      56,    20,    21,     3,     3,     4,     5,     6,    20,    21,
      33,    46,    47,    12,    35,    20,    21,    64,    65,    38,
      42,    10,    21,    46,    47,    46,    47,    39,    33,     3,
       4,     5,     6,    51,    48,    49,    50,     4,    12,     6,
      58,    97,    64,    65,     3,    63,    45,    21,    73,    24,
      72,    73,    30,    75,    32,    29,    74,    25,    26,    33,
      34,    12,    36,     3,     4,     5,     6,    11,    42,    43,
      44,    13,    12,    22,    23,     3,    20,    21,    20,    21,
      12,    21,    20,    21,     7,   107,   104,    53,    54,     9,
      25,    27,   114,     3,    37,    34,     3,     3,   116,    14,
      15,    16,    17,    18,    19,    20,    21,    28,     8,    13,
       9,    13,    41,     7,    30,    40,   109,    97,    13,    -1,
      57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    52,    10,     0,    25,    26,    53,     3,     4,
       5,     6,    12,    21,    29,    33,    34,    36,    42,    43,
      44,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      70,    71,    72,    73,    74,    75,     3,    54,    55,    24,
      70,    75,    45,    67,    68,    70,    57,    67,     3,    12,
      12,     7,    11,    20,    21,    22,    23,     9,    25,    27,
       3,    13,    68,    31,    46,    47,    14,    15,    16,    17,
      18,    19,    69,    34,    33,    37,    66,    72,     3,    57,
       3,    71,    71,    72,    72,    55,    57,    28,     8,    57,
      68,    68,    70,    67,    57,    70,    13,     9,    13,    48,
      49,    50,    56,    30,    32,    35,    41,    38,    66,     7,
      57,    70,    54,    30,    39,    70,    33,    57,    40
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
#line 147 "spl.y"
    { 
					TERNARY_TREE ParseTree;
					ParseTree = create_node((yyvsp[(1) - (6)].iVal), PROGRAM, (yyvsp[(3) - (6)].tVal), NULL, NULL, NULL);
					
#ifdef DEBUG
						PrintTree(ParseTree,0);
#else
						if((yyvsp[(1) - (6)].iVal) != (yyvsp[(5) - (6)].iVal)) fprintf(stderr,"\033[0;33m[WARNING]\033[0m Start identifier does not match to the end identifier!\n");
						WriteCode(ParseTree);
						/*CheckForUnusedVariables();*/
#endif
					;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 161 "spl.y"
    { 
				(yyval.tVal) = create_node(NOTHING, BLOCK_1, (yyvsp[(2) - (4)].tVal), (yyvsp[(4) - (4)].tVal), NULL,NULL);
        	;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 165 "spl.y"
    { 
				(yyval.tVal) = create_node(NOTHING, BLOCK_2, (yyvsp[(2) - (2)].tVal), NULL, NULL, NULL);
        	;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 170 "spl.y"
    { 
                		(yyval.tVal) = create_node(NOTHING, DECLARATION_BLOCK_1, (yyvsp[(1) - (5)].tVal), (yyvsp[(4) - (5)].tVal), NULL,NULL);
        			;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 174 "spl.y"
    { 
		                (yyval.tVal) = create_node(NOTHING, DECLARATION_BLOCK_2, (yyvsp[(1) - (6)].tVal), (yyvsp[(4) - (6)].tVal), (yyvsp[(6) - (6)].tVal),NULL);
		        	;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 179 "spl.y"
    { 
		            (yyval.tVal) = create_node((yyvsp[(1) - (1)].iVal), DECLARATION_1, NULL, NULL, NULL,NULL);
		        ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 183 "spl.y"
    { 
		            (yyval.tVal) = create_node((yyvsp[(1) - (3)].iVal), DECLARATION_2, (yyvsp[(3) - (3)].tVal), NULL, NULL, NULL);
		        ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 188 "spl.y"
    { 
            (yyval.tVal) = create_node(CHARACTER, TYPE, NULL, NULL, NULL, NULL);
        ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 192 "spl.y"
    { 
            (yyval.tVal) = create_node(INTEGER, TYPE, NULL, NULL, NULL, NULL);
        ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 196 "spl.y"
    { 
            (yyval.tVal) = create_node(REAL, TYPE, NULL, NULL, NULL, NULL);
        ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 201 "spl.y"
    { 
                	(yyval.tVal) = create_node(NOTHING, STATEMENT_LIST_1, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
        		;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 205 "spl.y"
    { 
                	(yyval.tVal) = create_node(NOTHING, STATEMENT_LIST_2, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
        		;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 209 "spl.y"
    {(yyval.tVal) = create_node(NOTHING, STATEMENT_ASS, (yyvsp[(1) - (1)].tVal),NULL, NULL, NULL);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 210 "spl.y"
    {(yyval.tVal) = create_node(NOTHING, STATEMENT_IF, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 211 "spl.y"
    {(yyval.tVal) = create_node(NOTHING, STATEMENT_DO, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 212 "spl.y"
    {(yyval.tVal) = create_node(NOTHING, STATEMENT_WHILE, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 213 "spl.y"
    {(yyval.tVal) = create_node(NOTHING, STATEMENT_FOR, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 214 "spl.y"
    {(yyval.tVal) = create_node(NOTHING, STATEMENT_WRITE, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 215 "spl.y"
    {(yyval.tVal) = create_node(NOTHING, STATEMENT_READ, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 218 "spl.y"
    { 
	                  (yyval.tVal) = create_node((yyvsp[(3) - (3)].iVal), ASSIGMENT_STATMENT, (yyvsp[(1) - (3)].tVal), NULL, NULL, NULL);
	            	;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 223 "spl.y"
    { 
	                (yyval.tVal) = create_node(NOTHING, IF_STATEMENT_1, (yyvsp[(2) - (7)].tVal), (yyvsp[(4) - (7)].tVal), (yyvsp[(6) - (7)].tVal), NULL);
	            ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 227 "spl.y"
    { 
	                (yyval.tVal) = create_node(NOTHING, IF_STATEMENT_2, (yyvsp[(2) - (5)].tVal), (yyvsp[(4) - (5)].tVal), NULL, NULL);
	            ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 232 "spl.y"
    { 
	                (yyval.tVal) = create_node(NOTHING, DO_STATEMENT, (yyvsp[(2) - (5)].tVal), (yyvsp[(4) - (5)].tVal), NULL, NULL);
	            ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 236 "spl.y"
    { 
	                (yyval.tVal) = create_node((yyvsp[(2) - (11)].iVal), FOR_STATEMENT, (yyvsp[(4) - (11)].tVal), (yyvsp[(6) - (11)].tVal), (yyvsp[(8) - (11)].tVal), (yyvsp[(10) - (11)].tVal));
	            ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 240 "spl.y"
    { 
	                (yyval.tVal) = create_node(NOTHING, WHILE_STATEMENT, (yyvsp[(2) - (5)].tVal), (yyvsp[(4) - (5)].tVal), NULL, NULL);
	            ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 245 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(NOTHING, WRITE_STATEMENT_1, (yyvsp[(3) - (4)].tVal), NULL, NULL, NULL);
	            ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 249 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(NEWLINE, WRITE_STATEMENT_2, NULL, NULL, NULL, NULL);
	            ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 254 "spl.y"
    { 
	        	    (yyval.tVal) = create_node((yyvsp[(3) - (4)].iVal), READ_STATEMENT, NULL, NULL, NULL, NULL);
	            ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 259 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(NOTHING, OUTPUT_LIST_1, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
	            ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 263 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(NOTHING, OUTPUT_LIST_2, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
	            ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 268 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(NOTHING, CONDITIONAL_1, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
	            ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 272 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(NOTHING, CONDITIONAL_2, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
	            ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 276 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(NOTHING, CONDITIONAL_3, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
	            ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 281 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(NOTHING, CONDITION_1, (yyvsp[(1) - (3)].tVal), (yyvsp[(2) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL);
	            ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 285 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(NOTHING, CONDITION_2, (yyvsp[(2) - (2)].tVal), NULL, NULL, NULL);
	            ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 290 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(EQUAL, COMPAROTOR_1, NULL, NULL, NULL, NULL);
	            ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 294 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(NOT_EQUAL, COMPAROTOR_2, NULL, NULL, NULL, NULL);
	            ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 298 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(LESS_THAN, COMPAROTOR_3, NULL, NULL, NULL, NULL);
	            ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 302 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(GREATER_THAN, COMPAROTOR_4, NULL, NULL, NULL, NULL);
	            ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 306 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(LESS_THAN_OR_EQUAL, COMPAROTOR_5, NULL, NULL, NULL, NULL);
	            ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 310 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(GREATER_THAN_OR_EQUAL, COMPAROTOR_6, NULL, NULL, NULL, NULL);
	            ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 315 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(NOTHING, EXPRESSION_1, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
	            ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 319 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(NOTHING, EXPRESSION_2, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
	            ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 323 "spl.y"
    { 
	        	    (yyval.tVal) = create_node(NOTHING, EXPRESSION_3, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
	            ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 328 "spl.y"
    { 
	       	(yyval.tVal) = create_node(NOTHING, TERM_1, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
	    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 332 "spl.y"
    { 
	       	(yyval.tVal) = create_node(NOTHING, TERM_2, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal), NULL, NULL);
	    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 336 "spl.y"
    { 
	       	(yyval.tVal) = create_node(NOTHING, TERM_3, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
	    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 341 "spl.y"
    { 
	       	(yyval.tVal) = create_node((yyvsp[(1) - (1)].iVal), VALUE_ID, NULL, NULL, NULL, NULL);
	    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 345 "spl.y"
    { 
	       	(yyval.tVal) = create_node(NOTHING, VALUE_CONSTANT, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
	    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 349 "spl.y"
    { 
	       	(yyval.tVal) = create_node(NOTHING, VALUE_EX, (yyvsp[(2) - (3)].tVal), NULL, NULL, NULL);
	    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 354 "spl.y"
    { 
	       	(yyval.tVal) = create_node(NOTHING, CONSTANT, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
	    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 358 "spl.y"
    { 
	       	(yyval.tVal) = create_node((yyvsp[(1) - (1)].iVal), CHAR_CONSTANT, NULL, NULL, NULL, NULL);
	    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 363 "spl.y"
    { 
			       	(yyval.tVal) = create_node(NOTHING, NUMBER_CONSTANT, (yyvsp[(1) - (1)].tVal), NULL, NULL, NULL);
			    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 367 "spl.y"
    { 
			       	(yyval.tVal) = create_node(NOTHING, MINUS_NUMBER_CONSTANT,(yyvsp[(2) - (2)].tVal), NULL, NULL, NULL);
			    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 372 "spl.y"
    { 
			       	(yyval.tVal) = create_node((yyvsp[(1) - (1)].iVal), RESULT_NUMBER_INT, NULL, NULL, NULL, NULL);
			    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 376 "spl.y"
    { 
			       	(yyval.tVal) = create_node((yyvsp[(1) - (1)].iVal), RESULT_NUMBER_FLO, NULL, NULL, NULL, NULL);
			    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2094 "spl.tab.c"
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
#line 379 "spl.y"


/* Code for routines for managing the Parse Tree */

TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1,
			 TERNARY_TREE  p2, TERNARY_TREE  p3, TERNARY_TREE  p4)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
	if (t == NULL) { 
		fprintf(stderr, "create_node:Out of memory: %d %d bytes\n", case_identifier, sizeof(TREE_NODE));
		return(t); 
	} 
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
    t->four = p4;
	
    return (t);
}

void WriteCode(TERNARY_TREE t)
{
	if (t == NULL) return;
	
	switch (t->nodeIdentifier)
        {
/*PROGRAM*/
        	case(PROGRAM) :
        		printf("#include <stdio.h>\n");
        		printf("int main(void) {\n");
        		WriteCode(t->first);
        		printf("\n");
        		printf("return 0;\n");
        		printf("}");
        		break;

/*DECLARATION_BLOCK*/
        	
        	case(DECLARATION_BLOCK_1) :
        		WriteCode(t->second);
        		WriteCode(t->first);
        		break;


        	case(DECLARATION_BLOCK_2) :
        		WriteCode(t->second);
        		WriteCode(t->first);
        		WriteCode(t->third);
        		break;

/*DECLARATION*/
        	case(DECLARATION_1) :
			
				if(symTab[t->item]->declared == 'y')
				{
					fprintf(stderr,"\033[0;31m[ERROR]\033[0m Redeclaration of identifier (%s)",symTab[t->item]->identifier);
					exit(1);
				}
				
				if(FindCKeywords(symTab[t->item]->identifier) == 1)
				{
					/*fprintf(stderr,"\033[0;31m[ERROR]\033[0m Varible name is reserved for C* ");exit(1);*/
					printf("_%s", symTab[t->item]->identifier);
					symTab[t->item]->reservedID = 1;
				}else
				{
					printf("%s", symTab[t->item]->identifier);
					symTab[t->item]->reservedID = 0;
				}
				symTab[t->item]->type = currentDeclarationType;
				symTab[t->item]->declared = 'y';
				symTab[t->item]->state = 'n';
				printf(";");
				
				printf("\n");	
				
				break;


			case(DECLARATION_2) :
			
				if(symTab[t->item]->declared == 'y')
				{
					fprintf(stderr,"\033[0;31m[ERROR]\033[0m Redeclaration of identifier (%s)",symTab[t->item]->identifier);
					exit(1);
				}
			
				if(FindCKeywords(symTab[t->item]->identifier) == 1)
				{
					printf("\n");
					fprintf(stderr,"\033[0;31m[ERROR]\033[0m Varible name is reserved for C* ");
					exit(1);
					printf("_");
				}
				printf("%s", symTab[t->item]->identifier);
				symTab[t->item]->type = currentDeclarationType;
				symTab[t->item]->declared = 'y';
				symTab[t->item]->state = 'n';
				printf(", ");
				WriteCode(t->first);
				break;


/*TYPE*/
			case TYPE:
			switch(t->item)
			{
				case CHARACTER:
					currentDeclarationType ='c';
					printf("char ");
					break;
				case REAL:
					currentDeclarationType ='f';
					printf("float ");
					break;
				case INTEGER:
					currentDeclarationType ='i';
					printf("int ");
					break;
			}
			break;	    	

/*DO STATMENT*/
	    	case (DO_STATEMENT) :
            	printf("do{\n");
            	WriteCode(t->first);
            	printf("\n");
            	printf("}\n");
            	printf("while(");
            	WriteCode(t->second);
            	printf(");");
            	printf("\n");
            	break;

/*WHILE STATMENT*/
        	case (WHILE_STATEMENT) :
            	printf("while(");
            	WriteCode(t->first);
            	printf("){\n");
            	WriteCode(t->second);
            	printf("}");
            	break;

/*FOR STATEMENT*/
        	case (FOR_STATEMENT) :
				 /* 
				 FOR a IS 1 BY 1 TO 13 DO
				 ....
				 ENDFOR;
				 */
				/*int i;*/
				printf("register int _by%d;", forLoopCounter);
				
        	 	printf("\n");
            	printf("for (");
				symTab[t->item]->state = 'y';
            	printf("%s",symTab[t->item]->identifier);
            	printf(" = ");
				
				inLoop = 1;
				
            	WriteCode(t->first);
            	printf("; ");
            	printf("_by%d=", forLoopCounter);
            	WriteCode(t->second);
            	printf(", (");
            	printf("%s",symTab[t->item]->identifier);
            	printf("-(");
            	WriteCode(t->third);
       			printf("))");
            	printf("*");
            	printf("((");
            	printf("_by%d > 0)", forLoopCounter);
            	printf(" - ");
            	printf("(_by%d < 0)) ", forLoopCounter);
            	printf("<= 0; ");
            	printf("%s",symTab[t->item]->identifier);
            	printf(" += _by%d", forLoopCounter);
            	printf("){\n");
            	WriteCode(t->four);
            	printf("\n}");
            	forLoopCounter++;
				inLoop = 0;
            	break;

/*ASSIGMENT_STATMENT*/
            case(ASSIGMENT_STATMENT) :
			
        		if(t->item  >= 0 && t->item < SYMTABSIZE)
				{
					if(symTab[t->item]->declared != 'y')
					{
						fprintf(stderr,"\033[0;31m[ERROR]\033[0m Assignment to undeclared var (%s)", symTab[t->item]->identifier);
						exit(1);
					}
				
				
					if(symTab[t->item]->reservedID == 1)
					{
						printf("_%s", symTab[t->item]->identifier);
					}
					else
					{
						printf("%s", symTab[t->item]->identifier);
					}
					symTab[t->item]->state = 'y';
				}
				else
				{
					fprintf(stderr,"\033[0;31m[ERROR]\033[0m Uknown identifier %s", symTab[t->item]->identifier);
					exit(1);
				}
				
				
				
				prev = symTab[t->item]->type;
        		printf(" = ");
        		WriteCode(t->first);
        		printf(";");
				prev='0';
        		printf("\n");
        		break;
				

/*IF STATMENT*/
    		case(IF_STATEMENT_1) :
            	printf("if (");
            	WriteCode(t->first);
            	printf(") { \n");
				prev ='0';
            	WriteCode(t->second);
            	printf("}\n");
            	printf("else { \n");
            	WriteCode(t->third);
            	printf("}\n");
            	break;

           	case(IF_STATEMENT_2) :
           		printf("if (");
            	WriteCode(t->first);
            	printf(") { \n");
            	WriteCode(t->second);
            	printf("}\n");
            	break;

/*WRITE_STATEMENT*/
    		case(WRITE_STATEMENT_1) :
            	WriteCode(t->first);
            	break;

            case(WRITE_STATEMENT_2) :
            	printf("printf(\"\\n\");\n");
            	break;

/*READ_STATEMENT*/

            case(READ_STATEMENT) :
            	printf("scanf(\"");
				switch(symTab[t->item]->type)
				{
					case 'c':
						/*printf("%%c\""", ");*/
						printf(" %%[^\\n]c");
						break;
					case 'i':
						printf("%%d");
						break;
					case 'f':
						printf("%%f"); 
						break;
				}
				printf("\",");
				symTab[t->item]->state = 'y';
				printf(" &%s", symTab[t->item]->identifier);
				printf(");\n");
				break;

/*OUTPUT_LIST*/
			case(OUTPUT_LIST_1) :
            	if(t->first != NULL && t->first->nodeIdentifier == VALUE_ID )
            	{
            		printf("printf(\"");
            		switch(symTab[t->first->item]->type)
					{
						case 'c':
							printf(" %%c,\""", ");
							break;
						case 'i':
							printf("%%d,\""", ");
							break;
						case 'f':
							printf("%%.2f\""", "); 
							break;
					}
            		WriteCode(t->first);
            		printf(");\n");
	            	WriteCode(t->second);
            	} 
            	else if(t->first != NULL && t->first->nodeIdentifier == VALUE_CONSTANT)
            	{
            		printf("printf(\"");
            		boolConstant = 1;
            		WriteCode(t->first);
	            	printf(");\n");
	            	WriteCode(t->second);
	            	boolConstant = 0;

            	}
            	else
            	{
            		if(CheckFloat(t) == 1)
            		{
            			printf("printf(\"");
            			printf("%%.2f\", ");
	            		WriteCode(t->first);
		            	printf(");\n");
		            	WriteCode(t->second);
            		}
            		else
            		{
            			printf("printf(\"");
            			printf("%%d\", ");
	            		WriteCode(t->first);
		            	printf(");\n");
		            	WriteCode(t->second);
            		}
            		
            	}
            	break;
            
            	
            case(OUTPUT_LIST_2) :
            	if(t->first != NULL && t->first->nodeIdentifier == VALUE_ID)
            	{
            		printf("printf(\"");
            		switch(symTab[t->first->item]->type)
					{
						case 'c':
							printf("%%c\""", ");
							break;
						case 'i':
							printf("%%d\""", ");
							break;
						case 'f':
							printf("%%.2f\""", "); 
							break;
					}
            		WriteCode(t->first);
            		printf(");\n");

            	}
            	else if(t->first != NULL && t->first->nodeIdentifier == VALUE_CONSTANT)
            	{
            		printf("printf(\"");
            		boolConstant = 1;
            		WriteCode(t->first);
	            	printf(");\n");
	            	boolConstant = 0;
            	}
            	else
            	{
            		if(CheckFloat(t) == 1)
            		{
            			printf("printf(\"");
            			printf("%%.2f\", ");
	            		WriteCode(t->first);
		            	printf(");\n");
            		}
            		else
            		{
            			printf("printf(\"");
            			printf("%%d\", ");
	            		WriteCode(t->first);
		            	printf(");\n");
            		}
            		
            	}
            	
            	
            	break;
            	
/*CONDITIONAL*/
        	case (CONDITIONAL_1) :
            	WriteCode(t->first);
            	printf(" && ");
            	WriteCode(t->second);
            	break;

            case (CONDITIONAL_2) :
            	WriteCode(t->first);
            	printf(" || ");
            	WriteCode(t->second);
            	break;

            case (CONDITIONAL_3) :
            	WriteCode(t->first);
            	break;

/*CONDITION*/
            case (CONDITION_1) :
            	WriteCode(t->first);
            	printf(" ");
            	WriteCode(t->second);
            	printf(" ");
            	WriteCode(t->third);
            	break;

            case (CONDITION_2) :
            	printf("!(");
				WriteCode(t->first);
				printf(")");
            	break;

/*COMPARATOR*/
            case (COMPAROTOR_1) :
            	printf(" == ");
            	break;

            case (COMPAROTOR_2) :
            	printf(" != ");
            	break;

            case (COMPAROTOR_3) :
            	printf(" < ");
            	break;

            case (COMPAROTOR_4) :
            	printf(" > ");
            	break;

            case (COMPAROTOR_5) :
            	printf(" <= ");
            	break;

            case (COMPAROTOR_6) :
            	printf(" >= ");
            	break;

/*EXPRESION*/
        	case(EXPRESSION_1) :
			
			if(t->second->second == NULL && t->second->first->nodeIdentifier == VALUE_CONSTANT)
				{
					if(t->second->first->first->first->first->item == 0 )
					{
						WriteCode(t->first);
					}
					else 
					{
						WriteCode(t->first);
						printf(" + ");
						WriteCode(t->second);
					}
				}
				else
				{
					WriteCode(t->first);
					printf(" + ");
					WriteCode(t->second);
				}
			
            	break;

            case(EXPRESSION_2) :
			
				if(t->second->second == NULL && t->second->first->nodeIdentifier == VALUE_CONSTANT)
				{
					if(t->second->first->first->first->first->item == 0 )
					{
						WriteCode(t->first);
					}
					else 
					{
						WriteCode(t->first);
						printf(" - ");
						WriteCode(t->second);
					}
				}
				else
				{
					WriteCode(t->first);
					printf(" - ");
					WriteCode(t->second);
				}		
				break;

        	case(EXPRESSION_3) :
            	WriteCode(t->first);
            	break;

/*TERM*/  		
            case(TERM_1) :
				if(t->second->nodeIdentifier == VALUE_CONSTANT)
				{						
					if(t->second->first->first->nodeIdentifier == NUMBER_CONSTANT)
					{
						if(t->second->first->first->first->item == 0)
						{
							printf("0");
							return;
						}	
						else if(t->second->first->first->item == 1)
						{
							WriteCode(t->first);
							return;
						}	
					}
					
				}
				if(t->first->first->nodeIdentifier == VALUE_CONSTANT)
				{								
					if(t->first->first->first->first->nodeIdentifier == NUMBER_CONSTANT)
					{
						if(t->first->first->first->first->first->item == 0)
						{
							printf("0");
							return;
						}	
						else if(t->first->first->first->first->first->item == 1)
						{
							WriteCode(t->second);
							return;
						}		
					}
				}
			
			    WriteCode(t->first);
    			printf(" * ");
    			WriteCode(t->second);
    			break;
			
    		case(TERM_2) :
				
				if(t->first->first->nodeIdentifier == VALUE_CONSTANT)
				{
					if(t->first->first->first->first->nodeIdentifier == NUMBER_CONSTANT)
					{
						if(t->first->first->first->first->first->item == 0)
						{	
							printf("0");
							return;
						}	
					}
				}
				if(t->second->nodeIdentifier == VALUE_CONSTANT)
				{
					if(t->second->first->first->nodeIdentifier == NUMBER_CONSTANT)
					{
						if(t->second->first->first->first->item == 1)
						{	
							WriteCode(t->first);
							return;
						}
						else if(t->second->first->first->first->item == 0)
						{
							fprintf(stderr,"\033[0;31m[ERROR]\033[0m Divide by 0 ");
							exit(1);
						}
					}
				}
    			WriteCode(t->first);
    			printf(" / ");
    			WriteCode(t->second);
    			break;

            case(TERM_3) :
    			WriteCode(t->first);
    			break;

/*VALUE*/
    		case(VALUE_CONSTANT) :
    			WriteCode(t->first);
    			break;

    		case(VALUE_ID) :
			
				if(symTab[t->item]->declared != 'y')
				{
					fprintf(stderr,"\033[0;31m[ERROR]\033[0m Use of undeclared variable in assignment! (%s)\n",symTab[t->item]->identifier);
					exit(1);
				};
				if(symTab[t->item]->state != 'y')
				{
					fprintf(stderr,"\033[0;33m[WARNING]\033[0m Use of uninitialised var! (%s)\n",symTab[t->item]->identifier);
					/*exit(1);*/
				};
				
				if(symTab[t->item]->reservedID == 1)
				{
					printf("_%s", symTab[t->item]->identifier);
				}
				else
				{
					printf("%s", symTab[t->item]->identifier);
				}
				break;

    		case(VALUE_EX) :
    			printf(" (");
    			WriteCode(t->first);
    			printf(") ");
    			break;
/*CONSTANT*/
    		case(CONSTANT) :
    			WriteCode(t->first);
    			break;

    		case(CHAR_CONSTANT) :
			
				if(inLoop==1)
				{
					fprintf(stderr,"\033[0;31m[ERROR]\033[0m For loop only can be declared as integer!\n");
					exit(1);
				}

				if(prev == 'f' || prev == 'i')
				{
					fprintf(stderr,"\033[0;31m[ERROR]\033[0m Cant assign char to a number type!\n");
					exit(1);
				}
				
				
    			if(boolConstant == 1)
    			{
    				printf("%%c\""", ");
    				printf("%s", symTab[t->item]->identifier);
    			}
    			else
    			{
    				printf("%s", symTab[t->item]->identifier);
    			}
				break;
				

	    	case(NUMBER_CONSTANT) :
		    	WriteCode(t->first);
		    	break;
    		
    		case(MINUS_NUMBER_CONSTANT) :
		    	printf("-");
		    	WriteCode(t->first);
		    	break;

/*RESULT_NUMBER*/
		    case(RESULT_NUMBER_INT) :
				if(t->item > MAX_INT_RANGE || t->item< MIN_INT_RANGE )
				{
					fprintf(stderr,"\033[0;33m[WARNING]\033[0m Integer exceeds valid size!\n");
					/*exit(1);*/
				}
		
				
				if(boolConstant == 1)
    			{
    				printf("%%d\""", ");
    				printf("%d", t->item);
    			}
    			else
    			{
    				printf("%d", t->item);
    			}
				
				/*WARNING*/
				if(prev == 'c')
				{
					 fprintf(stderr,"\033[0;33m[WARNING]\033[0m Assigning integer to a char!\n");
					
				}
				/*
				if(prev == 'f')
				{
					fprintf(stderr,"\033[0;33m[WARNING]\033[0m Cant assign float to an integer type!\n");
				}
				*/
				
				
				break;

				

			case(RESULT_NUMBER_FLO) :
			
				if(inLoop==1)
				{
					fprintf(stderr,"\033[0;31m[ERROR]\033[0m For loop only can be declared as integer!\n");
					exit(1);
				}
			
			
				/*ERROR*/
				if(prev == 'i'|| prev == 'c') 
				{
					fprintf(stderr,"\033[0;31m[ERROR]\033[0m Cant assign char/integer to a Real type!\n");
					exit(1);
				}
				
			
				if(boolConstant == 1)
    			{
    				printf("%%.2f\""", ");
    				printf("%s", symTab[t->item]->identifier);
    			}
    			else
    			{
   					printf("%s", symTab[t->item]->identifier);
    			}

				
				break;

			
			case (identifier_key):
				printf("%s",symTab[t->item]->identifier);
			break;
			
			default:
				WriteCode(t->first);
				WriteCode(t->second);
				WriteCode(t->third);
				WriteCode(t->four);
				break;
        }
        
}


int CheckFloat(TERNARY_TREE t)
{
	if(t == NULL){
		return 0;
	}
	if(t->nodeIdentifier == RESULT_NUMBER_FLO||CheckFloat(t->first)||CheckFloat(t->second)){
		return 1;
	}
	return 0;
}

int CheckForUnusedVariables()
{
	int i;
	for(i=0;i<SYMTABSIZE;i++)
	{	
		/* if we have an identifier*/
		if(symTab[i]->state == 'n')
		{
			fprintf(stderr,"\033[0;33m[WARNING]\033[0m Use of uninitialized identifier (%s)\n",symTab[i]->identifier);
		}
	}

}


int FindCKeywords(char *id)
{
	int i;
	int arraySize = sizeof(CKeyWords)/sizeof(CKeyWords[0]);
	for (i=0; i<arraySize; i++)
	{
		if(strcmp(id, CKeyWords[i]) == 0)
		{
			return 1;
		}	
	}
	return 0;
	
}


#ifdef DEBUG

void PrintTree(TERNARY_TREE t, int indent)
{
	int i;
	if(t == NULL) return;
	
	for(i=indent;i;i--)printf(" ");
	if(t->nodeIdentifier < 0 || t->nodeIdentifier > sizeof(NodeName))
	{
		printf("Unknown nodeIdentifier: %d", t->nodeIdentifier);
		return;
	}

	if (t->item != NOTHING){
		if(t->nodeIdentifier == RESULT_NUMBER_INT)
		{
			printf("Node identifier: RESULT_NUMBER_INT\n");
			for(i=indent;i;i--)printf(" ");
			printf(" INTEGER: %d\n", t->item);

		}
		if(t->nodeIdentifier == RESULT_NUMBER_FLO)
		{
			printf("Node identifier: RESULT_NUMBER_FLO\n");
			for(i=indent;i;i--)printf(" ");
			printf(" FLOAT: %s\n", symTab[t->item]->identifier);
		}
		else if(t->nodeIdentifier == VALUE_ID){
			printf("Node identifier: VALUE_ID\n");
			for(i=indent;i;i--)printf(" ");
			printf(" VAL IDENTIFIER: %s\n", symTab[t->item]->identifier);
		}
		else if(t->nodeIdentifier == CHAR_CONSTANT)
		{
			printf("Node identifier: CHAR_CONSTANT\n");
			for(i=indent;i;i--)printf(" ");
			printf(" CHAR CONSTANT: %s\n", symTab[t->item]->identifier);
		}
		else if(t->nodeIdentifier == identifier_key)
		{
			printf("Node identifier: identifier\n");
			for(i=indent;i;i--)printf(" ");
			printf(" ID_SPL: %s\n", symTab[t->item]->identifier);
			
		}
		else
		{
			printf("Node identifier: %s\n", NodeName[t->nodeIdentifier]);
		}
	}
	else
	{
			printf("Node identifier: %s\n", NodeName[t->nodeIdentifier]);
	}

	PrintTree(t->first,indent+2);
	PrintTree(t->second,indent+2);
	PrintTree(t->third,indent+2);
	PrintTree(t->four,indent+2);
}

#endif
#include "lex.yy.c"
