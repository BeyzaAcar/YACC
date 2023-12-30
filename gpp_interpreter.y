%{
/*definitions*/
#include <stdio.h> 
#include <stdlib.h> //for exit function and malloc
#include <string.h> //for string operations

#include "helpers.h" // for all the structs (valuef_t, variable_t, function_t)

FILE *inputFile,*outputFile, *strFile; //input and output files for reading and writing

extern FILE *yyin;
void writeList(int *list);

// /*functions*/
#include "valueF.h" //functions for fractional numbers
#include "variables.h" //functions for variables (set, get)
#include "functionsDef.h" //functions for functions definitions (set, get)

%}

%union{
    int num;
    int *nums;
    char *str;
    valuef_t fractionalNum;
}
 /*tokens of operators*/
%token OP_PLUS
%token OP_MINUS
%token OP_DIV
%token OP_MULT

%token OP_OP
%token OP_CP
%token OP_COMMA
 /*tokens for keywords in g++ language*/
%token KW_AND
%token KW_OR
%token KW_NOT
%token KW_EQUAL
%token KW_LESS
%token KW_NIL
%token KW_LIST
%token KW_APPEND
%token KW_CONCAT
%token KW_SET
%token KW_DEF
%token KW_FOR
%token KW_IF
%token KW_EXIT
%token KW_LOAD
%token KW_DISP
%token KW_TRUE
%token KW_FALSE
%token COMMENT

%token <fractionalNum> VALUEF
%token <str> IDENTIFIER

/*Types*/
%type <str> EXPI
%type <num> EXPB
%start START

%%
/*gpp Concrete Syntax*/
START:
    EXPI {printf("expi"); fprintf(outputFile,"CORRECT SYNTAX. \nResult: %s\n", $1 );}
    |
    EXPB {printf("expb"); fprintf(outputFile,"CORRECT SYNTAX. \nResult: %s\n", $1 == 1 ? "TRUE" : "FALSE");}
    |
    START EXPI {fprintf(outputFile,"CORRECT SYNTAX. \nResult: %s\n", $2); printf("expression is : %s\n", $2);}
    |
    START EXPB {printf("start expb"); fprintf(outputFile,"CORRECT SYNTAX. \nResult: %s\n", $2 == 1 ? "TRUE" : "FALSE");}
    |
    COMMENT {}
    |
    START COMMENT {}
    |
    OP_OP KW_EXIT OP_CP { printf("File has created!\n"); exit(-1);}
    |
    START OP_OP KW_EXIT OP_CP { printf("File has created!\n"); exit(-1); }
    ;
EXPI:
    OP_OP OP_PLUS EXPI EXPI OP_CP  { $$ = sumF($3, $4); }
    |
    OP_OP OP_MINUS EXPI EXPI OP_CP { $$ = subF($3, $4); } 
    |
    OP_OP OP_MULT EXPI EXPI OP_CP  { $$ = multF($3, $4); }
    |
    OP_OP OP_DIV EXPI EXPI OP_CP   {  $$ = divF($3, $4); }
    |
    OP_OP IDENTIFIER OP_CP {$$ = getVariableValue($2); }
    |
    IDENTIFIER {$$ = $1;} // an identifier in function definition
    |
    VALUEF {$$ = valuefToString($1) ;}
    |
    OP_OP KW_SET IDENTIFIER EXPI OP_CP {printf("burdayim sette\n"); $$ = $4; setVariable($3, $4);}
    |
    OP_OP KW_IF EXPB EXPI OP_CP { $$ = $3 ? $4 : "FALSE"; }  
    |
    OP_OP KW_FOR EXPB EXPI OP_CP { /* $$ = $4; for(int i=0; isTrue($3); ++i){$4 = $4;}*/ }
    |
    OP_OP KW_IF EXPB EXPI EXPI OP_CP { /* $$ = isTrue($3) ? $4 : $5; */ }
    |
    OP_OP KW_DISP EXPI OP_CP { /*$$ = $3; fprintf(outputFile,"Display : %d\n", $3);*/}
    ;

EXPB:
    OP_OP KW_AND EXPB EXPB OP_CP { $$ = $3 && $4;}
    |
    OP_OP KW_OR EXPB EXPB OP_CP  { $$ = $3 || $4; }
    |
    OP_OP KW_NOT EXPB OP_CP  { $$ = ! ($3); }
    |
    OP_OP KW_EQUAL EXPB EXPB OP_CP { $$ = ($3 == $4); }
    |
    OP_OP KW_EQUAL EXPI EXPI OP_CP { $$ = equalF($3, $4); }
    |
    OP_OP KW_LESS EXPI EXPI OP_CP { $$ = lessThanF($3, $4); }
    |
    KW_TRUE  { $$ = 1; }
    |
    KW_FALSE   { $$ = 0; }
    |
    OP_OP KW_DISP EXPB OP_CP { /* $$ = $3; fprintf(outputFile,"Display : %s\n", ($3 ? "T":"NIL")); */}
    ;

    

%%

int yyerror(char *error) {
    // this function is called when an error occurs. for example, when the input is not in the language. (syntax error)
    fprintf(outputFile, "SYNTAX ERROR \n");
}

void writeList(int *list){
    fprintf(outputFile, "(");
    for(int i=0;list[i]!=-999; ++i){
      if(list[i+1]!=-999){
        fprintf(outputFile,"%d ", list[i]);
      }
      else{
        fprintf(outputFile,"%d", list[i]);
      }
    }
    fprintf(outputFile, ")\n");
}


int main(int argc, char **argv){
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
      printf("Error File doesn't exist!\n");
      exit(1);
    }
    yyin = inputFile;
    yyparse();
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
    //after reading, tokenize by using string stream fuction fmemopen
    strFile = fmemopen (line, strlen (line) - 1, "r");
    yyin = strFile;
    yyparse();
    printf("The output.txt file is created!\n");
  }
  exit(-1);
}
