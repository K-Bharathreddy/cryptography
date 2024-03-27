#include <stdio.h>
#include <stdint.h>
int initial_permutation_table[] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};
int final_permutation_table[] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
};
uint64_t key = 0x133457799BBCDFF1;
uint64_t plaintext_block = 0x0123456789ABCDEF;
uint64_t initial_permutation(uint64_t block) {
    uint64_t result = 0;
    for (int i = 0; i < 64; i++) {
        result |= ((block >> (64 - initial_permutation_table[i])) & 0x01) << (63 - i);
    }
    return result;
}
uint64_t final_permutation(uint64_t block) {
    uint64_t result = 0;
    for (int i = 0; i < 64; i++) {
        result |= ((block >> (64 - final_permutation_table[i])) & 0x01) << (63 - i);
    }
    return result;
}
uint64_t des_encrypt(uint64_t plaintext, uint64_t key) {
    uint64_t encrypted_block;
    plaintext = initial_permutation(plaintext);
    encrypted_block = final_permutation(plaintext);

    return encrypted_block;
}

int main() {
    uint64_t ciphertext;
    ciphertext = des_encrypt(plaintext_block, key);
    printf("Ciphertext: %llx\n", ciphertext);

    return 0;
}
