// wshakespear_Assignment 1.c
// Written by Weston Shakespear
// Completed 9/9/2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
int testForLeapYear(int y);
void printWeek(int startDay);
int printFirstWeek(int firstDay);
int printLastWeek(int startDay, int lastDay);
int printMonth(int startDay, int totalDays);
void printMonths(year);
int calculateFirstDay(int year);
int getYear();

// Array for the amount of days per month
int numberOfDaysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Array for month names
char monthNames[12][10] = {     
    "Janurary",
    "Feburary",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
    };

// Main loop
void main() 
{
    // Prompt for the year from the user
    int year = getYear();

    // Print the calendar for the year
    printMonths(year);

    // pause before exiting
    getchar();
}


// Display all the months for a year
void printMonths(int year)
{
    // Find the first day using calculateFirstDay()   
    int startDay = calculateFirstDay(year);
    printf("|*******  Calendar for %4d  ******|\n", year);

    // Output the entire calendar
    for (int month = 1; month <= 12; month++)
    {
        int days = numberOfDaysInMonths[month - 1];

        if (month == 2)
        {
            // Test for a leap year if it's feburary
            if (testForLeapYear(year) == 0)
            {
                days = 29;
            }
        }

        printf("|-------    %9s   ---------- |\n", monthNames[month - 1]);
        startDay = printMonth(startDay, days);
        printf("\n\n");
    }
}

// Display a single month based off the first day and amount of days
int printMonth(int startDay, int totalDays)
{
    // Print an entire month based off the start day and total days
    printf("| Su | Mo | Tu | We | Th | Fr | Sa |\n");
    // Print the first week
    int next = printFirstWeek(startDay);

    while (next + 7 <= totalDays)
    {
        // Print the week
        printWeek(next);
        next += 7;
    }
    // Print the last week
    next = printLastWeek(next, totalDays);

    return next + 1;
}


// Print the first, most likely partial week
int printFirstWeek(int firstDay)
{
    int start = (-1 * firstDay)+2;
    int i = start;
    printf("|");
    for (; i < start + 7; i++)
    {
        if (i >= 1)
        {
            printf(" %2d |", i);
            continue;
        }
        printf("    |");
    }
    printf("\n");
    return i;
}

// Print a full week out
void printWeek(int startDay)
{
    printf("|");
    for (int i = startDay; i < startDay + 7; i++)
    {
        printf(" %2d |", i);
    }
    printf("\n");
}

// Print the last, most likely partial week
int printLastWeek(int startDay, int lastDay)
{
    int lastDayOfWeek = 0;

    // Iterate over each day of the week
    printf("|");
    for (int i = startDay; i < startDay + 7; i++)
    {
        if (i == lastDay)
        {
            lastDayOfWeek = (i - startDay) + 1;
        }
        if (i <= lastDay)
        {
            printf(" %2d |", i);
            continue;
        }
        printf("    |");
    }
    printf("\n");

    return lastDayOfWeek;
}

// Get the year from the user
int getYear()
{
    // I guess I decided to prompt for a string instead of a number
    char yearStr[10];
    int year = -1;

    while (year < 1)
    {
        // Prompt for a valid year
        printf("Enter a year from the year 1 and forwards: ");
        scanf("%s", yearStr, NULL);

        // Conver the string to a number
        year = atoi(yearStr);
    }
    // Return the prompted year
    return year;
}

int testForLeapYear(int y)
{
    // Complex logic statement to find out if the year is a multiple of
    // 4, 10 or 100 and then return whether or not that is a leap year
    if (
        (y != 0) && 
            (                // Don't count the first year
                (
                    ((y) % 4 == 0) &&   // The previous year was a leap
                    ((y) % 100 != 0)    // But it wasn't the end of a century
                ) ||
                (
                    ((y) % 4 == 0) &&   // The previous year was a leap
                    ((y) % 400 == 0)    // and it is divisible by 400
                )
            )
    )
    {
        return 0;
    }
    return 1;
}

// Figure out the first day of the year based on year 1 and leap year rules
int calculateFirstDay(int year)
{
    int day = 1;

    // Step through the years to find the first day of the week for the year requested
    for (int y = 1; y <= year; y++)
    {
        int leap = 1;

        // Calculate the first day based off years prior

        if (testForLeapYear(y - 1) == 0)
        {
          day += 2;
        }

        else
        {
            day += 1;
        }

        if (day > 7)
        {
            day = (day-7);
        }
    }

    // This is the first day of the year
    return day;
}
