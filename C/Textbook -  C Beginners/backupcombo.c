/* Basic Hash Table Implementation via combination of Linked List and Array */
/*
    Takes value and generates a hash key. Insert value into a hash table slot (slot = key).
    
    array[0]  -> linked list for the Letter A...
    array[1]  -> linked list for the letter B...
    array[2]  -> linked list for the letter C...
    .....
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10
#define LENGTH 50

int key;
char value[LENGTH];
int listPosition[10];       // position in a linked list





// Represent a node in a hash table
typedef struct node
{
    char data[LENGTH];
    struct node* next;
}   
node;
node* head = NULL;

// Represent an array of size n
struct node* array[SIZE];


// Function to create a single new node (linked list) at array[i]
void createNode (int arrayElement, int listPos, struct node** head, char new_data[LENGTH])
{
    // 1. Allocate memory for the new node.
    array[arrayElement, listPos] = (node*)malloc(sizeof(node));
    node* last = *head;
    
    // 2. Place data within the new node.
    strcpy(array[arrayElement, listPos] -> data, new_data);

    // 3. As this new node will be the last node in the list, point it to NULL.
    array[arrayElement, listPos] -> next = NULL;

    // 4. If the list is empty, make this new node the head.
    if (*head == NULL)
    {
        *head = array[arrayElement, listPos];
        return;
    }

    // 5. Otherwise, traverse until you find the last node.
    while (last -> next != NULL)
    {
        last = last -> next;
    }

    // 6. Then make the last node point to our new node.
    last -> next = array[arrayElement, listPos];
    return;
}

// Function to insert additional nodes to the linked lists
/*
void insertNode (int arrayElement, int listPosition, struct node** head, char new_data[LENGTH])
{
    // Allocate memory for additional node
    array[arrayElement, listPosition];

    //

    return;
}
*/

// You must free memory used by the Linked List when you are finished.
void deleteList(struct node** head)
{
    struct node* current = *head;
    struct node* next;

    while (current != NULL) // Repeat until we reach the end of the list.
    {
        next = current -> next;
        free(current);
        current = next;
    }
    *head = NULL;
}



int main()
{
    // Insert node at element 1 of array.
    createNode(1, 1, &head, "Apple");
    createNode(1, 2, &head, "Mango");

    createNode(2, 1, &head, "Jemma");
    createNode(2, 2, &head, "Sahil");





    //createNode(1, &head, "Apple");
    //createNode(1, &head, "Grapes");
    //createNode(1, &head, "Mango");

    printf("Node 1 Pos 1: %s \n", array[1, 1] -> data);
    printf("Node 1 Pos 2: %s \n", array[1, 2] -> data);

    printf("Node 2 Pos 1: %s \n", array[2, 1] -> data);
    printf("Node 2 Pos 2: %s \n", array[2, 2] -> data);



    //printList(1, head);
   // printf("Node 1: %s \n", array[1] ->data);
    //printf("Node 2: %s \n", array[2] ->data);
    //printf("Node 3: %s \n", array[3] ->data);
    //printf("Node ?: %s \n", array[10] ->data);

    // Delete the list.
    deleteList(&head);
}