#include <stdio.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char *plaintext, char *key) {
    int keyLen = strlen(key);
    int textLen = strlen(plaintext);
    char ciphertext[textLen + 1];

    for (int i = 0, j = 0; i < textLen; i++) {
        char currentChar = plaintext[i];
        if (isalpha(currentChar)) {
            char shift = isupper(currentChar) ? 'A' : 'a';
            ciphertext[i] = ((currentChar + key[j] - 2 * shift) % 26) + shift;
            j = (j + 1) % keyLen;
        } else {
            ciphertext[i] = currentChar;
        }
    }
    ciphertext[textLen] = '\0';
    printf("Encrypted message: %s\n", ciphertext);
}
void vigenereDecrypt(char *ciphertext, char *key) {
    int keyLen = strlen(key);
    int textLen = strlen(ciphertext);
    char plaintext[textLen + 1];

    for (int i = 0, j = 0; i < textLen; i++) {
        char currentChar = ciphertext[i];
        if (isalpha(currentChar)) {
            char shift = isupper(currentChar) ? 'A' : 'a';
            plaintext[i] = ((currentChar - key[j] + 26) % 26) + shift;
            j = (j + 1) % keyLen;
        } else {
            plaintext[i] = currentChar; 
        }
    }
    plaintext[textLen] = '\0';
    printf("Decrypted message: %s\n", plaintext);
}
int main() {
    char plaintext[1000], key[100];
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    if (plaintext[strlen(plaintext) - 1] == '\n')
        plaintext[strlen(plaintext) - 1] = '\0';
    printf("Enter the key: ");
    scanf("%s", key);
    vigenereEncrypt(plaintext, key);
    vigenereDecrypt(plaintext, key);

    return 0;
}
