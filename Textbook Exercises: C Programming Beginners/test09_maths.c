/*
    NOTE: To compile add the -lm flag next to filename in GCC.

    This section: floor(), ceil(), fabs(), pow(), sqrt()
        rand(), srand(), time_t
    Not covered: trig and log functions. Check chapter 20 page 163.
*/

#include <stdio.h>
#include <stdlib.h>     // required for rand()
#include <time.h>       // required to generate time of day for seed
#include <math.h>       // required for below functions

int main()
{
    /******************************************************************** 
    floor and ceil() 
    the floor and ceiling functions push down and push up non-integers to
    their next-lower or next-higher integer value.
    */
    float n1, n2, n3, n4;
    
    // floor - rounds int to next lowest INTEGER value.
    n1 = 1.4; n2 = 1.7; n3 = 4.9; n4 = 4.5;
    printf("Floor Val 1 = %.1f \n", floor(n1));
    printf("Floor Val 2 = %.1f \n", floor(n2));
    printf("Floor Val 3 = %.1f \n", floor(n3));
    printf("Floor Val 4 = %.1f \n\n", floor(n4));
    
    // ceil - rounds int to next highest INTEGER value.
    printf("Ceil Val 1 = %.1f \n", ceil(n1));
    printf("Ceil Val 2 = %.1f \n", ceil(n2));
    printf("Ceil Val 3 = %.1f \n", ceil(n3));
    printf("Ceil Val 4 = %.1f \n\n", ceil(n4));

    /********************************************************************
    fabs(): returns floating point absolute value
    -always returns positive
    -use when you always want a positive number returned
    -useful when comparing peoples ages/weight as age is always a positive 
    num.
    */
   
    printf("fabs of 55.0 is %.0f \n", fabs(55.0));
    printf("fabs of -25.20 is %.0f \n", fabs(-25.20));
    // fabs in action - time travel example:
    printf("The year 1876 was %.0f years ago \n", fabs(1876 - 2019));

    /********************************************************************
    pow() and sqrt()
    */
    int x = pow(4, 6);
    int y = sqrt(36);

    printf("4 to the power of 6 = %d \n", x);
    printf("Square Root of 36 = %d \n", y);

    /********************************************************************
    Random Number Generation with rand() */

    // BAD/BASIC - not truly random
        int dice = rand();
        printf("Value of dice: %d \n", dice);

    // BAD/BASIC but with range from 1 to 6 
        dice = ( rand() % 5 ) + 1;     // rand number from 1-6
        printf("Value of dice: %d \n", dice);  

    // GOOD IMPLEMENTATION - range + seed to make a truly random value
        // SEED Function
        time_t t;
        srand(time(&t));
        
        dice = ( rand() % 5 ) + 1;
        printf("Truly random value of dice: %d \n", dice);   
}