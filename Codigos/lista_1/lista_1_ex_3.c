#include <stdio.h>
int main()
{
    float a;
    printf("Salario: ");
    scanf("%f", &a);
    printf("Novo salario: %0.2f", a + (a * 0.25));
    return 0;
}