#include <stdio.h>
#include <ctype.h>
int modInverse(int a) {
    for(int i = 1; i < 26; i++)
        if((a * i) % 26 == 1)
            return i;
    return -1;
}
void decrypt(char *ciphertext, int a, int b) {
    int a_inv = modInverse(a);
    if(a_inv == -1) return;
    for(int i = 0; ciphertext[i]; i++) {
        if(isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            int c = ciphertext[i] - base;
            int p = (a_inv * (26 + c - b)) % 26;
            ciphertext[i] = base + p;
        }
    }
}
int main() {
    char ciphertext[] = "Your ciphertext here"; 
    char most_freq = 'B'; 
    char second_freq = 'U'; 
    int e = 'E' - 'A';
    int t = 'T' - 'A';
    int b = most_freq - 'A';
    int u = second_freq - 'A';
    int diff = (e - t + 26) % 26;
    int rhs = (b - u + 26) % 26;
    printf("Possible keys:\n");
    for(int a = 1; a < 26; a++) {
        if((a * diff) % 26 == rhs) {
            int b_val = (b - a * e + 26 * 26) % 26;
            printf("a=%d, b=%d: ", a, b_val);
            char test[256];
            strcpy(test, ciphertext);
            decrypt(test, a, b_val);
            printf("%s\n", test);
        }
    }
    return 0;
}
