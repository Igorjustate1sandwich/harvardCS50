// Write a program that prints a multiplication table for numbers up to 12.
#include <stdio.h>

// Function Declare
int multi_table (int n1);
int main()
{
    // Recieve Input
    int user_num;
    printf("Enter a number between 1 and 12: \n");
    scanf("%i", &user_num);

    // Pass to function
    multi_table(user_num);
}
// Function
int multi_table (int n1)
{
    int line = 0;
    int answer;
    for (int i = 0; i < 12; i++)
        {
        line++;
        printf("Line %i: %i multiplied by %i = %i \n", line , n1, line, answer = n1 * line);
        }
        
    return answer;
}   