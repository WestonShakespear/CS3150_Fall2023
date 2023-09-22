// In-Class 2 -  part 3 written by Weston Shakespear on 9/21/2023
// Write a C function that calculates the sum of all elements in an
// integer array. Pass the array and its size as parameters to the function.

#include <stdio.h>

int sum_all_elements(int * array, int size);

void main()
{
    // Test data and sizes of those arrays
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a_size = sizeof(a) / sizeof(a[0]);

    int b[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int b_size = sizeof(b) / sizeof(b[0]);

    // Find the sum of each array
    printf("Testing the sum function for the folowing data\n");
    
    printf("{ ");
    for (int i = 0; i < a_size; i++)
    {
        printf("%2d, ", a[i]);
    }
    printf("}\n");

    printf("The sum is: %4d\n\n", sum_all_elements(a, a_size));

    printf("Testing the sum function for the folowing data\n");
    
    printf("{ ");
    for (int i = 0; i < b_size; i++)
    {
        printf("%2d, ", b[i]);
    }
    printf("}\n");

    printf("The sum is: %4d\n\n", sum_all_elements(b, b_size));
}

int sum_all_elements(int * array, int size)
{
    // Just calculate the sum with a for loop
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}