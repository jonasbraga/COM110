#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MAZE_WIDTH 30;
#define MAZE_HEIGHT 30;

void showMenu();
void showGameOver();
void clearScreen();

int main (){
  int labirinto[15][30] = {
    {1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,0,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,0,0,0,0,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1},
    {1,1,1,0,0,0,0,1,1,1,1,0,0,0,0},
    {1,1,1,0,1,1,1,1,1,1,1,0,1,1,0},
    {1,1,1,0,1,1,1,1,1,1,1,0,1,1,0},
    {1,0,0,0,1,1,1,1,1,1,1,0,1,1,0},
    {1,0,1,1,1,1,1,1,1,1,1,0,1,1,0},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}
  };


  showMenu();
  // showGameOver();
  return 0;
}

void showMenu(){
  clearScreen();
  printf("\n====== BEM VINDO AO LIBIRINTO ======");
  printf("\n==                                ==");
  printf("\n==            START(1)            ==");
  printf("\n==            SAIR (2)            ==");
  printf("\n==                                ==");
  printf("\n====================================");
  printf("\n");
}

void showGameOver(){
  clearScreen();
  printf("\n====================================");
  printf("\n==                                ==");
  printf("\n==              GAME              ==");
  printf("\n==              OVER              ==");
  printf("\n==                                ==");
  printf("\n====================================");printf("\n");
}

void clearScreen(){
  system("clear");
}

void showCalcScore(){
  int score = 1;
  printf("Score: %d", score);
}