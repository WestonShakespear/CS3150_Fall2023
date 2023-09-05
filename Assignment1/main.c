#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printWeek(int startDay);
int printFirstWeek(int firstDay);
int printLastWeek(int startDay, int lastDay);
int printMonth(int startDay, int totalDays);
void printMonths(int startDay);
int calculateFirstDay(int year);
int getYear();


int numberOfDaysInMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char monthNames[12][9] = {     
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


void main() 
{
    printMonths
    (
        calculateFirstDay
        (
            getYear()
        )
    );

    getchar();
}


// Display all the months for a year
void printMonths(int startDay)
{

    for (int month = 1; month <= 12; month++)
    {
        int days = numberOfDaysInMonths[month - 1];

        printf("|-------    %9s   ---------- |\n", monthNames[month - 1]);
        startDay = printMonth(startDay, days);
        printf("\n\n");
    }
}

// Display a single month based off the first day and amount of days
int printMonth(int startDay, int totalDays)
{
    printf("| Su | Mo | Tu | We | Th | Fr | Sa |\n");
    int next = printFirstWeek(startDay);

    while (next + 7 <= totalDays)
    {
        printWeek(next);
        next += 7;
    }
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
    char yearStr[10];
    int year = -1;

    while (year < 1)
    {
        printf("Enter a year from the year 1 and forwards: ");
        scanf("%s", yearStr, NULL);

        year = atoi(yearStr);
    }

    return year;
}

// Figure out the first day of the year based on year 1 and leap year rules
int calculateFirstDay(int year)
{
    int day = 1;

    // Step through the years to find the first day of the week for the year requested
    for (int y = 1; y <= year; y++)
    {
        int leap = 1;

        if 
            ( 
                (y != 1) && 
                (                // Don't count the first year
                    (
                        ((y - 1) % 4 == 0) &&   // The previous year was a leap
                        ((y - 1) % 100 != 0)    // But it wasn't the end of a century
                    ) ||
                    (
                        ((y - 1) % 4 == 0) &&   // The previous year was a leap
                        ((y - 1) % 400 == 0)    // and it is divisible by 400
                    )
                )
            )
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

    return day;
}



