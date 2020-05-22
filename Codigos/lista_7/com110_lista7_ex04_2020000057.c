#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main()
{
  srand(time(0));     
  rand();

  int randomNumbers[5][7] = {0}, smallNumberColumn = 0, smallAux = 0, isPontoSela = 1, hasPontoSela = 0;

  printf("\n -- Matriz aleatória -- \n");

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 7; j++){
      randomNumbers[i][j] = rand() % 90 + 10;
      printf(" %d |", randomNumbers[i][j]);
    }
    printf("\n");
  }

  printf("\n");

  for(int i = 0; i < 5; i++){
    
    for(int j = 0; j < 7; j++){
      if(randomNumbers[i][j] < smallAux || j == 0){
        smallAux = randomNumbers[i][j];
        smallNumberColumn = j;
      }
    }

    isPontoSela = 1;

    for(int k = 0; k < 5; k++){
      if(randomNumbers[k][smallNumberColumn] < smallAux){
        isPontoSela = 0;
        break;
      }
    }

    if(isPontoSela){
      hasPontoSela = 1;
      printf("O campo [%d][%d] = %d é um ponto de sela!\n", i, smallNumberColumn, smallAux);
    }
  }

  if(!hasPontoSela){
    printf("A matriz não possui nenhum ponto de sela.\n");
  }

  return 0;
}