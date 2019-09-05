// Chapter 29: Saving/Reading Random-Access Files to Disk
/*
    This program opens a file called letters.txt and prints A-Z into
    the file. It then loops backwards printing Z-A.
*/

#include <stdio.h> 
#include <stdlib.h>

FILE * fptr;

int main()
{
    char letter;

    /* Opening Random Files                                          
       "r+" = open existing file for reading/writing
       "w+" = open new file for reading/writing
       "a+" = open in append mode. fptr = EOF.    
    */
    fptr = fopen("/home/sahil/Documents/Learning/letters.txt", "w+");

    if (fptr == 0)
    {
        printf("Error opening file. \n"); 
        exit(1);
    }

    /* Write data to the file                                        */
    fprintf(fptr, "Letters from A-Z printed below: \n");
    for (letter = 'A'; letter <= 'Z'; letter++)
    {
        fprintf(fptr, "%c", letter); // fputc is better altnerative.
        //fputc(letter,fptr);
    }

    /* Read & print the LAST 26 bytes of the file (but prints it backwards) */
    fseek(fptr, -1, SEEK_END);          // -1 byte from end of file
    for (int i = 26; i > 0; i--)
    {
        letter = fgetc(fptr);
        fseek(fptr, -2, SEEK_CUR);
        /*
            Why is the longVal (above) -2?
            1. Assume current letter = F.
            2. We want to go behind F to E.
            3. fseek already puts the pointer 1 element AHEAD of where we want 
               to be when it is equal to 0. (Output would be G)
            4. Therefore doing -1 will go from G to F.
            5. But we want to go one more element behind, from F to E! 
               Therefore do another -1 and we are now at E! 
        */
        printf("Next letter is %c. \n", letter);
    }

    /* Remember to close your files                                  */
    fclose(fptr);

}