/*
    - Program based on test20.c & test21.c (fopen)
    - Program will: allow user to create array of size n, randomly fill array,
      then print to a file called "array_output".
    
    FUN FACT: Replace the "doubles" with "integers" and see how the output changes.
*/

#include <stdio.h>
#include <stdlib.h>

FILE * fptr;

int main()
{
    int aSize;
    double * array;
    double data = 1;

    // get size
    printf("Enter size of array: ");
    scanf(" %d", &aSize);

    // create array
    array = malloc(aSize * sizeof(double));

    // error check
    if (!array)
    {
        puts("Memory Allocation Failure!");
        exit(1);
    }

    // fill array
    for (int i = 0; i < aSize; i++)
    {
        data = data * 2;
        array[i] = data;
    }

    // write to file
    fptr = fopen("/home/sahil/Documents/Learning/array_output.txt", "w");

    for (int i = 0; i < aSize; i++)
    {
        fprintf(fptr, "%1.f \n", array[i]);
    }

    // close file & free
    fclose(fptr);
    free(array);
}
