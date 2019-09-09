// Chapter 27: Data Structures (Part 1/2)
/*
    Introduction to Structs, importance of strcpy(), struct arrays
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>     // strcpy

/* Format of a structure - defines a single structure data type called 
   bookInfo 
*/
struct bookInfo {
    char title[25];                 // Member Definition #1
    char author[25];                // Member Definition #2     
    int pages;                      // Member Definition #3
    float price;                    // Member Definition #4
};

int main()
{
    /* To use the bookInfo structure format you must now define a structure
       variable. The name of the variable I have chosen is 'book1'.      */
    struct bookInfo book1;

    /* Now we may fill book1 with some data. Use the dot operator to access 
       individual members within a structure variable.                  */
    strcpy(book1.title, "Game of Thrones");         // Fill Title
    strcpy(book1.author, "George RR Martin");       // Fill Author
    book1.pages = 700;                              // Fill Pages
    book1.price = 29.95;                            // Fill Price

    /* REMEMBER! You need to use strcpy() because you can't assign data
    to an array after you have already defined it. As we're assigning data
    later, we can only copy data to it (via strcpy).

    Look at this example:
        char myname[25] = 'LOL';    // SUCCESS
        char yourname[25];              
        yourname = 'BOB';     // FAIL - can't assign after above definition
    */

   /* You can also create a few struct-variables in a single line     */
   struct bookInfo book2, book3, book4;

   /* You can even create hundreds of structure variables via array!  */
   struct bookInfo book[1000];      // a librarian might have 1000 books.

   book[5].price = 20.00;
   book[109].price = 24.99;
   strcpy(book[36].author, "JRR Tolkien");

   printf("Price for Book 109: %.2f \n", book[109].price);

   /* putting data in structs via user input */
   for (int i = 0; i < 2; i++)
   {
       printf("Enter the title for Book #%d: ", i+1);
       fgets(book[i].title, 25, stdin);
       printf("Enter the author for Book #%d: ", i+1);
       fgets(book[i].author, 25, stdin);
       printf("How many pages are in Book #%d?: ", i+1);
       scanf(" %d", &book[i].pages);
       printf("Enter the price for Book #%d: ", i+1);
       scanf(" %f", &book[i].price);
       getchar();   // IMPORTANT: Clears last newline for next loop.
   } 

   /* printing user input */
   for (int i = 0; i < 2; i++)
   {
       printf("***Book %d*** \n", i+1);
       printf("%s%s", book[i].title, book[i].author);
       printf("Pages: %d. Price: $%.2f.", book[i].pages, book[i].price);
       printf("\n");
   }

   /* You might notice some "problems" with fgets()...
        - fgets automatically includes a newline, which makes printing
          output..ugly.
        - you'll need to find a way to strip the newline.
        - or you can use gets but it's not safe.
   */
}