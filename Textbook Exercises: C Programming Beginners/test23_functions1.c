/*  Chapter 30/31/32: Organizing your programs with functions
    ****** OVERVIEW ******
    1. This is a simple program that demonstrates the basic structure of a
       function via local variables.
    2. A function is global if you define the variable (int) before the fun name
       A function is local if you define it after an opening brace.
    3. Passing Arguments: The terms 'passing by value' and 'passing by copy'
       mean the same thing. 
    4. Pass variables by value (aka copy) if you want their values protected from
       the called function.
    5. Pass variables by address if you want their values changed by the called
       function.                                                            */

#include <stdio.h>

/*  Prototyping:
    1. You MUST prototype all your functions.
       Prototyping ensures that you don't pass the wrong data types to functions.
    2. How? Make sure you always list the type (aka float, int) before
       the function name. See below                     
*/
int scoreCalc(int n);       // creating a prototype for an int function that 
                            // multiplies 'score' by 2

int main()
{
    int score = 25;
    scoreCalc(score);       // call function & pass a copy of score
    printf("Score in main is still %d \n", score);
    /*
        1. Note that C only passes a copy of 'score' to the function below. Therefore,
        the actual variable itself is not modified.
        2. If you wanted to modify 'score' itself via the scoreCalc function, you
        must pass the ADDRESS of score via pointers. See test24.c
        3. As a result, main will still report that score = 25!
    */
}

int scoreCalc(int n)
{
    n = n * 2;
    printf("Score is %d \n", n);
    return 1;
}