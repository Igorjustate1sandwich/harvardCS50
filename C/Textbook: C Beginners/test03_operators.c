#include <stdio.h>
#include <string.h>

int main()
{
   /* conditional operator */
   /*
        almost every if-else statement can be rewritten to a conditional
        - Requires 3 arguments to run
        - Parentheses = if  
        - ? = then  
        - : = else.
   */
   int age = 21;
   (age >= 21) ? (printf("Old enough \n")) : printf("Not old enough \n");
   
   // example 2: contextual answer based on amount
   int amount = 3;
   printf("Today I ate %d banana%s \n", amount, (amount>1) ? "s." : ".");


   /* prefix and postfix operators */
   int count = 50, n = 0;

   // prefix operand is computed before everything else in the line.
   n = ++count * 2;
   printf("n = %d \n", n);
   count = 50, n = 0;           // Reset

   // postfix operand is computed after everything else in the line.
   n = count++ *2;
   printf("n = %d \n", n);


}


