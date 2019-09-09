// Write a program that prints all prime numbers. 
// (Note: if your programming language does not support arbitrary size numbers, 
// ...printing all primes up to the largest number you can easily represent is fine too.)
// A prime number is a whole number that cannot be made by multiplying other whole numbers

#include <stdio.h>

int main()
{
    int i; int j;
    int line = 0;
    for (i = 2; i <= 1000 ; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (i == j)
        {
            line++;
            printf("LINE %i: %i is a prime number \n", line, i);
        }
    }
}