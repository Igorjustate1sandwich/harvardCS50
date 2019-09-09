// Chapter 26: The Heap (Part 2/3)
#include <stdio.h>
#include <stdlib.h> 

int main()
{
    /*  Memory: Using an array of pointers
        1. If you must track several chunks of heap memory, use an array
           of pointers. Each array element can point to a different amount
           of heap space.
        2. An array of pointers helps you allocate many different sets of 
           heap memory. See the example below. 
        
        
        Memory Exercise: Allocate an array of pointers onto the heap 
        1. Suppose a forecaster wanted to enter historical temperatures for 
          several different cities (in our case, two).
        2. The forecaster has THREE different weather readings for each city (2).
        2.5 e.g. Melbourne & Sydney
                - Melbourne: reading 1 = 21, reading 2 = 40, reading 3 = 33.
                - Sydney: reading 1 = 16, reading 2 = 43, reading 3 = 23.
    */

    /* Example 2: CODE */
    /* Create an array of TWO pointers (aka two cities) */
    int * cityArray[2];

    /* Allocate THREE weather readings for each city */
    for (int i = 0; i < 2; i++)
    {
        // Allocate three heap values worth of memory for TWO cities.
        cityArray[i] = (int *)malloc(3 * sizeof(int));

        /* Checks if theres not enough memory on the heap   */
        // Basically, if malloc fails, it's pointer value will point to 0.
        // If Malloc succeeds, the pointer variable cityArray would point
        // to the start of the allocated heap.
        if (cityArray[i] == 0)
        {
            printf("Critical Error: Not Enough Memory... \n");
            exit(1);
        }
    }

    /* Enter three weather readings for each of the two cities */
        cityArray [0][0] = 27;        // City 1, Temp #1 (C counts from 0!)
        cityArray [0][1] = 33;        // City 1, Temp #2
        cityArray [0][2] = 22;        // City 1, Temp #3

        cityArray [1][0] = 11;        // City 2, Temp #1 
        cityArray [1][1] = 21;        // City 2, Temp #2
        cityArray [1][2] = 16;        // City 2, Temp #3

    /* Print the output */
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Data for City %d. Weather Reading %d: %d \n",i+1, j+1, cityArray[i][j]);
        }
    }

    /* Free memory from application and put it back onto the heap! */
    for (int i = 0; i < 2; i++)
    {
        free(cityArray[i]);
    }
}