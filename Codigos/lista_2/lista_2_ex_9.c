/*
a) Joao precisa dos valores de a, b e c, correspondente ao (ax2 +- bx +- c = 0)
b) (-b +- √(b2 - 4ac))/2a
c) Nem sempre, pode possuir 1 raiz, 2 raízes ou nenhuma.
d) Se o delta for maior que 0 ele possuirá 2 raízes, se for igual a 0, 1 raíz e caso seja menor
que 0 nenhuma.
*/
#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, delta, x1, x2;
    int flagX1x2 = 1;
    printf("Insira os valores da equação (ax2 +- bx +- c = 0): ");
    scanf("%f %f %f", &a, &b, &c);
    delta = ((b * b) - (4 * a * c));
    if (delta > 0)
    {
        x1 = (b * (-1) + sqrt(delta)) / 2 * a;
        x2 = (b * (-1) - sqrt(delta)) / 2 * a;
    }
    else if (delta == 0)
    {
        x1 = ((b * (-1)) / (2 * a));
        x2 = x1;
    }
    else
    {
        printf("Raízes não existem! Delta negativo.");
        flagX1x2 = 0;
    }
    if (flagX1x2)
    {
        printf(" x1: %0.2f\n x2: %0.2f", x1, x2);
    }

    return 0;
}