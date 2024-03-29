//
// Created by alexe on 24.12.2023.
//

#include <stdio.h>

int myStrLen(char* str){
    int len = 0;
    while (str[len] != '\0')
        len++;
    return len;
}

void printLongestWord(const char* str, int len) {
    char longestWord[len];
    char currentWord[len];
    int longestLength = 0;
    int currentLength = 0;
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            currentWord[j++] = str[i];
            currentLength++;
        }
        else {
            currentWord[j] = '\0';
            if (currentLength > longestLength) {
                longestLength = currentLength;
                for (int k = 0; k < currentLength; k++) {
                    longestWord[k] = currentWord[k];
                }
                longestWord[currentLength] = '\0';
            }
            j = 0;
            currentLength = 0;
        }
        i++;
    }

    currentWord[j] = '\0';
    if (currentLength > longestLength) {
        longestLength = currentLength;
        for (int k = 0; k < currentLength; k++) {
            longestWord[k] = currentWord[k];
        }
        longestWord[currentLength] = '\0';
    }

    printf("Самое длинное слово: %s\n", longestWord);
}
