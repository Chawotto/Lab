#include <stdlib.h>
#include <stdio.h>

char* concatenateWords(const char* S1, const char* S2, int N1, int N2) {
    int i, j, count;
    int len1 = 0;
    int len2 = 0;

    // Вычисляем длину строки S1
    while (S1[len1] != '\0') {
        len1++;
    }

    // Вычисляем длину строки S2
    while (S2[len2] != '\0') {
        len2++;
    }

    // Выделяем память под новую строку
    int newLen = 0;
    i = 0;
    count = 0;
    while (count < N1 && i < len1) {
        if (S1[i] == ' ') {
            count++;
        }
        newLen++;
        i++;
    }

    j = len2 - 1;
    count = 0;
    while (count < N2 && j >= 0) {
        if (S2[j] == ' ') {
            count++;
        }
        newLen++;
        j--;
    }

    char* result = (char*)malloc((newLen + 1) * sizeof(char));

    // Копируем первые N1 слов из строки S1 в новую строку
    i = 0;
    count = 0;
    int k = 0;
    while (count < N1 && i < len1) {
        result[k] = S1[i];
        k++;
        if (S1[i] == ' ') {
            count++;
        }
        i++;
    }

    // Копируем последние N2 слов из строки S2 в новую строку
    j = len2 - 1;
    count = 0;

    while (count < N2 && j >= 0) {
        if (S2[j] == ' ') {
            count++;
            // Если достигнуто нужное количество слов, выходим из цикла
            if (count == N2) {
                break;
            }
        }
        int wordEnd = j;
        while (wordEnd >= 0 && S2[wordEnd] == ' ') {
            wordEnd--;
        }
        int wordStart = wordEnd;
        while (wordStart >= 0 && S2[wordStart] != ' ') {
            wordStart--;
        }
        wordStart++; // Индекс начала слова
        for (int l = wordStart; l <= wordEnd; l++) {
            result[k] = S2[l];
            k++;
        }
        result[k] = ' '; // Добавляем пробел после слова
        k++;
        j = wordStart - 1;
    }

    result[k] = '\0'; // Добавляем завершающий нулевой символ

    return result;
}
