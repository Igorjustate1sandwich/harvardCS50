#include <stdio.h>
#include <stdlib.h>

int main()
{
    // ROWS x COL matrix
    int ROWS = 2;
    int COL =  4;

	// dynamically create array of pointers of size ROWS
	int **array = (int **)malloc(ROWS * sizeof(int *));

	// dynamically allocate memory of size COL for each row
	for (int i = 0; i < ROWS; i++)
	{
		array[i] = (int *)malloc(COL * sizeof(int));
	}

    array[0][0] = 10;       // first row, first column (C counts from 0)
	array[0][1] = 20;       // first row, second column
    array[0][2] = 30;       // first row, third column
    array[0][3] = 40;       // first row, fourth column

    array[1][0] = 100;      // second row, first column
    array[1][1] = 200;      // second row, second column
    array[1][2] = 300;      // second row, third column
    array[1][3] = 400;      // second row, fourth column


	// print the 2D array
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COL; j++)
			printf("%d ", array[i][j]);	
		    printf("\n");
	}
}