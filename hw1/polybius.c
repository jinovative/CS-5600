/*
 * polybius.c / Asignment_1_Part_2_Create cipher
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Jan 15, 2025
 *
 */

#include <stdio.h>
#include <string.h>
#include "polybius.h"

char table[5][5] = {
    {'A', 'B', 'C', 'D', 'E'},
    {'F', 'G', 'H', 'I', 'K'},
    {'L', 'M', 'N', 'O', 'P'},
    {'Q', 'R', 'S', 'T', 'U'},
    {'V', 'W', 'X', 'Y', 'Z'}
};

void pbEncode(const char *plaintext, char *ciphertext) {
    int idx = 0;
    for (size_t i = 0; i < strlen(plaintext); i++) {
        char ch = toupper(plaintext[i]);
        if (ch == 'J') ch = 'I'; // Treat J as I
        if (ch < 'A' || ch > 'Z') continue; // Ignore special characters

        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 5; col++) {
                if (table[row][col] == ch) {
                    ciphertext[idx++] = '1' + row;
                    ciphertext[idx++] = '1' + col;
                }
            }
        }
    }
    ciphertext[idx] = '\0';
}

void pbDecode(const char *ciphertext, char *plaintext) {
    int idx = 0;
    for (size_t i = 0; i < strlen(ciphertext); i += 2) {
        int row = ciphertext[i] - '1';
        int col = ciphertext[i + 1] - '1';
        if (row >= 0 && row < 5 && col >= 0 && col < 5) {
            plaintext[idx++] = table[row][col];
        }
    }
    plaintext[idx] = '\0';
}
