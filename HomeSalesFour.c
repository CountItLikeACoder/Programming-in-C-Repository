#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define NUM_SALESPERSONS 3
#define FILENAME "sales_data.txt"

typedef struct {
    char name[20];
    char initial;
    double sales;
} SalesPerson;

int main() {
    SalesPerson salesPeople[NUM_SALESPERSONS];
    FILE *file;
    int i, found;
    char initial;
    double saleAmount;

    // Load salespeople data from file
    file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", FILENAME);
        return 1;
    }

    for (i = 0; i < NUM_SALESPERSONS; i++) {
        if (fscanf(file, "%s %c %lf", salesPeople[i].name, &salesPeople[i].initial, &salesPeople[i].sales) != 3) {
            printf("Error: Invalid data format in file\n");
            fclose(file);
            return 1;
        }
    }
    fclose(file);

    // Input loop
    while (1) {
        printf("\nEnter the initial of your salesperson (D, E, or F) or Z to stop: ");
        scanf(" %c", &initial);
        initial = toupper(initial);

        if (initial == 'Z') break;

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
            printf("Error, invalid salesperson selected, please try again\n");
        }
    }

    // Output results
    printf("\nSales Totals:\n");
    double grandTotal = 0.0;
    for (i = 0; i < NUM_SALESPERSONS; i++) {
        printf("%s: $%.2f\n", salesPeople[i].name, salesPeople[i].sales);
        grandTotal += salesPeople[i].sales;
    }
    printf("\nGrand Total: $%.2f\n", grandTotal);

    // Determine highest sales
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