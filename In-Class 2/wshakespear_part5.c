// In-Class 2 -  part 5 written by Weston Shakespear on 9/21/2023
// Write a program that allows the user to perform various operations on an
// integer array such as finding the maximum, minimum, and average values,
// and reversing the array.

#include <stdio.h>
#include <string.h>

int maximum(int * array, int size);
int minimum(int * array, int size);
int average(int * array, int size);
void reverse(int * array, int size);

void main()
{
    // Test data and sizes of those arrays
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int a_size = sizeof(a) / sizeof(a[0]);

    int b[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int b_size = sizeof(b) / sizeof(b[0]);

    // Find the sum of each array
    printf("Testing the functions with the following data\n");
    
    printf("{ ");
    for (int i = 0; i < a_size; i++)
    {
        printf("%2d, ", a[i]);
    }
    printf("}\n");

    printf("The maximum is: %4d\n", maximum(a, a_size));
    printf("The minimum is: %4d\n", minimum(a, a_size));
    printf("The average is: %4d\n", average(a, a_size));
    printf("The reversed array is now:\n");

    reverse(a, a_size);
    
    printf("{ ");
    for (int i = 0; i < a_size; i++)
    {
        printf("%2d, ", a[i]);
    }
    printf("}\n\n\n");


    // Find the sum of each array
    printf("Testing the functions with the following data\n");
    
    printf("{ ");
    for (int i = 0; i < b_size; i++)
    {
        printf("%2d, ", b[i]);
    }
    printf("}\n");

    printf("The maximum is: %4d\n", maximum(b, b_size));
    printf("The minimum is: %4d\n", minimum(b, b_size));
    printf("The average is: %4d\n", average(b, b_size));
    printf("The reversed array is now:\n");

    reverse(b, b_size);
    
    printf("{ ");
    for (int i = 0; i < b_size; i++)
    {
        printf("%2d, ", b[i]);
    }
    printf("}\n\n\n");
    
}

int maximum(int * array, int size)
{
    // Assign the minimum int value so the conditional
    // is true for anything higher
    int value = -1 * __INT_MAX__;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > value)
        {
            value = array[i];
        }
    }

    return value;
}

int minimum(int * array, int size)
{
    // Assign the max value so anything lower will be true for the if statement
    int value = __INT_MAX__;
    for (int i = 0; i < size; i++)
    {
        if (array[i] < value)
        {
            value = array[i];
        }
    }

    return value;
}

int average(int * array, int size)
{
    int value = 0;
    for (int i = 0; i < size; i++)
    {
        value += array[i];
    }

    return value / size;
}

void reverse(int * array, int size)
{
    int reversed[size];

    // Copy the array into the reversed variable
    memcpy(reversed, array, sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        array[i] = reversed[(size-1) - i];
    }
}