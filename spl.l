%{
#ifdef PRINT
#define TOKEN(t) printf("Token: " #t "\n");
#define ID(t) printf("Identifier: %s Token: " #t "\n", yytext);
#define CHAR(t) printf("Char: %s Token: " #t "\n", yytext);
#define TOKENINTEGER(t) printf("Integer: %d Token: " #t "\n", atoi(yytext));
#define TOKENFLOAT(t) printf("Float: %f Token: " #t "\n", atof(yytext)); 
#else
#include <strings.h>
extern SYMTABNODEPTR symTab[SYMTABSIZE];
extern int currentSymTabSize;

#define TOKEN(t) return(t);
#define ID(t) yylval.iVal = installId(yytext); return (t);
#define CHAR(t) yylval.iVal = installId(yytext); return (t);
#define TOKENINTEGER(t) yylval.iVal = atoi(yytext); return (t);
#define TOKENFLOAT(t) yylval.iVal = installId(yytext); return (t);
#endif
%}
delim			[ \t\n\r]
ws				{delim}+
digit			[0-9]
character		[A-Za-z]
character_constant	"'"[A-Za-z]"'"
integerNum		{digit}+
floatNum		[0-9]+(\.[0-9]+)
identifier		{character}({character}|{digit})*
%%
";"				TOKEN(SEMICOLON);
"."				TOKEN(PERIOD);
","				TOKEN(COMMA);
":"				TOKEN(COLON);
"->"			TOKEN(ASSIGN);
"("				TOKEN(OPEN_BRACKET);
")"				TOKEN(CLOSE_BRACKET);
"="				TOKEN(EQUAL);
"<>"			TOKEN(NOT_EQUAL);
"<"				TOKEN(LESS_THAN);
">"				TOKEN(GREATER_THAN);
"<="			TOKEN(LESS_THAN_OR_EQUAL);
">="			TOKEN(GREATER_THAN_OR_EQUAL);
"+"				TOKEN(PLUS);
"-"				TOKEN(MINUS);
"*"				TOKEN(TIMES);
"/"				TOKEN(DIVIDE);

"CHARACTER" 	TOKEN(CHARACTER);
"INTEGER" 		TOKEN(INTEGER);
"REAL" 			TOKEN(REAL);

"ENDP"			TOKEN(ENDP);
"CODE"			TOKEN(CODE);
"DECLARATIONS"	TOKEN(DECLARATIONS);
"OF"			TOKEN(OF);
"TYPE"			TOKEN(TYPE_KEY);
"IF"			TOKEN(IF);
"ENDIF"			TOKEN(ENDIF);
"THEN"			TOKEN(THEN);
"ELSE"			TOKEN(ELSE);
"DO"			TOKEN(DO);
"WHILE"			TOKEN(WHILE);
"ENDDO"			TOKEN(ENDDO);
"FOR"			TOKEN(FOR);
"IS"			TOKEN(IS);
"BY"			TOKEN(BY);
"TO"			TOKEN(TO);
"ENDFOR"		TOKEN(ENDFOR);
"ENDWHILE"		TOKEN(ENDWHILE);
"WRITE"			TOKEN(WRITE);
"NEWLINE"		TOKEN(NEWLINE);
"READ"			TOKEN(READ);
"NOT"			TOKEN(NOT);
"AND"			TOKEN(AND);
"OR"			TOKEN(OR);

{identifier}	ID(identifier_key);
{character_constant}  CHAR(CHARACTER_CONSTANT);
{integerNum}	TOKENINTEGER(INTERGER_NUM);
{floatNum}		TOKENFLOAT(FLOAT_NUM);
{ws}			;
.				fprintf(stderr,"\033[0;31m[ERROR]\033[0m Unexpected symbol in the lexer %s\n",yytext);
%%

#ifndef PRINT
/* Here is the code for the library of symbol table routines */

/* code for a simple symbol table, which is an array of pointers to
   structs, each of which contains an identifier.
*/


SYMTABNODEPTR newSymTabNode()
{
    return ((SYMTABNODEPTR)malloc(sizeof(SYMTABNODE)));
}

int lookup(char *s)
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE];
    extern int currentSymTabSize;
    int i;

    for(i=0; i<currentSymTabSize; i++)
    {
        if(strncmp(s,symTab[i]->identifier,IDLENGTH) == 0)
        {
            return (i);
        }
    }
    return (-1);    
}

/* Look up an identifier in the symbol table, if its there return
   its index.  If its not there, put it in the end position,
   as long as the table isn't full, and return its index.
*/

int installId(char *id) 
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE]; 
    extern int currentSymTabSize;
    int index;

    index = lookup(id);
    if (index >= 0)
    {
        return (index);
    }
    else 
       if (currentSymTabSize >= SYMTABSIZE) 
          /* SYMTAB is full */
          return (NOTHING) ;
    else
    {
       symTab[currentSymTabSize] = newSymTabNode();
	   if (symTab[currentSymTabSize] == NULL) { 
	      fprintf(stderr, "installId:Out of memory: %s %d\n", id, (int)sizeof(SYMTABNODEPTR)); 
		  return(NOTHING);
		  }
       /* Recommended code for preventing buffer overrun on bounded strings */
       strncpy(symTab[currentSymTabSize]->identifier,id,IDLENGTH);
       symTab[currentSymTabSize]->identifier[IDLENGTH-1] = '\0';
       
	   return(currentSymTabSize++);
    }
}
#endif