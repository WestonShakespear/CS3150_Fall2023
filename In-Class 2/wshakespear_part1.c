// In-Class 2 -  part 1 written by Weston Shakespear on 9/21/2023
// Write a C program that uses a static variable to count the number of times a
// function is called. Display the count each time the function is invoked.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void do_a_thing(int a, int b);

// Global Variables
static int times_called = 0;

void main()
{
   srand(time(NULL));
   int times = rand();

   // Run the function a random amount of times
   printf("Running the function %i times\n", times);

   for (int i = 0; i < times; i++)
   {
    do_a_thing(rand(), rand());
   }
   printf("The value of times_called is %i\n", times_called);
}

void do_a_thing(int a, int b)
{
    // Increment times_called
    times_called++;

    // Do the thing
    int c = a * b;
}