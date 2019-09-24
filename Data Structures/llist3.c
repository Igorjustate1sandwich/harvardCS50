#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 50
#define SIZE 26


typedef struct node
{
    char listName[20];
    char val[LENGTH];
    struct node* next;
}   
node;
node * array[SIZE];

// Insert a new node at the end of the list.
void push (node *head, char new_val[LENGTH])
{
    /* Iterate over all existing items to reach the end of the list */
    node * current = head;
    while (current -> next != NULL) 
    {
        current = current -> next;
    }

    /* We are at the end of the list, let's add a new variable */
    current -> next = malloc(sizeof(node));    
    strcpy(current -> next -> val, new_val);  
    current -> next -> next = NULL;        
}

// Iterate over a list printing everything until we reach the end.
void printList(node * head) {
    node * current = head;

    while (current != NULL) {
        printf("%s \n", current -> val);
        current = current ->next;
    }
    printf("\n");
}


int main()
{
    int input;

    /* Create 3 Linked Lists    */
    node* list1 = malloc(sizeof(node)); 
    node* list2 = malloc(sizeof(node)); 
    node* list3 = malloc(sizeof(node)); 

    /* Assign each list an array element */
    array[0] = list1;
    array[1] = list2;
    array[2] = list3;

    /* Fill each list with some data */
    push(list1, "Adam");
    push(list1, "Andrew");

    push(list2, "Bob");
    push(list2, "Baz");

    push(list3, "Carl");
    push(list3, "Carol");

    /* Print Output   */;
    while(1)
    {

        printf("Which array element do you want to access? ");
        scanf(" %d", &input);
        switch(input)
        {
            case(0): 
            printf("\nArray[0] contains the following linked list: \n");
            printList(list1);
            break;

            case(1):
            printf("\nArray[1] contains the following linked list: \n");
            printList(list2);
            break;

            case(2):
            printf("\nArray[2] contains the following linked list: \n");
            printList(list3);
            break;
        }
    }                 
}