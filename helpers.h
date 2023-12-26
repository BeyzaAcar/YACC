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

/*This Linked List is to keep variables for set operation*/
typedef struct node_s
{
    valuef_t data;
    char name[30]; //variable name
    struct node_s *next; //pointer to next node
}node_t;

#endif /* HELPERS_H */