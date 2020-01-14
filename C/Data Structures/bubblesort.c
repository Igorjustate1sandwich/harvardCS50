#include <stdio.h>

int main()
{
    int listSize = 9;
    int list[9] = {9, 5, 2, 45, 23, 11, 8, 34, 1};
    // Elements:   0  1  2   3   4   5  6   7  8

    // Bubble Sort Algorithim
    for (int i = 0; i < listSize; i++)
    {
        for (int j = 0; j < listSize-1; j++) // listSize-1 to prevent program going out of bounds when checking for list[j+1] below.
        {
            if (list[j] > list[j+1])
            {
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }

    // Print
    for (int i = 0; i < listSize; i++)
    {
        printf("%i. %i \n", i+1, list[i]);
    }
}
