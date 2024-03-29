#include <stdio.h>
#include <windows.h>


void input_array(int array[], int size);
void fill_array_preset(int array[], int size);
void shift_even_elements(int array[], int size, int k);
void print_array(int array[], int size);

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int array[100];
    int size;
    int k;

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

    printf("Введите количество позиций для сдвига: ");
    scanf("%d", &k);

    shift_even_elements(array, size, k);

    printf("Измененный массив:\n");
    print_array(array, size);

    return 0;
}

void input_array(int array[], int size) {
    printf("Введите %d элементов массива:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
}

void fill_array_preset(int array[], int size) {
    printf("Тестовый массив:\n");
    int test_array[] = { 1,2,3,4,5,6,7,8,9,10 };
    for (int i=0; i < size && i < sizeof(test_array) / sizeof(test_array[0]); i++) {
        array[i] = test_array[i];
        printf("%d ", array[i]);
    }
    printf("\n");
}

void shift_even_elements(int array[], int size, int k) {
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0) {
            int temp = array[i];
            int j = i - k;
            if (j < 0) {
                j += size;
            }
            array[i] = array[j];
            array[j] = temp;
        }
    }
}


void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

