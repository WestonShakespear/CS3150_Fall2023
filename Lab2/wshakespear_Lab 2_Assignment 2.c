// wshakespear_Lab 2_Assignment 2.c
// Written by Weston Shakespear
// Completed 9/27/2023
#include <stdio.h>

void run_this_function_static();
void run_this_function_local();

int static_variable = 0;

int main()
{
    // Test the static variable function
    printf("\nRunning function that increments a global (static) variable:\n");
    for (int i = 0; i < 5; i++)
    {
        run_this_function_static();
    }

    printf("\n\nRunning function that increments a local variable:\n");
    // Test the local variable function
    for (int i = 0; i < 5; i++)
    {
        run_this_function_local();
    }

    return 0;
}

void run_this_function_static()
{
    // Output the amount of time this function has ran
    printf("Run: %d\n", ++static_variable);
}

void run_this_function_local()
{
    // Local variable
    int local_variable = 0;
    // Output the amount of time this function has ran
    printf("Run: %d\n", ++local_variable);
}
