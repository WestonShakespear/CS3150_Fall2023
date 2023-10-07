// wshakespear_Lab 3_9.c
// Written by ~Weston Shakespear~
// 10/6/2023

#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Output assignment requirements
    printf("\nDynamic Memory Allocation: Write a C program that dynamically");
    printf(" allocates memory for an integer array of a user-defined size");
    printf(" and then frees the memory when done.\n\n");

    // Declare variables
    int size;
    int * data;

    // Obtain array size
    printf("Please enter the length of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    data = malloc(sizeof(int) * size);

    // Obtain values for the array
    printf("Please enter a value for index-\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d: ", i);
        scanf("%d", &(*(data + i)));
    }

    // Output the array
    printf("Finding the minimum and maximum of the array: \n");
    printf("{ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", *(data + i));
    }
    printf("}\n\n");

    // Free the manually allocated memory
    free(data);
}

