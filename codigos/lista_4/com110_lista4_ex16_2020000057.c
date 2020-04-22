#include <stdio.h>
int main()
{
    int a, b, i = -1;
    printf("Entre com 2 numero inteiros: ");
    scanf("%d %d", &a, &b);
    if(b >= a) {
      while (++i <= 10)
      {
          for (int j = a; j <= b; j++)
          {
              printf(" %d x %d = %d \t", j, i, j * i);
          }
          printf("\n");
      }
    }else{
      printf("O segundo numero deve ser maior que o primeiro.\n");
    }
    return 0;
}