/*
    - Simple Program that will take a user inputted dataset and then perform
      a statistical analysis.
    - Print statistical analysis to a text document.
    - Allow user to choose a custom name for document.
    - bonus: fgets() to replace scanf
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE * fptr;

int main()
{
    double * array;                // stores user dataset
    int * arrayModeTracker;        // used to store the mode      
    double * sDevElements;         // store temp sdev values
    double * array_lowerHalf;      // Lower half of array (for IQR)
    double * array_upperHalf;      // Upper half of array (for IQR)

    int aSize;                     // user defined dataset size
    int aSizeLower;
    int aSizeUpper;
    double temp = 0;

    double mean, mode, median, median_temp, sDev, sDevTemp, IQR;
    double median_lower, median_upper, IQR_lower, IQR_upper;

// Get dataset size
    printf("Enter size of dataset: ");
    scanf(" %d", &aSize);

// Allocate dataset memory
    array = malloc(aSize * sizeof(double));
    arrayModeTracker = malloc(aSize * sizeof(int));
    sDevElements = malloc(aSize * sizeof(double));
    array_lowerHalf = malloc((aSize/2) * sizeof(double));
    array_upperHalf = malloc((aSize/2) * sizeof(double));

// Get user input until size n
    for (int i = 0; i < aSize; i++)
    {
        printf("Enter value for element %d: ", i+1);
        scanf(" %lf", &array[i]); 
    }

// Sort data for clarity
    for (int i = 0; i < aSize; i++)
    {
        for (int j = i; j < aSize; j++)
        {
            if (array[i] > array[j])
            {
                int temp;
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

// Statistical Analysis
    // Calculate MEAN
    for (int i = 0; i < aSize; i++)
    {
        mean += array[i];
    }
    mean = mean/aSize;

    // Calculate MEDIAN 
    if (aSize % 2 == 0)  // check if aSize is even
    {
        int n = aSize /2;
        median = ((array[n] + array[n-1]) /2);
    }
    else  // if aSize is odd
    {
        median_temp = (aSize + 1.00) / 2.00;  //eg = 5,6,7,8,9  = element 3 aka 7
        for (int i = 0; i < median_temp; i++)
        {
            median = array[i];
        } 
    }
    
    // Calculate MODE
    for (int i = 0; i < aSize; i++)
    {
        for (int j = i; j < aSize; j++)
        {
            // Track elements that occur (repeat) more than once
            if (array[i] == array[j])
            {
                arrayModeTracker[i]++;
            }
            // Out of the above tracked elements, which most frequently occurs?
            if (arrayModeTracker[i] > arrayModeTracker[j])
            {
                mode = array[i];
            }
        }
    }

    // Calculate STANDARD DEVIATION
    for (int i = 0; i < aSize; i++)
    {
        temp = 0;
        temp = (array[i] - mean); 
        sDevElements[i] = pow(temp,2);
        sDevTemp += sDevElements[i];        // add up pow'd values

    }
    sDev = ((1/(double)aSize) * sDevTemp); 
    // must typecast int to double or else your values will be incorrect.
    // multiplying an integer by a double will always result in integer output, which is NOT what we want. 
    // Remove (double) and see what happens.
    sDev = sqrt(sDev); //sqrt to get final outcome

    // Calculate Interquartile Range (IQR)
    if (aSize % 2 != 0) // if odd 
    {
        aSizeLower = 0;
        // Split the dataset in half. This is the Lower Half (Q1).
        for (int i = 0; i < (aSize /2); i++)
        {
            aSizeLower++;
            array_lowerHalf[i] = array[i];
        }

        // Find the median of the Lower Half.
        int temp2 = (aSizeLower + 1.00) / 2.00;
        if (aSizeLower % 2 != 0) // if array size is odd
        {
            for (int i = 0; i < temp2; i++)
            {
                median_lower = array_lowerHalf[i];
            }
        }
        else
        {
            int x = aSizeLower / 2;
            median_lower = ( (array_lowerHalf[x] + array_lowerHalf[x-1]) /2 );
        }
        
        // Split the dataset in half. This is the Upper Half (Q3).
        aSizeUpper = 0;
        int ctr = 0;
        for (int i = ((aSize+1)/2); i < aSize; i++)
        {
            aSizeUpper++;
            array_upperHalf[ctr] = array[i];
            ctr++;
        }

        // Find the median of the Upper Half.
        int temp3 = (aSizeUpper + 1.00) / 2.00;
        if (aSizeUpper % 2 != 0) // if array size is odd
        {
            for (int i = 0; i < temp3; i++)
            {
                median_upper = array_upperHalf[i];
            }
        }
        else
        {
            int y = aSizeUpper / 2;
            median_upper = ( (array_upperHalf[y] + array_upperHalf[y-1]) /2);
        }
        
        // Subtract Q1 from Q3 to find the IQR.
        IQR = median_upper - median_lower;
    }
    else // if even
    {
        aSizeLower = 0;

        // Split dataset in half. This is lowerhalf (Q1)
        for (int i = 0; i < (aSize /2); i++)
        {
            aSizeLower++;
            array_lowerHalf[i] = array[i];
        }

        // Find median of lowerhalf
        if (aSizeLower % 2 != 0)     // if aSizeLower is odd
        {
            int tempA = (aSizeLower + 1.00) / 2.00;
            for (int i = 0; i < tempA; i++)
            {
                median_lower = array_lowerHalf[i];
            }
        }
        else
        {
            int x = aSizeLower /2;
            median_lower = ( (array_lowerHalf[x] + array_lowerHalf[x-1]) /2);
        }
        
        // Split dataset in half. This is upperhalf (Q2)
        aSizeUpper = 0;
        int ctr = 0;
        for (int i = aSize/2; i < aSize; i++)
        {
            aSizeUpper++;
            array_upperHalf[ctr] = array[i];
            ctr++;
        }

        // Find median of upperhalf
        if (aSizeUpper %2 != 0)     // if aSizeUpper is odd
        {
            int tempB = (aSizeUpper + 1.00) / 2.00;
            for (int i = 0; i < tempB; i++)
            {
                median_upper = array_upperHalf[i];
            }
        }
        else
        {
            int y = aSizeUpper /2.00;
            median_upper = ( (array_upperHalf[y] + array_upperHalf[y-1]) /2.00);
        }
        
        // Subtract Q1 from Q3 to find the IQR
        IQR = median_upper - median_lower;
    }

// Console Output
    printf("\n*** Output for N = %d *** \n",aSize);
    printf("1. Mean: %.1f \n", mean);
    printf("2. Median: %.1f \n", median);
    printf("3. Mode: %1.f \n", mode);
    printf("4. Standard Deviation: %.3f \n", sDev);
    printf("5. Interquartile Range: %.2f [Lower: %.1f | Upper: %.1f] \n", IQR, median_lower, median_upper);
    printf("\n");

// File Output
int test;
    fptr = fopen("/home/stndn/Documents/Learning/SPSSOutput.txt", "w");

    fprintf(fptr, "*** Output for N = %d *** \n",aSize);
    fprintf(fptr, " 1. Mean: %.1f \n", mean);
    fprintf(fptr, " 2. Median: %.1f \n", median);
    fprintf(fptr, " 3. Mode: %1.f \n", mode);
    fprintf(fptr, " 4. Standard Deviation: %.3f \n", sDev);
    fprintf(fptr, " 5. Interquartile Range: %.2f [Lower: %.1f | Upper: %.1f] \n", IQR, median_lower, median_upper);

    // User dataset
    fprintf(fptr, "\n\nUser Dataset: \n");
    for (int i = 0; i < aSize; i++)
    {
        fprintf(fptr, "%.2f \n", array[i]);
    }

// free
    free(array);
    free(arrayModeTracker);
    free(sDevElements);
    free(array_lowerHalf);
    free(array_upperHalf);
    fclose(fptr);
}