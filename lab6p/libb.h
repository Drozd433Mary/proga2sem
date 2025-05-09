#ifndef LIBB_H
#define LIBB_H

#include <string.h>

#define N 5

struct Student {
    char name[64];
    int matan;
    int fiz;
    int infa;
    int obb;
};

void insertionSort(struct Student students[], int size);
void countingSort(struct Student students[], int size);

#endif
