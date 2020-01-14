#include <cs50.h>
#include <stdio.h>

int get_correct_int(string prompt) 
{
    int userinput;
    do
    {
        userinput = get_int("%s", prompt); 
    }
    while (userinput <= 0 || userinput >= 9); 
    return userinput; 
}

int main(void)
{
    int height = get_correct_int("Input number between 1 and 8: "); 
    for (int rows = 0; rows < height; rows++) 
    {
        int hashes = rows + 1; 
        int spaces = height - (rows + 1);
        
        for (int x = 0; x < spaces; x++)
        {
           printf(" ");
        }       

        for (int x = 0; x < hashes; x++) 
        {
            printf("#");
        }
        
        printf("\n"); 
    }
}
