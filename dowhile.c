#include <stdio.h>

int main()
{
    int num;

    do
    {
        printf("Enter num between 1-10 \n");
        scanf(" %d", &num);

        if (num >= 1 && num <= 10)
        {
            printf("Good. \n");
        }
        else
        {
            printf("Bad. \n");
        }
    }
    while (num <=0 || num >= 11);
}