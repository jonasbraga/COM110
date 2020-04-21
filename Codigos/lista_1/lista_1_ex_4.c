#include <stdio.h>
int main()
{
    float a, b;
    printf("Salario: ");
    scanf("%f", &a);
    printf("Percentual de aumento: ");
    scanf("%f", &b);
    printf("Novo salario: %0.2f", a + (a * (b / 100)));
    return 0;
}