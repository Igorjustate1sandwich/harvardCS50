// Chapter 27: Data Structures (Part 2/2)
/*
    Using structs with pointers, -> operands.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcpy()

/* Format of a structure - defines a single structure data type called 
   bookInfo. Same as test18.c!           */
struct bookInfo {
    char title[25];                 // Member Definition #1
    char author[25];                // Member Definition #2     
    int pages;                      // Member Definition #3
    float price;                    // Member Definition #4
};

int main()
{
    /* New operand: -> 
        1. When you store structures on the heap you can't use the dot operator.
        2. use -> to store data in heap structures. -
        3. > requires a pointer on the LEFT and a member name on the RIGHT.

       Pointers & Structs:
        1. Perhaps you will need pointers to structures. You can define them
        and use them in the code below.
    */

    /* Creating pointers to three structure variables               */
    struct bookInfo *book1, *book2, *book3; // book1/2/3 points to 3 struct vars.
    
    /* You must allocate memory from the heap for the structures    */
    book1 = (struct bookInfo *)malloc(sizeof(struct bookInfo));
    book2 = (struct bookInfo *)malloc(sizeof(struct bookInfo));
    book3 = (struct bookInfo *)malloc(sizeof(struct bookInfo));

    /* Place data within the structure variables. Use the -> operator to
       access individual members within a structure pointed to by a pointer 
       variable.                                                    */
    strcpy(book1->title, "A Game of Thrones");
    strcpy(book1->author, "George RR Martin");
    book1->pages = 700;
    book1->price = 29.95;

    /* Print output                                                 */
    printf("%s by %s is %d pages long and costs $%.2f. \n",book1->title, book1->author, book1->pages, book1->price);

    /* Free                                                         */
    free(book1);
}