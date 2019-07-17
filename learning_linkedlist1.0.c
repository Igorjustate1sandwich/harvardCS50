// Create a linked list with three nodes (manually).

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}   
node;

// Three nodes in our list.
struct node* head = NULL;
struct node* second = NULL;
struct node* third = NULL;

// Function call to print size of list.
void printLength(struct node* ptr);

int main()
{
    // Assign memory to the three nodes in our list.
    head = malloc(sizeof(node));
    second = malloc(sizeof(node));
    third = malloc(sizeof(node));

    // Assign data to the head (first) node, then link to second node.
    head -> data = 10;
    head -> next = second;

    // Assign data to the second node, then link to third node.
    second -> data = 20;
    second -> next = third;

    // Assign data to final (third) node, then mark end via NULL.
    third -> data = 30;
    third -> next = NULL;

    // Pass to printLength function
    printLength(head);
}

// Print the size of the linked list, starting from the given node.
void printLength(struct node* ptr)
{
    int length = 0;
    // "Until we haven't reached the end of the list, length++"
    for (node* ptr = head; ptr != NULL; ptr = ptr -> next)
    {
     length++;   
    }
    printf("The size of this list is: %d \n", length);
}