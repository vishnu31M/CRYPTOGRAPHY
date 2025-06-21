#include <stdio.h>
#include <ctype.h>
#include <string.h>
void createCipherAlphabet(const char *keyword, char *cipherAlphabet) {
    int used[26] = {0};
    int pos = 0;
    for (int i = 0; keyword[i]; i++) {
        char c = toupper(keyword[i]);
        if (!used[c - 'A']) {
            cipherAlphabet[pos++] = c;
            used[c - 'A'] = 1;
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (!used[c - 'A']) {
            cipherAlphabet[pos++] = c;
        }
    }
    cipherAlphabet[26] = '\0';
}
void monoalphabeticCipher(char *text, const char *cipherAlphabet, int encrypt) {
    for (int i = 0; text[i]; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int index = toupper(text[i]) - 'A';
            if (encrypt) {
                text[i] = isupper(text[i]) ? cipherAlphabet[index] : tolower(cipherAlphabet[index]);
            } else {
                const char *found = strchr(cipherAlphabet, toupper(text[i]));
                if (found) {
                    int pos = found - cipherAlphabet;
                    text[i] = isupper(text[i]) ? 'A' + pos : 'a' + pos;
                }
            }
        }
    }
}
int main() {
    char keyword[] = "CIPHER";
    char cipherAlphabet[27];
    char text[256];
    createCipherAlphabet(keyword, cipherAlphabet);
    printf("Cipher alphabet: %s\n", cipherAlphabet);
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    monoalphabeticCipher(text, cipherAlphabet, 1);
    printf("Encrypted: %s\n", text);
    monoalphabeticCipher(text, cipherAlphabet, 0);
    printf("Decrypted: %s\n", text);
    return 0;
}
