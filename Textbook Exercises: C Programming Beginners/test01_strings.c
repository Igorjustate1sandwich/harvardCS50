#include <stdio.h>
#include <string.h>

#define AGELIMIT 30
#define PI 3.14159

int main()
{
    /* create a string */
    char month[] = "April";
    printf("Month: %s \n", month);

    /* if you want to change month you must use strcpy */
    strcpy(month, "May");
    printf("Month: %s \n", month);

    /* playing with constants */
    int var1 = 5; int var2;
    var1 = var1 + AGELIMIT;
    printf("AL: %d \n", var1);

    var2 = 60;
    if (var2 > AGELIMIT)
    {
        printf("You have exceeded age limit \n");
    }

    printf("Value of pi = %f \n", PI);

    /* getting multiple inputs with scanf */
    int day; int month_2; int year;
    printf("Enter date in XX/XX/XX format \n");
    scanf(" %d/%d/%d", &day, &month_2, &year);
    printf("You typed: %d/%d/%d \n", day, month_2, year);
}

