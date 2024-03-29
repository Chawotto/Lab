#include <stdio.h>
#include <locale.h>

int main()
{

    float a, b, c;
    setlocale(LC_ALL, "Russian");
    printf("Введите сторону треугольника a = ");
    scanf("%f", &a);
    printf("Введите сторону треугольникаа b = ");
    scanf("%f", &b);
    printf("Введите сторону треугольника c = ");
    scanf("%f", &c);
    if (a == b && b == c && a == c)
        printf("Треугольник равносторонний. ");

    else  printf("Треугольник не является равносторонним. ");

    return 0;
}