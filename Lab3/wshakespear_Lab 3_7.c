// wshakespear_Lab 3_7.c
// Written by ~Weston Shakespear~
// 10/6/2023

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void output_matrix(int * array, int rows, int columns);
void transpose_matrix(int * array, int rows, int columns);

void main()
{
    // Output assignment requirements
    printf("\nMatrix Transposition: Write a C function that transposes");
    printf(" a square matrix (2D array) in-place using pointers.\n\n");
    srand(time(0));
    int rows = 7;
    int columns = 3;

    // Allocate memory
    int * array = malloc((rows * columns) * sizeof(int));

    // Assign each cell a random number
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            *(array + (r * columns + c)) = rand();
        }
    }

    // Display the original matrix
    printf("Transposing the following matrix: \n");
    output_matrix(array, rows, columns);

    // Transpose the matrix
    transpose_matrix(array, rows, columns);

    // Display the modified matrix
    printf("\nResult: \n");
    output_matrix(array, columns, rows);
    
    // Free manually allocated memory
    free(array);
    printf("\n");
}

// Function for outputting a 2d array or matrix to the screen
void output_matrix(int * array, int rows, int columns)
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            printf("%8d ", *(array + (r * columns + c)));
        }
        printf("\n");
    }

}

void transpose_matrix(int * array, int rows, int columns)
{
    // Create a copy of the array in memory
    int * copy = malloc((rows * columns) * sizeof(int));
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            *(copy + (r * columns + c)) = *(array + (r * columns + c));
        }
    }

    // Transpose the rows and columns from the copied array into the original
    for (int c = 0; c < columns; c++)
    {
        for (int r = 0; r < rows; r++)
        {
            *(array + (c * rows + r)) =  *(copy + (r * columns + c));
        }
    }
    // Free the copied array from memory
    free(copy);
}

