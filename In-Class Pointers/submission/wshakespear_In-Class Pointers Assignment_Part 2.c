// wshakespear_In-Class Pointers Assignment_Part 2.c
// Written by Weston Shakespear
// Completed 9/27/2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse_array(int * array, int length);

int main()
{
    // Initialize then prompt for the length of the array
    int length = 0;
    
    printf("Please enter a length for array: ");
    scanf("%d", &length);
    
    // Exit with an error code if invalid length is given
    if (length <= 0)
    {
        printf("Invalid length defined\n");
        return 1;
    }
    
    // Manually allocate the memory for the array
    int * array = malloc(length * sizeof(int));
    
    // Loop and prompt for each item
    for (int i = 0; i < length; i++)
    {
        int value = 0;
        printf("Enter array index %d: ", i);
        scanf("%d", &value);
        *(array + i) = value;
    }
    
    // Reverse the array
    reverse_array(array, length);
    
    // Output the reversed array
    for (int i = 0; i < length; i++)
    {
        printf("Reversed index %d: %d\n", i, *(array + i));
    }
    
    return 0;
}


void reverse_array(int * array, int length)
{
    // Init the beginning and end references to the array
    int * array_begin = array;
    int * array_end = array + length - 1;
    
    // Loop half the size of the array
    for (int i = 0; i < length / 2; i++)
    {
        // Define the current referenced items
        int * a = array + i;
        int * b = array_end - i;
        
        // Get the values from the current referenced items
        int a_val = *a;
        int b_val = *b;
        
        // Swap the values to the aformentioned referenced memory locations
        *a = b_val;
        *b = a_val;
    }
}
