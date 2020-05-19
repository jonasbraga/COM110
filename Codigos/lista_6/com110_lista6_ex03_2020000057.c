#include <stdio.h>
int main()
{
  int i = 0, diceNumbers[7] = {}, numbersDrawn[20] = {}, aux = 0, j = 0;
  while(++i <= 20){
    do{
      printf("Entre com o %d numero: ", i);
      scanf("%d", &aux);
    }while(!(aux >= 1 && aux <= 6));
    numbersDrawn[i] = aux;
    diceNumbers[aux]++; 
  }

  while(++j <= 6){
    printf("Numero %d foi sorteado %d vezes!\n", j, diceNumbers[j]);
  }

  return 0;
}