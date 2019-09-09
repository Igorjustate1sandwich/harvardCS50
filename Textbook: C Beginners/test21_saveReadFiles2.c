// Chapter 28: Saving/Reading Sequential Files to Disk

#include <stdio.h> 

/* Define file pointer variable named fptr. This should be GLOBAL.   */
FILE * fptr;

int main()
{
    /* We need to connect fptr to a file with fopen()                */
    /* "r" = read     "w" = write    "a" = append/create             */
    fptr = fopen("/home/sahil/Documents/Learning/testfile20.txt", "r"); 

    /* Read the contents of testfile.20.txt.
        1. When reading from a file you MUST check for the end-of-file
           condition to ensure that you don't read past the EOF. Check
           with feof().                                              */
   
    char fileLine[100];     // holds each line of input
    if (fptr != 0)          // 0 indicates an error with fopen()
    {
        while (!feof(fptr))
        {
            fgets(fileLine, 100, fptr);
            if (!feof(fptr))
            {
                puts(fileLine);
            }
        }
    }
    else {
        printf("Error opening file. \n");
    }
    
    /* Remember to close your files                                  */
    fclose(fptr);
}