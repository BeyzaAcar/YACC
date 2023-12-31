#ifndef FUNCTIONSDEF_H
#define FUNCTIONSDEF_H

#include "structs.h" //to use valuef_t type (fractional value) and function_t typeS (function0_t, function1_t, function2_t)

// There are 3 functions types (all of them return valuef_t)
// 1. function with no parameters
// 2. function with one parameter
// 3. function with two parameters

// LIST OF ALL DEFINED FUNCTIONS
typedef struct function2_t_list
{
    function2_t function2;
    struct function2_t_list *next;
} function2_t_list;
typedef struct function1_t_list
{
    function1_t function1;
    struct function1_t_list *next;
} function1_t_list;
typedef struct function0_t_list
{
    function0_t function0;
    struct function0_t_list *next;
} function0_t_list;


// LIST OF ALL DEFINED FUNCTIONS 
function2_t_list* function2_t_list_head = NULL;
function1_t_list* function1_t_list_head = NULL;
function0_t_list* function0_t_list_head = NULL;

// ADD FUNCTIONS TO THE FUNCTION LISTS 
void addFunction0(function0_t_list* function0List, function0_t function0)
{
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
            printf("ERROR: function is already defined\n");
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
void addFunction1(function1_t_list* function1List, function1_t function1)
{
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
            printf("ERROR: function is already defined\n");
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
void addFunction2(function2_t_list* function2List, function2_t function2)
{
    function2_t_list* temp = function2List;
    if(temp == NULL) // if function2_t_list is empty (no function2 is defined)
    {
        function2_t_list_head = (function2_t_list*)malloc(sizeof(function2_t_list));
        function2_t_list_head->function2 = function2;
        function2_t_list_head->next = NULL;
        return;
    }
    // check if function2 is already defined 
    while(temp->next != NULL)
    {
        if(strcmp(temp->function2.name, function2.name) == 0)
        {
            printf("ERROR: function is already defined\n");
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
}


// CREATE FUNCTIONS
function0_t createFunction0(char* name, char* body)
{
    function0_t function0;
    strcpy(function0.name, name);
    strcpy(function0.body, body);
    return function0;
}
function1_t createFunction1(char* name, char* parameter, char* body)
{
    function1_t function1;
    strcpy(function1.name, name);
    strcpy(function1.parameter, parameter);
    strcpy(function1.body, body);
    return function1;
}
function2_t createFunction2(char* name, char* parameter1, char* parameter2, char* body)
{
    function2_t function2;
    strcpy(function2.name, name);
    strcpy(function2.parameter1, parameter1);
    strcpy(function2.parameter2, parameter2);
    strcpy(function2.body, body);

    // add function2 to function2_t_list
    addFunction2(function2_t_list_head, function2);
    return function2;
}

// FIND FUNCTIONS IN THE FUNCTION LISTS
function0_t findFunction0(char* name)
{
    function0_t_list* temp = function0_t_list_head;
    while(temp != NULL)
    {
        if(strcmp(temp->function0.name, name) == 0)
        {
            return temp->function0;
        }
        temp = temp->next;
    }
    printf("ERROR: function not found\n");
    exit(1); // exit with error code 1
}
function1_t findFunction1(char* name)
{
    function1_t_list* temp = function1_t_list_head;
    while(temp != NULL)
    {
        if(strcmp(temp->function1.name, name) == 0)
        {
            return temp->function1;
        }
        temp = temp->next;
    }
    printf("ERROR: function not found\n");
    exit(1); // exit with error code 1
}
function2_t findFunction2(char* name)
{
    function2_t_list* temp = function2_t_list_head;
    while(temp != NULL)
    {
        if(strcmp(temp->function2.name, name) == 0)
        {
            return temp->function2;
        }
        temp = temp->next;
    }
    printf("ERROR: function not found\n");
    exit(1); // exit with error code 1
}

// REPLACE PARAMETERS WITH VALUES IN THE BODY OF THE FUNCTION
// values are in valuef_t type but a string
// example : function : (+ x y), value1 : 2f2, value2 : 3f3 ----> (+ 2f2 3f3)
char * getReplacedExp2(char* body, char* parameter1, char* parameter2, char* value1, char* value2)
{
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

// CALL FUNCTIONS
char * callFunction2(char* name, char* value1, char* value2)
{
    function2_t function2 = findFunction2(name);
    char* replacedExp = getReplacedExp2(function2.body, function2.parameter1, function2.parameter2, value1, value2);
    return replacedExp;
}
char * callFunction1(char* name, char* value)
{
    function1_t function1 = findFunction1(name);
    char* replacedExp = getReplacedExp1(function1.body, function1.parameter, value);
    return replacedExp;
}
char * callFunction0(char* name)
{
    function0_t function0 = findFunction0(name);
    int len = strlen(function0.body);
    char *replacedExp = (char*)malloc(sizeof(char)*len);
    strcpy(replacedExp, function0.body);
    return replacedExp;

}



#endif /* FUNCTIONSDEF_H */