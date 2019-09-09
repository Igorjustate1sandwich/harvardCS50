// Number Change without using pointers.
// Doesn't work as whenever you pass a variable to a function, a temporary copy is created for the life of that function.

#include <stdio.h>

int num_change(int);
int main()
{
    int x = 10;
    printf("\nThe value of X before num_change = %d \n", x);
    num_change(x);
    printf("The value of X after num_change = %d \n\n", x);

}
int num_change(int change)
{
    change = change + 10;
    return change;
}