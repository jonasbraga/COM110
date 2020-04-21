#include <stdio.h>
int main()
{
    float a, b, c, maior, menor;
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
        printf("Maior: %0.2f \n Menor: %0.2f", maior, menor);
    }
    return 0;
}