/*
    Character Testing: Part 1 of 2 [Chapter 19]
    isalpha(), isdigit(), isupper(), islower()
    toupper() & tolower()
    continue() function.
*/

#include <stdio.h>
#include <ctype.h>  // REQUIRED FOR THE NEW FUNCTIONS
#include <string.h>
#include <stdlib.h>

int main()
{
    
char letter[1];
/*
please only enter one letter because my programming skill is shit and I
don't know how to account for segfaults (YET) for when the user bashes
in multiple letters on purpose because he's a prick 
*/
printf("Enter only letter: \n");
scanf("%s", letter);
(isalpha(letter[0])) ? printf("input is alpha\n") : printf("not alpha\n");
(isdigit(letter[0])) ? printf("input is digit\n") : printf("not digit\n");

/********************************************************************** 
Password Checker
*check if the password a user enters has upper/lowercase letters
and a digit. */

char pass[16];
int hasUpper, hasLower, hasDigit;
hasUpper = hasLower = hasDigit = 0;

while (hasUpper || hasLower || hasDigit == 0)
{
    printf("Input a potential password to check it's security: ");
    scanf(" %s", pass);
    for (int i = 0; i < strlen(pass); i++)
   {
       if (isupper(pass[i]))
       {
           hasUpper = 1;
           continue; /* 
           Importance of the Continue Statement:
            -The [i] value cannot be an upper, lower and digit ALL at once.
            -If C detects that a character is Uppercase, it's safe to assume
            that it's not a lowercase or a digit either.
            -Therefore, for efficiency we skip the following two if 
            statements and directly iterate to the next cycle in the loop.
            - final if statement doesn't need continue because it's at the end of loop.
            - for another example check test4.c      */
       }

       if (islower(pass[i]))
       {
           hasLower = 1;
           continue;
       }
       if (isdigit(pass[i]))
       {
           hasDigit = 1;
       }
   }
   if ( (hasUpper) && (hasLower) && (hasDigit))
   {
       printf("Secure password. \n\n");
       break;
   }
   else
   {
       printf("Password not secure. Try again. \n");
   }
}

/**********************************************************************
Case-Changing via the toupper and tolower function */
char firstInit = 'a';

printf("Your character in lowercase: %c \n", firstInit);
printf("Your character in uppercase: %c \n",toupper(firstInit));

}