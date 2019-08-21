#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*
PSEUDOCODE
hash_new("Bob");
hash code = 4;
hash_search("Bob"); 
https://www.youtube.com/watch?v=nvzVHwrrub0
*/

// Hash Table Struct
typedef struct node {
    char *name;
    struct node* next;
    //struct node* word;
} node;

// Hash Table Root
node* first[26] = {NULL};

// FUNCTION 1: HASH KEY
int hash(const char* buffer) {
    // Assign a number to first letter of user input from 0-25
    return tolower(buffer[0]) - 'a';
}

// FUNCTION 2: INSERT
void insert(int key, const char* buffer) {
    
    //
    node* newptr = malloc(sizeof(node));
    if (newptr == NULL)
    {
        return;
    }

    // make a new pointer
   strcpy(newptr->word, buffer);
    newptr -> next = NULL;

    // check for empty list
    if (first[key] == NULL)
    {
       first[key] = newptr;
    }

    // check for insertion at tail
    else
    {
        node* predptr = first[key];
        while (1)
        {
            // insert at tail
            if (predptr->next == NULL)
            {
                predptr->next = newptr;
                break;
            }

            // update pointer
            predptr = predptr->next;
        }
    }
}


int main(char* name){

    // Take username you want to hash then insert
    int hashedVal = hash(name); //??
    insert(hashedVal, name);

}