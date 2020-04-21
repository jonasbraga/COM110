#include <stdio.h>
int main()
{
    float kg = 0, m = 0;
    printf("Insira seu peso em kilos (exemplo: 50): ");
    scanf("%f", &kg);
    printf("Insira sua altura em metros (exemplo: 1.60): ");
    scanf("%f", &m);
    printf("\nO seu IMC é: %.2f", (kg / (m * m)));
    return 0;
}