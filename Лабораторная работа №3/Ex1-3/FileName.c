#include <windows.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNING


void input_array(double array[], int size);
void fill_array_preset(double array[], int size);
float max_element(double array[], int size, double max);
float sum(double array[], int size, double sum_a);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    double const array[100];
    int size;
    double sum_a=0;
    double max=0;
    printf("������� ������ ������� (�� 100): ");
    scanf("%d", &size);

    printf("�������� ��� �������� ������:\n");
    printf("1. ���� � ����������\n");
    printf("2. �������� ������\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        input_array(array, size);
        break;
    case 2:
        fill_array_preset(array, size);
        break;
    default:
        printf("�������� �����\n");
        return 1;
    }

    max_element(array, size, max);

    sum( array,size, sum_a);

    return 0;
}
void fill_array_preset(double array[], int size) {
    printf("�������� ������:\n");
    double test_array[] = { 1.2,2.1,3.6,2.1,5.5,2,7.5,2.9,9.1,10 };
    for (int i = 0; i < size && i < sizeof(test_array) / sizeof(test_array[0]); i++) {
        array[i] = test_array[i];
        printf("%.1f  ", array[i]);
    }
    printf("\n");
}

void input_array(double array[], int size) {
    printf("������� %d ��������� �������:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%lf", &array[i]);
    }
}

float max_element(double array[], int size, double max) {
    max = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    printf("������������ ������� �������: %.2f\n", max);
}

float sum(double array[], int size, double sum_a ) {
    int last_positive = -1;
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            last_positive = i;
        }
    }
    if (last_positive == -1) {
        printf("� ������� ��� ������������� ���������\n");
    }
    else {
        for (int i = 0; i < last_positive; i++) {
            sum_a += array[i];
        }
        printf("����� ��������� �� ���������� �������������� ��������: %.2f\n", sum_a);
    }
}