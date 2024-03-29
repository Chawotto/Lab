#include <stdio.h>
#include <Windows.h>


int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    float sum = 10000;
    float p = 0.03;
    float f_sum = 20000;
    float y = 0;

    while (sum < f_sum) {
        float pl = sum * p;
        sum += pl;
        y++;
    }

    printf("Это займет %.1f года.\n", y);

    return 0;
}