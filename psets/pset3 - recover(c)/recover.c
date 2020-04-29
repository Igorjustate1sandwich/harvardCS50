#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    // Screen for correct usage
    if (argc != 2)
    {
        printf("Correct usage: enter only one argument \n");
        return 1;
    }
    
    // Open memory card
    FILE *card = fopen(argv[1], "r");
    
    // If card does not exist, prompt user.
    if (card == NULL)
    {
        fprintf(stderr, "Cannot open file (%s) for reading. \n", argv[1]); 
        return 2;
    }
    
    // Track image count
    int count = 0; 
    
    // File name
    char filename[10];
    
    // Allocate space for Buffer
    unsigned char buffer[512];
    
    // Outfile for image
    FILE *img = NULL;
    
    // Bool jpeg_found
    bool jpeg_found = false;
    
    // Read memory card 512 blocks at a time
    while (fread(buffer, 512, 1, card))
    {
        // Check if first four bytes matches that of a JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close current file (if opened) so we may start reading the next
            // Start of a new JPEG
            if (jpeg_found == true)
            {
                fclose(img);
            }
            
            else
            // We have already found a JPEG so we have the green light to write it.
            {
                jpeg_found = true;
            }
            
            // Create a blank new JPEG file
            sprintf(filename, "%03i.jpg", count);
            
            // Open blank file for writing
            img = fopen(filename, "w");
            count++;
        }
        
        if (jpeg_found == true)
        {
            // Write to the blank new JPEG file
            fwrite(&buffer, 512, 1, img);
        }
    }

    // Close all files
    fclose(card);
    fclose(img);
    
    // Success
    return 0;
}
