#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5 
void preprocessMessage(char *message) {
    int len = strlen(message);
    for (int i = 0; i < len; i++) {
        if (!isalpha(message[i])) {
            for (int j = i; j < len; j++) {
                message[j] = message[j + 1];
            }
            len--;
            i--;
        } else {
            message[i] = toupper(message[i]);
        }
    }
}
void generatePlayfairMatrix(char *key, char matrix[SIZE][SIZE]) {
    int i, j, k;
    int used[26] = {0};
    i = 0;
    j = 0;
    k = 0;
    while (key[k] != '\0') {
        if (!used[key[k] - 'A']) {
            matrix[i][j] = key[k];
            used[key[k] - 'A'] = 1;
            j++;
            if (j == SIZE) {
                j = 0;
                i++;
            }
        }
        k++;
    }
    for (k = 0; k < 26; k++) {
        if (k != ('J' - 'A') && !used[k]) {
            matrix[i][j] = k + 'A';
            j++;
            if (j == SIZE) {
                j = 0;
                i++;
            }
        }
    }
}
void findPositions(char matrix[SIZE][SIZE], char a, char b, int *row_a, int *col_a, int *row_b, int *col_b) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (matrix[i][j] == a) {
                *row_a = i;
                *col_a = j;
            } else if (matrix[i][j] == b) {
                *row_b = i;
                *col_b = j;
            }
        }
    }
}
void encryptPair(char matrix[SIZE][SIZE], char a, char b, char *encrypted_pair) {
    int row_a, col_a, row_b, col_b;
    findPositions(matrix, a, b, &row_a, &col_a, &row_b, &col_b);

    if (row_a == row_b) {
        encrypted_pair[0] = matrix[row_a][(col_a + 1) % SIZE];
        encrypted_pair[1] = matrix[row_b][(col_b + 1) % SIZE];
    } else if (col_a == col_b) {
        encrypted_pair[0] = matrix[(row_a + 1) % SIZE][col_a];
        encrypted_pair[1] = matrix[(row_b + 1) % SIZE][col_b];
    } else {
        encrypted_pair[0] = matrix[row_a][col_b];
        encrypted_pair[1] = matrix[row_b][col_a];
    }
}
void decryptPair(char matrix[SIZE][SIZE], char a, char b, char *decrypted_pair) {
    int row_a, col_a, row_b, col_b;
    findPositions(matrix, a, b, &row_a, &col_a, &row_b, &col_b);

    if (row_a == row_b) {
        decrypted_pair[0] = matrix[row_a][(col_a - 1 + SIZE) % SIZE];
        decrypted_pair[1] = matrix[row_b][(col_b - 1 + SIZE) % SIZE];
    } else if (col_a == col_b) {
        decrypted_pair[0] = matrix[(row_a - 1 + SIZE) % SIZE][col_a];
        decrypted_pair[1] = matrix[(row_b - 1 + SIZE) % SIZE][col_b];
    } else {
        decrypted_pair[0] = matrix[row_a][col_b];
        decrypted_pair[1] = matrix[row_b][col_a];
    }
}

int main() {
    char key[100];
    char matrix[SIZE][SIZE];
    char message[100];
    char encrypted_message[100];
    char decrypted_message[100];
    printf("Enter the keyword: ");
    scanf("%s", key);
    printf("Enter the message: ");
    scanf(" %[^\n]s", message);
    preprocessMessage(message);
    generatePlayfairMatrix(key, matrix);
    int len = strlen(message);
    int index = 0;
    for (int i = 0; i < len; i += 2) {
        encryptPair(matrix, message[i], message[i + 1], &encrypted_message[index]);
        index += 2;
    }
    encrypted_message[index] = '\0';
    index = 0;
    for (int i = 0; i < len; i += 2) {
        decryptPair(matrix, encrypted_message[i], encrypted_message[i + 1], &decrypted_message[index]);
        index += 2;
    }
    decrypted_message[index] = '\0';

    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}
