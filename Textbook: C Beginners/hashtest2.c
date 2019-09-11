// Putting it all together!
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct node
{
    char data[200];
    struct node* next;
}   
node;
node* head = NULL;

// Function to create a new node at the end of a list.
void insertEnd(struct node** head, char new_data[200])
{
    // 1. Allocate memory for the new node.
    node* new_node = malloc(sizeof(node));
    node* last = *head;

    // 2. Place data within the new node.
    strcpy(new_node -> data, new_data);

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


void printNode(struct node *node, int pos)
{
    struct node *temp;

    // If list is empty
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    temp = head;

    for (int i = 1; i < pos; i++)
    {
            temp = temp->next;
    }
    printf("Node %d = %s \n", pos, temp->data);
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
   // Insert some new nodes
   insertEnd(&head, "Apple");
   insertEnd(&head, "Mango");
   insertEnd(&head, "Lemon");
   insertEnd(&head, "Grape");

    // Print the entire list.
    printf("\nContents of linked list:\n");
    printNode(head, 3);
    printf("\n");

    // Delete the list.
    deleteList(&head);
}