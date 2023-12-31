// Creator:  <Beyza Acar>

#ifndef VALUEF_H
#define VALUEF_H

#include "structs.h"
#include <stdlib.h>

/*
//This library does some operations on string valueF type and returns string valueF 


* This library does some operations on valuef_t type (fractional numbers) like :
    * sum of two valuef_t
    * subtraction of two valuef_t
    * multiplication of two valuef_t
    * division of two valuef_t
    * simplify valuef_t
    * change valuef_t to string for printing
    * check if two valuef_t are equal
    * check if a valuef_t is less than another valuef_t
    * create a zero valuef_t
    * create a valuef_t from string
*/


//change valuef to string for printing
char *valuefToString(valuef_t valuef){
    char *str = malloc(sizeof(char) * 100);
    sprintf(str, "%df%d", valuef.numerator, valuef.denominator); //sprintf writes to string instead of stdout and adds '\0' at the end 
    return str;
}

// This method creates a valuef_t from string search for 'f' and divide the string into two parts 
// and convert them to integer and return a valuef_t
valuef_t createValueF(char *str){
    //it is assumed that str is in the form of "numerator(f)denominator"
    //for example: "1f2" or "123f456"
    valuef_t valuef;
    char *numerator = malloc(sizeof(char) * 10); // max 10 digits
    char *denominator = malloc(sizeof(char) * 10); // max 10 digits
    int i = 0;
    while (str[i] != 'f' && str[i] != '\0'){
        numerator[i] = str[i];
        i++;
    }
    //if there are no 'f' in the string, this is an error
    if (str[i] == '\0'){
        printf("ERROR: This is not a valueF\n");
        printf("Exiting...\n");
        exit(1);
    }
    numerator[i] = '\0';
    i++;
    int j = 0;
    while (str[i] != '\0'){
        denominator[j] = str[i];
        i++;
        j++;
    }
    denominator[j] = '\0';
    valuef.numerator = atoi(numerator);
    valuef.denominator = atoi(denominator);
    return valuef;
}

// OPERATIONS ON VALUEF OPERANDS

int findGCD(int a, int b){
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}
valuef_t simplifyF(valuef_t valuef){
    // simplifies a valuef_t
    int gcd = findGCD(valuef.numerator, valuef.denominator);
    valuef.numerator /= gcd;
    valuef.denominator /= gcd;
    return valuef;
}
char* sumF(char* a, char* b){
    valuef_t valuefA = createValueF(a);
    valuef_t valuefB = createValueF(b);
    valuef_t result;
    result.numerator = valuefA.numerator * valuefB.denominator + valuefB.numerator * valuefA.denominator;
    result.denominator = valuefA.denominator * valuefB.denominator;
    result = simplifyF(result);
    return valuefToString(result);
}
char* subF(char* a, char* b){
    valuef_t valuefA = createValueF(a);
    valuef_t valuefB = createValueF(b);
    valuef_t result;
    result.numerator = valuefA.numerator * valuefB.denominator - valuefB.numerator * valuefA.denominator;
    result.denominator = valuefA.denominator * valuefB.denominator;
    result = simplifyF(result);
    return valuefToString(result);
}
char* multF(char* a, char* b){
    valuef_t valuefA = createValueF(a);
    valuef_t valuefB = createValueF(b);
    valuef_t result;
    result.numerator = valuefA.numerator * valuefB.numerator;
    result.denominator = valuefA.denominator * valuefB.denominator;
    result = simplifyF(result);
    return valuefToString(result);
}
char* divF(char* a, char* b){
    valuef_t valuefA = createValueF(a);
    valuef_t valuefB = createValueF(b);
    valuef_t result;
    result.numerator = valuefA.numerator * valuefB.denominator;
    result.denominator = valuefA.denominator * valuefB.numerator;
    result = simplifyF(result);
    return valuefToString(result);
}
int equalF(char* a, char* b){
    valuef_t valuefA = createValueF(a);
    valuef_t valuefB = createValueF(b);

    if(valuefA.numerator * valuefB.denominator == valuefB.numerator * valuefA.denominator)
        return 1;
    return 0;
}
int lessThanF(char* a, char* b){
    valuef_t valuefA = createValueF(a);
    valuef_t valuefB = createValueF(b);
    if (valuefA.numerator * valuefB.denominator < valuefB.numerator * valuefA.denominator)
        return 1;
    return 0;
}

valuef_t createZeroValueF(){
    valuef_t valuef;
    valuef.numerator = 0;
    valuef.denominator = 1;
    return valuef;
}

// check if a character is a digit
int isDigitF(char c){
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}

int paranthesesHashList[1000] ; // list of parantheses hash

//This method finds the pairs of parantheses and adds them to the paranthesesHashList 
//Example: (- (+ 2f2 8f4) 1f1) --> so there are open parantheses at index 0 and 3 and close parantheses at index 13 and 18
//so paranthesesHashList[0] = 13 and paranthesesHashList[3] = 18 and all other elements of paranthesesHashList are -1
//So when i try to reach the end of the parantheses pair of index 0, i can reach it by paranthesesHashList[0] = 13th index
void findParantheses(char *expression){
    //fill with -1 first
    for(int i = 0; i < 1000; i++)
        paranthesesHashList[i] = -1;

    int begin = 0;
    int end = strlen(expression) - 1;
    while(end> begin && end < strlen(expression) && begin < strlen(expression))
    {
        while (begin < strlen(expression) && expression[begin] != '(')
            begin++;
        while(end > 0 && expression[end] != ')')
            end--;

        paranthesesHashList[begin] = end;

        begin++;
        end--;
    }
    paranthesesHashList[begin-1] = -1; 
    
}

/**
 * begin offset is the ditance from the beginning of the original expression
 * end offset is the distance from the end of the original expression 
 * This method returns the evaluated expression in a string recursively
 * Every pair of parantheses is added to the paranthesesHashList (Check findParantheses method to understand how it works)
 * Example input : (- (+ 2f2 8f4) 1f1) --> (- 3f1 1f1) --> 2f1 
*/
char * evaluateExpressionHelper(char * expression, int beginOffset)
{
    char * operand1 = malloc(sizeof(char) * 100);
    char * operand2 = malloc(sizeof(char) * 100);
    char operator = expression[1]; // operator is the second character of the expression 
    int i = 1;
    int lenExp = strlen(expression);

    //first operand
    while(i < lenExp)
    {
        if(isDigitF(expression[i])) // first operand is the raw valuef
        {
            int j = 0;
            while(isDigitF(expression[i]) | expression[i] == 'f')
            {
                operand1[j] = expression[i];
                i++;
                j++;
            }
            operand1[j] = '\0';
            break;
        }
        else if(expression[i] == '(') // first operand is an expression
        {
            int closeParanthesesIndex = paranthesesHashList[i + beginOffset];
            int k = 0;
            int beginOffsetHold = i;
            while(i < closeParanthesesIndex - beginOffset)
            {
                operand1[k] = expression[i];
                i++;
                k++;
            }
            operand1[k] = '\0';
            operand1 = evaluateExpressionHelper(operand1, beginOffset+ beginOffsetHold); 
            break;
        }
        i++;
    }
    //second operand
    while(i < lenExp)
    {
        if(isDigitF(expression[i])) // second operand is the raw valuef
        {
            int j = 0;
            while(isDigitF(expression[i]) | expression[i] == 'f')
            {
                operand2[j] = expression[i];
                i++;
                j++;
            }
            operand2[j] = '\0';
            break;
        }
        else if(expression[i] == '(') // second operand is an expression
        {
            int closeParanthesesIndex = paranthesesHashList[i + beginOffset];
            int k = 0;
            int beginOffsetHold = i;
            while(i < closeParanthesesIndex - beginOffset)
            {
                operand2[k] = expression[i];
                i++;
                k++;
            }
            operand2[k] = '\0';
            operand2 = evaluateExpressionHelper(operand2, beginOffsetHold + beginOffset); 
            break;
        }
        i++;
    }
    
    //evaluate the expression
    char * result = malloc(sizeof(char) * 100);
    switch(operator)
    {
        case '+':
            result = sumF(operand1, operand2);
            break;
        case '-':
            result = subF(operand1, operand2);
            break;
        case '*':
            result = multF(operand1, operand2);
            break;
        case '/':
            result = divF(operand1, operand2);
            break;
        default:
            printf("Invalid operator\n");
            break;
    }
    return result;
}

//EVALUATE EXPRESSION RECURSIVELY 
char * evaluateExpression(char * expression)
{
    evaluateExpressionHelper(expression, 0);
}





#endif // VALUEF_H