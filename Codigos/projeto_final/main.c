#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MAZE_WIDTH 30;
#define MAZE_HEIGHT 30;

void showMenu();
void showGameOver();
void clearScreen();
void showCalcScore();
void showMaze();

int main (){

  showMenu();
  // showGameOver();
  return 0;
}

void showMaze(){

char action = ' ', maze[15][30] = {
    {'@','@','$','@','@','@','@','@','@','@','@','@','@','@','@'},
    {'@','@',' ','@','@','@','@','@','@','@','@','@','@','@','@'},
    {'@','@',' ',' ','@','@','@','@','@','@','@','@','@','@','@'},
    {'@','@','@',' ',' ',' ',' ','@','@','@','@','@','@','@','@'},
    {'@','@','@','@','@','@',' ','@','@','@','@','@','@','@','@'},
    {'@','@','@','@','@','@',' ','@','@','@','@','@','@','@','@'},
    {'@','@','@','@','@','@',' ','@','@','@','@','@','@','@','@'},
    {'@','@','@',' ',' ',' ',' ','@','@','@','@',' ',' ',' ','@'},
    {'@','@','@',' ','@','@','@','@','@','@','@',' ','@',' ','@'},
    {'@','@','@',' ','@','@','@','@','@','@','@',' ','@',' ','@'},
    {'@',' ',' ',' ','@','@','@','@','@','@','@',' ','@',' ','@'},
    {'@',' ','@','@','@','@','@','@','@','@','@',' ','@',' ','@'},
    {'@',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','@',' ','@'},
    {'@','@','@','@','@','@','@','@','@','@','@','@','@',' ','@'},
    {'@','@','@','@','@','@','@','@','@','@','@','@','@',' ','@'}
  };

  while(action != 'z') {
    clearScreen();
    //showCalcScore();
    for(int i = 0; i < 15; i++){
      for(int j = 0; j < 30; j++){
        printf(" %c", maze[i][j]);
      }
      printf("\n");
    }

    printf("\nInsira o movimento: ");
    scanf("%c", &action);

  }
}

void showMenu(){
  char option = ' ';

  clearScreen();
  printf("\n====== BEM VINDO AO LABIRINTO ======");
  printf("\n==                                ==");
  printf("\n==                                ==");
  printf("\n==            START(1)            ==");
  printf("\n==            SAIR (2)            ==");
  printf("\n==                                ==");
  printf("\n==                                ==");
  printf("\n====================================");
  printf("\n");

  scanf("%c", &option);
  if(option == '1'){
    showMaze();
  }
}

void showGameOver(){
  clearScreen();
  printf("\n====================================");
  printf("\n==                                ==");
  printf("\n==                                ==");
  printf("\n==              GAME              ==");
  printf("\n==              OVER              ==");
  printf("\n==                                ==");
  printf("\n==                                ==");
  printf("\n====================================");printf("\n");
}

void clearScreen(){
  system("clear");
}

void showCalcScore(){
  int score = 1;
  printf("Score: %d\n", score);
}
