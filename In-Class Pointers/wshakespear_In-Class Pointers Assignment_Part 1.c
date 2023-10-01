// wshakespear_In-Class Pointers Assignment_Part 1.c
// Written by Weston Shakespear
// Completed 9/27/2023

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // This will store the amount of elements in the array
    int elements = 0;
    
    // Prompt for a the size of elements
    printf("Please enter the length of the array: ");
    scanf("%d", &elements);
    
    // If it's 0 or less exit the program with an error
    if (elements <= 0)
    {
        printf("Element is less than of equal to 0\n");
        return 1;
    }
    
    // Manually allocate the memory for the array
    int * array = malloc(elements * sizeof(int));
    
    for (int i = 0; i < elements; i++)
    {
        // Prompt for this value, then add it to the i index
        int value = 0;
        printf("Enter index %d: ", i);
        scanf("%d", &value);
        
        *(array + i) = value;
    }
    
    // Calculate the sum, then using that calculate the average
    int sum = 0;
    int average = 0;
    
    for (int i = 0; i < elements; i++)
    {
        sum += *(array + i);
    }
    
    average = sum;
    average /= elements;

    // Output the results
    printf("The sum is: %d\n", sum);
    printf("The average is: %d\n", average);
    
    // Free manually allocated memory
    free(array);
	
    // Return success on running
	return 0;
}
