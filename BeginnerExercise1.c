// Simple program that asks for your name and compares it with a list of authorized users.
#include <stdio.h>
#include <string.h>

int main()
{
    char user_name[25];
    char validname_1[25] = "Bob";
    char validname_2[25] = "Alice";
 
    printf("What is your name? \n");
    scanf("%s", user_name);
    
    // Compare user inputted name with the authorized name list on the system.
    int strcmp_bob; int strcmp_alice;
    strcmp_bob = strcmp (user_name, validname_1);
    strcmp_alice = strcmp(user_name, validname_2);
    
    if (strcmp_bob == 0 || strcmp_alice == 0)
        {
            printf("Hello %s! \n", user_name); 
        }
    else
        {
            printf("Unauthorized user detected. \n");
        }
}
