// wshakespear_Lab 4_1.c
// ~/**Weston Shakespear**\~
// Completed: 10/06/2023

// Includes
#include <stdio.h>

// Defines
#define HOLD_TIME_T 0.65
#define RETURN_TIME_T 1.12
#define RETURN_TIME_T_B 1.6
#define TOTAL_TIME_T 10.0

#define OUTPUT_MULTIPLIER 10

// The maxJuggledBalls function recursively calculates the maximum number of balls a
// juggler can juggle within a given time limit. It takes into account the time to hold, throw,
// catch each ball, and the time for a ball to return to the other hand.
int max_juggled_balls(float hold_time, float return_time, float total_time, int * total_balls)
{
    // First run, output x axis legend
    if (*(total_balls) == 0)
    {
        for (int i = 0; i < OUTPUT_MULTIPLIER * TOTAL_TIME_T; i += 10)
        {
            for (int b = 0; b < OUTPUT_MULTIPLIER - 3; b++)
            {
                printf(" ");
            }
            printf("|%.0f|", ((float)i) / OUTPUT_MULTIPLIER);
        }
        printf("\n");
    }
    // Base case, if time left is less than the hold time
    // The base case of the recursion checks if the remaining time is less than the hold time. If it
    // is, it returns the current count of balls juggled.
    if ( total_time < hold_time )
    {
        return 0;
    }
    // There is still time left
    // Otherwise, it calculates the time required for one throw and catch (holdTime +
    // returnTime) and subtracts this time from the remaining time. If there is enough remaining
    // time for another throw and catch, it increases the count of juggled balls and continues the
    // recursion.
    else
    {
        // Calculate a throw and catch
        float throw_and_catch = hold_time + return_time;
        // Increment the amount of balls
        *(total_balls) = *(total_balls) + 1;

        // Output visual guide
        int hold_n = HOLD_TIME_T * OUTPUT_MULTIPLIER;
        int ret_n = RETURN_TIME_T * OUTPUT_MULTIPLIER;

        for (int s = 0; s < (hold_n + ret_n) * (*(total_balls) - 1); s++)
        {
            printf(" ");
        }


        for (int h = 0; h < hold_n; h++)
        {
            printf("-");
        }
        for (int r = 0; r < ret_n; r++)
        {
            printf("^");
        }
        printf("\n");
    

        // Recursively return the rest of the time
        return max_juggled_balls(hold_time, return_time, total_time - throw_and_catch, total_balls);
    }
}

void main()
{
    // Output prompt and legend
    printf(
        "\nHow many balls can the juggler juggle?\n"
        "- = hold\n"
        "^ = return\n\n");

    // Calculate for 10 seconds
    int total = 0;
    max_juggled_balls(HOLD_TIME_T, RETURN_TIME_T, TOTAL_TIME_T, &total);

    // Print results for 10 seconds
    printf(
        "With a hold time of %.2f and a return tme of %.2f the juggler"
        " can juggle %d balls for %.2f seconds\n\n",
        HOLD_TIME_T,
        RETURN_TIME_T,
        total,
        TOTAL_TIME_T);


    printf("In order to juggle 5 balls:\n\n");

    // Calculate for 5 balls
    total = 0;
    max_juggled_balls(HOLD_TIME_T, RETURN_TIME_T_B, TOTAL_TIME_T, &total);

    // Print results for 10 seconds
    printf(
        "With a hold time of %.2f and a return tme of %.2f the juggler"
        " can juggle %d balls for %.2f seconds\n\n",
        HOLD_TIME_T,
        RETURN_TIME_T_B,
        total,
        TOTAL_TIME_T);
    
}

