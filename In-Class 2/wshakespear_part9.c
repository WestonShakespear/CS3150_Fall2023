// In-Class 2 -  part 9 written by Weston Shakespear on 9/21/2023
// Implement a function that reverses a string in-place.
// Pass the string as a character array to the function.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char * string);

void main()
{
    char name[] = "Weston Shakespear";

    printf("Reversing the string: '%s'\n", name);
    reverse(name);
    printf("The reversed string is: '%s'\n\n", name);

    char name2[] = "I Love Computer Science";

    printf("Reversing the string: '%s'\n", name2);
    reverse(name2);
    printf("The reversed string is: '%s'\n", name2);
}

void reverse(char * string)
{
    // Get the length of the string
    int length = strlen(string);

    // Allocate a copy + null terminator for a copy of the string
    char * string_copy = malloc(length + 1);
    strcpy(string_copy, string);

    // Loop and resassign
    for (int i = 0; i < length; i++)
    {
        *(string + i) =  *((string_copy + length - 1) - i);
    }
    free(string_copy);
}

