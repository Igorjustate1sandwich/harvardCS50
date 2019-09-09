// Write a guessing game where the user has to guess a secret number. 
// After every guess the program tells the user whether their number was too large or too small. 
// At the end the number of tries needed should be printed. It counts only as one try if they input the same number multiple times consecutively.
// Guess between 1-10

#include <stdio.h>
int userNum;
int compNum = 6;
int counter;
int success = 0;

int main()
{
    while (success == 0)
    {
    printf("Guess a number between 1 to 10: \n");
    scanf("%i",&userNum);
        if (userNum == compNum)
        {
            counter++;
            printf("Perfect! You successfuly guessed the number %i after %i tries! \n", compNum, counter);
            success = 1; counter = 0;
        }
        if (userNum < compNum)
        {
            counter++;
            printf("Your number is too low, try again! Tries: %i \n", counter);
        } 
        if (userNum > compNum)
        {
            counter++;
            printf("Your number is too high, try again! Tries: %i \n", counter);
        } 
    }
}