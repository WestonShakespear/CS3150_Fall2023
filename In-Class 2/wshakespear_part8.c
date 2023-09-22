// In-Class 2 -  part 8 written by Weston Shakespear on 9/21/2023
// Write a function that checks if a given integer is a prime number or not.
// Return 1 if it's prime and 0 otherwise.

#include <stdio.h>
#include <stdbool.h>

bool prime(int number);

bool main()
{
    int number = 5;
    bool is_prime = prime(number);
    
    if (is_prime == true)
    {
        printf("The number %d is prime\n", number);
    }
    else
    {
        printf("The number %d is not prime\n", number);
    }
}


bool prime(int number)
{
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            return true;
        }
    }
    return false;
}

