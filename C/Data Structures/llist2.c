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

/* 
Function to insert a new node at the end of the list (SLOW insertion)
Append: Add item to the end of the linked list. Slow because you need to first iterate the
entire list to determine the end. Time complexity of O(n) linear time.
*/
void append (node *head, char new_val[40])
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

/* 
Function to insert a new node at the start of a list (FAST insertion)
Push: Insert a new item at start, push all existing items further down. Fast because
items added to the start of the linked list has Time Complexity O(1) constant time. 
*/
void push (node **head, char new_val[40])
{
    node * new_node;
    new_node = malloc(sizeof(node));

    strcpy(new_node -> val, new_val);
    new_node-> next = *head;
    *head = new_node;
}

// Function that iterates over a list printing everything
void printList(node * head) {
    while (head != NULL) {
        printf("%s \n", head -> val);
        head = head ->next;
    }
}

int main()
{
    /* Create some lists    */
    node* list1 = malloc(sizeof(node));         // list which contains names starting with A
    node* list2 = malloc(sizeof(node));         // list which contains names starting with B

    /* Fill list 1 with data    */
    push(&list1, "Apple");
    push(&list1, "Adam");
    push(&list1, "Ava");

    /* Fill list 2 with data    */
    push(&list2, "Bob");
    push(&list2, "Burger");
    push(&list2, "Bethany");

    /* Assign list to a specific array */
    array[0] = list1;
    array[1] = list2;

    /* Print Output   */;
    printList(array[1]);                        // print all names starting with B  
}