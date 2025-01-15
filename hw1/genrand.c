/*
 * genrand.c / Asignment_1_Part_1_Random number generation
 *
 * JinYoung Park / CS5600 / Northeastern University
 * Spring 2025 / Jan 15, 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

static unsigned long seed = 12345;

int genRand(int min, int max) {
    seed = (1103515245 * seed + 12345) % (1UL << 31);
    return min + (seed % (max - min + 1));
}

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        printf("Usage: %s <number_of_randoms> <file_name> [-a]\n", argv[0]);
        return -1;
    }

    int numRandoms = atoi(argv[1]);
    const char *fileName = argv[2];
    int appendMode = (argc == 4 && strcmp(argv[3], "-a") == 0);

    FILE *file = fopen(fileName, appendMode ? "a" : "w");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    for (int i = 0; i < numRandoms; i++) {
        fprintf(file, "%d\n", genRand(1, 100)); // Example range: 1 to 100.
    }

    fclose(file);
    printf("Generated %d random numbers and wrote to %s\n", numRandoms, fileName);
    return 0;
}
