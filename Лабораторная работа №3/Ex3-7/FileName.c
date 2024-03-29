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

    printf("Введите размер массива (до 100): ");
    scanf("%d", &size);

    printf("Выберите тип тестовых данных:\n");
    printf("1. Ввод с клавиатуры\n");
    printf("2. Тестовый массив\n");
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
        printf("Неверный выбор\n");
        return 1;
    }

    compare(array, size, max_value, max_count);


    return 0;
}
void fill_array_preset(int array[], int size) {
    printf("Тестовый массив:\n");
    int test_array[] = { 1,2,3,2,5,2,7,2,9,10 };
    for (int i = 0; i < size && i < sizeof(test_array) / sizeof(test_array[0]); i++) {
        array[i] = test_array[i];
        printf("%d ", array[i]);
    }
    printf("\n");
}
void input_array(int array[], int size) {
    printf("Введите %d элементов массива:\n", size);
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
        printf("В массиве все элементы встречаются один раз\n"); 
    }
    else { 
        printf("Наиболее часто встречающееся значение: %d\n", max_value);
    }
}