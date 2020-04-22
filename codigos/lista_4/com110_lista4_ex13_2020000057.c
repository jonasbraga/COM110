#include <stdio.h>
int main()
{
    int i = 0, x = 0, y = 0;
    printf("Insira dois valores: ");
    scanf("%d %d", &x, &y);
    printf("\nOs números entre esses dois valores são: ");
    for (i = x + 1; i > x && i < y; i++)
    {
        printf("%d ", i);
    }
    return 0;
}