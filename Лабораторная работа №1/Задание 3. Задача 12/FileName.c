#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{

    float s1, s2;
    setlocale(LC_ALL, "Russian");
    printf("������� ������� ����� S1 = ");
    scanf("%f", &s1);
    printf("������� ������� �������� S2 = ");
    scanf("%f", &s2);
    if ((sqrt(s2)/2) >= sqrt(s1 /3.14 ))
        printf("���� ���������� � ������� \n");
    else printf("���� �� ���������� � ������� \n"); 

    if (sqrt(s1 / 3.14) >= sqrt(s2) / 2 * sqrt(2))
        printf("������� ���������� � ���� \n");
    else printf("������� �� ���������� � ���� \n");

    return 0;
}