// Declares a dictionary's functionality
// Contains function prototypes for use in dictionary.c

#ifndef DICTIONARY_H        // don't worry about this
#define DICTIONARY_H        // don't worry about this

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Prototypes
bool load(const char *dictionary);
unsigned int size(void);
bool check(const char *word);
bool unload(void);

#endif // DICTIONARY_H
