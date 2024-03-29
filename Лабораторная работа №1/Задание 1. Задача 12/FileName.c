#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{

    float a, b, c;
    setlocale(LC_ALL, "Russian");
    printf("Введите радиус основания конуса a = ");
    scanf("%f", &a);
    printf("Введите длину ребра конуса b = ");
    scanf("%f", &b);
    printf("Введите высоту конуса c = ");
    scanf("%f", &c);
    float s, v, n;
    s = 3.14 * a * b;
    printf("Площадь боковой поверхности конуса = %.3f \n", s);
    v = 3.14 * a * a * c / 3;
    printf("Объём конуса = %.3f \n", v);
    n = s + (a*3.14*a);
    printf("Площадь полной поверхности конуса = %.3f \n", n);
    return 0;
}