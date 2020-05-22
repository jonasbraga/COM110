#include <stdio.h>

int main()
{
  int numbers[8][8] = {0}, isSimetric = 1;

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      printf("Numero [%d][%d]: ", i, j);
      scanf("%d", &numbers[i][j]);
    }
  }

  printf("\n -- Sua Matriz -- \n");

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      printf(" %d |", numbers[i][j]);
      if(numbers[i][j] != numbers[j][i]){
        isSimetric = 0;
      }
    }
    printf("\n");
  }

  if(isSimetric){
    printf("\n As matrizes são simétricas! \n");
  }else{
    printf("\n As matrizes não são simétricas! \n");
  }
  
  return 0;
}  