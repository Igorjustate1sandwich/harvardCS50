// Putting it all together!
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

// Function to insert a new node at the front of the list.
void insertBeginning (struct node** head, int new_data)
{
    // 1. Allocate memory for new node.
    node* new_node = malloc(sizeof(node));
    // 2. Put data into the new node.
    new_node -> data = new_data;
    // 3. Make new_node point to the old head.
    new_node -> next = (*head);
    // 4. Make the new node the head.
    (*head) = new_node;
}

// Function to insert a new node after an existing node.
void insertMiddle(int data, int position)
{
    node* new_node= malloc(sizeof(node));
    node* prev_node;

    if(new_node == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        new_node -> data = data;
        new_node -> next = NULL;
        prev_node = head;

        // Traverse to n-1 position
        for (int i = 2; i <= position-1; i++)
        {
            prev_node = prev_node -> next;
            if (prev_node == NULL)
            {
                break;
            }
        }

        if (prev_node != NULL)
        {
            // Point new node to where previous node was pointing to.
            new_node -> next = prev_node -> next;
            // Make previous node point to the new node.
            prev_node -> next = new_node;
        }
    }
}

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
    while (node != NULL) 
    { 
        printf(" %d ", node->data); 
        node = node->next; 
    } 
} 

// You must free memory used by the Linked List when you are finished.
void deleteList(struct node** head)
{
    // Create a new pointer called Current to keep track of where we are in the list.
    struct node* current = *head;
    struct node* next;

    // Delete the contents of the list until the end of the list is reached.
    while (current != NULL) // Repeat until we reach the end of the list.
    {
        // Point the pointer "next" to the adjacent node of where we currently are in the list.
        // If we don't do this, our link with the rest of the list is lost.
        next = current -> next;

        free(current);
        current = next;
    }
    *head = NULL;
}
int main()
{
    // Create some nodes.
    insertEnd(&head, 100);
    insertEnd(&head, 200);
    insertEnd(&head, 300);
    insertMiddle(250, 2);

    // Print the entire list.
    printf("\nContents of linked list:\n");
    printList(head);
    printf("\n");

    // Delete the list.
    deleteList(&head);
}