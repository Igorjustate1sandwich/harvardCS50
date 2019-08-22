/*
    Ch24. Solving the Mystery of Pointers
*/

#include <stdio.h>
#include <stdlib.h>     // used for exit(1)

int main()
{
    /* two important operators:
    & == Address-of operator [used to assign address of a var to a ptr]
    * == Dereferencing operator and is also used to define a pointer variable.                                    */

    int age = 21;   /* store num 19 in variable age */
    int * pAge;     /* define a new pointer variable */
                    /* the * tells C that the variable pAge is a ptr */  
    pAge = &age;   /* put the memory address of age into pAge */


    /* Using the Dereferencing (*) operator */
        /* As soon as you link up a pointer with another variable, you
        can work with the other value by dereferencing the pointer */
    
    /* age = 25 and *pAge = 25 do the exact same thing */
    age = 25;       /* store num 25 in INT age */
    *pAge = 25;     /* store num 25 in INT age (same as above) */

    printf("Age = %d \n", age);
    printf("Age = %d \n", *pAge);

    age = 30; 
    *pAge = 31;     /* stores num 31 in INT age (overwrites 30 in age) */
    printf("Age = %d \n", age);
    printf("Age = %d \n", *pAge);

    /* Example Exercise
        - ask user how much fuel they've filled their car with
        - ask for discount options (employee, coles voucher, none)
        - compute final cost
        - all to be done using pointers
    */

    int fuel;                 // in litres
    float cost = 1.26;        // $1.26 per litre
    float discount;
    float total = 0;
    int option;

    int * pFuel = &fuel;
    float * pCost = &cost;
    float * pDiscount = &discount;
    float * pTotal = &total;

    printf("How many litres of fuel did you pump into your car? \n");
    scanf(" %d", &fuel);
    do
    {
        printf("Discount options: Press [1] for employee discount [2] for coles voucher or [3] for none \n");
        scanf(" %d", &option);
        switch(option)
        {
            /* this method does NOT use pointers */
            case(1): printf("You selected Employee Discount. \n");
            total += fuel * cost;
            discount = total * 15/100;      // 15% discount
            total -= discount;
            printf("Total fee owing: $%.2f \n", total);
            break;

            /* this method uses dereferenced POINTERS and does the same thing! */
            case(2): printf("You selected Coles Voucher. \n");
            *pTotal += *pFuel * *pCost;
            *pDiscount = *pTotal * 10/100;  // 10% discount
            *pTotal -= *pDiscount;
            printf("Total fee owing: $%.2f \n", *pTotal);
            break;

            case(3): printf("You are paying without discount \n");
            *pTotal += *pFuel * *pCost;
            // note below how total and *pTotal are the same.
            printf("Total fee owing: $%.2f \n", total); 
            break;

            default: printf("Invalid choice. Try again! \n");
            break;
        }

    } while (option < 1 || option > 3);
}