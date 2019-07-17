// Intro to Linked Lists starting with Arrays


#include <stdio.h>

int main()
{
    // Problem: This is a static list. It is fixed and cannot "grow" over time.

    int list[5] = {1, 2, 3, 4, 5};
    printf("List 3 = %d \n", list[3]);
    list[3] = 10;
    printf("List 3 = %d \n", list[3]);
    

}