#ifndef VALUEF_H
#define VALUEF_H

#include "helpers.h"
#include <stdlib.h>

valuef_t createValueF(char *str){
    valuef_t valuef;
    char *token;
    token = strtok(str, "f");
    valuef.numerator = atoi(token);
    token = strtok(NULL, "f");
    valuef.denominator = atoi(token);
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

valuef_t sumF(valuef_t a, valuef_t b){
    valuef_t result;
    result.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    result = simplifyF(result);
    return result;
}

valuef_t subF(valuef_t a, valuef_t b){
    valuef_t result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    result = simplifyF(result);
    return result;
}

valuef_t multF(valuef_t a, valuef_t b){
    valuef_t result;
    result.numerator = a.numerator * b.numerator;
    result.denominator = a.denominator * b.denominator;
    result = simplifyF(result);
    return result;
}

valuef_t divF(valuef_t a, valuef_t b){
    valuef_t result;
    result.numerator = a.numerator * b.denominator;
    result.denominator = a.denominator * b.numerator;
    result = simplifyF(result);
    return result;
}

//change valuef to string for printing
char *valuefToString(valuef_t valuef){
    char *str = malloc(sizeof(char) * 100);
    sprintf(str, "%df%d", valuef.numerator, valuef.denominator);
    return str;
}

int equalF(valuef_t a, valuef_t b){
    if (a.numerator == b.numerator && a.denominator == b.denominator)
        return 1;
    return 0;
}

int lessThanF(valuef_t a, valuef_t b){
    if (a.numerator * b.denominator < b.numerator * a.denominator)
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