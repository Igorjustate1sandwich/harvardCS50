// LearningPointers1.2
// Number change with the use of pointers.

#include <stdio.h>

void num_change(int*);

int main()
{
    int x = 10;
    printf("\nThe value of X before num_change = %d \n", x);
    num_change(&x);
    printf("The value of X after num_change = %d \n\n", x);

}
void num_change(int *p)
{
    *p = *p + 9;
}

// See numchange_noptr.c to see what happens if you don't use pointers...