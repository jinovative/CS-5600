#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "polybius.h"

int main() {
    FILE *input = fopen("batch_input.txt", "r");
    FILE *output = fopen("batch_output.txt", "w");
    if (!input || !output) {
        perror("Error opening file");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), input)) {
        char encrypted[256];
        line[strcspn(line, "\n")] = '\0'; // Remove newline
        pbEncode(line, encrypted);
        fprintf(output, "%s\n", encrypted);
    }

    fclose(input);
    fclose(output);
    return 0;
}

