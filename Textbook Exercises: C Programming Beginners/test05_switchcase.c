#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* case and switch statement 
        *Rather than using multiple if/else if statements to handle a 
        menu, the switch statement is clearer for multiple conditions.
        *Can only be int or char. No floats/doubles.
        *Case statements don't need to be arranged in any order.
        *For efficiency put common cases towards top of switch statement.
    */
   int user_choice;

   printf("** ATM Program ** \n");
   printf("Enter a choice via number keys \n");
   printf("1. View Balance \n");
   printf("2. Deposit \n");
   printf("3. Withdraw \n");
   printf("4. Exit \n");

   do
   {
       printf("INPUT CHOICE: ");
       scanf(" %d", &user_choice);
       switch (user_choice)
       {
           case (1): printf("You selected View Balance \n");
           break;   // stop case 2/3/4 from occuring because user picked 1.
           case (2): printf("You selected Deposit \n");
           break;
           case (3): printf("You selected Withdraw \n");
           break;
           case (4): exit(1);
           default: printf("%d is not a valid choice. Retry. \n", user_choice);
           break;
       }
   }
   while ( (user_choice < 1) || (user_choice > 4));
}



