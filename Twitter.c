#include <stdio.h>
#include <string.h>

int main() {
    char message[142]; // array that can hold 141 characters (140 characters + null terminator) for the message

    // prompt user to input their message
    printf("Enter your message: ");
    fgets(message, sizeof(message), stdin); // read message

    // remove newline character
    message[strcspn(message, "\n")] = '\0';
    
    //check message length
    if (strlen(message) <= 140) {
        printf("Posted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
