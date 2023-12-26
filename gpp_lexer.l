%{
  /*definitions*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
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

 /*rules for keywords in g++ language*/
and { return KW_AND; }
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
                        printf("numerator: %d, denominator: %d\n", valuef.numerator, valuef.denominator);
                        yylval.fractionalNum = valuef;
                        return VALUEF; 
                    }

 /* rule for identifier*/
[a-zA-Z][0-9a-zA-Z]* {strcpy(yylval.str, yytext); return IDENTIFIER; }
[\n\f\r\t ] {} /*ignorable tokens*/
 /*
  * violation part -any stament nothing but
  * different than these rules will be caught.-
  */
. {return 0;}
([a-zA-Z]*[,+-/*])|([0-9][0-9a-zA-Z]+) { return 0;}
[+][0-9A-zA-Z]* {return 0;}
[-][0-9A-zA-Z]*	{return 0;}
[/][0-9A-zA-Z]* {return 0;}
[*][0-9A-zA-Z]* { return 0;}
[,][0-9A-zA-Z]* { return 0;}
%%
int yywrap(){}
/*int main(int argc, char **argv){
  outputFile = fopen("output.txt","w");
  if(outputFile == NULL)
  {
    printf("Error output.txt doesn't exist!\n");
    exit(1);
  }
  if(argc > 1){
    //read input from file
    inputFile = fopen(argv[1],"r");
    if(inputFile == NULL)
    {
      printf("Error program doesn't exist!\n");
      exit(1);
    }
    yyin = inputFile;
    yylex();
    printf("File has created!\n");
  }
  else{
    //read input from terminal in repl mode
    printf("Welcome to G++ shell \n> ");
    char* newLine = NULL;
    char* line = (char*)malloc(20*sizeof(char));;
    int is_empty_string;
    size_t size = 0;
    //read until empty string and store them
    do{
      is_empty_string = getline(&newLine, &size, stdin);
      if(is_empty_string != 1){
        line = (char *) realloc(line, (strlen(line)+size+2)*sizeof(char));
        strcat(line,newLine);
      }
    }while(is_empty_string != 1);
    //after reading, tokenize by using string stream function fmemopen
    strFile = fmemopen (line, strlen (line) - 1, "r");
    yyin = strFile;
    yylex(); // this method is used for tokenizing the input and writing to output.txt by using fprintf function in yylex function
    printf("File has created!\n");
  }
  exit(-1);
}*/