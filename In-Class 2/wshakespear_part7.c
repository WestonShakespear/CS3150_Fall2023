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
    int rows = 3;
    int columns = 4;

    int * array = malloc((rows * columns) * sizeof(int));


    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            *(array + (r * columns + c)) = r * columns + c;
        }
    }

    printf("Transposing the following matrix: \n");
    output_matrix(array, rows, columns);

    transpose_matrix(array, rows, columns);

    printf("\nResult: \n");
    output_matrix(array, columns, rows);




    srand(time(NULL));
    rows = 7;
    columns = 3;

    int * array2 = malloc((rows * columns) * sizeof(int));


    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            *(array2 + (r * columns + c)) = rand();
        }
    }

    printf("Transposing the following matrix: \n");
    output_matrix(array2, rows, columns);

    transpose_matrix(array2, rows, columns);

    printf("\nResult: \n");
    output_matrix(array2, columns, rows);
    
    
    free(array2);

}

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

    // Transpose the rows and columns from the copied array
    for (int c = 0; c < columns; c++)
    {
        for (int r = 0; r < rows; r++)
        {
            *(array + (c * rows + r)) =  *(copy + (r * columns + c));
        }
    }
    free(copy);
}



