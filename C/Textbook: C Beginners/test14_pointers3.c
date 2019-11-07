/*
    Chapter 25: Arrays and Pointers (Part 2/2)
    movie ranking program
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    /*
    - Go through each movie and ask user for a rating between 1-10
    - User must be able to say whether they have not seen a movie
    - At the end, tally ratings from highest to lowest.
    */

   char * pMovies[5] = {"Game of Thrones S8", "Avengers Infinity War", "Creed 2", "Black Panther", "Spiderman: Homecoming"};
   char choice;
   int rating[5] = {0};
   int ctr = 0;
  
   for (int i = 0; i < 5; i++)
   {
       printf("\nMovie %d. Have you seen %s? (Y/N) \n", i+1, pMovies[i]);
       scanf(" %c", &choice);

       if ( (toupper(choice)) == 'Y')       // convert 'y' to 'Y'.
       {
           do
           {
               printf("Give %s a rating out of 10: ", pMovies[i]);
               scanf(" %d", &rating[i]);
           } while (rating[i] < 0 || rating[i] > 10);
       }
       else
        {
           rating[i] - 1;      
        }
   }

   /* sort from high to low */
   printf("Your total film ratings sorted: \n");
   for (int i = 0; i < 5; i++)
   {
       for (int j = i; j < 5; j++)
       {
           if (rating[j] > rating[i])
           {
               int temp;
               char * tempmovie[10];

               // Order ratings
               temp = rating[j];
               rating[j] = rating[i];
               rating[i] = temp;

               // Order movies
               *tempmovie = pMovies[j];
               pMovies[j] = pMovies[i];
               pMovies [i] = *tempmovie;
           }
       }
   }

    /* print the results */
   for (int i = 0; i < 5; i++)
   {
       printf("Rank %d. Movie: %s \n",i+1, pMovies[i]);
       printf("Rating: %d \n", rating[i]);
   }

char fruit[25] = "Banana";
printf("Fruit: %s \n", fruit);

char *pFruit = fruit;
printf("Fruit: %s \n", pFruit);
pFruit = "Apple";
printf("Fruit: %s \n", pFruit);

}

/* textbook notes: arrays are fixed pointers which is why you can't put
an array name on the left side of an equals sign */

/* EXPLANATION:
    1. Say I have: char name[25] = 'Billy';
    The array name[25] is fixed and is pointing at 'B'.
    If I want to rename the contents of name[25], I must use strcpy:
    strcpy(name, 'Jon Snow');

    2. WHEREAS if I had used a pointer, eg; char * pName[25] = 'Billy';
    I could simply type: pName = 'Jon Snow'.

    Do you see how we're able to put the array name left of the equals sign
    in example 2?
*/
