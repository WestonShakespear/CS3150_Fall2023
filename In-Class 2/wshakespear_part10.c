// In-Class 2 -  part 10 written by Weston Shakespear on 9/21/2023
// 	Write a C program to calculate the nth Fibonacci number using a recursive
// function. Prompt the user for the value of n and display the result.

#include <stdio.h>


void main()
{
   // Infinite loop, prompt the user for a number and find the fibonacci number
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

