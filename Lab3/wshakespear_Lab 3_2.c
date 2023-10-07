// wshakespear_Lab 3_2.c
// Written by ~Weston Shakespear~
// 10/6/2023

#include <stdio.h>

// Function prototypes
void reverse_in_place(char * string);

void main()
{
    // Output assignment requirements
    printf("\nReverse a String: Create a C function that takes a character");
    printf(" pointer (string) as input and reverses the string in-place");
    printf(" using pointers.\n\n");

    // Define test params and output them
    char input_string[] = "Weston";
    printf("Reversing the string: '%s'\n", input_string);

    // Reverse the string
    reverse_in_place(input_string);

    // Output the reversed string
    printf("The reversed string: '%s'\n\n", input_string);
}

// Reverse a string function
void reverse_in_place(char * string)
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

    // Since we started at the second char in the loop subtract 2 for the length
    int string_length = char_index - 2;
    
    // Swap the characters of the string in place looping half of the string
    for (int swap_counter = 0; swap_counter < string_length / 2; swap_counter++)
    {
        // Store the lower indice char
        char head_buf = *(string + swap_counter);

        // Assign the value up the upper indice character to the lower one
        *(string + swap_counter) = *(string + string_length - swap_counter);

        // Assign the stored char to the higher indice char
        *(string + string_length - swap_counter) = head_buf;
    }
}
