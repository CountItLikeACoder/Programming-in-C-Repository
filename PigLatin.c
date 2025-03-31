#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function that returns when character is a vowel
int isVowel(char c) {
    c = tolower(c);  // Make it case-insensitive
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Function to translate a single word from English to Pig Latin
void toPigLatin(char *word) {
    int len = strlen(word);
    int i = 0;

    // Skip non-alphabetic characters
    while (i < len && !isalpha(word[i])) {
        i++;
    }

    // If the word starts with a consonant or consonant cluster
    if (i < len && !isVowel(word[i])) {
        // Find the first vowel or end of the word
        int j = i;
        while (j < len && !isVowel(word[j])) {
            j++;
        }

        // Move the consonant cluster to the end and append "ay"
        char temp[len + 3];  
        int k = 0;

        // Move the consonant cluster to the end
        for (int p = j; p < len; p++) {
            temp[k++] = word[p];
        }

        // Add the part of the word before the consonant cluster
        for (int p = i; p < j; p++) {
            temp[k++] = word[p];
        }

        // Add "ay" to the end
        temp[k++] = 'a';
        temp[k++] = 'y';
        temp[k] = '\0';  // Null-terminate the string

        // Copy the result back to the original word
        strcpy(word, temp);
    } else {
        // If the word starts with a vowel, add "yay"
        strcat(word, "yay");
    }
}

// Function to handle the translation of a sentence
void translate() {
    char sentence[500];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the newline character if present
    sentence[strcspn(sentence, "\n")] = '\0';

    char word[100];
    int i = 0, j = 0, len = strlen(sentence);

    // Process each word in the sentence
    while (i <= len) {
        if (sentence[i] == ' ' || sentence[i] == '\0' || ispunct(sentence[i])) {
            // End of a word or punctuation
            if (j > 0) {
                word[j] = '\0'; // Null-terminate the word
                toPigLatin(word); // Translate to Pig Latin
                printf("%s", word); // Print translated word
            }

            // Print punctuation if any
            if (ispunct(sentence[i])) {
                printf("%c", sentence[i]);
            }

            // Print space if necessary
            if (sentence[i] == ' ') {
                printf(" ");
            }

            j = 0; // Reset for the next word
        } else {
            word[j++] = sentence[i]; // Add character to word
        }
        i++;
    }

    printf("\n");
}

int main() {
    translate();  // Translate and print the Pig Latin
    return 0;
}