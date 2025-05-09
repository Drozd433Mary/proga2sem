#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *m_thread(void *arg) {
    for (int i=0; i<5; i++){
        printf("thread: i=%d\n", i);
        sleep(2);
    }
    return NULL;
}

int main(void) {
    pthread_t thread;
    pthread_create(&thread, NULL, m_thread, NULL);
    for (int i=0; i<5; i++) {
        printf("main process: i=%d\n", i);
        sleep(1);
    }
    pthread_join(thread, NULL);
    return 0;
}