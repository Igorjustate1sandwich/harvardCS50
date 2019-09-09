#include <stdio.h>
#include <math.h>

int main()
{
    int array[10] = {3,5,6,8,9};
    int mean = 6;
    int sdev[10];
    int temp = 0;

    for (int i = 0; i < 5; i++)
    {
        temp = 0;
        temp = (array[i] - mean);
        sdev[i] = pow(temp,2);
        printf("SDEV Element %d:  %d \n", i+1, sdev[i]);
    }


}