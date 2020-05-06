#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void showMenu();
void drawSquare();
void drawRectangle();
void drawTriangle();
void drawRectangleTriangle();
void drawParallelogram();

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
        drawRectangleTriangle();
      break;
      case 5:
        drawParallelogram();
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
  printf("\n##  5. Paralelogramo\t\t\t\t\t\t ##");
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

  printf("AREA: %d\n", side*side);  
  printf("PERIMETRO: %d\n\n", side*4);  

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
  
  printf("AREA: %d\n", line*column);  
  printf("PERIMETRO: %d\n\n", line*2+column*2);  
  
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
  int line = 0;
  printf("\nEntre com o lado do triângulo: ");
  scanf("%d", &line);

  float area = (line*(sqrt(pow(line, 2) - pow(line/2.0, 2)))/2.0);
  printf("AREA: %f\n", area);  
  printf("PERIMETRO: %d\n\n", line*3);  
  
  
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

void drawRectangleTriangle(){
  int line = 0;
  printf("\nEntre com o cateto do triângulo: ");
  scanf("%d", &line);

  float area = (line * line) / 2;
  printf("AREA: %f\n", area);  
  printf("PERIMETRO: %f\n\n", line*2 + (sqrt(pow(line, 2) + pow(line, 2))));  
  
  line += 3;
  for(int i = 1; i <= line; i++){
    
    int spaces = (line-i) * 2;
    while(spaces--){
      printf(" ");
    }
    if(i == 1){
      printf(".");
    }else if(i == 2){
      printf("/ |");
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
          printf("|");
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

void drawParallelogram(){
int line = 0, column = 0;
  printf("\nEntre com a base e a altura do paralelogramo: ");
  scanf("%d %d", &column, &line);
  
  printf("AREA: %d\n", line*column);  
  printf("PERIMETRO: %d\n\n", line*2+column*2);  
  
  line += 2;
  column += 2;
  for(int i = 1; i <= line; i++){

    int spaces = (line-i) * 2;
    while(spaces--){
      printf(" ");
    }
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
          printf("/ ");          
        }else{
          printf("@ ");
        }   
      }
    }  
    printf("\n");
  }
}
