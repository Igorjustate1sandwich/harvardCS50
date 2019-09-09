// Learning Pointers 1.0

#include <stdio.h>

int main()
{
    int x = 25;
    int *p = &x;

    printf("\n*** REFERENCING(&) EXAMPLE: MEMORY ADDRESSES *** \n");
    printf("Output 1: Raw memory address of int x using ampersand = %p \n", &x);
    printf("Output 2: Printing the variable p =  %p \n", p);

    printf("\n*** DEREFERENCING(*) EXAMPLE *** \n");
    printf("Output 1: Variable x = %d \n", x);
    printf("Output 2: Variable p = %d \n \n", *p);
}
