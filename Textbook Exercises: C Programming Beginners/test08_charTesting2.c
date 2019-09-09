/*
    Character Testing: Part 2 of 2 [Chapter 19]
    Old: we already know strcpy() and strlen()
    new: strcat(), puts(), gets()
*/

#include <stdio.h>
#include <string.h>

int main()
{
    /******************************************************************
    strcat: merge two strings (char arrays)
    also called string concatenation (sequence) 
    */

    char firstN[25] = "Jehn";
    char lastN[25] = " Snewh";
    strcat(firstN, lastN); // link lastN with firstN or string2 with string1.
    printf("My name is %s \n", firstN);

    /* IMPORTANT: make sure the first array is large enough to hold both
        strings.
        Watch what happens when you set firstN[25] to firstN[7] */

   /*******************************************************************
    puts() & gets() [Not Recommended, use fgets() instead]
    - easy way to print and get strings from the user.
    - use gets() when you get strings that contain spaces.
    - scanf cannot grab strings with spaces.
   */
  
    char city [30];
    char country [30];
    char fullLocation[60];

    puts("What city are you from?"); 
    gets(city);
    puts("What country are you from?");
    gets(country);

    // concatenate the two strings
    strcat(fullLocation, city);
    strcat(fullLocation, ", "); // Add a comma/space between city/country.
    strcat(fullLocation, country);

    puts("\nYou live in: ");
    puts(fullLocation);
}