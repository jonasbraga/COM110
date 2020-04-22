#include <stdio.h>
int main()
{
    int maior, menor, num, i = 0;
    do
    {
        scanf("%d", &num);
        maior = i == 0 ? num : (num > maior ? num : maior);
        menor = i == 0 ? num : (num < menor && num >= 0 ? num : menor);
        i++;
    } while (num >= 0);
    printf("Maior numero: %d \nMenor numero: %d", maior, menor);
    return 0;
}