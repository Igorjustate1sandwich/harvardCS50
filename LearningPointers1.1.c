// Learning Pointers 1.1.
// Dereferencing a Pointer and then making that Pointer apart of an assignment. 

#include <stdio.h>

int main()
{
    int x = 25;
    int *p = &x;

    printf("\n*** Prior to Assignment ***\n");
        printf("Output 1: Int x = %d \n", x);
        printf("Output 2: Int p = %d \n", *p);

    *p = 40;
    printf("\n*** After re-assignment ***\n");
        printf("Output 1: Int x = %d \n", x);
        printf("Output 2: Int p = %d \n\n", *p);
    return 0;
}

