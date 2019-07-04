// Learning the Bubble Sort 

#include <stdio.h>

void bubblesort (int count, int *unsorted);
int temp; int count = 4; int line = 0;
int i;

int main()
{
    printf("\n");
    int unsorted[] = {7,9,4,6};
    bubblesort(count, unsorted);

    // Print
    printf("\n Bubble Swap: \n");
    for (int i = 0; i < count; i++)
    {
        printf("%i \n", unsorted[i]);
    }
}

void bubblesort (int count, int *unsorted)
{
    for (int i = 0; i <  count-1; i++) // MASSIVE NOTE FOR WHY YOU GET 3 AS OUTPUT!! COUNT = 0 HERE AS BASELINE. SEE WHAT HAPPENS WHEN REMOVE NUMERICALS.
    {
        
        for (int j = 0; j < count-i-1; j++) // SAME AS ^
        {
            if (unsorted[j] > unsorted[j+1])
            {
                temp = unsorted[j];
                unsorted[j] = unsorted[j+1];
                unsorted[j+1] = temp;
            }
        }
    }
}


