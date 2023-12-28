#ifndef VARIABLES_H
#define VARIABLES_H

#include "helpers.h" //to use valuef_t type (fractional value)

//In this file, we will define the functions to handle variables 
//All variables will be kept in a linked list (node_t) 

/*This Linked List is to keep variables for set operation*/
typedef struct node_s
{
    valuef_t data;
    char name[30]; //variable name
    struct node_s *next; //pointer to next node
}node_t;


// head of the linked list to keep variables
node_t *head;


// print all variables

void printVariables()
{
    node_t *temp = head;
    while(temp != NULL)
    {
        printf("%s = %d/%d\n", temp->name, temp->data.numerator, temp->data.denominator);
        temp = temp->next;
    }
}



// function to create a new node
void setVariable(char *name, valuef_t data) // update can be done in this function too
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    newNode->data = data;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if(head == NULL) // if list is empty
    {
        head = newNode;
    }
    else // if list is not empty
    {
        node_t *temp = head;
        while(temp != NULL)
        {
            if(strcmp(temp->name, name) == 0) // if variable is already defined, update it
            {
                temp->data = data;
                return;
            }
            temp = temp->next;
        }
        newNode->next = head; // add new node to the beginning of the list if variable is not defined
        head = newNode;
    }
}

// function to get a variable from linked list
valuef_t getVariableValue(char *name)
{
    printf("evet buraya geliyom dogrudur\n");
    node_t *temp = head;
    while(temp != NULL)
    {
        if(strcmp(temp->name, name) == 0)
        {
            return temp->data;
        }
        temp = temp->next;
    }
    printf("Variable %s is not defined\n", name);
    //return a valuef_t with numerator = 0 and denominator = 0
    //return createZeroValueF();
    exit(0);
}




#endif /* VARIABLES_H */