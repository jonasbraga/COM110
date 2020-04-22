#include <stdio.h>
int main()
{
    float a, b;
    printf("Insira 2 numeros reais: ");
    scanf("%f %f", &a, &b);
    printf("\nAdicao: %0.2f + %0.2f = %0.2f", a, b, a + b);
    printf("\nSubtracao: %0.2f - %0.2f = %0.2f", a, b, a - b);
    printf("\nMultiplicacao: %0.2f * %0.2f = %0.2f", a, b, a * b);
    printf("\nDivisao: %0.2f / %0.2f = %0.2f", a, b, a / b);
    return 0;
}