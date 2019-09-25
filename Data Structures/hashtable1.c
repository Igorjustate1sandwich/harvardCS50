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

int key;                        // generated by hash function
char user_val[LENGTH];          // used to store input from scanf()

typedef struct node
{
    char val[LENGTH];
    struct node* next;
}   
node;

// Represent a Hash Table: Contains 26 seperate linked lists.
node * listArray[26];

// Hash Function (CS50: Speller)
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

Where **head == listArray[n]
Where new_val == Data to store at the head of a given linked list.

*/
void push (node **head, char new_val[LENGTH])           
{
    /* EXAMPLE: Assume **head == (listArray[0]) AND new_val = "Adam"      */
    node * new_node;                    // Create a new node & malloc
    new_node = malloc(sizeof(node));   
    strcpy(new_node -> val, new_val);   // new_node now stores the value "Adam".


    new_node-> next = *head;            // Adam points to whatever the head (listArray[0]) is equal to (NULL). Because there is nothing in listArray[0], lA[0] = NULL.
                                        //      listArray[0] = NULL
                                        //      Adam -> NULL
    *head = new_node;                   // The head (listArray[0]) now EQUALS to Adam.
                                        //      listArray[0] = Adam -> NULL

                                        // Assume you add "Andrew" to the linked list
                                        // Andrew points to whatever the head (listArray[0]) is EQUAL to (Adam)
                                        //      Andrew -> Adam -> NULL      
                                        // The head (listArray[0]) now EQUALS to Andrew
                                        //      listArray[0] = Andrew -> Adam -> NULL
                                        
                                        // Note: There is an important difference between 'pointing to' and 'equals'.
                                        // VISUALISATION:   https://i.imgur.com/BSDm6V6.png
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
        listArray[i] = NULL;
    }

    /* Use hash function to get a key, then fill the 26 linked lists with user data! */
    while(1)
    {
        /* Generate a hash key      */
        printf("\nEnter a user_val to generate a hash key: ");
        scanf(" %s", user_val);
        hash(user_val);
        printf("Hash User_val: %s | Hash Key: %d  \n\n", user_val, key);

        /* Add user_val to the correct linked list (key-array pair) */
        push(&listArray[key], user_val);

        /* Print the contents of the hash table     */
        printf(" ** Hash Table ** \n");
        printf("Key      User_val\n");
        for(int i = 0; i < SIZE; i++)
        {
            printf("List[%d]: ", i);
            printList(listArray[i]); printf("\n");
        }
    }
}