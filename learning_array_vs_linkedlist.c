// Make Array program that adds an element to the start of an existing array.
// See handwritten note on OneNote for line by line explanation.

#include <stdio.h>

int main()
{
    int a[5] = {100, 200, 300};
    int size_list = 3; // What's the size of your list? 
    int pos = 1; // What position in the list do you want to change?
    int new_val = 50; // What is the new value for the position in the list?

    // Create room for new element by shifting everything to the right.
    for (int i = 3; pos <= i; i--)
    {
        a[i] = a[i-1];
    }

    // Insert new element at given position and increment size_list.
    a[pos - 1] = new_val;

    // Print final result.
    for (int i=0; i <= size_list; i++)
    {
        printf("New Element: %d \n", a[i]);
    }
}