#include <windows.h>
#include <stdio.h>

void input_array(int array[], int size);
void fill_array_preset(int array[], int size);
float compare(int array[], int size);
    int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int array[100];
    int size;
    int max_count = 0;
    int max_value = 0;

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

    compare(array, size, max_value, max_count);


    return 0;
}
void fill_array_preset(int array[], int size) {
    printf("�������� ������:\n");
    int test_array[] = { 1,2,3,2,5,2,7,2,9,10 };
    for (int i = 0; i < size && i < sizeof(test_array) / sizeof(test_array[0]); i++) {
        array[i] = test_array[i];
        printf("%d ", array[i]);
    }
    printf("\n");
}
void input_array(int array[], int size) {
    printf("������� %d ��������� �������:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}
float compare(int array[], int size, int max_value, int max_count) {
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = i + 1; j < size; j++) {
            if (array[i] == array[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            max_value = array[i];
        }

    }
    if (max_count == 0) { 
        printf("� ������� ��� �������� ����������� ���� ���\n"); 
    }
    else { 
        printf("�������� ����� ������������� ��������: %d\n", max_value);
    }
}