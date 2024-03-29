#include <stdio.h>
#include <stdlib.h>
#include "task 1.h"
#include "task 2.h"

int main(int argc, char *argv[]) {
    system("chcp 65001");
    if (argc != 2) {
        printf("Пожалуйста, укажите путь к файлу в качестве аргумента командной строки.\n");
        return 1;
    }
    int choice;
    do {
        printf("[1]-задача №1, [2]-задача №2, [3]-Вывод содержимого файла, [4]-выход из программы : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                task1(argv[1]);
                break;
            case 2:
                task2(argv[1]);
                break;
            case 3:
                printf("Вывод содержимого файла.\n");
                printFileContents (argv[1]);
                break;
            case 4:
                printf("Выход из программы.\n");
                break;
            default:
                printf("Неверный выбор!\n");
                break;
        }
    } while(choice != 4);

    return 0;
}
