/*
    Chapter 26: The Heap (Part 1/3)
    malloc(), free()
*/

#include <stdio.h>
#include <stdlib.h>     // Required for malloc()

int main()
{
    /*  Memory: Introduction to the Heap
        1. The heap is the collection of unused memory in your computer.
        2. You'll want to access the heap because sometimes your program
           will require more memory than you initally defined in variables 
           and arrays.
        3. The only way to access data stored in the heap is via pointer 
           variables. You must keep track of memory you allocate with
           pointer variables!

        Heap: The pile of dirt analogy
        1. Think of the heap as one large pile of dirt stacked up in a pile.
        2. When you shovel dirt out of the pile, one shovel doesn't pick up
           dirt granules that were right below the last shovel of dirt. Also,
           when you throw the shovel of dirt pack onto the heap, the dirt 
           doesn't go right back where it was!
        3. Likewise in computer memory, you have no idea where the memory you
           allocate and deallocate will come from or go back to. You only know 
           that memory comes and goes from the heap.

        Malloc(): Allocate the heap [requires stdlib.h]
        1. Use malloc() (memory allocate) to allocate heap memory.
            1.5. Each set of allocated memory is contiguous. This means you
                 can literally treat it like an array! See Example 1 below.
        2. Use free() to deallocate heap memory.

    */


/* Example 1: Allocate five integers onto a heap */
   /* Create ptr to first heap value        */
   int * ages;  

   /* Allocate five ints onto the heap      */
   ages = (int *) malloc(5 * sizeof(int));  // This is like an array.
   
   
   /* Get data and print output             */
        /* Get input and store in array[i]  */
        for (int i = 0; i < 5; i++)
        {
            printf("Enter data for Age %d:  \n", i+1);
            scanf(" %d", &ages[i]);
        }

        /* Print output in array[i]         */        
        printf("You entered: \n");
        for (int i = 0; i < 5; i++)
        {
            printf("Ages %d: %d \n", i+1, ages[i]);
        }

   /* Finished: Free the heap memory         */
   free(ages);
}