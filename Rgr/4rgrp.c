#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int palind(char *str) {
    int len = strlen(str);
    char *cleaned = malloc(len + 1);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            cleaned[j] = tolower(str[i]);
            j++;
        }
    }
    cleaned[j] = '\0';
    int left = 0, right = j - 1;
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            free(cleaned);
            return 0;
        }
        left++;
        right--;
    }
    free(cleaned);
    return 1;
}

int main() {
    FILE *file = fopen("rgrp.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, " \n")] = '\0';
        printf("Строка: %s\n", line);
        if (palind(line)) {
            printf("Это палиндром!\n");
        } else {
            printf("Это НЕ палиндром!\n");
        }
    }

    fclose(file);
    return 0;
}
