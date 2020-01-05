// old backup speller.c

// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>


#include "dictionary.h"

// Represents number of buckets in a hash table. 26 letters in english alphabet.
#define N 26

int key;
int dictSize;
char tempWord[LENGTH];

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 25, inclusive, based on its first letter
unsigned int hash(const char *word)
{
    key =  tolower(word[0]) - 'a';
    return key;
}

/* Function to push a new node at the start of a linked list */
void push(node **head, char new_word[LENGTH])
{
    node *new_node;
    new_node = malloc(sizeof(node));
    strcpy(new_node -> word, new_word);

    new_node -> next = *head;
    *head = new_node;
}

/* Function that handles node traversal */
bool traverse(node *head)
{
    node *cursor = head;

    while (cursor != NULL)
    {
        int result = strcasecmp(cursor -> word, tempWord);
        if (result == 0)
        {
            return true;
        }
        else
        {
            cursor = cursor -> next;
        }
    }
    return false;

}

/* Function that deletes nodes in the hash table to free all memory */
void delete(node *head)
{
    node *cursor = head;
    while (cursor != NULL)
    {
        node *temp = cursor;
        cursor = cursor -> next;
        free(temp);
    }
}

/* Function to print the hash table and its contents */
void printList(node *head)
{
    while (head != NULL)
    {
        printf("%s ", head -> word);
        head = head -> next;
    }
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // Run each value (word) through a hash function to generate a hash key
        hash(word);

        // Place each word in hashtable[key]
        push(&hashtable[key], word);
        dictSize++;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return dictSize;

}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    strcpy(tempWord, word);
    hash(word);
    return traverse(hashtable[key]);
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        delete(hashtable[i]);
    }
    return true;
}
