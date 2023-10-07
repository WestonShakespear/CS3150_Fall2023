// Lab 1 part 3 written by Weston Shakespear on 8/9/2023

#include <stdio.h>

int fibonacciRecursive(int number);
int factorialRecursive(int number);

void main()
{
    printf("Part Three:\n");

    //----------------------------------SECTION 1-----------------------------//

    printf("Implement a recursive C function to calculate the nth ");
    printf("Fibonacci number.\n");

    printf("Printing the first ten, calling the function each time:\n");

    for (int i = 1; i <= 10; i++)
    {
        printf("\t%2d\t->\t%d\n", i, fibonacciRecursive(i));
    }
    printf("\n\n");


    //----------------------------------SECTION 2-----------------------------//
    
    printf("Write a C program that uses recursion to compute the factorial");
    printf(" of a number.\n");

    // Test 1
    int n = 3;
    printf(
        "Testing recursive factorial function with %d. Got %d\n\n",
        n,
        factorialRecursive(n));

    // Test 2
    n = 7;
    printf(
        "Testing recursive factorial function with %d. Got %d\n\n",
        n,
        factorialRecursive(n));
    
    // Test 3
    n = 9;
    printf(
        "Testing recursive factorial function with %d. Got %d\n\n",
        n,
        factorialRecursive(n));

    // Test 4
    n = 12;
    printf(
        "Testing recursive factorial function with %d. Got %d\n\n",
        n,
        factorialRecursive(n));
}



// Implement a recursive C function to calculate the nth Fibonacci number.
// The program should include:
//    - A recursive function to calculate the Fibonacci number.
//    - A function prototype.
//    - A main function that takes user input for 'n' and displays the nth
//      Fibonacci number.
int fibonacciRecursive(int number)
{
    // Return 1 if we are looking for the first and second item of the
    // fibonacci sequence
    if (number <= 2)
    {
        return 1;
    }
    // Return the sum of the two fibonacci numbers before this one
    return fibonacciRecursive(number - 1) + fibonacciRecursive(number - 2);
}

// Write a C program that uses recursion to compute the factorial of a number.
// The program should include:
//    - A recursive function for factorial calculation.
//    - A function prototype.
//    - A main function that takes user input and displays the factorial.
int factorialRecursive(int number)
{
    // This is the base case, we want all the positive integers the same or less
     if (number == 1)
     {
        return 1;
     }

     return number * factorialRecursive(number - 1);
}
