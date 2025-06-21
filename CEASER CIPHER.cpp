#include <stdio.h>
#include <ctype.h>
#include <string.h>
void caesar_cipher(char *text, int k) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + k) % 26 + base;
        }
    }
}
int main() {
    char text[1000];
    int k;  
    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  
    printf("Enter shift value (1-25): ");
    scanf("%d", &k);
    if (k < 1 || k > 25) {
        printf("Shift value must be between 1 and 25.\n");
        return 1;
    }
    caesar_cipher(text, k);
    printf("Result: %s\n", text);
    return 0;
}
