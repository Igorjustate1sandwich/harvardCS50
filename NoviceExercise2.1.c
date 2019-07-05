// Write a function that returns the largest element in a list.

#include <stdio.h>

void bubblesort (int n, int *array);
int temp; int n = 5; 

int main()
{
    printf("\n");
    int array[] = {7,4,9,2,5};
    bubblesort(n, array);

    // Print
    printf("The largest element in this list is %i. \n", array[n-1]);
    printf("The smallest element in this list is %i. \n \n", array[0]);
}

void bubblesort (int n, int *array)
{
    for (int i = 0; i <  n-1; i++) 
    {
        for (int j = 0; j < n-i-1; j++) 
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}


