#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void showMenu();
void drawSquare();
void drawRectangle();
void drawTriangle();
void drawEquilateralTriangle();
void drawDiamond();

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
        drawRectangle();
      break;
      case 3:
        drawTriangle();
      break;
      case 4:
        drawEquilateralTriangle();
      break;
      case 5:
        drawDiamond();
      break;
      case 6:
        printf("Até mais!\n\n");
      break;
      default:
      printf("Opção nao encontrada!\n\n");
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
  printf("\n##  5. Losango\t\t\t\t\t\t\t\t ##");
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
  side += 2;
  for(int i = 1; i <= side; i++){
    for(int j = 1; j <= side; j++){
      if(i == 1 || i == side){
          if(j == 1){
            int border = ((side-2)*2 + 3);
            while(border--){
              printf("_");
            }
          }
      }else{
        if(j == 1 || j == side){
          printf("| ");          
        }else{
          printf("@ ");
        }   
      }
    }  
    printf("\n");
  }
}

void drawRectangle(){
  int line = 0, column = 0;
  printf("\nEntre com a base e a altura do retângulo: ");
  scanf("%d %d", &column, &line);
  line += 2;
  column += 2;
  for(int i = 1; i <= line; i++){
    for(int j = 1; j <= column; j++){
      if(i == 1 || i == line){
          if(j == 1){
            int border = ((column-2)*2 + 3);
            while(border--){
              printf("_");
            }
          }
      }else{
        if(j == 1 || j == column){
          printf("| ");          
        }else{
          printf("@ ");
        }   
      }
    }  
    printf("\n");
  }
}

void drawTriangle(){
  int line = 0, column = 0;
  printf("\nEntre com a altura do triângulo: ");
  scanf("%d", &line);
  line += 3;
  for(int i = 1; i <= line; i++){
    
    int spaces = (line-i);
    while(spaces--){
      printf(" ");
    }
    if(i == 1){
      printf(".");
    }else if(i == 2){
      printf("/ \\");
    }else {

      int j = 1;
      while(j <= i){
        if(j == 1){
          if(i == line){
            printf("/_");
          }else{
            printf("/ ");
          }
        }else if(j == i){
          printf("\\");
        }else if(i == line){
          printf("__");
        }else{
          printf("@ ");
        } 
        j++;
      }      
    }
    printf("\n");
  }
}

void drawEquilateralTriangle(){

}

void drawDiamond(){

}
