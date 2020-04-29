#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int key;
int key_modulo;
int x = 0;

int main(int argc, string argv[])
{
    // CHECK 1: Make sure there is only one command line argument.
    if (argc != 2)
    {
        printf("Try Again\n"); return 1;
    }
    // Converts contents of argv[1] into a string 's'.
    string s = (argv[1]);
    
    // CHECK 2: Make sure command line argument is a letter.
    for (int i = 0; i < strlen(s); i++)
    {
        // If any word in the string != alphabetical (letter) then print "Try Again"
        if (isalpha(s[i]) == false)
        {
            printf("Try Again\n"); return 1;
        }
    }
    
    string plainText = get_string("plaintext: "); // Get userinput and store in 'plainText' string.
    printf("ciphertext: "); 


    // Encryption Algorithim
    for (int i = 0; i < strlen(plainText); i++)
    {
        // Encrypt uppercase plaintext if any letter inside 'plainText' is uppercase.
        if isupper(plainText[i]) 
        {
            key_modulo = (x % strlen(s));
            key = (tolower(argv[1][key_modulo]) - 97);
            printf("%c", (((plainText[i] + key) - 65) % 26) + 65);
            x+= 1;
        }
        
        else if islower(plainText[i])
        {
            key_modulo = (x % strlen(s));
            key = (tolower(argv[1][key_modulo]) - 97);
            printf("%c", (((plainText[i] + key) - 97) % 26) + 97);
            x+= 1;
        }
        
        else
        {
            printf("%c", plainText [i]);
        }
    }
    printf("\n");
}
