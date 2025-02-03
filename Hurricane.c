#include <stdio.h>

int main() {
    float wind_speed;

    printf("Enter wind speed of hurricane (miles per hour): ");
    scanf("%f", &wind_speed); //scan input and store it in wind_speed

    // determine category 
    if (wind_speed >= 157) {
        printf("Category Five Hurricane\n");
    } else if (wind_speed >= 130) {
        printf("Category Four Major Hurricane\n");
    } else if (wind_speed >= 111) {
        printf("Category Three Hurricane\n");
    } else if (wind_speed >= 96) {
        printf("Category Two Hurricane\n");
    } else if (wind_speed >= 74) {
        printf("Category One Hurricane\n");
    } else {
        printf("Not a hurricane\n");
    }

    return 0; 
}