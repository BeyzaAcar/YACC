%{
  /*definitions*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "y.tab.h"
//FILE *inputFile,*outputFile,*strFile;
%}
 /*Rule and DFA part of lexer*/
%%

 /*rules of operators*/

\+ { return OP_PLUS; }
\- { return OP_MINUS; }
\/ { return OP_DIV; }
\* { return OP_MULT; }

\( { return OP_OP; }
\) { return OP_CP; }
\, { return OP_COMMA; }

and { return KW_AND; }
def { return KW_DEF; }
or { return KW_OR; }
not { return KW_NOT; }
equal { return KW_EQUAL; }
less { return KW_LESS; }
nil { return KW_NIL; }
list { return KW_LIST; }
append { return KW_APPEND; }
concat { return KW_CONCAT; }
set { return KW_SET; }
for { return KW_FOR; }
if  { return KW_IF; }
exit { return KW_EXIT; }
load { return KW_LOAD; }
disp { return KW_DISP; }
true { return KW_TRUE; }
false { return KW_FALSE; }


 /*rule for comment*/
;;(.*) { return COMMENT; }
 /*rule for value*/
(0)|([1-9]*"f"[0-9]*) {
                        valuef_t valuef;
                        char *token;
                        token = strtok(yytext, "f");
                        valuef.numerator = atoi(token);
                        token = strtok(NULL, "f");
                        valuef.denominator = atoi(token);
                        yylval.fractionalNum = valuef;
                        return VALUEF; 
                    }

 /* rule for identifier*/
[a-zA-Z][0-9a-zA-Z]* {
                      yylval.str = malloc(strlen(yytext)+1); //+1 for '\0' at the end
                      strcpy(yylval.str, yytext);
                      return IDENTIFIER; }
[\n\f\r\t ] {} /*ignorable tokens*/



 /*
  * ERRORS
  */
. { return 0; }
([a-zA-Z]*[,+-/*])|([0-9][0-9a-zA-Z]+) {  return 0;}
[+][0-9A-zA-Z]* { return 0;}
[-][0-9A-zA-Z]*	{ return 0;}
[/][0-9A-zA-Z]* {  return 0;}
[*][0-9A-zA-Z]* {  return 0;}
[,][0-9A-zA-Z]* {  return 0;}
%%
int yywrap(){}

