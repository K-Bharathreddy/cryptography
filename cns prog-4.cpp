#include <stdio.h>
#include <string.h>
#include <ctype.h>
void polyalphabeticCipher(char message[], char key[]) {
    int i, j, k;
    int keyLength = strlen(key);
    for(i = 0; i < keyLength; ++i) {
        key[i] = toupper(key[i]);
    }
    for(i = 0, j = 0; i < strlen(message); ++i) {
        char ch = message[i];
        if(isalpha(ch)) {
            int offset = toupper(key[j % keyLength]) - 'A';
            if(isupper(ch)) {
                message[i] = ((ch - 'A' + offset) % 26) + 'A';
            } else {
                message[i] = ((ch - 'a' + offset) % 26) + 'a';
            }
            j++;
        }
    }
}

int main() {
    char message[100];
    char key[100];

    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';
    polyalphabeticCipher(message, key);
    printf("Encrypted message: %s\n", message);
    return 0;
}