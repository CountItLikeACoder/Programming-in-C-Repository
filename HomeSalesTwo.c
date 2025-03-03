#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_SALESPERSONS 3

int main() {
    // Arrays to store each salesperson's names and initials
    char* salesPersonNames[NUM_SALESPERSONS] = {"Danielle", "Edward", "Francis"};
    char salesPersonInitials[NUM_SALESPERSONS] = {'D', 'E', 'F'};
    double sales[NUM_SALESPERSONS] = {0.0, 0.0, 0.0}; // Sales for each salesperson
    double saleAmount;
    char initial;
    int i, found;

    // While loop that ends when 'z' or 'Z' is entered
    while (1) {
        printf("\nEnter the initial of your salesperson (D, E, or F) or Z to stop: ");
        scanf(" %c", &initial); 

        initial = toupper(initial); // Convert to uppercase

        // Check if the user entered 'Z' to stop
        if (initial == 'Z') {
            break;
        }

        // Search for the salesperson matching the entered initial
        found = 0;
        for (i = 0; i < NUM_SALESPERSONS; i++) {
            if (salesPersonInitials[i] == initial) {
                printf("Enter %s's sale amount: ", salesPersonNames[i]);
                scanf("%lf", &saleAmount);
                sales[i] += saleAmount; // Add sales to amount for the appropriate salesperson
                found = 1;
                break;
            }
        }

        // If no valid salesperson is found
        if (!found) {
            printf("\nError, invalid salesperson selected, please try again\n");
        }
    }

    // Display each salesperson's total sales
    printf("\n");
    double grandTotal = 0;
    for (i = 0; i < NUM_SALESPERSONS; i++) {
        printf("%s: $%.2f\n", salesPersonNames[i], sales[i]);
        grandTotal += sales[i];
    }

    // Display the grand total for all sales
    printf("\nGrand Total: $%.2f\n", grandTotal);

    // Display the name of the salesperson with the highest total
    int highestIndex = 0;
    for (i = 1; i < NUM_SALESPERSONS; i++) {
        if (sales[i] > sales[highestIndex]) {
            highestIndex = i;
        }
    }

    // Check if there is a tie
    int tie = 0;
    for (i = 0; i < NUM_SALESPERSONS; i++) {
        if (i != highestIndex && sales[i] == sales[highestIndex]) {
            tie = 1;
            break;
        }
    }

    if (tie) {
        printf("Highest Sale is a tie!\n");
    } else {
        printf("Highest Sale: %c\n", salesPersonInitials[highestIndex]);
    }

    return 0;
}
