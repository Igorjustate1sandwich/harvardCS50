// Old: Write a program that asks the user for a number n and prints the sum of the numbers 1 to n
// New: Now modify the previous program (old) such that only multiples of three or five are considered in the sum.
// Example: 3, 5, 6, 9, 10, 12, 15 for n = 17
#include <stdio.h>

int main()
{
    int num; int counter = 1;
    printf("ENTER a number between 1 and 50: \n");
    scanf("%i", &num);

    while (counter <num+1)
    {
        if (counter % 3 == 0 || counter % 6 == 0)
        {
            printf ("The sum of %i and %i is %i \n", counter, num, counter + num);
        }
        counter++;
    }
}