#include <stdio.h>
#include <ctype.h>
void vigenere(char *t, char *k, int e) {
    for(int i=0,j=0;t[i];i++)
        if(isalpha(t[i])) {
            int c = toupper(t[i])-'A';
            int o = toupper(k[j++])-'A';
            if(!e) o = 26-o;
            t[i] = (isupper(t[i])?'A':'a') + (c+o)%26;
        }
}
int main() {
    char t[256], k[256];
    printf("Text: "); fgets(t,256,stdin);
    printf("Key: "); fgets(k,256,stdin);
    vigenere(t,k,1); printf("Encrypted: %s",t);
    vigenere(t,k,0); printf("Decrypted: %s",t);
}
