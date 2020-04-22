#include <stdio.h>
int main()
{
    int a;
    printf("Insira a idade: ");
    scanf("%d", &a);
    if (a < 16)
    {
        printf("Nao eleitor.");
    }
    else if (a >= 18 && a <= 65)
    {
        printf("Eleitor obrigatorio.");
    }
    else
    {
        printf("Eleitor facultativo.");
    }
    return 0;
}