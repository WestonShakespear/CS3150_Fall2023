// In-Class 2 -  part 4 written by Weston Shakespear on 9/21/2023
// Implement a recursive function to calculate the factorial of a non-negative
// integer. The function should take an integer as input and 
// return its factorial.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int factorial(int number);

void main()
{
    // Infinite loop, prompt the user for a number and find the factorial
    while(1==1)
    {
        printf("To find the factorial enter a positive integer (0 to exit): ");
        
        int number;
        scanf("%d", &number);

        if (number == 0)
        {
            break;
        }
        if (number < 0)
        {
            continue;
        }
        printf("The factorial of %4d is %4d\n", number, factorial(number));
    }
}

int factorial(int number)
{
    // Base case
    if (number <= 1)
    {
        return 1;
    }

    // Other than that add the number and the factorial of one less
    return number + factorial(number - 1);
}