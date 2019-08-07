/*
    Hash Table 3.0: Brief Overview 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // allows for sleep() for debug purpose.
#include <math.h>

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

// Hash function algoritihm (generic) overview
/*  
    - Take a string and a rand_num as input, return a number between 0 and SIZE
    - This number is our key.
    1. Convert string to a large integer..
    2. ..then shrink that large integer to a fixed range via mod
*/
// Hash function alogritihm (generic) implementation
static int ht_hash(const char* s, const int rand_num, const int m){
    long hash = 0;
    const int len_s = strlen(s);
    for (int i = 0; i < len_s; i++) {
        hash += (long)pow(rand_num, len_s - (i+1)) * s[i];
        hash = hash % m;
    }
    printf("\n\nKey = %ld \n\n", hash);
    return (int)hash;
}

// Double Hashing
static int ht_get_hash(
    const char* s, const int num_buckets, const int attempt
) {
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_2, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

// Insert something you want to hash
void ht_insert(ht_hash_table* ht, const char* key, const char* value) {
    ht_item* item = ht_new_item(key, value);
    int index = ht_get_hash(item->key, ht->size, 0);
    ht_item* cur_item = ht->items[index];
    int i = 1;
    while (cur_item != NULL) {
        index = ht_get_hash(item->key, ht->size, i);
        cur_item = ht->items[index];
        i++;
    } 
    ht->items[index] = item;
    ht->count++;
}

// Search something that has been hashed
char* ht_search(ht_hash_table* ht, const char* key) {
    int index = ht_get_hash(key, ht->size, 0);
    ht_item* item = ht->items[index];
    int i = 1;
    while (item != NULL) {
        if (strcmp(item->key, key) == 0) {
            return item->value;
        }
        index = ht_get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    } 
    return NULL;
}

int main()
{
    ht_hash_table* ht = ht_new();
    ht_hash("cat", 152, 53);

    //sleep(1);
    //ht_delete_hash_table(ht);
}