/*
    dealing with arrays
    - ch 21.
*/

#include <stdio.h>


int main()
{

    /* Creating placeholder values in your array by zeroing each element */

    /*
    int amt[100] = {0};

    for (int i = 1; i < 6; i++)
    {
        printf("Line %d = %d \n", i, amt[i]);
    }

    // Now I can freely change the values in amt[] whenever I want rather
    // than doing it once at the start.
    amt[25] = 500;
    printf("%d \n", amt[25]);
    */

   /* customer ID (key), customer database, customer balances */
   int key = 0;
   int cusDB [10] = {100,101,102,103,104,105,106,107,108,109};   
   int cusBal [10] = {24, 83, 193, 238, 1920, 5, 27, 88, 68, 140};

   do
   {
       printf("Welcome. Please enter your ID key (100 - 109): ");
       scanf(" %d", &key);
   } while (key < 100 || key > 109);
   
   for (int i = 0; i < 10; i++) // i = position in cusDB/cusBal array
   {
       //printf("Current pos in cusDB = %d \n", cusDB[i]); //use for debug
       if (key == cusDB[i])
       {
           if (cusBal[i] > 100)
            {
                printf("Your customer ID is %d and your balance is $%d \n", key, cusBal[i]);
                printf("Warning. Your balance is over the threshold ($100 max) \n");
                break;
            }
            else
            {
                printf("Your customer ID is %d and your balance is $%d \n", key, cusBal[i]);
                printf("You have a good credit history! \n");
                break; /* remember that breaking is efficient as it terminates
                the loop when you're done rather than running the entire cycle */
            }
       }
   }
}