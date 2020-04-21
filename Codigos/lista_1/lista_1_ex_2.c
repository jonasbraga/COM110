#include <stdio.h>
int main()
{
    float a, b, c, d, e, f;

    printf("Valores: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("Pesos: ");
    scanf("%f %f %f", &d, &e, &f);
    printf("Media ponderada: %0.2f", (a * d + b * e + c * f) / (d + e + f));

    return 0;
}