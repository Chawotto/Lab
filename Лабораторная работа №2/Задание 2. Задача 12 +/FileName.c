#include <stdio.h>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    float n;
    int sum_s = 0, sum_c = 0;

    printf("Введите положительное целое число n: ");
    scanf("%f", &n);
    if (n > 0) {
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum_s += i * i;
                sum_c += i * i * i;
            }
        }
        printf("Сумма квадратов натуральных четных чисел от 1 до %.1f это %d\n", n, sum_s);
        printf("Сумма кубов натуральных четных чисел от 1 до %.1f это %d\n", n, sum_c);

    }
    else { printf("Ошибка, число n меньше нуля."); }
    return 0;
}