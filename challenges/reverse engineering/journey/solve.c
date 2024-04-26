#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>

void swap(unsigned char *a, unsigned char *b) {
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

void RC4_init(unsigned char *key, size_t key_length, unsigned char *S) {
    for (int i = 0; i < 256; i++) {
        S[i] = i;
    }

    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % key_length]) % 256;
        swap(&S[i], &S[j]);
    }
}

void RC4_process(unsigned char *data, size_t data_length, unsigned char *S, unsigned char *output) {
    int i = 0, j = 0;
    for (size_t n = 0; n < data_length; n++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(&S[i], &S[j]);
        unsigned char rnd = S[(S[i] + S[j]) % 256];
        output[n] = data[n] ^ rnd;
    }
}

//  decrypt flag A4E9C5E25CAA59C86796D74974E11AA204337BAA56A818B2E08395E0EDBDE0B3011FB8D23B3F4DEF914C199C1EB9
int main() {
    unsigned char key[] = {0x41, 0x42, 0x43, 0x44, 0x45};
    unsigned char S[256];
    RC4_init(key, sizeof(key), S);

    unsigned char encrypted[] = {0xA4, 0xE9, 0xC5, 0xE2, 0x5C, 0xAA, 0x59, 0xC8, 0x67, 0x96, 0xD7, 0x49, 0x74, 0xE1, 0x1A, 0xA2, 0x04, 0x33, 0x7B, 0xAA, 0x56, 0xA8, 0x18, 0xB2, 0xE0, 0x83, 0x95, 0xE0, 0xED, 0xBD, 0xE0, 0xB3, 0x01, 0x1F, 0xB8, 0xD2, 0x3B, 0x3F, 0x4D, 0xEF, 0x91, 0x4C, 0x19, 0x9C, 0x1E, 0xB9};
    size_t encrypted_length = sizeof(encrypted);
    unsigned char *decrypted = (unsigned char *)malloc(encrypted_length);
    RC4_process(encrypted, encrypted_length, S, decrypted);

    printf("Decrypted message: %s\n", decrypted);

    free(decrypted);
    return 0;
}
