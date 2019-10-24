// Note: See llist4.c for the final, good explanation of how linked lists work.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
}   
node;
node * array[26];

// Function to create a new node
node *new_node(int new_val, node *next)
{
    node *head = malloc(sizeof(node));
    head -> val = new_val;
    head -> next = NULL;
    return head;
}

// Function to insert a new node at the end of the list (slow insertion)
/* Appending is slow because you must first iterate list to reach the end */
void append (node *head, int new_val)
{
    /* We must first iterate over all existing items to reach the end of the list */
    node * current = head;
    while (current -> next != NULL) 
    {
        current = current -> next;
    }

    /* Now we are at the end of the list, let's add a new variable */
    current -> next = malloc(sizeof(node));      
    current -> next -> val = new_val;    
    current -> next -> next = NULL;        

}


// Print Function that iterates over a list 
void printList(node * head) {
    node * current = head;

    while (current != NULL) {
        printf("%d \n", current -> val);
        current = current ->next;
    }
}

int main()
{
    /* Create some lists    */
    node* list1 = malloc(sizeof(node));
    node* list2 = malloc(sizeof(node));

    /* Fill list 1 with data.    */
    append(list1, 5);
    append(list1, 10);
    append(list1, 15);

    /* FIll list 2 with data   */
    append(list2, 500);
    append(list2, 1000);
    append(list2, 1500);

    /* Set arrays to each list  */
    array[0] = list1;
    array[1] = list2;

    /* Print Output   */;
    printList(array[0]);
}