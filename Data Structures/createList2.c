#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 50
#define SIZE 26


typedef struct node
{
    char val[LENGTH];
    char listName[20];
    struct node* next;
}   
node;
node * array[SIZE];

// Insert a new node at the end of the list.
void push (node *head, char new_val[LENGTH])
{
    /* Iterate over all existing items to reach the end of the list */
    node * current = head;
    while (current -> next != NULL) 
    {
        current = current -> next;
    }

    /* We are at the end of the list, let's add a new variable */
    current -> next = malloc(sizeof(node));    
    strcpy(current -> next -> val, new_val);  
    current -> next -> next = NULL;        
}

// Iterate over a list printing everything until we reach the end.
void printList(node * head) {
    node * current = head;

    while (current != NULL) {
        printf("%s \n", current -> val);
        current = current ->next;
    }
}

void createList (char input_name[50])
{
    node * new_listname = malloc(sizeof(node));
    strcpy (new_listname -> listName, input_name);

}

void dataEntry (node* listName, char new_val[LENGTH])
{
    push(listName, new_val);
}

int main()
{
    /* Create 5 Lists      */
    for (int i = 0; i < 5; i++)
    {
        char listname[50];
        sprintf(listname, "List%d", i);         // concatenate string with integer
        createList(listname);
        dataEntry(listname, "APPLE");
    }


    /* Fill 5 lists 
    for (int i = 0; i < 5; i++)
    {
        char input[LENGTH];
        char listname[50];
        sprintf(listname, "List%d", i);         // concatenate string with integer

        printf("Enter name for list %d", i);
        scanf(" %s", input);
        push(listname, input);

    }
/*
 
    /* Print Output   */;
                     
}