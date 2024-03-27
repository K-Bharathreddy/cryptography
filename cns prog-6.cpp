#include <stdio.h>
#include <string.h>

#define ALPHABET_SIZE 26
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}
void decryptAffine(char *ciphertext, int a, int b) {
    int a_inverse = modInverse(a, ALPHABET_SIZE);
    if (a_inverse == -1) {
        printf("Multiplicative inverse doesn't exist.\n");
        return;
    }
    int len = strlen(ciphertext);
    for (int i = 0; i < len; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int c = ciphertext[i] - 'A';
            int x = (a_inverse * (c - b + ALPHABET_SIZE)) % ALPHABET_SIZE;
            printf("%c", (char)(x + 'A'));
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
}
int main() {
    char ciphertext[] = "YOUR_CIPHERTEXT_HERE"; 
    int most_frequent = 'B' - 'A';
    int second_most_frequent = 'U' - 'A';
    for (int a = 1; a < ALPHABET_SIZE; a++) {
        int a_inverse = modInverse(a, ALPHABET_SIZE);
        if (a_inverse == -1)
            continue;

        for (int b = 0; b < ALPHABET_SIZE; b++) {
            if ((a * a_inverse) % ALPHABET_SIZE == 1) {
                int decrypted_most = (a_inverse * (most_frequent - b + ALPHABET_SIZE)) % ALPHABET_SIZE;
                int decrypted_second_most = (a_inverse * (second_most_frequent - b + ALPHABET_SIZE)) % ALPHABET_SIZE;
                if (decrypted_most == 4 && decrypted_second_most == 19) {
                    printf("Possible keys found: a = %d, b = %d\n", a, b);
                    printf("Decrypted Text:\n");
                    decryptAffine(ciphertext, a, b);
                }
            }
        }
    }

    return 0;
}
