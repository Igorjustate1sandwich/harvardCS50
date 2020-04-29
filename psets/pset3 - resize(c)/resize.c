#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
// STAGE 1: CONDITIONAL CHECKING 
    if (argc != 4)
    {
        printf("Error. Try typing: ./resize n infile outfile \n");
        return 1;
    }
    
    // remember filenames // assign infile/outfile
    int factor = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

// STAGE 2: FILE I/O
    // Open input file (infile)
    FILE *inptr = fopen(infile, "r"); // "r" = read
    if (inptr == NULL) // Null = empty file
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // Create (write) an empty output file for writing
    FILE *outptr = fopen(outfile, "w"); 
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // Read infile BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    
    // Read infile BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    
    // Check if infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
    bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

// OUTFILE HEADERS
BITMAPFILEHEADER obf;
BITMAPINFOHEADER obi;

// copies of input headers
obf = bf;
obi = bi;

// factor
obi.biWidth *= factor;
obi.biHeight *= factor;
    
int inPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
int outPadding = (4 - (obi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
obi.biSizeImage = 
((sizeof(RGBTRIPLE) * obi.biWidth) + outPadding) * 
abs(obi.biHeight);
    
obf.bfSize = obi.biSizeImage + 
sizeof(BITMAPFILEHEADER) +
sizeof(BITMAPINFOHEADER);
    
// Write headers to outfile
fwrite(&obf, sizeof(BITMAPFILEHEADER),1, outptr);
fwrite(&obi, sizeof(BITMAPINFOHEADER),1, outptr);

// Store a scanlines worth of pixels
RGBTRIPLE * scanline = malloc((sizeof(RGBTRIPLE)) * obi.biWidth);
    
// Loop Over Scanline
for (int i = 0; i < abs(bi.biHeight); i++)
{
    int pixel_tracker = 0;
    // iterate over each pixel in scanline
    // for every pixel in row
    for (int j = 0; j < bi.biWidth; j++)
    {
        RGBTRIPLE pixel;
        // read RGB triple from infile
        fread(&pixel, sizeof(RGBTRIPLE), 1, inptr);
            
        for (int k = 0; k < factor; k++)
        {
            *(scanline + pixel_tracker) = pixel;
            pixel_tracker++;
        }
    }

    // skip over padding, if any
    fseek(inptr, inPadding, SEEK_CUR);
        
    // Loop through adding rows based on n factor
    for (int l = 0; l < factor; l++)
    {
        fwrite(scanline, sizeof(RGBTRIPLE), obi.biWidth, outptr);
            
    // add padding to each row manually
        for (int m = 0; m < outPadding; m++)
        { 
            fputc(0x00, outptr); 
        }
    }
}
    free(scanline);
    // close infile
    fclose(inptr);
    // close outfile
    fclose(outptr);
    // success
    return 0;
}
