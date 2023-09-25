// In-Class 2 -  part 8 written by Weston Shakespear on 9/22/2023
// Write a function that checks if a given integer is a prime number or not.
// Return 1 if it's prime and 0 otherwise.

#include <stdio.h>
#include <stdbool.h>

bool prime(int number);

void main()
{
    // Infinite loop, prompt the user for a number
    while(1==1)
    {
        printf(
            "Enter an integer to test of the absolute value is prime (0 to exit): "
            );
        
        int number;
        scanf("%d", &number);

        // Exit the program if the number is 0 or
        // overwrite with the positive version if negative
        if (number == 0)
        {
            break;
        }
        if (number < 0)
        {
            number = number * -1;
        }

        // Test the number
        bool is_prime = prime(number);
        
        // Output results
        if (is_prime == true)
        {
            printf("The number %d is prime\n", number);
        }
        else
        {
            printf("The number %d is not prime\n", number);
        }
    }
}


bool prime(int number)
{
    // Check if any number between 2 and 1 less than the number
    // is a possible factor
    for (int i = 2; i < number; i++)
    {
        // Divide the number and check the decimal part
        float division = ((float)number / i);
        int i_part = division;
        float d_part = division - i_part;

        // If we have a whole number than it's a factor
        if (d_part == 0)
        {
            return false;
        }
    }
    return true;
}
