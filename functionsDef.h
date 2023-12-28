#ifndef FUNCTIONSDEF_H
#define FUNCTIONSDEF_H

#include "helpers.h" //to use valuef_t type (fractional value) and function_t typeS (function0_t, function1_t, function2_t)

// There are 3 functions types (all of them return valuef_t)
// 1. function with no parameters
// 2. function with one parameter
// 3. function with two parameters


// example function definition : (def sum x y (+ x y)) 

// function with no parameters
function0_t createFunction0(char* name, char* body)
{
    printf("createFunction0\n");
    function0_t function0;
    strcpy(function0.name, name);
    strcpy(function0.body, body);
    return function0;
}

// function with one parameter
function1_t createFunction1(char* name, char* parameter, char* body)
{
    printf("createFunction1\n");
    function1_t function1;
    strcpy(function1.name, name);
    strcpy(function1.parameter, parameter);
    strcpy(function1.body, body);
    return function1;
}


// function with two parameters
function2_t createFunction2(char* name, char* parameter1, char* parameter2, char* body)
{
    printf("createFunction2\n");
    function2_t function2;
    strcpy(function2.name, name);
    strcpy(function2.parameter1, parameter1);
    strcpy(function2.parameter2, parameter2);
    strcpy(function2.body, body);
    return function2;
}

// evaluate body of functions (function body can only be an expression) (example : (/(+ x y)z))








#endif /* FUNCTIONSDEF_H */