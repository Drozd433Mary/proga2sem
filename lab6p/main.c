#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "libb.h"

struct Student addStudent(const char *name, int matan, int fiz, int infa) {
    struct Student newStudent;
    strncpy(newStudent.name, name, 64);
    newStudent.matan = matan;
    newStudent.fiz = fiz;
    newStudent.infa = infa;
    newStudent.obb = matan + fiz + infa;
    return newStudent;
}

void printStudentInfo(struct Student student) {
    printf("Имя: %s, Математика: %d, Физика: %d, Информатика: %d, Общий балл: %d\n",
           student.name, student.matan, student.fiz, student.infa, student.obb);
}

double getCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}

int main() {
    srand(time(NULL)); 

    struct Student students[N];

    for (int i = 0; i < N; i++) {
        char name[64];
        sprintf(name, "Student%d", i + 1);
        students[i] = addStudent(name, rand() % 101, rand() % 101, rand() % 101);
    }

    printf("Студенты до сортировки:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    struct Student students_copy[N];
    for (int i = 0; i < N; i++) {
        students_copy[i] = students[i];
    }

    double startTime = getCurrentTime();
    insertionSort(students, N);
    double endTime = getCurrentTime();
    printf("\nВремя сортировки вставками: %.6f секунд\n", endTime - startTime);

    printf("\nСтуденты после сортировки вставками:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    startTime = getCurrentTime();
    countingSort(students_copy, N);
    endTime = getCurrentTime();
    printf("\nВремя сортировки CountingSort: %.6f секунд\n", endTime - startTime);

    printf("\nСтуденты после сортировки CountingSort:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students_copy[i]);
    }

    return 0;
}
