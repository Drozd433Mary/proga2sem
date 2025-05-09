// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <time.h>
// #define N 10000
// struct Student {
//     char name[64];
//     int matan;
//     int fiz;
//     int infa;
//     int obb;
// };
// struct Student addStudent(const char *name, int matan, int fiz, int infa) {
//     struct Student newStudent;
//     strncpy(newStudent.name, name, 64);
//     newStudent.matan = matan;
//     newStudent.fiz = fiz;
//     newStudent.infa = infa;
//     newStudent.obb = matan + fiz + infa;
//     return newStudent;
// }
// void printStudentInfo(struct Student student) {
//     printf("Имя: %s, Математика: %d, Физика: %d, Информатика: %d, Общий балл: %d\n",
//            student.name, student.matan, student.fiz, student.infa, student.obb);
// }

// // Сортировка вставками по убыванию общего балла
// void insertionSort(struct Student students[], int size) {
//     for (int i = 1; i < size; i++) {
//         struct Student key = students[i];
//         int j = i - 1;

//         // сдвигаем элементы вправо если они меньше key
//         while (j >= 0 && students[j].obb < key.obb) {
//             students[j + 1] = students[j];
//             j--;
//         }
//         students[j + 1] = key;
//     }
// }

// int main() {
//     srand(time(NULL));
//     struct Student students[N];
//     for (int i = 0; i < N; i++) {
//         char name[64];
//         sprintf(name, "Student%d", i + 1);
//         students[i] = addStudent(name, rand() % 101, rand() % 101, rand() % 101);
//     }

//     // Вывод студентов до сортировки
//     printf("Студенты до сортировки:\n");
//     for (int i = 0; i < N; i++) {
//         printStudentInfo(students[i]);
//     }
//     insertionSort(students, N);

//     // Вывод студентов после сортировки
//     printf("\nСтуденты после сортировки:\n");
//     for (int i = 0; i < N; i++) {
//         printStudentInfo(students[i]);
//     }

//     return 0;
// }






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#define N 5

struct Student {
    char name[64];
    int matan;
    int fiz;
    int infa;
    int obb;
};


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

// сортировка вставками
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

// сортировка CountingSort 
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

// временя выполнения
double getCurrentTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.0;
}

int main() {
    srand(time(NULL)); // генератор случайных чисел

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
    double startTime = getCurrentTime();
    insertionSort(students, N);
    double endTime = getCurrentTime();
    printf("\nВремя сортировки вставками: %.6f секунд\n", endTime - startTime);

    printf("\nСтуденты после сортировки вставками:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }

    startTime = getCurrentTime();
    countingSort(students, N);
    endTime = getCurrentTime();
    printf("\nВремя сортировки CountingSort: %.6f секунд\n", endTime - startTime);

    printf("\nСтуденты после сортировки CountingSort:\n");
    for (int i = 0; i < N; i++) {
        printStudentInfo(students[i]);
    }
    return 0;
}