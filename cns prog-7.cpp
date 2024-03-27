#include <stdio.h>
#include <ctype.h>
void encryptCaesar(char *message, int key) {
    while (*message) {
        if (isalpha(*message)) {
            char base = isupper(*message) ? 'A' : 'a';
            *message = (char)(((int)(*message - base + key) % 26) + base);
        }
        message++;
    }
}
void decryptCaesar(char *message, int key) {
    encryptCaesar(message, 26 - key); 
}

int main() {
    char message[100];
    int key;
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    printf("Enter the key (a number between 0 and 25): ");
    scanf("%d", &key);
    encryptCaesar(message, key);
    printf("Encrypted message: %s\n", message);
    decryptCaesar(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}
