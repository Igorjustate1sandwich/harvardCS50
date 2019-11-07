#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 50
#define TABLE_SIZE 5

int key;
char value[LENGTH];

typedef struct node
{
    char val[LENGTH];
    struct node* next;
}   
node;

// Represent a hash table with 5 slots
node * slot[TABLE_SIZE];

/* Hash Function by Engineer Man    */
unsigned int hash(const char *word)
{
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int key_length = strlen(word);

    // do several rounds of multiplication
    for (; i < key_length; i++) {
        value = value * 37 + word[i];
    }

    // make sure value is 0 <= TABLE_SIZE
    value = value % TABLE_SIZE;

    key = value;
    return value;
}

/* Push a new node at the start of a list   */
void push (node **head, char new_val[40])
{
    node * new_node;
    new_node = malloc(sizeof(node));

    strcpy(new_node -> val, new_val);
    new_node-> next = *head;
    *head = new_node;
}

/* Function that iterates over a list printing everything   */
void printList(node * head) {
    while (head != NULL) {
        printf("%s ", head -> val);
        head = head ->next;
    }
}

int main()
{

    /* Create TABLE_SIZE amount of linked Lists (slots)   */
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        slot[i] = malloc(sizeof(node));
    }

    /* Hash data to generate key, then assign key-value pair to hash table       */
    hash("apple");
    push(&slot[key], "apple");

    hash("mango");
    push(&slot[key], "mango");

    hash("orange");
    push(&slot[key], "orange");

    hash("pear");
    push(&slot[key], "pear");

    hash("grape");
    push(&slot[key], "grape");

    /* Print table                  */
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Slot %d: ", i);
        printList(slot[i]);
        printf("\n");
    }
}