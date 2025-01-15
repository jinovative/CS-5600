/*
 * cipher.c / Asignment_1_Part_2_Create cipher
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Jan 15, 2025
 *
 */

#include <stdio.h>
#include <string.h>
#include "polybius.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s -e \"plaintext\" or %s -d \"ciphertext\"\n", argv[0], argv[0]);
        return -1;
    }

    char result[256];
    if (strcmp(argv[1], "-e") == 0) {
        pbEncode(argv[2], result);
        printf("Encoded: %s\n", result);
    } else if (strcmp(argv[1], "-d") == 0) {
        pbDecode(argv[2], result);
        printf("Decoded: %s\n", result);
    } else {
        printf("Invalid option. Use -e to encode or -d to decode.\n");
        return -1;
    }
    return 0;
}

