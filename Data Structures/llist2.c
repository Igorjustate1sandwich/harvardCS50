#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char val[40];
    struct node* next;
}   
node;
node * array[26];

// Function to create a new node
node *new_node(char new_val[40], node *next)
{
    node *head = malloc(sizeof(node));
    strcpy(head -> val, new_val);
    head -> next = NULL;
    return head;
}

// Function to insert a new node at the end of the list
void push (node *head, char new_val[40])
{
    /* We must first iterate over all existing items to reach the end of the list */
    node * current = head;
    while (current -> next != NULL) 
    {
        current = current -> next;
    }

    /* Now we are at the end of the list, let's add a new variable */
    current -> next = malloc(sizeof(node));    
    strcpy(current -> next -> val, new_val);  
    current -> next -> next = NULL;        
}

// Function that iterates over a list printing everything
void printList(node * head) {
    node * current = head;

    while (current != NULL) {
        printf("%s \n", current -> val);
        current = current ->next;
    }
}

int main()
{
    /* Create some lists    */
    node* list1 = malloc(sizeof(node));         // list which contains names starting with A
    node* list2 = malloc(sizeof(node));         // list which contains names starting with B

    /* Fill list 1 with data    */
    push(list1, "Apple");
    push(list1, "Alison");
    push(list1, "Adam");

    /* Fill list 2 with data    */
    push(list2, "Bob");
    push(list2, "Barry");
    push(list2, "Bobo");
    push(list2, "Burger");

    /* Assign list to a specific array */
    array[0] = list1;
    array[1] = list2;

    /* Print Output   */;
    printList(array[1]);                        // print all names starting with B  
}