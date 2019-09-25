/*
    - This hash table uses 26 singly linked lists and an array for fast lookup O(1).
    - There are 26 letters in the alphabet, therefore we have 26 linked lists. Each list
      stores names starting with a certain letter. Example:
        listArray[0] stores head of Linked List 1 (all names starting with A)
        listArray[1] stores head of Linked List 2 (all names starting with B)
        ..... etc......
    - User inputs a name which is sent to hash function. Hash function generates a key between 
      0 - 26. The name is then stored at listArray[key].
        - e.g. The name Carl has a key of 2 and is stored in listArray[2].
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 50
#define SIZE 26

int key;
char value[LENGTH];

typedef struct node
{
    char val[40];
    struct node* next;
}   
node;
node * listArray[26];


// Hash Function 
unsigned int hash(const char *word)
{
    key = tolower(word[0]) - 'a';  // return a key between 0 and 26-1
    key = key % SIZE;
    return key;
}

/* Function to insert a new node at the end of the list (SLOW insertion)
Append: Add item to the end of the linked list. Slow because you need to first iterate the
entire list to determine the end. Time complexity of O(n) linear time.
*/
void append (node *head, char new_val[40])
{
    /* We must first iterate over all existing items to reach the end of the list */
    node * current = head;
    while (current -> next != NULL) 
    {
        current = current -> next;
    }

    /* Now we are at the end of the list, let's add a new variable */
    current -> next = malloc(sizeof(node));    
    strcpy(current -> next -> val, new_val);  
    current -> next -> next = NULL;        
}

/* Function to insert a new node at the start of a list (FAST insertion)
Push: Insert a new item at start, push all existing items further down. Fast because
items added to the start of the linked list has Time Complexity O(1) constant time. 
*/
void push (node **head, char new_val[40])
{
    node * new_node;
    new_node = malloc(sizeof(node));

    strcpy(new_node -> val, new_val);
    new_node-> next = *head;
    *head = new_node;
}

// Function that iterates over a list printing everything
void printList(node * head) {
    while (head != NULL) {
        printf("%s ", head -> val);
        head = head ->next;
    }
}

int main()
{
    /* Create 26 Linked Lists   */
    for (int i = 0; i < 25; i++)
    {
        listArray[i] = malloc(sizeof(node));
    }

    /* Use hash function to get a key, then fill the 26 linked lists with user data! */
    while(1)
    {
        /* Generate a hash key      */
        printf("\nEnter a value to generate a hash key: ");
        scanf(" %s", value);
        hash(value);
        printf("Hash Value: %s | Hash Key: %d  \n\n", value, key);

        /* Add value to the correct linked list (key-array pair) */
        push(&listArray[key], value);

        /* Print the contents of the hash table     */
        printf(" ** Hash Table ** \n");
        printf("Key      Value\n");
        for(int i = 0; i < SIZE; i++)
        {
            printf("List[%d]: ", i);
            printList(listArray[i]); printf("\n");
        }
    }
}