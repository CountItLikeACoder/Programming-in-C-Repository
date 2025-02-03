#include <stdio.h> 
#include <ctype.h> 

int main() {
    // variables to store each salesperson's total sales
    double danielleSales = 0, edwardSales = 0, francisSales = 0;
    double saleAmount;
    char initial;

    // while loop that ends when 'z' or 'Z' is entered
    while (1) {
        printf("\nEnter the initial of your salesperson (D, E, or F) or Z to stop: ");
        scanf(" %c", &initial); 

        initial = toupper(initial); // convert to uppercase

        // switch statement to handle different cases based on initial entered
        switch (initial) {
            case 'D':
                printf("Enter Danielle's sale amount: ");
                scanf("%lf", &saleAmount);
                danielleSales += saleAmount;
                break;
            case 'E':
                printf("Enter Edward's sale amount: ");
                scanf("%lf", &saleAmount);
                edwardSales += saleAmount;
                break;
            case 'F':
                printf("Enter Francis's sale amount: ");
                scanf("%lf", &saleAmount);
                francisSales += saleAmount;
                break;
            case 'Z':
                // Display each salesperson's total
                printf("\n");
                printf("Danielle: $%.2f\n", danielleSales);
                printf("Edward: $%.2f\n", edwardSales);
                printf("Francis: $%.2f\n", francisSales);

                // Display a grand total for all sales
                double grandTotal = danielleSales + edwardSales + francisSales;
                printf("\nGrand Total: $%.2f\n", grandTotal);
                printf("\n");

                // Display the name of the salesperson with the highest total
                if (danielleSales > edwardSales && danielleSales > francisSales) {
                    printf("Highest Sale: D\n");
                } else if (edwardSales > danielleSales && edwardSales > francisSales) {
                    printf("Highest Sale: E\n");
                } else if (francisSales > danielleSales && francisSales > edwardSales) {
                    printf("Highest Sale: F\n");
                } else {
                    printf("Highest Sale is a tie\n");
                }
                break;
            default:
                // Handle invalid initials
                printf("\nError, invalid salesperson selected, please try again\n");
                break;
        }

        // if 'z' or 'Z' is entered, break out of loop
        if (initial == 'Z') {
                break;
        }
    }

    return 0;
}
