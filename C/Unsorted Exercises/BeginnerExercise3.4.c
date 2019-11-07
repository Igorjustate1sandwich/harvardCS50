// Write a program that prints the next 20 leap years.

#include <stdio.h>
int year = 2019;
int counter;

int main()
{
    for (int i = 1; i <= 20; i++)
    {
    int calculation = year % 4;
        if (calculation == 0)
        {
            counter++;
            printf("YEAR %i. The year %i is a leap year. \n", counter, year);
            year++; 
        }
        else
        {
            i--; year++;
        }
    }
}
