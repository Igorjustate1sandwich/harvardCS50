#include <stdio.h>

int main()
{
    int nums[5] = {7, 3, 2, 4, 1};

    // Find minimum number
    int min = nums[0];

    for (int i = 0; i < 5; i++)
    {
        if (nums[i] < min)
        {
            min = nums[i];
        }
    }

    printf("Min: %i \n", min);
}


