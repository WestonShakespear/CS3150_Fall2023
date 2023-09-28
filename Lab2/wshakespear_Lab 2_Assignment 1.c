// wshakespear_Lab 2_Assignment 1.c
// Written by Weston Shakespear
// Completed 9/27/2023
#include <stdio.h>

int sum(int arr[], int size);
double average(int arr[], int size);

int main()
{
    // Test data
    int test_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int test_array_size = sizeof(test_array) / sizeof(test_array[0]);

    int test_array2[] = {103, 103, 101};
    int test_array2_size = sizeof(test_array2) / sizeof(test_array2[0]);


    // Test One
    // Output data
    printf("\nTesting functions with array:\n");
    printf("{ ");
    for (int i = 0; i < test_array_size; i++)
    {
        printf("%d, ", test_array[i]);
    }
    printf("}\n");

    // Run sum function
    int array_sum = sum(test_array, test_array_size);
    printf("The sum is: %d\n", array_sum);

    // Run average function
    double array_average = average(test_array, test_array_size);
    printf("The average is: %f\n\n\n", array_average);

    // Test Two
    // Output data
    printf("Testing functions with array:\n");
    printf("{ ");
    for (int i = 0; i < test_array2_size; i++)
    {
        printf("%d, ", test_array2[i]);
    }
    printf("}\n");

    // Run sum function
    array_sum = sum(test_array2, test_array2_size);
    printf("The sum is: %d\n", array_sum);

    // Run average function
    array_average = average(test_array2, test_array2_size);
    printf("The average is: %f\n", array_average);

    return 0;
}

int sum(int arr[], int size)
{
    // Initialize the sum
    int sum = 0;
    // Iterate over array contents
    for (int i = 0; i < size; i++)
    {
        // Add each item in the array to the sum
        sum += arr[i];
    }
    // Return the sum
    return sum;
}

double average(int arr[], int size)
{
    // Obtain the sum of the array cast as a double
    double arr_sum = ((double) sum(arr, size));

    // Return the sum divided by the size, or the average
    return arr_sum / size;
}
