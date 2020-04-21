#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, maior, menor;
    printf("Insira 2 numeros: ");
    scanf("%f %f", &a, &b);
    if (a >= b)
    {
        maior = a;
        menor = b;
    }
    else
    {
        menor = a;
        maior = b;
    }
    printf("ordem crescente: %0.2f %0.2f", menor, maior);
    return 0;
}