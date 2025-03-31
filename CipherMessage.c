#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptText(char *text, int shift) {
    for (int i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            // Apply the backward shift
            text[i] = (text[i] - base - shift + 26) % 26 + base;
        }
    }
}

void processShift(int *shift) {
    if (*shift < 0) {
        *shift = *shift + 26 * ((-(*shift)) / 26 + 1);  // to handle negative shifts
    }
    *shift = *shift % 26; // Ensure the shift is within 0 to 25
}

int main() {
    char text[1000];
    int shift;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0;  // Remove the newline character

    printf("Enter the shift value: ");
    scanf("%d", &shift);

    processShift(&shift); // Adjust negative or out-of-range shifts

    // Output original text
    printf("\nText: %s\n", text);
    printf("Shift: %d\n", shift);

    // Encrypt the text
    encryptText(text, shift);
    
    // Output encrypted text (ciphered)
    printf("Cipher: %s\n", text);

    return 0;
}