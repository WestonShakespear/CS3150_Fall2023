// Lab 1 part 1 written by Weston Shakespear on 8/9/2023

#include <stdio.h>

int factorial(int number);
int gcd(int a, int b);

void main()
{
    printf("Part One:\n");

    //----------------------------------SECTION 1-----------------------------//

    printf("Write a C program that calculates the factorial of a given ");
    printf("integer using a function.\n");

    // Test 1
    int number = 3;
    int fact = factorial(number);
    printf("The factorial for %d is %d\n\n", number, fact); 

    // Test 2
    number = 7;
    fact = factorial(number);
    printf("The factorial for %d is %d\n\n", number, fact); 

    // Test 3
    number = 10;
    fact = factorial(number);
    printf("The factorial for %d is %d\n\n", number, fact); 

    // Test 4
    number = 13;
    fact = factorial(number);
    printf("The factorial for %d is %d\n\n", number, fact); 


    //----------------------------------SECTION 2-----------------------------//

    printf("Write a C program that finds the greatest common divisor (GCD) ");
    printf("of two integers using a function.\n");

    // Test 1
    int a = 279;
    int b = 155;
    int gcdNumber = gcd(a, b);
    printf("The GCD for %d and %d is %d\n\n", a, b, gcdNumber);

    // Test 2
    a = 310;
    b = 279;
    gcdNumber = gcd(a, b);
    printf("The GCD for %d and %d is %d\n\n", a, b, gcdNumber);

    // Test 3
    a = 315;
    b = 280;
    gcdNumber = gcd(a, b);
    printf("The GCD for %d and %d is %d\n\n", a, b, gcdNumber);

    // Test 4
    a = 108;
    b = 54;
    gcdNumber = gcd(a, b);
    printf("The GCD for %d and %d is %d\n\n", a, b, gcdNumber);
}

// Write a C program that calculates the factorial of a given integer using a 
// function. The program should include:
//     - A function to calculate the factorial.
//     - A function prototype.
//     - A main function that takes user input and displays the result.
int factorial(int number)
{
    int fact = 1;

    for (int i = 2; i <= number; i++)
    {
        fact *= i;
    }

    return fact;
}

// Write a C program that finds the greatest common divisor (GCD) of two 
// integers using a function. The program should include:
//     - A function to calculate the GCD.
//     - A function prototype.
//     - A main function that takes user input and displays the GCD.
int gcd(int a, int b)
{
    int greatest = 1;
    int larger = a;
    int smaller = b;

    if (b > a)
    {
        larger = b;
        smaller = a;
    }

    for (int i = 2; i < larger; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            greatest = i;
        }
    }

    return greatest;
}
