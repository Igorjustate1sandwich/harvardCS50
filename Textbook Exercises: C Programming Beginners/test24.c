/*  Chapter 30/31/32: Organizing your programs with functions
    ****** OVERVIEW ******
    1. Basic program that builds upon test23.c. 
    2. Rather than pass a copy of 'score', we pass the memory address to allow 
       us to modfiy the value of score itself in the scoreCalc function.
    3. Pass variables by value (aka copy) if you want their values protected from
       the called function.
    4. Pass variables by address if you want their values changed by the called
       function.                                                            */

#include <stdio.h>

int scoreCalc(int *n);       // this is a prototype    

int main()
{
    int score = 25;
    scoreCalc(&score);       // call function & pass the ADDRESS of score.
    printf("Score in main is %d \n", score);

    /* 
        1. As we passed the memory address of score (&score), scoreCalc was 
           allowed to modify the value of score. Variable score in main is now 
           set to 50!
        2. Whereas in test 23.c, we only passed a COPY of score.
    */
}

int scoreCalc(int *n)
{
    *n = *n * 2;
    printf("Score is %d \n", *n);
    return 1;
}