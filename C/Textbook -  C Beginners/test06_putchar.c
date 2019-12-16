// putchar(), getchar(), newline buffering, getch

#include <stdio.h>
#include <string.h>
// #include <conio.h> // only runs on MS-DOS systems :(

int main()
{
    /* putchar() and getchar 
        *getchar() get a char from keyboard and put into a BUFFER
        *putchar() send a char to the screen.
        *buffer: unfortunately pressing 'ENTER' is included in the buffer
        and therefore this must be corrected
    */

   char name[] = "Sahil";


   for (int i = 0; i < strlen(name); i++)
   {
       putchar(name[i]);    // output a single char
       printf("\n");        // seperate char output
   }

    /* 
    *********************************************************************
    Program that takes up to 30 characters and input and then
       reverses it as output.
    */
    char message[50];
    int i;

    printf("Type up to 30 characters then hit ENTER... \n");
    for (i = 0; i < 30; i++)
    {
        message[i] = getchar();
        if (message[i] == '\n')
        {
            i--;    // "ENTER" incorrectly adds +1 to i, therefore i--
            break;  /*  Rather than loop 30 times, break upon 
                        user demand (ENTER KEY) */
        } 
    }

    printf("\n");   // make output format neat

    for (; i >= 0; i--)
    {
        putchar(message[i]);
    }

    printf("\n");   // make output format neat


    /* 
    *********************************************************************
    getchar(), bufer and correcting the ENTER keypress 
        - hold_newline in 'good code demo' is a junk value that accounts
        for the ENTER keypress.
    */
    char firstInit; char lastInit; int hold_newline;
    
    // INCORRECT
    printf("Enter your two initials (bad code demo): \n");
    firstInit = getchar();
    lastInit = getchar();
    printf("You entered %c and %c \n", firstInit, lastInit);
    printf("\n");   // make output format neat

    // CORRECT
    printf("Enter your two initials (good code demo): \n");
    firstInit = getchar();
    hold_newline = getchar();
    lastInit = getchar();
    hold_newline = getchar();
    printf("You entered %c and %c \n", firstInit, lastInit);
    printf("\n");   // make output format neat






    /* 
    *********************************************************************
    using getch() as an alternative (REQUIRES WINDOWS)
        pro: doesn't wait for enter keypress thereby eliminating leftover
        enter keypresss.
        cons: unbuffered - user can't use backspace to correct bad input.
    */

    /* Example code: requires conio.h that only runs on MS-DOS
    printf("Enter your two initials (getch demo) \n");
    firstInit = getch();
    lastInit = getch();
    */
}