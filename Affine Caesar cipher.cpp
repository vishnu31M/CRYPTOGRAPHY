#include <stdio.h>
#include <ctype.h>
int isCoprime(int a) {
    for(int i=2; i<=a; i++)
        if(a%i==0 && 26%i==0) return 0;
    return 1;
}
int modInverse(int a) {
    for(int i=1; i<26; i++)
        if((a*i)%26 == 1) return i;
    return -1;
}
void affine_cipher(char *text, int a, int b, int encrypt) {
    if(!isCoprime(a)) {
        printf("Error: 'a' must be coprime with 26\n");
        return;
    }
    for(int i=0; text[i]; i++) {
        if(isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            int p = text[i] - base;
            int c = encrypt ? (a*p + b) % 26 : (modInverse(a)*(26 + p - b)) % 26;
            text[i] = base + (c < 0 ? c+26 : c);
        }
    }
}
int main() {
    char text[256];
    int a, b;
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter key 'a' (must be coprime with 26): ");
    scanf("%d", &a);
    printf("Enter key 'b': ");
    scanf("%d", &b);
    affine_cipher(text, a, b, 1);
    printf("Encrypted: %s", text);
    affine_cipher(text, a, b, 0);
    printf("Decrypted: %s", text);
    return 0;
}
