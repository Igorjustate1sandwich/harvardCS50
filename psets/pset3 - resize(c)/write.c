// Program that writes my name

#include <stdio.h>

int main(void)
{
    // Placeholder for a new file that doesn't exist yet
    FILE *filepointer;
    
    // Write a new file
    filepointer = fopen("myname.txt", "write");
    
    // Data contained in an array which we will use in our file
    char data[] = "My name is Sahil Tandon \n";
    
    // Write above data to the new file
    fwrite(data, sizeof(data[0]), sizeof(data), filepointer);
    
    fclose(filepointer);
}