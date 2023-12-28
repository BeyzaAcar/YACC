#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int yylex(); //lex function to get tokens from lex file (gpp_lexer.l)
int yyerror(char *error); // error function to print error messages

// a struct to keep valuef ( fractional value) ex : 4f2 
typedef struct valuef_s
{
    int numerator;
    int denominator;
} valuef_t;


// function with no parameters struct
typedef struct function0_s
{
    char name[30];
    char body[100];
} function0_t;

// function with one parameter struct
typedef struct function1_s
{
    char name[30];
    char parameter[30];
    char body[100];
} function1_t;

// function with two parameters struct
typedef struct function2_s
{
    char name[30];
    char parameter1[30];
    char parameter2[30];
    char body[100];
} function2_t;


#endif /* HELPERS_H */