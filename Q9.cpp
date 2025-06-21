#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void prepareKeyMatrix(char key[], char keyMatrix[SIZE][SIZE]) {
    int used[26] = {0};
    int k = 0;
    for(int i = 0; key[i]; i++) {
        char c = toupper(key[i]);
        if(c == 'J') c = 'I';
        if(!used[c-'A'] && isalpha(c)) {
            keyMatrix[k/SIZE][k%SIZE] = c;
            used[c-'A'] = 1;
            k++;
        }
    }
    for(char c = 'A'; c <= 'Z'; c++) {
        if(c != 'J' && !used[c-'A']) {
            keyMatrix[k/SIZE][k%SIZE] = c;
            k++;
        }
    }
}
void findPosition(char keyMatrix[SIZE][SIZE], char ch, int *row, int *col) {
    if(ch == 'J') ch = 'I';
    for(*row = 0; *row < SIZE; (*row)++)
        for(*col = 0; *col < SIZE; (*col)++)
            if(keyMatrix[*row][*col] == ch) return;
}
void decryptPair(char keyMatrix[SIZE][SIZE], char a, char b) {
    int r1, c1, r2, c2;
    findPosition(keyMatrix, a, &r1, &c1);
    findPosition(keyMatrix, b, &r2, &c2);
    if(r1 == r2) {
        printf("%c%c", keyMatrix[r1][(c1-1+SIZE)%SIZE], keyMatrix[r2][(c2-1+SIZE)%SIZE]);
    } else if(c1 == c2) {
        printf("%c%c", keyMatrix[(r1-1+SIZE)%SIZE][c1], keyMatrix[(r2-1+SIZE)%SIZE][c2]);
    } else {
        printf("%c%c", keyMatrix[r1][c2], keyMatrix[r2][c1]);
    }
}
int main() {
    char key[] = "KENNEDY";
    char keyMatrix[SIZE][SIZE];
    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    prepareKeyMatrix(key, keyMatrix);
    printf("Playfair Key Matrix:\n");
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++)
            printf("%c ", keyMatrix[i][j]);
        printf("\n");
    }
    printf("\nDecrypted Message:\n");
    for(int i = 0; ciphertext[i]; i += 2) {
        if(i+1 >= strlen(ciphertext)) break;
        decryptPair(keyMatrix, ciphertext[i], ciphertext[i+1]);
        printf(" ");
    }
    return 0;
}
