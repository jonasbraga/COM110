#include <stdio.h>
int main()
{
    int a = 0;
    while (++a <= 20)
        printf(" %d ", a);
    printf("\n");
    while (--a)
        printf(" %d ", a);
    printf("\n");
    while (++a <= 20)
        if (a % 2)
            printf(" %d ", a);
    return 0;
}