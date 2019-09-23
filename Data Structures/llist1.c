#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
    int data;
    struct node* next;
}   
node;
node* head = NULL;

// Function to create a new node at the end of a list.
void insertEnd(struct node** head, int new_data)
{
    // 1. Allocate memory for the new node.
    node* new_node = malloc(sizeof(node));
    node* last = *head;

    // 2. Place data within the new node.
    new_node -> data = new_data;

    // 3. As this new node will be the last node in the list, point it to NULL.
    new_node -> next = NULL;

    // 4. If the list is empty, make this new node the head.
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    // 5. Otherwise, traverse until you find the last node.
    while (last -> next != NULL)
    {
        last = last -> next;
    }

    // 6. Then make the last node point to our new node.
    last -> next = new_node;
    return;
}

// Function to print contents of linked list.
void printList(struct node *node) 
{
    int ctr = 1;
    while (node != NULL) 
    {
        printf("Node %d: %d \n", ctr, node->data); 
        node = node->next;
        ctr++;
    } 
} 

int main()
{
    for (int i = 1; i <= 100; i++)
    {
        insertEnd(&head, i);
    }
    printf("Contents of Linked List: \n");
    printList(head);
}