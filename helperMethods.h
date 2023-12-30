#ifndef HELPERMETHODS_H
#define HELPERMETHODS_H

#include <string.h>
#include <stdlib.h>

// Expression struct
char * createExpString(char *exp1, char *exp2, char *op)
{
    // (OP EXP1 EXP2)
    int len = strlen(exp1) + strlen(exp2) + strlen(op) + 5;
    char *exp = (char *)malloc(len * sizeof(char));
    strcpy(exp, "(");
    strcat(exp, op);
    strcat(exp, " ");
    strcat(exp, exp1);
    strcat(exp, " ");
    strcat(exp, exp2);
    strcat(exp, ")");
    return exp;
}

//isDigit function 
int isDigit(char c){
  return (c >= '0' && c <= '9');
}


#endif /* HELPERMETHODS_H */