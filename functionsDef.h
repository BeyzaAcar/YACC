#ifndef FUNCTIONSDEF_H
#define FUNCTIONSDEF_H

#include "helpers.h" //to use valuef_t type (fractional value) and function_t typeS (function0_t, function1_t, function2_t)

// There are 3 functions types (all of them return valuef_t)
// 1. function with no parameters
// 2. function with one parameter
// 3. function with two parameters


// a linked list to store function2_ts (function with two parameters)
typedef struct function2_t_list
{
    function2_t function2;
    struct function2_t_list *next;
} function2_t_list;

// a linked list to store function1_ts (function with one parameter)
typedef struct function1_t_list
{
    function1_t function1;
    struct function1_t_list *next;
} function1_t_list;

// a linked list to store function0_ts (function with no parameters)
typedef struct function0_t_list
{
    function0_t function0;
    struct function0_t_list *next;
} function0_t_list;


// example function definition : (def sum x y (+ x y)) 

// LIST OF ALL DEFINED FUNCTIONS 
function2_t_list* function2_t_list_head = NULL;
function1_t_list* function1_t_list_head = NULL;
function0_t_list* function0_t_list_head = NULL;



// print the function2_t_list (TEMPORARY FUNCTION) (FOR TESTING)
void printFunctionInfos2()
{
    printf("printFunctionInfos2\n");
    function2_t_list* temp = function2_t_list_head;
    while(temp != NULL)
    {
        printf("name : %s\n", temp->function2.name);
        printf("parameter1 : %s\n", temp->function2.parameter1);
        printf("parameter2 : %s\n", temp->function2.parameter2);
        printf("body : %s\n", temp->function2.body);
        temp = temp->next;
    }
}

// add function0 to function0_t_list
void addFunction0(function0_t_list* function0List, function0_t function0)
{
    printf("addFunction0\n");
    function0_t_list* temp = function0List;
    if(temp == NULL) // if function0_t_list is empty (no function0 is defined)
    {
        function0_t_list_head = (function0_t_list*)malloc(sizeof(function0_t_list));
        function0_t_list_head->function0 = function0;
        function0_t_list_head->next = NULL;
        return;
    }
    // check if function0 is already defined 
    while(temp->next != NULL)
    {
        if(strcmp(temp->function0.name, function0.name) == 0)
        {
            printf("function0 is already defined\n");
            exit(1); // exit with error code 1
        }
        temp = temp->next;
    }

    // if function0 is not defined, add it to the end of the function0_t_list
    temp->next = (function0_t_list*)malloc(sizeof(function0_t_list));
    temp->next->function0 = function0;
    temp->next->next = NULL;
    // change the head of the function0_t_list
    function0_t_list_head = temp->next;
    return;
}

// add function1 to function1_t_list
void addFunction1(function1_t_list* function1List, function1_t function1)
{
    printf("addFunction1\n");
    function1_t_list* temp = function1List;
    if(temp == NULL) // if function1_t_list is empty (no function1 is defined)
    {
        function1_t_list_head = (function1_t_list*)malloc(sizeof(function1_t_list));
        function1_t_list_head->function1 = function1;
        function1_t_list_head->next = NULL;
        return;
    }
    // check if function1 is already defined 
    while(temp->next != NULL)
    {
        if(strcmp(temp->function1.name, function1.name) == 0)
        {
            printf("function1 is already defined\n");
            exit(1); // exit with error code 1
        }
        temp = temp->next;
    }

    // if function1 is not defined, add it to the end of the function1_t_list
    temp->next = (function1_t_list*)malloc(sizeof(function1_t_list));
    temp->next->function1 = function1;
    temp->next->next = NULL;
    // change the head of the function1_t_list
    function1_t_list_head = temp->next;
    return;
}

// add function2 to function2_t_list
void addFunction2(function2_t_list* function2List, function2_t function2)
{
    printf("addFunction2\n");
    function2_t_list* temp = function2List;
    if(temp == NULL) // if function2_t_list is empty (no function2 is defined)
    {
        function2_t_list_head = (function2_t_list*)malloc(sizeof(function2_t_list));
        function2_t_list_head->function2 = function2;
        function2_t_list_head->next = NULL;
        //print function2_t_list (TEMPORARY FUNCTION) (FOR TESTING)
        printf("printing function info NULL:\n");
        printFunctionInfos2();
        return;
    }
    // check if function2 is already defined 
    while(temp->next != NULL)
    {
        if(strcmp(temp->function2.name, function2.name) == 0)
        {
            printf("function2 is already defined\n");
            exit(1); // exit with error code 1
        }
        temp = temp->next;
    }

    // if function2 is not defined, add it to the end of the function2_t_list
    temp->next = (function2_t_list*)malloc(sizeof(function2_t_list));
    temp->next->function2 = function2;
    temp->next->next = NULL;
    // change the head of the function2_t_list
    function2_t_list_head = temp->next;

    //print function2_t_list (TEMPORARY FUNCTION) (FOR TESTING)
    printf("printing function info:\n");
    printFunctionInfos2();
    return;
}


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

    // add function2 to function2_t_list
    addFunction2(function2_t_list_head, function2);
    return function2;
}

// find function0 in function0_t_list
function0_t findFunction0(char* name)
{
    printf("findFunction0\n");
    function0_t_list* temp = function0_t_list_head;
    while(temp != NULL)
    {
        if(strcmp(temp->function0.name, name) == 0)
        {
            return temp->function0;
        }
        temp = temp->next;
    }
    printf("function0 not found\n");
    exit(1); // exit with error code 1
}

// find function1 in function1_t_list
function1_t findFunction1(char* name)
{
    printf("findFunction1\n");
    function1_t_list* temp = function1_t_list_head;
    while(temp != NULL)
    {
        if(strcmp(temp->function1.name, name) == 0)
        {
            return temp->function1;
        }
        temp = temp->next;
    }
    printf("function1 not found\n");
    exit(1); // exit with error code 1
}

// find function2 in function2_t_list
function2_t findFunction2(char* name)
{
    printf("findFunction2\n");
    function2_t_list* temp = function2_t_list_head;
    while(temp != NULL)
    {
        if(strcmp(temp->function2.name, name) == 0)
        {
            return temp->function2;
        }
        temp = temp->next;
    }
    printf("function2 not found\n");
    exit(1); // exit with error code 1
}

// REPLACE PARAMETERS WITH VALUES IN THE BODY OF THE FUNCTION

// values are in valuef_t type but a string
// example : function : (+ x y), value1 : 2f2, value2 : 3f3 ----> (+ 2f2 3f3)
char * getReplacedExp2(char* body, char* parameter1, char* parameter2, char* value1, char* value2)
{
    printf("getReplacedExp2\n");
    char* replacedExp = (char*)malloc(sizeof(char)*100);
    int lenParameter1 = strlen(parameter1);
    int lenParameter2 = strlen(parameter2);
    int lenExp = strlen(body);
    int i = 0;
    int j = 0;

    while(body[i] != '\0')
    {
        if(body[i] == parameter1[0])
        {
            int k = 0;
            //check if parameter1 is in the body
            while(i+k < lenExp && body[i+k] == parameter1[k])
            {
                k++;
                if(k == lenParameter1)
                {
                    // parameter1 is in the body
                    // replace parameter1 with value1
                    int l = 0;
                    while(value1[l] != '\0')
                    {
                        replacedExp[j] = value1[l];
                        j++;
                        l++;
                    }
                    i = i + lenParameter1;
                    break;
                }
            }
        }
        else if(body[i] == parameter2[0])
        {
            int k = 0;
            //check if parameter2 is in the body
            while(i+k < lenExp && body[i+k] == parameter2[k])
            {
                k++;
                if(k == lenParameter2)
                {
                    // parameter2 is in the body
                    // replace parameter2 with value2
                    int l = 0;
                    while(value2[l] != '\0')
                    {
                        replacedExp[j] = value2[l];
                        j++;
                        l++;
                    }
                    i = i + lenParameter2;
                    break;
                }
            }
        }
        else
        {
            replacedExp[j] = body[i];
            i++;
            j++;
        }
    }
    replacedExp[j] = '\0';
    return replacedExp;
}

char * getReplacedExp1(char* body, char* parameter, char* value)
{
    printf("getReplacedExp1\n");
    char* replacedExp = (char*)malloc(sizeof(char)*100);
    int i = 0;
    int j = 0;
    while(body[i] != '\0')
    {
        if(body[i] == parameter[0])
        {
            int k = 0;
            while(parameter[k] != '\0')
            {
                replacedExp[j] = parameter[k];
                j++;
                k++;
            }
            i++;
        }
        else
        {
            replacedExp[j] = body[i];
            i++;
            j++;
        }
    }
    replacedExp[j] = '\0';
    return replacedExp;
}

char * callFunction2(char* name, char* value1, char* value2)
{
    printf("callFunction2\n");
    function2_t function2 = findFunction2(name);
    printf("function2 found\n");
    printf("function2.name : %s\n", function2.name);
    printf("function2.parameter1 : %s\n", function2.parameter1);
    printf("function2.parameter2 : %s\n", function2.parameter2);
    printf("function2.body : %s\n", function2.body);

    char* replacedExp = getReplacedExp2(function2.body, function2.parameter1, function2.parameter2, value1, value2);
    printf("replacedExp : %s\n", replacedExp);

    //char* result = evaluate(replacedExp);
    //return result;
    return replacedExp;
}

char * callFunction1(char* name, char* value)
{
    printf("callFunction1\n");
    function1_t function1 = findFunction1(name);
    printf("function1 found\n");
    printf("function1.name : %s\n", function1.name);
    printf("function1.parameter : %s\n", function1.parameter);
    printf("function1.body : %s\n", function1.body);

    char* replacedExp = getReplacedExp1(function1.body, function1.parameter, value);
    printf("replacedExp : %s\n", replacedExp);

    //char* result = evaluate(replacedExp);
    //return result;
    return replacedExp;
}

char * callFunction0(char* name)
{
    
}

#endif /* FUNCTIONSDEF_H */