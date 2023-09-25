// In-Class 2 -  part 6_static written by Weston Shakespear on 9/22/2023
// Explain the difference between static and dynamic memory allocation in C,
// and provide an example illustrating when to use each.

#include <stdio.h>

// Function for static memory demonstration
void log_message(char * message);

// Variable for static memory demonstration
int message_number = 1;

void main()
{
    // Static memory demonstration
    for (int i = 0; i < 10; i++)
    {
        log_message("Here is a sample log message");
    }
}

void log_message(char * message)
{
    printf("[%2d] - '%s'\n", message_number++, message);
}
