// Write a program that asks the user for a number n and prints the sum of the numbers 1 to n
#include <stdio.h>

int main()
{
    int num; int counter = 1;
    printf("ENTER a number between 1 and 50: \n");
    scanf("%i", &num);

    while (counter <num+1)
    {
        printf("The sum of %i and %i is %i \n", counter, num, counter + num);
        counter++;
    }
}