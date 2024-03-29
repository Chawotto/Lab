#include <stdlib.h>
#include <stdio.h>
#include "task2.h"

void task2 (int argc, char** argv) {
    const char* S1 = argv[2];
    const char* S2 = argv[3];
    int N1 = atoi(argv[4]);
    int N2 = atoi(argv[5]);

    char* result = concatenateWords(S1, S2, N1, N2);
    printf("Результат: %s\n", result);
    free(result);
    exit(1);
}
