#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_STRINGS 10000
#define STRING_LENGTH 8

void generate_random_string(char *str, int length) {
    static const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < length; i++) {
        str[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    str[length] = '\0';
}

int main() {
    FILE *file = fopen("strings.txt", "w");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < NUM_STRINGS; i++) {
        char str[STRING_LENGTH + 1];
        generate_random_string(str, STRING_LENGTH);
        fprintf(file, "%s\n", str);
    }

    fclose(file);
    printf("Generated %d random strings in strings.txt\n", NUM_STRINGS);
    return 0;
}

