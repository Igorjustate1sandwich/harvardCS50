// C program to get basic user input in form if integer. No scanf. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    char line[100];
    int n;
    /* prompt for input */
    printf( "Input integer: \n");
    /* grab the output from the keyboard */
    fgets(line,sizeof(line), stdin);
    /* convert this text to the numbers */
    sscanf(line, "%d", &n);
    /* print out what you have read in */
    printf("You inputted integer: %d \n", n);
    return 0;
} 