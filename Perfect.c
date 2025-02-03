#include <stdio.h>

int main() {
    int num, i;
    // prompt user to enter an integer between 1-10,000
    printf("Enter an integer between 1 and 10,000: ");
    scanf("%d", &num);

    int sum = 0;

    // loop to find factors and their sum
    for (int i = 1; i <= num / 2; i++) {
        if (num % i == 0) { // to check if i is a factor
            sum += i;
        }
    }

    // check if sum of factors equals original number
    if (sum == num) {
        printf("Perfect Number");
    } else {
        printf("Not A Perfect Number");
    }
    
    return 0;
}