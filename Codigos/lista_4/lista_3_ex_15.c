#include <stdio.h>

int main()
{
    int n = 0, i = 0, j = 0;
    printf("Insira um valor maior ou igual a 2: ");
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}