#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{

    float a, b, c;
    setlocale(LC_ALL, "Russian");
    printf("������� ������ ��������� ������ a = ");
    scanf("%f", &a);
    printf("������� ����� ����� ������ b = ");
    scanf("%f", &b);
    printf("������� ������ ������ c = ");
    scanf("%f", &c);
    float s, v, n;
    s = 3.14 * a * b;
    printf("������� ������� ����������� ������ = %.3f \n", s);
    v = 3.14 * a * a * c / 3;
    printf("����� ������ = %.3f \n", v);
    n = s + (a*3.14*a);
    printf("������� ������ ����������� ������ = %.3f \n", n);
    return 0;
}