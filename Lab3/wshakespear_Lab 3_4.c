// wshakespear_Lab 3_4.c
// Written by ~Weston Shakespear~
// 10/6/2023

#include <stdio.h>

// Function prototypes
void find_min_max(int * array, int size, int * out_min, int * out_max);
void output_array(int * array, int size);

void main()
{
    // Output assignment requirements
    printf("\nFind Maximum and Minimum in an Array: Define a C function ");
    printf("that takes an integer array and its size as input and uses ");
    printf("pointers to find the maximum and minimum values in the array.\n\n");

    // Setup and output params
    int array_input[] = {-7, -6, -5, -4, -3, -2, -1, 1, 2, 3, 4, 5, 6, 7};
    int array_size = sizeof(array_input) / sizeof(array_input[0]);
    int min = 0;
    int max = 0;

    // Output the array
    printf("Finding the minimum and maximum of the array: \n");
    printf("{ ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d, ", *(array_input + i));
    }
    printf("}\n");

    // Run the find_min_max function
    // Inputs:  array_input array_size
    // Outputs: min max
    find_min_max(array_input, array_size, &min, &max);

    // Output the minimum and maximum
    printf("\nThe minimum is: %d\n", min);
    printf("The maximum is: %d\n\n", max);

    
}

void find_min_max(int * array, int size, int * out_min, int * out_max)
{
    // Initialize the value of out_min as the highest possible integer
    *out_min = __INT_MAX__;
    // Initilize the value of out_max as the lowest possible integer
    *out_max = __INT_MAX__ * -1;

    // Loop through every value of the array
    for (int i = 0; i < size; i++)
    {
        // Obtain the value of this entry in the array
        int val = *(array + i);

        // Test if this value is less than the current minimum
        if (val < *out_min)
        {
            // If it is assign the current value as the minimum value
            *out_min = val;
        }
        // Test if this value is greater than the current maximum
        if (val > *out_max)
        {
            // If it is assign the current value as the maximum value
            *out_max = val;
        }
    }
}

