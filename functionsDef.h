#ifndef FUNCTIONSDEF_H
#define FUNCTIONSDEF_H

#include "helpers.h" //to use valuef_t type (fractional value) and function_t typeS (function0_t, function1_t, function2_t)

// There are 3 functions types (all of them return valuef_t)
// 1. function with no parameters
// 2. function with one parameter
// 3. function with two parameters

// a list to store function2_ts (function with two parameters)
typedef struct function2_t_list
{
    function2_t function2;
    struct function2_t_list *next;
} function2_t_list;

// a list to store function1_ts (function with one parameter)
typedef struct function1_t_list
{
    function1_t function1;
    struct function1_t_list *next;
} function1_t_list;

// a list to store function0_ts (function with no parameters)
typedef struct function0_t_list
{
    function0_t function0;
    struct function0_t_list *next;
} function0_t_list;


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


// add function0 to function0_t_list
function0_t_list* addFunction0(function0_t_list* function0List, function0_t function0)
{
    printf("addFunction0\n");
    function0_t_list* newFunction0List = malloc(sizeof(function0_t_list));
    newFunction0List->function0 = function0;
    newFunction0List->next = function0List;
    return newFunction0List;
}

// add function1 to function1_t_list
function1_t_list* addFunction1(function1_t_list* function1List, function1_t function1)
{
    printf("addFunction1\n");
    function1_t_list* newFunction1List = malloc(sizeof(function1_t_list));
    newFunction1List->function1 = function1;
    newFunction1List->next = function1List;
    return newFunction1List;
}

// add function2 to function2_t_list
function2_t_list* addFunction2(function2_t_list* function2List, function2_t function2)
{
    printf("addFunction2\n");
    function2_t_list* newFunction2List = malloc(sizeof(function2_t_list));
    newFunction2List->function2 = function2;
    newFunction2List->next = function2List;
    return newFunction2List;
}








#endif /* FUNCTIONSDEF_H */