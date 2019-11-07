#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define LENGTH 50
#define TABLE_SIZE 26

int key;
char value[LENGTH];
char tempWord[LENGTH];


typedef struct node
{
    char val[LENGTH];
    struct node* next;
}   
node;

// Represent a hash table with 5 slots
node * slot[TABLE_SIZE];

/* Hash Function by CS50   */
unsigned int hash(const char *word)
{
    key = tolower(word[0]) - 'a';  // return a key between 0 and 26-1
    key = key % TABLE_SIZE;
    return key;
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

// Compare words in the dictionary with the user word provided by check function.
bool traverse(node * head)
{
    node * cursor = head;
    
    printf("\n\n");
    while (cursor != NULL)
    {
        int result = strcasecmp(cursor -> val, tempWord);
        if (result == 0){
            printf("Match Found! User word %s matches dictionary word %s. \n", tempWord, cursor->val);
            return true;
        }
        else {
            printf("No match. User word %s does not match dictionary word %s.  \n", tempWord, cursor->val);
        }
        cursor = cursor -> next;
    }
    return false;
    printf("\n\n");
}

// Compare words in the dictionary with the user word. Pass to traverse function.
bool check(const char *word)
{
    strcpy(tempWord, word);
    hash(word);
    return traverse(slot[key]);
}

void delete(node * head)
{
    node * cursor = head;
    while (cursor != NULL)
    {
        node * temp = cursor;
        cursor = cursor -> next;
        free(temp);
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
    hash("Apple");
    push(&slot[key], "Apple");

    hash("Apricot");
    push(&slot[key], "Apricot");

    hash("Mango");
    push(&slot[key], "Mango");

    hash("Orange");
    push(&slot[key], "Orange");

    hash("Pear");
    push(&slot[key], "Pear");

    hash("Pineapple");
    push(&slot[key], "Pineapple");

    hash("Grape");
    push(&slot[key], "Grape");

    /* Print table                  */
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Slot %d: ", i);
        printList(slot[i]);
        printf("\n");
    }

    /* Traversal to check if a word currently exists in the linked list */
    check("Apple");

    /* Free memory                                                      */
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        delete(slot[i]);
    }

}