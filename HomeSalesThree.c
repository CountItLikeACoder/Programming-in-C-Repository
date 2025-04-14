#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUM_SALESPERSONS 3

// Struct to represent each salesperson
typedef struct {
    char name[20];
    char initial;
    double sales;
} SalesPerson;

int main() {
    // Initialize the salespersons
    SalesPerson salesPeople[NUM_SALESPERSONS] = {
        {"Danielle", 'D', 0.0},
        {"Edward", 'E', 0.0},
        {"Francis", 'F', 0.0}
    };

    double saleAmount;
    char initial;
    int i, found;

    // Input loop
    while (1) {
        printf("\nEnter the initial of your salesperson (D, E, or F) or Z to stop: ");
        scanf(" %c", &initial);

        initial = toupper(initial); // Normalize input to uppercase

        if (initial == 'Z') {
            break;
        }

        // Find the matching salesperson
        found = 0;
        for (i = 0; i < NUM_SALESPERSONS; i++) {
            if (salesPeople[i].initial == initial) {
                printf("Enter %s's sale amount: ", salesPeople[i].name);
                scanf("%lf", &saleAmount);
                salesPeople[i].sales += saleAmount;
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("\nError, invalid salesperson selected, please try again\n");
        }
    }

    // Output individual totals
    printf("\n");
    double grandTotal = 0.0;
    for (i = 0; i < NUM_SALESPERSONS; i++) {
        printf("%s: $%.2f\n", salesPeople[i].name, salesPeople[i].sales);
        grandTotal += salesPeople[i].sales;
    }

    // Output grand total
    printf("\nGrand Total: $%.2f\n", grandTotal);

    // Find highest sales
    int highestIndex = 0;
    for (i = 1; i < NUM_SALESPERSONS; i++) {
        if (salesPeople[i].sales > salesPeople[highestIndex].sales) {
            highestIndex = i;
        }
    }

    // Check for tie
    int tie = 0;
    for (i = 0; i < NUM_SALESPERSONS; i++) {
        if (i != highestIndex && salesPeople[i].sales == salesPeople[highestIndex].sales) {
            tie = 1;
            break;
        }
    }

    if (tie) {
        printf("Highest Sale is a tie!\n");
    } else {
        printf("Highest Sale: %c\n", salesPeople[highestIndex].initial);
    }

    return 0;
}