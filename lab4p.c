#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define DEFAULT_PATH "/home/maria/Рабочий стол/labprog/ll.txt"

void replace_word_in_file(const char* filepath, const char* old_word, const char* new_word) {
    FILE* file = fopen(filepath, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char temp_path[MAX_LINE_LENGTH];
    snprintf(temp_path, sizeof(temp_path), "%s.temp", filepath);
    
    FILE* temp_file = fopen(temp_path, "w");
    if (temp_file == NULL) {
        perror("Error creating temp file");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        char* pos = strstr(line, old_word);
        while (pos != NULL) {
            char temp[MAX_LINE_LENGTH] = {0};
            strncpy(temp, line, pos - line);
            strcat(temp, new_word);
            strcat(temp, pos + strlen(old_word));
            strcpy(line, temp);
            pos = strstr(line, old_word);
        }
        fputs(line, temp_file);
    }

    fclose(file);
    fclose(temp_file);

    if (remove(filepath) != 0) {
        perror("Error removing original file");
        exit(EXIT_FAILURE);
    }
    if (rename(temp_path, filepath) != 0) {
        perror("Error renaming temp file");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[]) {
    const char* filepath;
    const char* word_to_replace = "you";
    const char* new_word = "Maria";

    
    if (argc > 1) {
        filepath = argv[1];
    } else {
        filepath = DEFAULT_PATH;
        printf("Using default file path: %s\n", DEFAULT_PATH);
    }

    replace_word_in_file(filepath, word_to_replace, new_word);

    printf("All '%s' replaced with '%s' in file '%s'\n",
           word_to_replace, new_word, filepath);

    return EXIT_SUCCESS;
}