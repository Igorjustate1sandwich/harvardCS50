// Malloc 1

#include <stdio.h>
#include <stdlib.h>

int *new_int(void);
int main()
{
    int *p;
    p = new_int();
    *p = 100;

    printf("P: %d \n", *p);
    free(p);
    return 0;
}
int *new_int(void)
{
    int *p = malloc(sizeof(int));
    return p;
}