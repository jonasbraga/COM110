#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, media;
    char d;
    printf("Insira 3 notas: ");
    scanf("%f %f %f", &a, &b, &c);
    printf(" (a) Média aritmética: (n1 + n2 + n3)/3");
    printf("\n (b) Média geométrica: (n1 ∗ n2 ∗ 3)^1/3");
    printf("\n (c) Média ponderada: ((1 ∗ n1) + (2 ∗ n2) + (3 ∗ n3))/6 \n");
    scanf(" %c", &d);
    if (d == 'a')
    {
        media = (a + b + c) / 3;
    }
    else if (d == 'b')
    {
        media = pow((a * b * c), 1 / 3);
    }
    else
    {
        media = ((1 * a) + (2 * b) + (3 * c)) / 6;
    }
    printf("\nMedia: %0.2f", media);
    return 0;
}