%{
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

%}

/****************/
/* Start symbol */
/****************/

%start  program

/**********************/
/* Action value types */
/**********************/

%union {
    int iVal;
    TERNARY_TREE  tVal;
}

/* We can declare types of tree nodes */
/* These are the types of lexical tokens -> iVal */
%token<iVal> identifier_key INTERGER_NUM CHARACTER_CONSTANT FLOAT_NUM


%token SEMICOLON PERIOD COMMA COLON ASSIGN OPEN_BRACKET CLOSE_BRACKET EQUAL NOT_EQUAL LESS_THAN GREATER_THAN 
	LESS_THAN_OR_EQUAL GREATER_THAN_OR_EQUAL PLUS MINUS TIMES DIVIDE ENDP CODE DECLARATIONS OF TYPE_KEY IF ENDIF THEN ELSE DO 
	WHILE ENDDO FOR IS BY TO ENDFOR ENDWHILE WRITE NEWLINE READ NOT AND OR CHARACTER INTEGER REAL 
	
%type<tVal> program block declaration_block type statement_list
				statement assignment_statement if_statement do_statement while_statement
				for_statement write_statement read_statement output_list conditional 
				condition comparator expression term value constant number_constant 
				result_number identifiers

%%
program : identifier_key COLON block ENDP identifier_key PERIOD { 
					TERNARY_TREE ParseTree;
					ParseTree = create_node($1, PROGRAM, $3, NULL, NULL, NULL);
					
#ifdef DEBUG
						PrintTree(ParseTree,0);
#else
						if($1 != $5) fprintf(stderr,"\033[0;33m[WARNING]\033[0m Start identifier does not match to the end identifier!\n");
						WriteCode(ParseTree);
						/*CheckForUnusedVariables();*/
#endif
					};

block : DECLARATIONS declaration_block CODE statement_list 
			{ 
				$$ = create_node(NOTHING, BLOCK_1, $2, $4, NULL,NULL);
        	}
			| CODE statement_list 
			{ 
				$$ = create_node(NOTHING, BLOCK_2, $2, NULL, NULL, NULL);
        	};

declaration_block : identifiers OF TYPE_KEY type SEMICOLON
					{ 
                		$$ = create_node(NOTHING, DECLARATION_BLOCK_1, $1, $4, NULL,NULL);
        			} 
					| identifiers OF TYPE_KEY type SEMICOLON declaration_block 
					{ 
		                $$ = create_node(NOTHING, DECLARATION_BLOCK_2, $1, $4, $6,NULL);
		        	};

identifiers : identifier_key
				{ 
		            $$ = create_node($1, DECLARATION_1, NULL, NULL, NULL,NULL);
		        }
				| identifier_key COMMA identifiers
				{ 
		            $$ = create_node($1, DECLARATION_2, $3, NULL, NULL, NULL);
		        };

type : CHARACTER 
		{ 
            $$ = create_node(CHARACTER, TYPE, NULL, NULL, NULL, NULL);
        }
		| INTEGER 
		{ 
            $$ = create_node(INTEGER, TYPE, NULL, NULL, NULL, NULL);
        }
		| REAL 
		{ 
            $$ = create_node(REAL, TYPE, NULL, NULL, NULL, NULL);
        };

statement_list : statement SEMICOLON statement_list
				{ 
                	$$ = create_node(NOTHING, STATEMENT_LIST_1, $1, $3, NULL, NULL);
        		}
				| statement 
				{ 
                	$$ = create_node(NOTHING, STATEMENT_LIST_2, $1, NULL, NULL, NULL);
        		};
			
statement : assignment_statement {$$ = create_node(NOTHING, STATEMENT_ASS, $1,NULL, NULL, NULL);}
			| if_statement {$$ = create_node(NOTHING, STATEMENT_IF, $1, NULL, NULL, NULL);}
			| do_statement {$$ = create_node(NOTHING, STATEMENT_DO, $1, NULL, NULL, NULL);}
			| while_statement {$$ = create_node(NOTHING, STATEMENT_WHILE, $1, NULL, NULL, NULL);}
			| for_statement {$$ = create_node(NOTHING, STATEMENT_FOR, $1, NULL, NULL, NULL);}
			| write_statement {$$ = create_node(NOTHING, STATEMENT_WRITE, $1, NULL, NULL, NULL);}
			| read_statement {$$ = create_node(NOTHING, STATEMENT_READ, $1, NULL, NULL, NULL);};

assignment_statement : expression ASSIGN identifier_key
					{ 
	                  $$ = create_node($3, ASSIGMENT_STATMENT, $1, NULL, NULL, NULL);
	            	} ;

if_statement : IF conditional THEN statement_list ELSE statement_list ENDIF
				{ 
	                $$ = create_node(NOTHING, IF_STATEMENT_1, $2, $4, $6, NULL);
	            }
				| IF conditional THEN statement_list ENDIF
				{ 
	                $$ = create_node(NOTHING, IF_STATEMENT_2, $2, $4, NULL, NULL);
	            };
				
do_statement : DO statement_list WHILE conditional ENDDO 
				{ 
	                $$ = create_node(NOTHING, DO_STATEMENT, $2, $4, NULL, NULL);
	            };
for_statement : FOR identifier_key IS expression BY expression TO expression DO statement_list ENDFOR 
				{ 
	                $$ = create_node($2, FOR_STATEMENT, $4, $6, $8, $10);
	            };
while_statement : WHILE conditional DO statement_list ENDWHILE 
				{ 
	                $$ = create_node(NOTHING, WHILE_STATEMENT, $2, $4, NULL, NULL);
	            };

write_statement : WRITE OPEN_BRACKET output_list CLOSE_BRACKET 
				{ 
	        	    $$ = create_node(NOTHING, WRITE_STATEMENT_1, $3, NULL, NULL, NULL);
	            }
				| NEWLINE 
				{ 
	        	    $$ = create_node(NEWLINE, WRITE_STATEMENT_2, NULL, NULL, NULL, NULL);
	            };

read_statement : READ OPEN_BRACKET identifier_key CLOSE_BRACKET 
				{ 
	        	    $$ = create_node($3, READ_STATEMENT, NULL, NULL, NULL, NULL);
	            };

output_list : value COMMA output_list
				{ 
	        	    $$ = create_node(NOTHING, OUTPUT_LIST_1, $1, $3, NULL, NULL);
	            }
				| value 
				{ 
	        	    $$ = create_node(NOTHING, OUTPUT_LIST_2, $1, NULL, NULL, NULL);
	            };

conditional : conditional AND condition
				{ 
	        	    $$ = create_node(NOTHING, CONDITIONAL_1, $1, $3, NULL, NULL);
	            }
				| conditional OR condition
				{ 
	        	    $$ = create_node(NOTHING, CONDITIONAL_2, $1, $3, NULL, NULL);
	            }
				| condition
				{ 
	        	    $$ = create_node(NOTHING, CONDITIONAL_3, $1, NULL, NULL, NULL);
	            }
				
condition : expression comparator expression 
				{ 
	        	    $$ = create_node(NOTHING, CONDITION_1, $1, $2, $3, NULL);
	            }
				| NOT condition 
				{ 
	        	    $$ = create_node(NOTHING, CONDITION_2, $2, NULL, NULL, NULL);
	            };

comparator : EQUAL 
				{ 
	        	    $$ = create_node(EQUAL, COMPAROTOR_1, NULL, NULL, NULL, NULL);
	            }
				| NOT_EQUAL 
				{ 
	        	    $$ = create_node(NOT_EQUAL, COMPAROTOR_2, NULL, NULL, NULL, NULL);
	            }
				| LESS_THAN 
				{ 
	        	    $$ = create_node(LESS_THAN, COMPAROTOR_3, NULL, NULL, NULL, NULL);
	            }
				| GREATER_THAN 
				{ 
	        	    $$ = create_node(GREATER_THAN, COMPAROTOR_4, NULL, NULL, NULL, NULL);
	            }
				| LESS_THAN_OR_EQUAL 
				{ 
	        	    $$ = create_node(LESS_THAN_OR_EQUAL, COMPAROTOR_5, NULL, NULL, NULL, NULL);
	            }
				| GREATER_THAN_OR_EQUAL 
				{ 
	        	    $$ = create_node(GREATER_THAN_OR_EQUAL, COMPAROTOR_6, NULL, NULL, NULL, NULL);
	            };

expression : expression PLUS term 
				{ 
	        	    $$ = create_node(NOTHING, EXPRESSION_1, $1, $3, NULL, NULL);
	            }
				| expression MINUS term
				{ 
	        	    $$ = create_node(NOTHING, EXPRESSION_2, $1, $3, NULL, NULL);
	            }  
				| term
				{ 
	        	    $$ = create_node(NOTHING, EXPRESSION_3, $1, NULL, NULL, NULL);
	            };

term : term TIMES value
		{ 
	       	$$ = create_node(NOTHING, TERM_1, $1, $3, NULL, NULL);
	    } 
		| term DIVIDE value
		{ 
	       	$$ = create_node(NOTHING, TERM_2, $1, $3, NULL, NULL);
	    } 
		| value
		{ 
	       	$$ = create_node(NOTHING, TERM_3, $1, NULL, NULL, NULL);
	    };

value : identifier_key 
		{ 
	       	$$ = create_node($1, VALUE_ID, NULL, NULL, NULL, NULL);
	    }
		| constant
		{ 
	       	$$ = create_node(NOTHING, VALUE_CONSTANT, $1, NULL, NULL, NULL);
	    }
		| OPEN_BRACKET expression CLOSE_BRACKET 
		{ 
	       	$$ = create_node(NOTHING, VALUE_EX, $2, NULL, NULL, NULL);
	    };

constant : number_constant 
		{ 
	       	$$ = create_node(NOTHING, CONSTANT, $1, NULL, NULL, NULL);
	    }
		| CHARACTER_CONSTANT
		{ 
	       	$$ = create_node($1, CHAR_CONSTANT, NULL, NULL, NULL, NULL);
	    };			

number_constant : result_number 
				{ 
			       	$$ = create_node(NOTHING, NUMBER_CONSTANT, $1, NULL, NULL, NULL);
			    }
				| MINUS result_number
				{ 
			       	$$ = create_node(NOTHING, MINUS_NUMBER_CONSTANT,$2, NULL, NULL, NULL);
			    };
				
result_number : INTERGER_NUM 
				{ 
			       	$$ = create_node($1, RESULT_NUMBER_INT, NULL, NULL, NULL, NULL);
			    }
				| FLOAT_NUM
				{ 
			       	$$ = create_node($1, RESULT_NUMBER_FLO, NULL, NULL, NULL, NULL);
			    }
%%

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