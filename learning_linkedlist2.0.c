// Create a linked list that let's you insert a new node to the front of a list dynamically.
// So far we can: Insert a node at the beginning of a list.

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}   
node;
node* head = NULL;

// Function to insert a new node to the front of the list.
void insert (struct node** head, int new_data)
{
    // 1. Allocate memory for new node.
    node* new_node = malloc(sizeof(node));
    // 2. Put data into the new node.
    new_node -> data = new_data;
    // 3. Make new_node point to where head is pointing to.
    new_node -> next = (*head);
    // 4. Make head point to new node.
    (*head) = new_node;
}

// Function to print contents of linked list.
void printList(struct node *node) 
{ 
    while (node != NULL) 
    { 
        printf(" %d ", node->data); 
        node = node->next; 
    } 
} 

int main()
{
    // Insert a new node at the beginning of the list.
    insert(&head, 343); 
    insert(&head, 69);
    insert(&head, 700);

    // Print the entire list.
    printf("Contents of linked list: \n");
    printList(head);
    printf("\n");
}