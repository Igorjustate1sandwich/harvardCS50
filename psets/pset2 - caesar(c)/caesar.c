#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    int convert; // Converted Int Value from String Input
    
    if (argc != 2)
    {
        printf("ERROR. Use ./caesar inputyournumber \n");
        return 1;
    }
    
    convert = atoi(argv[1]);
    int key = convert;
    
    if (convert <= 0)
    {
        printf("ERROR. Use ./caesar inputyournumber \n");
        return 1;
    }
    
    string plaintext = get_string("Enter Plaintext: ");
    printf("Ciphertext: ");
    
    for (int i = 0, n = strlen(plaintext); i < n; i++)
        if (plaintext[i] >= 97 && plaintext[i] <= 122) // Check if between 'a' and 'z' (Check ASCII-2 table)
        {
            printf("%c", (((plaintext[i] - 97) + key ) % 26) + 97); // Plaintext char - 97 + key then result%26 +97
        }
    else if (plaintext[i] >= 65 && plaintext[i] <= 90) // Check if between 'A' and 'Z'
    {
        printf("%c", (((plaintext[i] - 65) + key ) % 26) + 65); 
    }
    printf("\n");
}

// EXPLANATION - Using "h" as an example and key = 1
// h in ASCII = 104
// Formula = ((104 - 97) + key)) % 26 which = 8.    
            // AKA 7 + 1 = 8 then do 8 MODULO 26. Use 26 because thats how many chars in alphabet.
// Then do 8 + 97 which = 105. 105 in ASCII = 'i'
// Therefore When entering 'h' as plaintext you will get 'i' as ciphertext.

