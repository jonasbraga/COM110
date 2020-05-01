#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void showMenu();
void drawSquare();
int main(){
  
  int opcao = 0;

  while(opcao != 6){
    showMenu();
    scanf("%d", &opcao);
    system("clear");
    switch(opcao){
      case 1:
        drawSquare();
      break; 
      case 2:

      break;
      case 3:
      break;
      case 4:
      break;
      case 5:
      break;
      case 6:
      break;
    }
  }



  return 0;
}


void showMenu(){
  printf("\n###############################################");
  printf("\n############### MENU DE OPÇÕES ################");
  printf("\n###############################################");
  printf("\n## \t\t\t\t\t\t\t\t\t\t\t ##");
  printf("\n## Escolha uma forma geometrica: \t\t\t ##");
  printf("\n## \t\t\t\t\t\t\t\t\t\t\t ##");
  printf("\n##  1. Quadrado \t\t\t\t\t\t\t ##");
  printf("\n##  2. Retângulo\t\t\t\t\t\t\t ##");
  printf("\n##  3. Triângulo Equilátero \t\t\t\t ##");
  printf("\n##  4. Triângulo Retângulo (catetos iguais)  ##");
  printf("\n##  5. Outra \t\t\t\t\t\t\t\t ##");
  printf("\n##  6. Sair \t\t\t\t\t\t\t\t ##");
  printf("\n## \t\t\t\t\t\t\t\t\t\t\t ##");
  printf("\n###############################################");
  printf("\n###############################################");
  printf("\n\nOpção: ");
}

void drawSquare(){
  int side = 0;
  printf("\nEntre com o lado do quadrado: ");
  scanf("%d", &side);
  for(int i = 1; i <= side; i++){
    for(int j = 1; j <= side; j++){
      if(i == 1 || i == side){
          printf("_");
      }else{
        if(j == 1 || j == side){
          printf("|");          
        }else{
          printf("@");
        }   
      }
    }  
    printf("\n");
  }
}


