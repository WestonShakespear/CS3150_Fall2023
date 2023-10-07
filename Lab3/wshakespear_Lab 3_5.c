// wshakespear_Lab 3_5.c
// Written by ~Weston Shakespear~
// 10/6/2023

#include <stdio.h>

// Function prototypes
void pointer_factorial(int * number);

void main()
{
    // Output assignment requirements
    printf("\nFactorial Calculation: Implement a C function to calculate");
    printf(" the factorial of a given integer using pointers.\n\n");

    // Interactive loop
    while(0 == 0)
    {
        // Obtain a number from the user
        int number = 0;
        printf("Please enter a number (0 to exit): ");
        scanf("%d", &number);

        // Exit the program if the number is zero
        if (number == 0)
        {
            break;
        }
        // Always use the absolute value of the number
        if (number < 0)
        {
            number *= -1;
        }

        // Obtain the factorial of the number
        pointer_factorial(&number);

        // Output the factorial
        printf("The factorial is: %d\n", number);

    }

    printf("\n");

}

void pointer_factorial(int * number)
{
    // Store the number
    int buf = *number;

    // Init number as 1
    *number = 1;

    // Find the factorial
    for (int i = 1; i <= buf; i++)
    {
        *number *= i;
    }
}



