// Insert a new node between two existing nodes
// So far we can: Insert a node at the beginning of a list, Insert a node after an existing node.

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

// Function to insert a new node between two existing nodes. 
void insertAfter(struct node* prev_node, int new_data)
{
    // 1. Check if prev_node is NULL.
    if (prev_node == NULL)
    {
        exit(1);
    }
    // 2. Allocate memory for the new node.
    node* new_node = malloc(sizeof(node));
    // 3. Place data within the new node.
    new_node -> data = new_data;
    // 4. Make new node point to where the previous node is pointing to.
    new_node -> next = prev_node -> next;
    // 5. Make "next" of previous node point to the new node.
    prev_node -> next = new_node;
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
    // Create some nodes.
    insert(&head, 10);
    insert(&head, 15);
    insertAfter(head -> next, 20);

    // Print the entire list.
    printf("\nContents of linked list:\n");
    printList(head);
    printf("\n");

}