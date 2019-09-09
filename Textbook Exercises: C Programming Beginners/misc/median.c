#include <stdio.h>
#include <math.h>

int main()
{
    double nums [10] = {2.0, 3.0, 6.0 ,7.0};
    int n = 4;
    double median;




    printf("Median value is %f. \n", median);
}


/*
ARRAY POS       0 | 1 | 2 | 3
ELEMENTS:       2 | 3 | 6 | 7
n = 4
do n/2 which brings you to array pos 2 (element 6)
Find the average of array[2] and array[2-1];
aka average of 6 and 3 = (6+3) / 2 = 4.5




*/