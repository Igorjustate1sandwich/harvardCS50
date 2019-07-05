// Learning the Bubble Sort 
#include <stdio.h>

void bubblesort (int n, int *array);
int temp; int n = 5; 

int main()
{
    printf("\n");
    int array[] = {5,4,3,2,1};
    bubblesort(n, array);

    // Print
    printf("\nBubble Sort: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%i \n", array[i]);
    }
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


