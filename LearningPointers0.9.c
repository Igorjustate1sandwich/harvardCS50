#include <stdio.h>

int main()
{
    int age = 52;
    int *x = &age;
    int *y = &age;

    printf("Age = %p, x = %p, y = %p \n", &age, x, y);
}