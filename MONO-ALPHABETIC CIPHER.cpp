#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define ALPHABET_SIZE 26
void generate_key(char *key) {
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, j;
    char temp;
    strcpy(key, alphabet);
    srand(time(0));
    for (i = ALPHABET_SIZE - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = key[i];
        key[i] = key[j];
        key[j] = temp;
    }
}
void monoalphabetic_substitute(char *text, const char *key, int encrypt) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i])) {
            if (encrypt) {
                text[i] = key[text[i] - 'A'];
            } else {
                char *pos = strchr(key, text[i]);
                if (pos) {
                    text[i] = 'A' + (pos - key);
                }
            }
        }
        else if (islower(text[i])) {
            if (encrypt) {
                text[i] = tolower(key[toupper(text[i]) - 'A']);
            } else {
                char *pos = strchr(key, toupper(text[i]));
                if (pos) {
                    text[i] = 'a' + (pos - key);
                }
            }
        }
    }
}
int main() {
    char text[1000];
    char key[ALPHABET_SIZE + 1];
    int choice;
    printf("Monoalphabetic Substitution Cipher\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Generate Random Key\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar(); 
    if (choice == 3) {
        generate_key(key);
        printf("Generated Key: %s\n", key);
        return 0;
    }
    printf("Enter the substitution key (26 uppercase letters): ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0'; 
    if (strlen(key) != ALPHABET_SIZE) {
        printf("Key must be exactly 26 letters long.\n");
        return 1;
    }
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; 
    if (choice == 1) {
        monoalphabetic_substitute(text, key, 1);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        monoalphabetic_substitute(text, key, 0);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }
    return 0;
}
