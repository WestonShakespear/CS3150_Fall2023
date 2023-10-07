// wshakespear_Lab 3_10.c
// Written by ~Weston Shakespear~
// 10/6/2023

#include <stdio.h>

// Function prototypes
void double_array(int * array, int size);

void main()
{
    // Output assignment requirements
    printf("\nPassing Arrays to Functions: Create a C function that takes");
    printf(" an integer array and its size as input, doubles each element in");
    printf(" the array using pointers, and returns the modified array.\n\n");

    // Init and declare test variables
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int array_size = sizeof(array) / sizeof(array[0]);

    // Output the initial array
    printf("Doubling the values in the array: \n{ ");

    for (int i = 0; i < array_size; i++)
    {
        printf("%d, ", *(array + i));
    }
    printf("}\n\n");

    // Process the array
    double_array(array, array_size);

    // Outupt the modified array
    printf("The modified array: \n{ ");

    for (int i = 0; i < array_size; i++)
    {
        printf("%d, ", *(array + i));
    }
    printf("}\n\n");
}

void double_array(int * array, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(array + i) *= 2;
    }
}

