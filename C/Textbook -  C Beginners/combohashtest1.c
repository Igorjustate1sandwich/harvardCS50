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


#define SIZE 10
#define LENGTH 50

int key;
char value[LENGTH];

// Represent a node in a hash table
typedef struct node
{
    char data[LENGTH];
    struct node* next;
    struct node* last;
}   
node;
node* head = NULL;

// Represent an array of size n
struct node* array[SIZE];


// Function to create a new node at array[i]
void createNode (int arrayElement, struct node** head, char new_data[LENGTH])
{
    // 1. Allocate memory for the new node.
    array[arrayElement] = (node*)malloc(sizeof(node));
    node* last = *head;
    array[arrayElement] -> last = *head;
    
    // 2. Place data within the new node.
    strcpy(array[arrayElement] -> data, new_data);

    // 3. As this new node will be the last node in the list, point it to NULL.
    array[arrayElement]-> next = NULL;

    // 4. If the list is empty, make this new node the head.
    if (*head == NULL)
    {
        *head = array[arrayElement];
        return;
    }

    // 5. Otherwise, traverse until you find the last node.
    while (array[arrayElement] -> last -> next != NULL)
    {
        array[arrayElement] -> last = array[arrayElement] -> last -> next;
    }

    // 6. Then make the last node point to our new node.
    array[arrayElement] -> last -> next = array[arrayElement];
    return;
}

void printList(int arrayElement, struct node *node)
{
    while (node != NULL){
        printf(" %s \n", node->data);
        node = node->next;
    }
}

int main()
{
    // Insert nodes at Linked List A
    createNode(1, &head, "Apple");
    createNode(1, &head, "Alpha");

    createNode(2, &head, "Bob");
    createNode(2, &head, "Burger");

    printList(1, head);


    /* Print Linked List 1 */
    //printf("Array[0] Node 1: %s \n", array[1] -> data);
    //printf("Array[0] Node 2: %s \n", array[1] -> data);

}