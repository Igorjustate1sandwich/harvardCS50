// Write a function that returns the largest element in a list.
#include <stdio.h>

// Define Function
void Bubble_Sort(int count, int *array);

int main()
{
    int array[10]; int count; // make sure count is array - 1 or NULL error.

    printf("How many elements do you want to sort? \n");
    scanf("%d", &count); 

    printf("Enter the %i elements: \n", count);
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &array[i]);
    }
 
    // Pass Function
    Bubble_Sort (count, array);

    // Print Output
    printf("After Sorting: \n");
    for (int i = 0; i < count; i++)
    {
        printf("%d \n", array[i]);
    }
}

void Bubble_Sort(int count, int *array)
{
    int swap;
    for (int i = count-2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            if (array[j] > array[j+1])
            {
                swap = array[j];
                array[j] = array[j+1];
                array[j+1] = swap; // Not sure if this is necessary.
            }
        }
    }
}
