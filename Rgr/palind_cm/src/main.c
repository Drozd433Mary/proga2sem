#include "palind.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("rgr1.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла!\n");
        return 1;
    }

    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';
        printf("Строка: %s\n", line);
        if (palind(line)) {
            printf("Это палиндром (по алгоритму Манакера)!\n");
        } else {
            printf("Это НЕ палиндром!\n");
        }
    }

    fclose(file);
    return 0;
}
