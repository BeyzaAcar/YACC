#ifndef VALUEF_H
#define VALUEF_H

#include "helpers.h"
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
    while (str[i] != 'f'){
        numerator[i] = str[i];
        i++;
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

// find greatest common divisor
int findGCD(int a, int b){
    if (b == 0)
        return a;
    return findGCD(b, a % b);
}

// simplify valuef
valuef_t simplifyF(valuef_t valuef){
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
    printf("equalF\n");
    printf("a: %s\n", a);
    printf("b: %s\n", b);
    valuef_t valuefA = createValueF(a);
    valuef_t valuefB = createValueF(b);

    printf("after createValueF\n");
    printf("valuefA.numerator: %d\n", valuefA.numerator);
    printf("valuefA.denominator: %d\n", valuefA.denominator);
    printf("valuefB.numerator: %d\n", valuefB.numerator);
    printf("valuefB.denominator: %d\n", valuefB.denominator);

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

// EVALUATE AN EXPRESSION WITH VALUEF OPERANDS RECURSIVELY USING THE ABOVE FUNCTIONS
// example : (- (+ 2f2 8f4) 1f1) --> (- 3f1 1f1) --> 2f1 

int paranthesesHashList[1000] ; // list of parantheses hash

//This method finds the pairs of parantheses and adds them to the paranthesesHashList 
//Example: (- (+ 2f2 8f4) 1f1) --> so there are open parantheses at index 0 and 3 and close parantheses at index 13 and 18
//so paranthesesHashList[0] = 13 and paranthesesHashList[3] = 18 and all other elements of paranthesesHashList are -1
//So when i try to reach the end of the parantheses pair of index 0, i can reach it by paranthesesHashList[0] = 13th index
void findParantheses(char *expression){
    //fill with -1 first
    printf("findParantheses\n");
    for(int i = 0; i < 1000; i++)
        paranthesesHashList[i] = -1;

    int begin = 0;
    int end = strlen(expression) - 1;
    while(end> begin && end+begin < strlen(expression) && end > 0 && begin < strlen(expression))
    {
        printf("begin: %d\n", begin);
        printf("end: %d\n", end);
        while (expression[begin] != '(' && begin < strlen(expression))
        {
            printf("begin inside: %d\n", begin);
            begin++;
        }
        while(expression[end] != ')' && end > 0)
        {
            printf("end inside: %d\n", end);
            end--;
        }

        paranthesesHashList[begin] = end;

        begin++;
        end--;
    }
    paranthesesHashList[begin-1] = -1;
    
}

void printParanthesesHashList(){
    printf("printParanthesesHashList\n");
    for(int i = 0; i < 25; i++)
        printf("paranthesesHashList[%d] = %d\n", i, paranthesesHashList[i]);
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
    //printf("evaluateExpressionHelper\n");
    //printf("expression: %s\n", expression);
    char * operand1 = malloc(sizeof(char) * 100);
    char * operand2 = malloc(sizeof(char) * 100);
    char operator = expression[1]; // operator is the second character of the expression 
    //printf("operator: %c\n", operator);
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
            //operand 1 is the expression between i and j 
            int k = 0;
            while(i < closeParanthesesIndex - beginOffset+1)
            {
                operand1[k] = expression[i];
                i++;
                k++;
            }
            operand1[k] = '\0';
            // recursive call to evaluate the expression
            operand1 = evaluateExpressionHelper(operand1, i + beginOffset); 
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
            //operand 2 is the expression between i and j 
            int k = 0;
            while(i < closeParanthesesIndex - beginOffset)
            {
                operand2[k] = expression[i];
                i++;
                k++;
            }
            operand2[k] = '\0';
            // recursive call to evaluate the expression
            operand2 = evaluateExpressionHelper(operand2, i + beginOffset); 
            break;
        }
        i++;
    }
    
    printf("operand1: %s\n and the expression is %s\n", operand1, expression);
    printf("operand2: %s\n and the expression is %s\n", operand2, expression);
    printf("operator: %c\n", operator);
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
        //TODO: add other operators 
        /*case '=':
            if(equalF(operand1, operand2))
                result = "1";
            else
                result = "0";
            break;
        case '<':
            if(lessThanF(operand1, operand2))
                result = "1";
            else
                result = "0";
            break;
            */
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