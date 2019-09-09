// Chapter 26: The Heap (Part 3/3)
#include <stdio.h>
#include <stdlib.h>

int main()
{
    /**** Example Program 3: Dealing with large datasets ****/
    /*  1. This program allows the user to create their own array with a size
        of their choosing. They will then fill the array elements with some
        data, and then a basic statistical analysis will be performed.
        2. The program also checks to make sure there is enough memory to
        create an array of user size n.

        Why do we need pointer variables?
        1. Remember that normally, the SIZE of an array must be defined exactly
        in advance. So if I defined an array to hold 100 user elements, but the
        user entered 110 elements, the array is fixed at 100 and cannot expand.
        2. WITH pointer variables we don't need to predict how much memory the 
        user will need. We can just let the user grow or shrink the size of the
        array to their needs, thanks to pointers and memory allocation.

        In essence: the heap enables the program to use only as much memory
        as it needs. When the user requires more memory, malloc() can allocate
        that memory. When the user is finished, don't forget to free().
    */

   int aSize;
   int * array;
   int min, max;
   float average;
   double total = 0;

   /* Ask user for size of array (aSize)                            */
   printf("How many elements will your array consist of? \n");
   scanf(" %d", &aSize);

   /* Create an array of aSize (allocate aSize ints onto heap)      */
   array = malloc(aSize * sizeof(int));

   /* Make sure theres enough memory                                */
   if (array == NULL)   // aka if array == 0 or (!array)
   {
       printf("Array Allocation Failure. Insufficient memory. \n");
       exit(1);     
   }

   /* Fill in the array with some data!                             */
   for (int i = 0; i < aSize; i++)
   {
       printf("Enter data for array element %d: \n", i + 1);
       scanf(" %d", &array[i]);
   }
   
   /* Data Analysis: Find min, max and avg                          */
   // Init min and max values for our comparison
   max = 0;
   min = 50;

   for (int i = 0; i < aSize; i++)
   {
       total += array[i];
       if (array[i] >  max)
       {
           max = array[i];
       }
       if (array[i] < min)
       {
           min = array[i];
       }
   }

   average = ((float)total) / ((float)aSize);

   /* Print out the data in the array                               */
   printf("\n");
   for (int i = 0; i < aSize; i++)
   {
        printf("Data for array element %d: %d \n", i + 1, array[i]);
   }
   
   printf("\nYour array has %d elements! \n\n", aSize);
   printf("Largest value in the array: %d \n", max);
   printf("Smallest value in the array: %d \n", min);
   printf("Average of all values %.2f \n", average);

   /* free and dealloc memory back to the heap                      */
   free(array);
}