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
    sprintf(str, "%df%d", valuef.numerator, valuef.denominator);
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
        printf("str[i]: %c\n", str[i]);
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


#endif // VALUEF_H