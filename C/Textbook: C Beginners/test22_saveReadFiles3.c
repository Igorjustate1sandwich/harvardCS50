// Chapter 29: Saving/Reading Random-Access Files to Disk
/*
    Exploring fseek a little more.
*/

#include <stdio.h> 
#include <stdlib.h>

FILE * fptr;

int main()
{
    int num;

    /* Fseek Modes                                                   */
    // SEEK_SET = go to a position  ||  SEEK_END = go to EOF


    /* Create new file                                               */
    fptr = fopen("/home/sahil/Documents/Learning/letters2.txt", "w+");
    if (fptr == 0)
    {
        printf("Error opening file. \n"); 
        exit(1);
    }

    /* Write data to the file                                        */
    for (int num = 1; num <=10; num++)
    {
        fprintf(fptr, "%d", num);
    }

    /* Using fseek()                                                      
        1. REMEMBER THAT C AND FSEEK COUNT FROM ZERO & NOT ONE!!!!!
        Say I want to put the fptr on the number 5 in the file (aka pos 4)
    */
    fseek(fptr, (5-1), SEEK_SET);
    fputc('*', fptr);       // put a * on where the fptr is.

    /*
        The above code puts a * symbol on position 4 of the file (Number 5).
        If you entered fputs("**",fptr), then both position 4 and position
        5 would be overwritten (aka Number 5 and Number 6)!
    */

    /* Remember to close your files                                  */
    fclose(fptr);
}