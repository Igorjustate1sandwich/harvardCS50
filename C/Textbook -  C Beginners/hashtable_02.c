/* Basic Hash Table Implementation via Linked List */
/*
    Takes value and generates a hash key. Insert value into a hash table slot (slot = key).
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 26
int key;

/* prototypes */
unsigned int hash(const char *word);

/* hash table node */
typedef struct node
{
    int data;
    struct node* next;
}
node;
node* head = NULL;

/* hash function */
unsigned int hash(const char *word)
{
    key = tolower(word[0]) - 'a';  // return a key between 0 and 26-1
    key = key % SIZE;
    return key;
}

int main()
{
    char name[SIZE];
    char array[100];

    char charArray[30];
    charArray[20] = 'K';

    printf("Enter a name: ");
    scanf(" %s", name);
    printf("The hash key for the value %s is: %d. \n", name, hash(name));
}