// wshakespear_Lab 3_6.c
// Written by ~Weston Shakespear~
// 10/6/2023

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
bool palindrome(char word[]);

void main()
{
    // Output assignment requirements
    printf("\nCheck for Palindrome: Create a C function that checks");
    printf(" whether a given string (character array) is a palindrome");
    printf(" using pointers.\n\n");

    // Obtain a number from the user
    char word[100];

    printf("Please enter a word less than 100 characters: ");
    scanf("%s", &word);

      
    // Obtain the factorial of the number
    bool check = palindrome(word);

    // Output whether or not the word is a palindrome
    if (check == true)
    {
        printf("'%s' is a palindrome!\n\n", word);
    }
    else
    {
        printf("'%s' is not a palindrome\n\n", word);
    }

}

// Check palindrome function
bool palindrome(char word[])
{
    // Get the length of the word
    int string_len = strlen(word);

    // Loop through at most half of the length of the word
    for (int i = 0; i < string_len / 2; i++)
    {
        // Store the earlier char from the word
        char upper = *(word + i);
        // Store the later char from the word
        char lower = *(word + string_len - 1 - i);

        // Compare these chars
        if (upper != lower)
        {
            // Return false if they don't match
            return false;
        }
    }
    // If we got through the whole word and didn't return false
    // the word is a palindrome
    return true;
}


