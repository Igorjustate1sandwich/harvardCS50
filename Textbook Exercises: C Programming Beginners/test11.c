/*
    array sorting
    https://stackoverflow.com/questions/12259622/why-bubble-sort-needs-nested-loops
*/

#include <stdio.h>

int main()
{
    int arraySize = 3;
    int array[5] = {50, 40, 30, 20, 200};   // unsorted

    /* Bubble Sort via Nested Loop (EASY)
    How this nested for loop works: 
    1. Inner loop walks through the list swapping any pair of values that is
        out of order down the list.
    2. Outer loop causes the inner loop to run several times (one time for
        each item in the list.)

    FANTASTIC resource to visualise the nested for loop:
    http://pythontutor.com/c.html#mode=display
    
    Outer : Determine the current position of the array, starting at 0.
    Inner : Swap out of order values using position from outer loop.
    Inner = Outer in order to sync position between the two loops. If inner
    was assigned to 0, the loop would not sort anything beyond the first 
    element.        */

    for (int outer = 0; outer < arraySize; outer++)
    {
        for (int inner = outer; inner < arraySize; inner++)
        {
            if (array[inner] < array[outer])
            {
                int temp = array[inner];
                array[inner] = array[outer];
                array[outer] = temp;
            }
        }
    }

    printf("Sorted List: \n");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d \n", array[i]);
    }

}