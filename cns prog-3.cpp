#include <stdio.h>
#include <string.h>
#include <ctype.h>
void prepareKey(char key[], char matrix[][5]) {
    int i, j, k;
    char alphabet[26] = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; 
    for(i = 0; i < strlen(key); ++i) {
        key[i] = toupper(key[i]);
        if(key[i] == 'J') key[i] = 'I'; 
        for(j = i + 1; j < strlen(key); ++j) {
            if(key[i] == key[j]) {
                for(k = j; k < strlen(key); ++k) {
                    key[k] = key[k + 1];
                }
            }
        }
    }
    k = 0;
    for(i = 0; i < 5; ++i) {
        for(j = 0; j < 5; ++j) {
            if(k < strlen(key)) {
                matrix[i][j] = key[k++];
            } else {
                while(strchr(key, alphabet[k]) != NULL) ++k;
                matrix[i][j] = alphabet[k++];
            }
        }
    }
}
void findPosition(char matrix[][5], char ch, int *row, int *col) {
    int i, j;

    for(i = 0; i < 5; ++i) {
        for(j = 0; j < 5; ++j) {
            if(matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}
void playfairEncrypt(char matrix[][5], char ch1, char ch2) {
    int row1, col1, row2, col2;

    findPosition(matrix, ch1, &row1, &col1);
    findPosition(matrix, ch2, &row2, &col2);

    if(row1 == row2) { 
        printf("%c%c ", matrix[row1][(col1 + 1) % 5], matrix[row2][(col2 + 1) % 5]);
    } else if(col1 == col2) { 
        printf("%c%c ", matrix[(row1 + 1) % 5][col1], matrix[(row2 + 1) % 5][col2]);
    } else { 
        printf("%c%c ", matrix[row1][col2], matrix[row2][col1]);
    }
}

int main() {
    char key[26];
    char matrix[5][5];
    char plaintext[100];
    int i, j;

    printf("Enter the keyword: ");
    fgets(key, sizeof(key), stdin);
    prepareKey(key, matrix);

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    for(i = 0; i < strlen(plaintext); ++i) {
        plaintext[i] = toupper(plaintext[i]);
        if(plaintext[i] == ' ') {
            for(j = i; j < strlen(plaintext); ++j) {
                plaintext[j] = plaintext[j + 1];
            }
        }
    }
    if(strlen(plaintext) % 2 != 0) {
        strcat(plaintext, "X");
    }
    printf("Encrypted text: ");
    for(i = 0; i < strlen(plaintext); i += 2) {
        playfairEncrypt(matrix, plaintext[i], plaintext[i + 1]);
    }
    printf("\n");

    return 0;
}
