#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define CIPHERTEXT "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83(88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8*;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81(‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?;"
void frequencyAnalysis(const char* ciphertext) {
    int freq[256] = {0};
    int total = 0;
    for(int i = 0; ciphertext[i]; i++) {
        if(ciphertext[i] != ' ') {
            freq[(unsigned char)ciphertext[i]]++;
            total++;
        }
    }
    printf("Character Frequency Analysis:\n");
    printf("Char\tCount\tPercentage\n");
    for(int i = 0; i < 256; i++) {
        if(freq[i] > 0) {
            printf("%c\t%d\t%.2f%%\n", i, freq[i], (freq[i] * 100.0) / total);
        }
    }
}
void decryptWithMapping(const char* ciphertext, const char* mapping) {
    printf("\nDecrypted Message:\n");
    for(int i = 0; ciphertext[i]; i++) {
        if(ciphertext[i] == ' ') {
            putchar(' ');
        } else {
            const char* pos = strchr(mapping, ciphertext[i]);
            if(pos) {
                int index = pos - mapping;
                putchar("etaoinshrdlcumwfgypbvkjxqz"[index]);
            } else {
                putchar(ciphertext[i]);
            }
        }
    }
    putchar('\n');
}
int main() {
    printf("Original Ciphertext:\n%s\n\n", CIPHERTEXT);
    frequencyAnalysis(CIPHERTEXT);
    const char* mapping = "8;4‡*5)6†(01?9:23—¶.]";
    decryptWithMapping(CIPHERTEXT, mapping);
    printf("\nRefined Mapping (after seeing partial decryption):\n");
    printf("8=e, ;=t, 4=h, ‡=o, *=a, 5=n, )=d, 6=i, †=r, (=s, 0=l, 1=m, ?=u, 9=g, :=f, 2=y, 3=w, —=v, ¶=c, ]=b, .=p\n");
    const char* finalMapping = "8;4‡*5)6†(01?9:23—¶.]";
    const char* englishFreq = "etaohnrisdlmufgwyvcpb";
    printf("\nFinal Decryption:\n");
    for(int i = 0; CIPHERTEXT[i]; i++) {
        const char* pos = strchr(finalMapping, CIPHERTEXT[i]);
        if(pos) {
            int index = pos - finalMapping;
            putchar(englishFreq[index]);
        } else {
            putchar(CIPHERTEXT[i]);
        }
    }
    putchar('\n');
    return 0;
}
