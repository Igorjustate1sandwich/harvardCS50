// Write a program that asks the user for a number n and gives them the possibility to choose between 
// computing the sum and computing the product of 1,…,n.

#include <stdio.h>

int main()
{
    int n;
    int y;
    int answer;

    printf("Enter a number: \n");
    scanf("%i", &n);

    printf("Press 1 to compute SUM or press 2 to compute PRODUCT. \n");
    scanf("%i", &y);

    if (y == 1)
    {
        printf("The sum of 1 and %i is %i \n",n, answer = 1 + n);
    }

    if (y == 2)
    {
        printf("The product of 1 and %i is %i \n", n, answer = 1 * n);
    }

    else if (y !=1 || y!=2)
    {
        printf("Unknown command. \n");
    }
}
