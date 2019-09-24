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

// Create a linked list


// Iterate over a list printing everything until we reach the end.
void printList(node * head) {
    node * current = head;

    while (current != NULL) {
        printf("%s \n", current -> val);
        current = current ->next;
    }
}


void createList (char input_name[50], char new_val[LENGTH])
{
    node * new_listname = malloc(sizeof(node));
    strcpy (new_listname -> listName, input_name);

    push(new_listname, new_val); 
    printList(new_listname);

}

int main()
{

    createList("List", "Apple");


    /* Print Output   */;
                     
}