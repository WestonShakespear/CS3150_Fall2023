// wshakespear_Lab 2_Assignment 3.c
// Written by Weston Shakespear
// Completed 9/27/2023
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initializeArray(int arr[], int size);
void printArray(int arr[], int size);
int findMax(int arr[], int size);
int findMin(int arr[], int size);
void reverseArray(int arr[], int size);

int main()
{
    // Initialize random seed
    srand(time(0));

    // Assign size and allocate the correct amount of memory for the array
    int size = 10;
    int * array = malloc(size * sizeof(int));

    // Test all functions and output results
    printf("\nTest:  initializeArray\n");
    initializeArray(array, size);

    printf("\nTest:  printArray\n");
    printArray(array, size);

    printf("\nTest:  findMax\n");
    printf("Result: %d\n", findMax(array, size));

    printf("\nTest:  findMin\n");
    printf("Result: %d\n", findMin(array, size));

    printf("\nTest:  reverseArray\n");
    reverseArray(array, size);
    printf("Result:\n");
    printArray(array, size);

    // Free up allocated memory
    free(array);
}

void initializeArray(int arr[], int size)
{
    // Iterate through arry and assign a random number
    for (int i = 0; i < size; i++)
    {
        // Assign random number between 1 and 100
        *(arr + i) = (rand() % 100);
    }
}

void printArray(int arr[], int size)
{
    // Iterate through array and output the values
    printf("{ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", *(arr + i));
    }
    printf("}\n");
}

int findMax(int arr[], int size)
{
    // Init max as the minimum possible int value
    int max = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        // If this item is bigger than the current max, assign it
        if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }

    return max;
}

int findMin(int arr[], int size)
{
    // Init min as the maximum possible int value
    int min = INT_MAX;

    for (int i = 0; i < size; i++)
    {
        // If this item is smaller than the current min, assign it
        if (*(arr + i) < min)
        {
            min = *(arr + i);
        }
    }

    return min;
}

void reverseArray(int arr[], int size)
{
    // Define the beginning and end address of the array;
    int * begin = arr;
    int * end = arr + size - 1;

    // Iterate over the first half of the array
    for (int i = 0; i < size / 2; i++)
    {
        // Get the current referenced addresses
        int * a = begin + i;
        int * b = end - i;

        // Get the current referenced values
        int a_val = *(a);
        int b_val = *(b);

        // Swap these values to the referenced spots
        *(a) = b_val;
        *(b) = a_val;
    }
}
