#include <stdio.h>
#include <string.h>

int main(void) {
    char name[] = "Robert Hall";
    char birthdate[] = "2/27/1949";
    char workNumber[] = "work 000-444-0101";
    char cellNumber[] = "cell 000-444-0189";

    printf("%s\n", name);
    // name = Robert Hall
    printf("%s\n", birthdate);
    // birthdate = 2/27/1949
    printf("%s\n", workNumber);
    // workNumber = work 000-444-0101
    printf("%s\n", cellNumber);
    // cellNumber = cell 000-444-0189
}