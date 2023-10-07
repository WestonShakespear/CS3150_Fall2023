// wshakespear_Lab 3_1.c
// Written by ~Weston Shakespear~
// 10/6/2023

#include <stdio.h>

// Swap the numbers function prototype
void swap_two_numbers(int * ref_a, int * ref_b);

void main()
{
    // Output the assignment information
    printf("\nSwap Two Numbers: Write a C function that takes two integer");
    printf(" pointers as arguments and swaps the values they point to.\n\n");

    // The numbers to swap
    int number_one = 5;
    int number_two = 4;

    // Output the numbers
    printf("Number 1: %d\n", number_one);
    printf("Number 2: %d\n", number_two);
    
    // Swap the numbers
    printf("SWAP\n");
    swap_two_numbers(&number_one, &number_two);

    // Output the results
    printf("Number 1: %d\n", number_one);
    printf("Number 2: %d\n", number_two);
}

// Swap the numbers function
void swap_two_numbers(int * ref_a, int * ref_b)
{
    // Store the value of ref_a in buf
    int buf = *ref_a;

    // Copy the value of ref_b into ref_a
    *ref_a = *ref_b;

    // Copy buf into the value of ref_b
    *ref_b = buf; 

}
