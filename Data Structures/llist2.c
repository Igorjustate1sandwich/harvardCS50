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
void insert (struct node** head, int arrayPos, int new_data)
{
    array[arrayPos] = (node*)malloc(sizeof(node));
    array[arrayPos] -> data = new_data;
    array[arrayPos] -> next = (*head);
    *head = array[arrayPos];

    //printf("%d \n", array[arrayPos] -> data);
}

void printList (struct node *node, int arrayPos)
{
    while (array[arrayPos] != NULL) 
    { 
        printf("%d \n", array[arrayPos]->data); 
        array[arrayPos] = array[arrayPos]->next; 
    } 
}


int main()
{
    insert(&head, 1, 2);
    insert(&head, 1, 20);

    insert(&head, 2, 4);
    insert(&head, 2, 40);

    printList(head, 2);



}
