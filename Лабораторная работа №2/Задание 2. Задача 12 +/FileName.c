#include <stdio.h>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    float n;
    int sum_s = 0, sum_c = 0;

    printf("������� ������������� ����� ����� n: ");
    scanf("%f", &n);
    if (n > 0) {
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 0) {
                sum_s += i * i;
                sum_c += i * i * i;
            }
        }
        printf("����� ��������� ����������� ������ ����� �� 1 �� %.1f ��� %d\n", n, sum_s);
        printf("����� ����� ����������� ������ ����� �� 1 �� %.1f ��� %d\n", n, sum_c);

    }
    else { printf("������, ����� n ������ ����."); }
    return 0;
}