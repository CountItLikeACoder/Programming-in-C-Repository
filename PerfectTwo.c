#include <stdio.h>

// Function to prompt user to enter an integer between 1-10,000
int getUserInput() {
    int num;
    printf("Enter an integer between 1 and 10,000: ");
    scanf("%d", &num);
    return num;
}

// Function to check if number is perfect
int isNumberPerfect(int num) {
    int sum = 0;

    // loop to find factors and their sum
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) { // to check if i is a factor
            sum += i;
        }
    }

    return sum == num; // Check if sum of factors equals original number, returns true if so
}

// Function to display result to user
void displayResult(int num, int result) {
    if (result) {
        printf("Perfect Number");
    } else {
        printf("Not A Perfect Number");
    }
}

int main() {
    int num = getUserInput(); // Get input from user and store it
    int result = isNumberPerfect(num); // Check if number is perfect 
    displayResult(num, result); // Display Result

    return 0;
}