// In-Class 2 -  part 6_dynamic written by Weston Shakespear on 9/22/2023
// Explain the difference between static and dynamic memory allocation in C,
// and provide an example illustrating when to use each.

#include <stdio.h>
#include <stdlib.h>

void main()
{
    // Prompt for a number of items
    int items = 0;
    printf("Please enter the total daily transactions: ");
    scanf("%d", &items);
    
    // Allocated the needed memory
    float * transactions = malloc(items * sizeof(float));

    // Input and assign the values
    for (
            int transaction_counter = 0;
            transaction_counter < items;
            transaction_counter++
        )
    {
        float value = 0.0;
        printf("Please enter transacton %4d: ", transaction_counter);
        scanf("%f", &value);

        // Assign the value to the memory address "transactions"
        // plus the "transaction_counter"
        *(transactions + transaction_counter) = value;
    }

    // Prompt for a starting balance
    float balance = 0.0;
    printf("Please enter the daily starting balance: ");
    scanf("%f", &balance);

    // Output the results
    printf("\n");
    printf("|  # |  BALANCE     |  WITHDRAW    |  DEPOSIT     |\n");

    for (
            int transaction_counter = 0;
            transaction_counter < items;
            transaction_counter++
        )
    {
        float transaction = *(transactions + transaction_counter);
        balance += transaction;
        printf("| %2d |  %10.2f  |", transaction_counter, balance);
        
        if (transaction < 0.0)
        {
            printf("  %10.2f  |              |\n", transaction);
        }
        else
        {
            printf("              |  %10.2f  |\n", transaction);
        }
    }

    // Free the manually allocated memory
    free(transactions);
}
