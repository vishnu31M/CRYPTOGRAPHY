#include <stdio.h>
#include <ctype.h>
#include <string.h>
void prepareText(char *text) {
    int len = strlen(text);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(text[i])) {
            text[j++] = toupper(text[i]);
        }
    }
    text[j] = '\0';
    len = strlen(text);
    for (int i = 0; i < len; i += 2) {
        if (i + 1 >= len) {
            strcat(text, "X");
            break;
        }
        if (text[i] == text[i + 1]) {
            memmove(&text[i + 2], &text[i + 1], len - i);
            text[i + 1] = 'X';
            len++;
            text[len] = '\0';
        }
    }
}
void encryptPair(char a, char b) {
    char matrix[5][5] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };
    int row1, col1, row2, col2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == a || (a == 'J' && matrix[i][j] == 'I')) {
                row1 = i;
                col1 = j;
            }
            if (matrix[i][j] == b || (b == 'J' && matrix[i][j] == 'I')) {
                row2 = i;
                col2 = j;
            }
        }
    }
    if (row1 == row2) {
        printf("%c%c", matrix[row1][(col1 + 1) % 5], matrix[row2][(col2 + 1) % 5]);
    }
    else if (col1 == col2) {
        printf("%c%c", matrix[(row1 + 1) % 5][col1], matrix[(row2 + 1) % 5][col2]);
    }
    else {
        printf("%c%c", matrix[row1][col2], matrix[row2][col1]);
    }
}
int main() {
    char message[] = "Must see you over Cadogan West. Coming at once.";
    prepareText(message);
    printf("Encrypted message: ");
    for (int i = 0; i < strlen(message); i += 2) {
        encryptPair(message[i], message[i + 1]);
    }
    printf("\n"); 
    return 0;
}
