#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char val[40];
    struct node* next;
}   
node;
node * listArray[26];

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
    /* Create 26 Linked Lists   */
    for (int i = 0; i < 25; i++)
    {
        listArray[i] = malloc(sizeof(node));
    }

    /* Fill lists with data */
    push(&listArray[0], "Adam");         // Storing all names with letter "A" in listArray[0]
    push(&listArray[0], "Andrew");       
    push(&listArray[0], "Austin");

    push(&listArray[1], "Barry");       // Storing all names with letter "B" in listArray[1]
    push(&listArray[1], "Bob");
    push(&listArray[1], "Bertha");

    push(&listArray[3], "David");      // Storing all names with letter "D" in listArray[3]
    push(&listArray[3], "Davos");
    push(&listArray[3], "Dane");


    /* Print Output   */;
    printList(listArray[1]);            // Print all the names that start with letter "D"
}