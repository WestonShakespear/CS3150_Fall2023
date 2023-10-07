// wshakespear_Lab 4_1.c
// ~/**Weston Shakespear**\~
// Completed: 10/06/2023

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Defines
#define TRIES 10
#define RANGE_MIN 1
#define RANGE_MAX 100

// Between random definition
#define brand() (rand()%((RANGE_MAX+1)-RANGE_MIN) + RANGE_MIN)

// Function prototypes
bool play_game();

void main()
{
    // Seed random numbers
    srand(time(0));

    // Play the game and reward accordingly
    if (play_game() == true)
    {
        printf("\n!!!YOU WON!!!\n\n");
    }
    else
    {
        printf("\nyou lost...sorry...\n\n");
    }
}

bool play_game()
{
    // Output the rules of the game
    printf("\n\nBefore obtaining the prize you must guess the correct password\n");
    printf("The password lies in the range of %d-%d\n", RANGE_MIN, RANGE_MAX);
    printf("You have %d guesses\n\n", TRIES);

    // Setup variables and generate a random number
    int try = 0;
    int correct = brand();
    int guess = RANGE_MIN - 1;


    // Loop through the amount of tries DEFINED
    for (int try = 0; try < TRIES; try++)
    {
        // Output the current guess information
        printf("(%2d of %2d) :>", try, TRIES);

        // Read the user input
        scanf("%d", &guess);

        // Evaluate accoringly
        if (guess == correct)
        {
            // The guess was correct, return true
            return true;
        }
        else if (guess > correct)
        {
            // The guess was too high
            printf("      Try guessing a little lower\n");
        }
        else
        {
            // The guess was too low
            printf("      Try guessing a little higher\n");
        }
    }

    // Ran out of tries, return false
    return false;
    
}

