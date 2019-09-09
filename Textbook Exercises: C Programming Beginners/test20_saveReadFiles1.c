// Chapter 28: Saving/Reading Sequential Files to Disk

#include <stdio.h> 

/* Define file pointer variable named fptr. This should be GLOBAL.   */
FILE * fptr;

int main()
{
    char text[200];
    char * pText = text;

    /* There are two types of files:
       1. Sequential: must read/write the file in the order of the data.
          e.g. video tape operates in a sequence
       2. Random-access: free to read/write any place of the file.
          e.g. blu-ray - you can skip to different chapters easily

       Opening a File requires a File Pointer:
       1. Regular ptr holds address of data in a variable.
       2. fptr holds the disk location of the disk you're working with.
       3. Before using fopen(), you MUST define a file pointer variable.
    */

    /* We need to connect fptr to a file with fopen()                */
    fptr = fopen("/home/sahil/Documents/Learning/testfile20.txt", "w"); 
    /* "r" = read     "w" = write    "a" = append/create             */
    /* "w" will overwrite an existing file with the same name        */
    
    /* Enter some data                                               */
    printf("Type some text: ");
    fgets(pText, 199, stdin);

    /* Write data to the file                                        */
    fprintf(fptr, "%s \n", pText);

    /* Remember to close your files                                  */
    fclose(fptr);

    // you can hook this functionality to the earlier programs you wrote
    // for some fun. Maybe try printing 100 array elements to a file?
    // see fopen.c
}