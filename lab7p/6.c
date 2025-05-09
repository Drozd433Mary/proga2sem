#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void* sleepsort_thread(void* arg) {
    int value = *(int*)arg;
    usleep(value * 500000);
    printf("%d\n", value);
    return NULL;
}

int main() {
    int n = 10; 
    int arr[50];

    srand(time(NULL)); 
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 + 1; 
    }

    pthread_t threads[50];

    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, sleepsort_thread, &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Сортировка завершена.\n");
    return 0;
}