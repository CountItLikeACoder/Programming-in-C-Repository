#include <stdio.h>

#define NUM_TEMPERATURES 5
#define MIN_TEMP -30
#define MAX_TEMP 130

int main() {
    int temperatures[NUM_TEMPERATURES];
    int i, isWarmer = 1, isCooler = 1;
    int sum = 0;

    // Input temperatures
    for (i = 0; i < NUM_TEMPERATURES; i++) {
        int temp;

        // Keep prompting the user until a valid temperature is entered
        while (1) {
            printf("Enter temperature %d between -30 and 130 Fahrenheit: ", i + 1);
            scanf("%d", &temp);

            // Ensure the temperature is within the valid range
            if (temp >= MIN_TEMP && temp <= MAX_TEMP) {
                break; // Exit the loop if a valid temperature is entered
            } else {
                printf("Temperature %d is invalid, Please enter a valid temperature between -30 and 130\n", temp);
            }
        }

        temperatures[i] = temp;
        sum += temp;

        // Check if the sequence is getting warmer or cooler
        if (i > 0) {
            if (temperatures[i] > temperatures[i - 1]) {
                isCooler = 0;
            } else if (temperatures[i] < temperatures[i - 1]) {
                isWarmer = 0;
            }
        }
    }

    // Determine if the sequence is getting warmer, cooler, or mixed
    if (isWarmer) {
        printf("Getting Warmer\n");
    } else if (isCooler) {
        printf("Getting Colder\n");
    } else {
        printf("It’s a mixed bag\n");
    }

    // Display the temperatures entered
    printf("5-day Temperature [");
    for (i = 0; i < NUM_TEMPERATURES; i++) {
        printf("%d", temperatures[i]);
        if (i < NUM_TEMPERATURES - 1) {
            printf(", ");  // Print a comma if it's not the last temperature
        }
    }
    printf("]\n");

    // Calculate and display the average temperature
    double average = (double)sum / NUM_TEMPERATURES;
    printf("Average temperature is %.2f degrees\n", average);

    return 0;
}
