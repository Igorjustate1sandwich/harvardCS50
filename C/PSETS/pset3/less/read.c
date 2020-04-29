// Program that reads my name stored in a .txt file

#include <stdio.h>

int main(void)
{
    FILE *filepointer;
    
    filepointer = fopen("myname.txt", "read");
    
    char c;
    
    while(1)
    {
        // If you are at the end of the file then stop.
        if(feof(filepointer))
        break;
        
        // Get next character for data within the filepointer address.
        c = fgetc(filepointer);
        printf("%c", c);
    }
    printf("Finished. \n");
    
    fclose(filepointer);
}