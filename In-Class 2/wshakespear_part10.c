// In-Class 2 -  part 10 written by Weston Shakespear on 9/22/2023
// 	Write a C program to calculate the nth Fibonacci number using a recursive
// function. Prompt the user for the value of n and display the result.

#include <stdio.h>

int fibonacci(int number);

void main()
{
    // Infinite loop, prompt the user for a number
    while(1==1)
    {
        printf(
            "To find the fibonacci number enter a positive integer (0 to exit): "
            );
        
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
        printf("Fibonacci number %4d is %4d\n", number, fibonacci(number));
    }
}

int fibonacci(int number)
{
    // Base case of either the first or second fibonacci number
    if (number <= 2)
    {
        return 1;
    }
    // Otherwise return the sum of the two most previous fibonacci numbers
    return fibonacci(number - 1) + fibonacci(number - 2);
}
