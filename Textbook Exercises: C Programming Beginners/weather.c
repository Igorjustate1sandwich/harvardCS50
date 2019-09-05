#include <stdio.h>
#include <stdlib.h>

/*
- Suppose a forecaster wanted to enter historical temperatures for several 
different cities (in our case, two).
- The forecaster has three different weather readings for each different city.
- Our dataset will consist of TWO cities and..
- Our dataset will consist of THREE weather readings for each of the
  city (two cities).
*/

int main()
{
    /* Create an array of TWO pointers (aka two cities) */
    int * cityArray[2];

    /* Allocate THREE weather readings for each city */
    for (int i = 0; i < 2; i++)
    {
        // Allocate three heap values worth of memory for TWO cities.
        cityArray[i] = (int *)malloc(3 * sizeof(int));
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