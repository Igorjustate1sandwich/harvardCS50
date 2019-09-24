#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* last;
}
node;
node * array[5];
node* head = NULL;

// Create a linked list
node* insert(struct node** head, int new_data)
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
        return new_node;
    }

    // 5. Otherwise, traverse until you find the last node.
    while (last -> next != NULL)
    {
        last = last -> next;
    }

    // 6. Then make the last node point to our new node.
    last -> next = new_node;
    return new_node;
}


int main()
{
    array[1] = insert(&head, 200);
    array[1] = insert(&head, 2000);

    array[2] = insert(&head, 400);
    array[2] = insert(&head, 4000);



    printf("%d \n", array[1] -> data);
    printf("%d \n", array[1] -> data);
    //printf("%d \n", array[2] -> data);

}
