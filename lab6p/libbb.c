#include "libb.h"

void insertionSort(struct Student students[], int size) {
    for (int i = 1; i < size; i++) {
        struct Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].obb < key.obb) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
    }
}

void countingSort(struct Student students[], int size) {
    int max_total = 0;
    for (int i = 0; i < size; i++) {
        if (students[i].obb > max_total) {
            max_total = students[i].obb;
        }
    }
    int count[max_total + 1];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < size; i++) {
        count[students[i].obb]++;
    }
    for (int i = max_total - 1; i >= 0; i--) {
        count[i] += count[i + 1];
    }
    struct Student output[size];
    for (int i = size - 1; i >= 0; i--) {
        output[count[students[i].obb] - 1] = students[i];
        count[students[i].obb]--;
    }
    for (int i = 0; i < size; i++) {
        students[i] = output[i];
    }
}
