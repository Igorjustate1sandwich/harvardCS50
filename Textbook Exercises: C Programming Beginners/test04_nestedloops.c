#include <stdio.h>
#include <string.h>

int main()
{
   /* nested loops */
   for (int outer = 1; outer <= 4; outer++)
   {
       for (int inner = 1; inner <= 5; inner++)
       {
           printf("%d|", inner);
       }
       printf("\n");
   }

    /* fun fact: if you want to print a % sign you type %% */
   printf("Your score is 98%% \n");
   
   /* continue statement */
    for (int i = 0; i <= 10; i++)
    {
        if ((i % 2) == 1)
        {
            printf("The number %d is odd. \n", i);
            // jump to next iteration (cycle) of loop
            //continue;
        }
        printf("The number %d is even! \n", i);
    }

    /* case and switch statement */
    

}



