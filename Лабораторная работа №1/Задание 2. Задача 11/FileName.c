#include <stdio.h>
#include <locale.h>

int main()
{

    float a, b, c;
    setlocale(LC_ALL, "Russian");
    printf("������� ������� ������������ a = ");
    scanf("%f", &a);
    printf("������� ������� ������������� b = ");
    scanf("%f", &b);
    printf("������� ������� ������������ c = ");
    scanf("%f", &c);
    if (a == b && b == c && a == c)
        printf("����������� ��������������. ");

    else  printf("����������� �� �������� ��������������. ");

    return 0;
}