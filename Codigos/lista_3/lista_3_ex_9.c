#include <stdio.h>
int main()
{
    int x = 0, i = 0;
    for (x = 0; x < 22; x++)
    {
        printf("#");
    }
    for (i = 0; i < 5; i++)
    {
        printf("\n#");
        for (x = 0; x < 20; x++)
        {
            if (x == 3 && i == 2)
            {
                printf("SEJA BEM-VINDO #");
            }
            else
            {
                printf(" ");
            }
        }
        for (x = 0; x < 1 && i != 2; x++)
        {
            printf("#");
        }
    }
    printf("\n");
    for (x = 0; x < 22; x++)
    {
        printf("#");
    }
    return 0;
}