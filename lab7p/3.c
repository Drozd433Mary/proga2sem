#include <pthread.h>
#include <stdio.h>

void *p_strings(void *arg) {
    char **s = (char**)arg; 
    int i = 0;
    while (s[i] != NULL) {
        printf("Thread %ld: %s\n", pthread_self(), s[i]);
        i++;
    }
    return NULL;
}

int main() {
    pthread_t threads[4];
    char *s[4][3] = {
        {"Кот", "Простой", NULL},
        {"Котэ", "Ленивый", NULL},
        {"Котяра", "Суровый", NULL},
        {"Котейка", "Милаха", NULL}
    };

    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, p_strings, s[i]);
    }

    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
