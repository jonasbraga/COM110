#include <stdio.h>
int main()
{
    float min = 0;
    printf("Insira uma quantidade de minutos: ");
    scanf("%f", &min);
    printf("%.0f minutos tem %.0f segundos", min, min * 60);
    return 0;
}