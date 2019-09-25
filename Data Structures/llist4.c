// Final document which explores the linked list data structure in detail.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 50
#define SIZE 10

typedef struct node
{
    char val[40];
    struct node* next;
}   
node;

// Create an array that contains 10 unique linked lists.
node * listArray[SIZE];

// Prototype for printList function.
void printList(node * head);



// Push Function.
/*  * Insert a new node at the start of a list, pushing all existing items down (FAST insertion).
    * Fast because items added to the start of the linked list has Time Complexity O(1) constant time.    
*/
void push (node **head, char new_val[LENGTH])           
{
    /* EXAMPLE: Assume **head == (listArray[0]) AND new_val = "Adam"      */
    node * new_node;                    // Create a new node & malloc
    new_node = malloc(sizeof(node));   

    strcpy(new_node -> val, new_val);   // new_node now stores the value "Adam".

    new_node-> next = *head;            // Adam points to whatever the head (listArray[0]) is equal to (NULL). Because there is nothing in listArray[0], lA[0] = NULL.
                                        //      listArray[0] = NULL
                                        //      Adam -> NULL
    *head = new_node;                   // The head (listArray[0]) now EQUALS to Adam.
                                        //      listArray[0] = Adam -> NULL

                                        // Assume you add "Andrew" to the linked list
                                        // Andrew points to whatever the head (listArray[0]) is EQUAL to (Adam)
                                        //      Andrew -> Adam -> NULL      
                                        // The head (listArray[0]) now EQUALS to Andrew
                                        //      listArray[0] = Andrew -> Adam -> NULL
                                        
                                        // Note: There is an important difference between 'pointing to' and 'equals'.
                                        // VISUALISATION:   https://i.imgur.com/BSDm6V6.png
}



int main()
{
    // Set the linked list at ListArray[0] to NULL
    listArray[0] = NULL;
    
    // Put data
    push(&listArray[0], "Adam");
    push(&listArray[0], "Andrew");
    
    // Print
    printList(listArray[0]);
}

// Function that iterates over a list printing everything
void printList(node * head) {
    while (head != NULL) {
        printf("%s \n", head -> val);
        head = head ->next;
    }
}