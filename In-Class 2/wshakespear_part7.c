// In-Class 2 -  part 7 written by Weston Shakespear on 9/21/2023
// Create a function that takes a two-dimensional integer array representing
// a matrix and returns its transpose (rows become columns and vice versa).

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void output_matrix(int * array, int rows, int columns);
void transpose_matrix(int * array, int rows, int columns);

void main()
{
    // Test 1
    // Size of the original test matrix
    int rows = 3;
    int columns = 4;

    // Allocate memory
    int * array = malloc((rows * columns) * sizeof(int));

    // Iterate over the cells and assign a sequencial number
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            *(array + (r * columns + c)) = r * columns + c;
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


    // Test 2
    // Seed random generator
    srand(time(0));
    rows = 7;
    columns = 3;

    // Allocate memory
    int * array2 = malloc((rows * columns) * sizeof(int));

    // Assign each cell a random number
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            *(array2 + (r * columns + c)) = rand();
        }
    }

    // Display the original matrix
    printf("Transposing the following matrix: \n");
    output_matrix(array2, rows, columns);

    // Transpose the matrix
    transpose_matrix(array2, rows, columns);

    // Display the modified matrix
    printf("\nResult: \n");
    output_matrix(array2, columns, rows);
    
    // Free manually allocated memory
    free(array);
    free(array2);

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
