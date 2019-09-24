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
node* insert (struct node** head, int new_data)
{
    node * new_node = (node*)malloc(sizeof(node));
    new_node -> data = new_data;
    new_node -> next = (*head);
    *head = new_node;

    return *head;
}

void printList (int pos)
{
    while (array[pos] != NULL)
    {
        printf("%d \n", array[pos]->data); 
        array[pos] = array[pos]->next;
    }
}


int main()
{
    array[1] = insert(&head, 200);
    array[1] = insert(&head, 2000);
    array[2] = insert(&head, 400);
    array[2] = insert(&head, 4000);

    printList(2);

    //printf("%d \n", array[1] -> data);
    //printf("%d \n", array[2] -> data);

}
