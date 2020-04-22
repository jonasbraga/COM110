#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, maior, menor, meio;
    printf("Insira 3 numeros: ");
    scanf("%f %f %f", &a, &b, &c);
    if (a == b && a == c)
    {
        printf("Numeros iguais!");
    }
    else
    {
        maior = (a >= b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
        menor = (a <= b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
        meio = (maior == a || menor == a) ? ((maior == b || menor == b) ? c : b) : a;
        printf("ordem crescente: %0.2f %0.2f %0.2f", menor, meio, maior);
    }
    return 0;
}