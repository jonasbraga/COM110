#include <stdio.h>
int main()
{
    float a, salario;
    int aumento;
    printf("Insira o salario: ");
    scanf("%f", &a);
    aumento = (a >= 2000) ? 5 : ((a > 1000) ? 10 : 15);
    printf("Novo salario com aumento de %d\%% : %0.2f", aumento, a + (a * (aumento / 100.0)));
    return 0;
}