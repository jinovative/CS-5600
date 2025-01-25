#include <stdio.h>
#include <ctype.h>
#include <string.h>

void to_upper(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void to_lower(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void to_capitalize(char *str) {
    int capitalize = 1;
    for (int i = 0; str[i]; i++) {
        if (isspace(str[i])) {
            capitalize = 1;
        } else if (capitalize && isalpha(str[i])) {
            str[i] = toupper(str[i]);
            capitalize = 0;
        } else {
            str[i] = tolower(str[i]);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Error: Invalid arguments\n");
        return -1;
    }

    char result[1024] = "";
    for (int i = 2; i < argc; i++) {
        strcat(result, argv[i]);
        if (i < argc - 1) strcat(result, " ");
    }

    if (strcmp(argv[1], "-u") == 0) {
        to_upper(result);
    } else if (strcmp(argv[1], "-l") == 0) {
        to_lower(result);
    } else if (strcmp(argv[1], "-cap") == 0) {
        to_capitalize(result);
    } else {
        printf("Error: Invalid option\n");
        return -1;
    }

    printf("%s\n", result);
    return 0;
}
