#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


void cleanup_handler(void* arg) {
    printf("Thread %ld: Очистка.\n", pthread_self());
}

void *p_strings(void *arg) {
    pthread_cleanup_push(cleanup_handler, NULL);
    char **s = (char**)arg; 
    int i = 0;
    while (s[i] != NULL) {
        printf("Thread %ld: %s\n", pthread_self(), s[i]);
        i++;
        sleep(1);
    }
    pthread_cleanup_pop(0);
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
    sleep(2);
    for (int i = 0; i < 4; i++) {
        pthread_cancel(threads[i]);
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }
    printf("УСЕ\n");
    return 0;
}

