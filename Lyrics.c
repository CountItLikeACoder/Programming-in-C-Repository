#include <stdio.h>
#include <string.h>

int main(void) {
    char lineOne[] = "Now, this is a story all about how";
    char lineTwo[] = "My life got flipped-turned upside down";
    char lineThree[] = "And I'd like to take a minute";
    char lineFour[] = "Just sit right there";
    char lineFive[] = "I'll tell you how I became the prince of a town called Bel-Air";

    printf("%s\n", lineOne);
    // lineOne = Now, this is a story all about how
    printf("%s\n", lineTwo);
    // lineTwo = My life got flipped-turned upside down
    printf("%s\n", lineThree);
    // lineThree = And I'd like to take a minute
    printf("%s\n", lineFour);
    // lineFour = Just sit right there
    printf("%s\n", lineFive);
    // lineFIve = I'll tell you how I became the prince of a town called Bel-Air
}