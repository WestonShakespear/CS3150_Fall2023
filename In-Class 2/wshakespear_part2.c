// In-Class 2 -  part 2 written by Weston Shakespear on 9/21/2023
// Create a program that dynamically allocates memory for an integer
// array of user-defined size. Prompt the user for the array size and
// then input the elements. Finally, print the array in reverse order.

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void main()
{
    // This will be the total size of the array
    int array_size;

    // Prompt the user for a valid size in an infinite loop
    while (1 == 1)
    {
        // Get the array size from the user
        printf("How large should the array be? ");
        scanf("%d", &array_size);

        // Exit the program if the size is zero
        if (array_size > 0)
        {
            break;
        }
        // Re-prompt if the array size is unusable
        else
        {
            printf("Try entering a number larger than 0\n\n");
        }
    }

    // Allocate the memory for the "array"
    int * array_reference = malloc(array_size * sizeof(int));

    // Prompt the user for the values of each array index
    for (int index = 0; index < array_size; index++)
    {
        int value;

        printf("array[%4d]: ", index);
        scanf("%d", &value);
        // Assign the value to the memory address of
        // array_reference plus the index
        *(array_reference + index) = value;
    }

    // Print out the data to verify
    printf("Here is the data in the array:\n");
    for (int index = 0; index < array_size; index++)
    {
        printf("    Index %4d", index);
        printf("        Value: %4d\n", *(array_reference + index));
    }
    // Free the memory that was manually allocated
    free(array_reference);
}
