#include "palind.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int palind(char *str) {
    int len = strlen(str);
    int t_len = 2 * len + 3;
    char *T = malloc(t_len);
    T[0] = '$';
    T[t_len - 1] = '@';
    
    for (int i = 0; i < len; i++) {
        T[2 * i + 1] = '#';
        T[2 * i + 2] = tolower(str[i]);
    }
    T[2 * len + 1] = '#';
    T[t_len] = '\0';

    int *P = malloc(t_len * sizeof(int));
    for (int i = 0; i < t_len; i++) P[i] = 0;
    
    int C = 0, R = 0;
    for (int i = 1; i < t_len - 1; i++) {
        int mirror = 2 * C - i;
        if (i < R) P[i] = (R - i < P[mirror]) ? R - i : P[mirror];
        while (T[i + P[i] + 1] == T[i - P[i] - 1]) P[i]++;
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    int palind = 0;
    for (int i = 1; i < t_len - 1; i++) {
        if (P[i] >= len) {
            palind = 1;
            break;
        }
    }

    free(T);
    free(P);
    return palind;
}
