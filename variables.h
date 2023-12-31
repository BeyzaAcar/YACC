#ifndef VARIABLES_H
#define VARIABLES_H

#include "structs.h" //to use valuef_t type (fractional value)

//In this file, we will define the functions to handle variables 
//All variables will be kept in a linked list (node_t) 

/*This Linked List is to keep variables for set operation*/
typedef struct node_s
{
    char* data;
    char *name; //variable name
    struct node_s *next; //pointer to next node
}node_t;


// head of the linked list to keep variables
node_t *head;

// function to create a new node
void setVariable(char *name, char* data) // update can be done in this function too
{
    node_t *temp = head;
    // if head is null, create a new node and assign it to head 
    if(head == NULL)
    {
        head = (node_t*)malloc(sizeof(node_t));
        head->name = name;
        head->data = data;
        head->next = NULL;
        return;
    }
    // if head is not null, traverse the linked list and check if the variable is already defined   
    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            temp->data = data;
            return;
        }
        temp = temp->next;
    }
    // if variable is not defined, create a new node and add it to the end of the linked list
    temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = (node_t*)malloc(sizeof(node_t));
    temp->next->name = name;
    temp->next->data = data;
    temp->next->next = NULL;
    return;
}

// function to get a variable from linked list
char* getVariableValue(char *name)
{
    node_t *temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
            return temp->data;
        temp = temp->next;
    }
    printf("Variable %s is not defined\n", name);
    return NULL;
}




#endif /* VARIABLES_H */