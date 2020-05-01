#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    printf("Insira um numero inteiro positivo: ");
    scanf("%d", &a);

    for (int i = 0; i <= a; i++)
    {
        printf("\n3^%d = %0.2lf", i, pow(3, i));
    }

    return 0;
}
