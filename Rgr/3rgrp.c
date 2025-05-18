#include <stdio.h>
#include <string.h>
#include <ctype.h>

int palind(char *str) {
    int len = strlen(str);
    int left = 0, right = len - 1;
    while (left < right) {
        if (tolower(str[left]) != tolower(str[right])) {
            return 0;
        }
        left++;
        right--;
    }
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
        line[strcspn(line, "\n")] = '\0';
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
