#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void createMatrix(char key[], char m[SIZE][SIZE]) {
    char used[26] = {0};
    int k = 0;
    for(int i = 0; key[i]; i++) {
        char c = toupper(key[i]);
        if(c == 'J') c = 'I';
        if(!used[c-'A'] && isalpha(c)) {
            m[k/SIZE][k%SIZE] = c;
            used[c-'A'] = 1;
            k++;
        }
    }
    for(char c = 'A'; c <= 'Z'; c++) {
        if(c != 'J' && !used[c-'A']) {
            m[k/SIZE][k%SIZE] = c;
            k++;
        }
    }
}
void findPos(char m[SIZE][SIZE], char c, int *r, int *c) {
    if(c == 'J') c = 'I';
    for(*r = 0; *r < SIZE; (*r)++)
        for(*c = 0; *c < SIZE; (*c)++)
            if(m[*r][*c] == c) return;
}
void encryptPair(char m[SIZE][SIZE], char a, char b) {
    int r1, c1, r2, c2;
    findPos(m, a, &r1, &c1);
    findPos(m, b, &r2, &c2);   
    if(r1 == r2) {
        printf("%c%c", m[r1][(c1+1)%SIZE], m[r2][(c2+1)%SIZE]);
    } else if(c1 == c2) {
        printf("%c%c", m[(r1+1)%SIZE][c1], m[(r2+1)%SIZE][c2]);
    } else {
        printf("%c%c", m[r1][c2], m[r2][c1]);
    }
}
int main() {
    char key[100], text[1000], m[SIZE][SIZE];
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    createMatrix(key, m);
    int len = 0;
    for(int i = 0; text[i]; i++)
        if(isalpha(text[i])) text[len++] = toupper(text[i]);
    text[len] = '\0';
    for(int i = 0; i < len; i += 2) {
        if(i+1 >= len) encryptPair(m, text[i], 'X');
        else if(text[i] == text[i+1]) encryptPair(m, text[i], 'X'), i--;
        else encryptPair(m, text[i], text[i+1]);
    }
    return 0;
}
