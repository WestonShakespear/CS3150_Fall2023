// wshakespear_Lab 3_3.c
// Written by ~Weston Shakespear~
// 10/6/2023

#include <stdio.h>

// Function prototypes
int string_length(char * string);

void main()
{
    // Output assignment requirements
    printf("\nCalculate the Length of a String: Write a C function that ");
    printf("calculates the length of a string (character array) using ");
    printf("pointers, without using any standard library functions.\n\n");

    // Define test params and output them
    char input_string[] = "Weston";
    printf("Calculating the length of the string: '%s'\n", input_string);

    // Calculate the string length
    int length = string_length(input_string);

    // Output the reversed string
    printf("The length is: %d\n\n", length);
}

// String length function
int string_length(char * string)
{
    // Get the first char of the string
    char current_char = *string;
    // Current char index
    int char_index = 1;

    // Loop to find the length of the string
    while (current_char != '\0')
    {
        // Update current char and post increment char_index
        current_char = *(string + char_index++);
    }

    // Since we started at the second char in the loop subtract 1 for the length
    return char_index - 1;
}
