#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{

    float s1, s2;
    setlocale(LC_ALL, "Russian");
    printf("¬ведите площадь круга S1 = ");
    scanf("%f", &s1);
    printf("¬ведите площадь квадрата S2 = ");
    scanf("%f", &s2);
    if ((sqrt(s2)/2) >= sqrt(s1 /3.14 ))
        printf(" руг поместитс€ в квадрат \n");
    else printf(" руг не поместитс€ в квадрат \n"); 

    if (sqrt(s1 / 3.14) >= sqrt(s2) / 2 * sqrt(2))
        printf(" вадрат поместитс€ в круг \n");
    else printf(" вадрат не поместитс€ в круг \n");

    return 0;
}