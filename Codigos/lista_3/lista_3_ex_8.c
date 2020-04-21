#include <stdio.h>
int main()
{
    int a;
    printf("Hora atual (24h): ");
    scanf("%d", &a);
    if (a >= 5 && a <= 11)
    {
        printf("\n Manhã");
    }
    else if (a >= 12 && a <= 17)
    {
        printf("\n Tarde");
    }
    else
    {
        printf("\n Noite");
    }
    return 0;
}