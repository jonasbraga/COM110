#include <stdio.h>
int main()
{
    float a, b, c, d, media;
    printf("Insira 4 notas: ");
    scanf("%f %f %f %f", &a, &b, &c, &d);
    media = (a + b + c + d) / 4;
    if (media >= 6)
        printf("Aprovado com media %0.2f!", media);
    else
        printf("Reprovado com media %0.2f!", media);
    return 0;
}