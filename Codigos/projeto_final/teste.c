#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include <wchar.h>
#include <locale.h>

#define MAZE_WIDTH 30;
#define MAZE_HEIGHT 30;

void showMenu();
void showGameOver();
void clearScreen();
void showCalcScore();
void showMaze();
void showMazeUnicode();

int main (){
  clearScreen();
  
  showMaze();

  // showMenu();
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

  while(1) {
    clearScreen();
    showCalcScore();
    for(int i = 0; i < 15; i++){
      for(int j = 0; j < 30; j++){
        printf(" %c", maze[i][j]);
      }
      printf("\n");
    }

    printf("\nInsira o movimento: ");
    scanf("%c", &action);

    if(action == 'z'){
      showMenu();
      break;
    }
  }
}

void showMenu(){
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

/*
ʕ•ᴥ•ʔ  checklist  ʕ•ᴥ•ʔ

repl.it: gcc ./Codigos/projeto_final/Versão1/main.c -o exe -lm && ./exe

fantasminha: 
[ ] => if (posJogador == posFantasma) {showGameOver}
[ ] => deixar 4* fixos no mapa
[ ] => fazer logica para ele sumir de loop em loop
[ ] => fazer logica para ele spawnar aleatoriamente

unicode: 
[ ] => arrumar desenhinho pra tudo
[ ] => ajustar os ifs e etc usando o formato do unicode

moedinha:
[ ] => fazer 10 moedas spawnando aleatorimente no mapa
[ ] => if (posJogador == posMoeda) {score++}

*/

/* 
void showMazeUnicode(){

  clearScreen();
  // joao
  // maria
  // chave 0x1F5DD   
  // arvore 0x1F332
  // mao dada U+1F46B

  setlocale(LC_CTYPE, "");
  wchar_t maze[15][30] = {
    {0x1F332,0x1F332,0x1F466,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332},
    {0x1F332,0x1F332,0x0020,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332},
    {0x1F332,0x1F332,0x0020,0x0020,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332},
    {0x1F332,0x1F332,0x1F332,0x0020,0x0020,0x0020,0x0020,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332},
    {0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x0020,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332},
    {0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x0020,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332},
    {0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x0020,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332},
    {0x1F332,0x1F332,0x1F332,0x0020,0x0020,0x0020,0x0020,0x1F332,0x1F332,0x1F332,0x1F332,0x0020,0x0020,0x0020,0x1F332},
    {0x1F332,0x1F332,0x1F332,0x0020,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x0020,0x1F332,0x0020,0x1F332},
    {0x1F332,0x1F332,0x1F332,0x0020,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x0020,0x1F332,0x0020,0x1F332},
    {0x1F332,0x0020,0x0020,0x0020,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x0020,0x1F332,0x0020,0x1F332},
    {0x1F332,0x0020,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x0020,0x1F332,0x0020,0x1F332},
    {0x1F332,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x0020,0x1F332,0x0020,0x1F332},
    {0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x0020,0x1F332},
    {0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x1F332,0x0020,0x1F332}
  };

  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 30; j++){
      wprintf(L" %lc", maze[i][j]);
    }
    wprintf("\n");
  }
} */