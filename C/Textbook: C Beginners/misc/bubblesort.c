#include <stdio.h>
/*
https://stackoverflow.com/questions/12259622/why-bubble-sort-needs-nested-loops
*/

int main()
{
    int arraySize = 3;
    int array[5] = {13, 3, 1, 20, 200};   // unsorted

    
        for (int inner = 0; inner < 3; inner++)
        {
            if (array[inner] > array[inner+1])
            {
                int temp = array[inner];
                array[inner] = array[inner+1];
                array[inner+1] = temp;
            }
        }
    

    printf("Sorted List: \n");
    for (int i = 0; i < arraySize; i++)
    {
        printf("%d \n", array[i]);
    }

}