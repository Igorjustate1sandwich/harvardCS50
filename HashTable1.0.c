/*
    Hash Table 1.0: Brief Overview 
    - Simple structure of a hash table.
    - Allows us to create and destroy a hash table.
    - Does not include hash functionality. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // allows for sleep() for debug purpose.

// Hash Table Structure
// Key-Value pairs
typedef struct{
    char* key;
    char* value;
} ht_item;

// Array of pointers to items with metadata
typedef struct{
    int size;
    int count;
    ht_item** items;
}   ht_hash_table;

// Initialize and delete new items
static ht_item* ht_new_item(const char* k, const char* v){
    ht_item* i = malloc(sizeof(ht_item)); // allocate memory
    i->key = strdup(k); // saves a copy of string K in new memory
    i->value = strdup(v); // saves a copy of string K in new memory
    return i;
}
// Initalize a new hash table by creating an array of size = 53
ht_hash_table* ht_new() {
    ht_hash_table* ht = malloc(sizeof(ht_hash_table));
    ht->size = 53;
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(ht_item*));
    printf("\nNEW TABLE CREATED SUCCESSFULLY\n");
    return ht;
}

// Item & hash table deletion function
static void ht_delete_item(ht_item* i){
    free(i->key);
    free(i->value);
    free(i);
}

void ht_delete_hash_table(ht_hash_table* ht){
    for (int i = 0; i < ht->size; i++){
        ht_item* item = ht->items[i];
        if (item != NULL){
            ht_delete_item(item);
        }
    }
    free(ht->items);
    free(ht);
    printf("\nHASH TABLE DELETED SUCCESSFULLY\n");
}

int main()
{
    ht_hash_table* ht = ht_new();
    sleep(1);
    ht_delete_hash_table(ht);
}