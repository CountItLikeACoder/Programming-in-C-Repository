#include <stdio.h>

//Function to get wind speed from user input
float getWindSpeed() {
    float wind_speed;
    printf("Enter wind speed of hurricane (miles per hour): ");
    scanf("%f", &wind_speed); // Scan input and store it in wind_speed
    return wind_speed;
}

// Function to determine hurricane category based on wind speed
void determineCategory(float wind_speed) {
    if (wind_speed >= 157) {
        printf("Category Five Hurricane\n");
    } else if (wind_speed >= 130) {
        printf("Category Four Hurricane\n");
    } else if (wind_speed >= 111) {
        printf("Category Three Hurricane\n");
    } else if (wind_speed >= 96) {
        printf("Category Two Hurricane\n");
    } else if (wind_speed >= 74) {
        printf("Category One Hurricane\n");
    } else {
        printf("Not a hurricane\n");
    }
}

int main() {
    float wind_speed = getWindSpeed();
    determineCategory(wind_speed);

    return 0; 
}