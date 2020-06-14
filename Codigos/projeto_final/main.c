#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

const int MAZE_ROWS = 25;
const int MAZE_COLUMNS = 25;
const int KEYS = 4;

void showMenu();
void showGameOver();
void clearScreen();
void showCalcScore();
void showMaze();

struct Key 
{ 
  char symbol; 
  int posX; 
  int posY; 
};

int main (){
  srand(time(0));     
  rand();

  showMenu();
  // showGameOver();
  return 0;
}

void showMaze(){
int posX = 2, posY = 0, quantKeys = 0;
char action = ' ', maze[25][25] = {
    {'@','@',' ','@','@','@','@','@','@','@','@','@','@','@','@'},
    {'@',' ',' ',' ',' ',' ',' ',' ','@','@','@','@',' ',' ','@'},
    {'@',' ','@','@','@',' ','@',' ','@','@',' ','@',' ',' ','@'},
    {'@',' ','@',' ','@',' ','@',' ','@','@',' ','@','@',' ','@'},
    {'@',' ','@',' ','@',' ','@',' ',' ',' ',' ',' ',' ',' ','@'},
    {'@',' ','@',' ','@',' ','@','@','@','@','@','@','@',' ','@'},
    {'@',' ','@',' ','@',' ','@','@','@','@','@','@','@',' ','@'},
    {'@',' ','@',' ',' ',' ','@',' ','@',' ',' ',' ',' ',' ','@'},
    {'@',' ','@','@','@','@','@',' ','@',' ','@','@','@','@','@'},
    {'@',' ','@','@','@','@','@',' ','@',' ','@','@','@','@','@'},
    {'@',' ',' ',' ','@',' ',' ',' ',' ',' ','@','@',' ',' ','@'},
    {'@','@','@',' ','@',' ','@','@','@',' ','@','@',' ','@','@'},
    {'@',' ','@',' ','@',' ','@','@','@',' ','@','@',' ','@','@'},
    {'@',' ',' ',' ','@',' ','@',' ','@',' ','@','@',' ','@','@'},
    {'@',' ','@','@','@',' ','@',' ','@',' ',' ',' ',' ','@','@'},
    {'@',' ','@','@','@',' ','@',' ','@','@','@','@',' ','@','@'},
    {'@',' ',' ',' ','@',' ','@',' ',' ','@','@','@',' ','@','@'},
    {'@','@','@',' ','@',' ','@','@',' ','@','@','@',' ','@','@'},
    {'@','@','@',' ','@',' ','@','@',' ','@','@','@',' ',' ','@'},
    {'@',' ',' ',' ','@',' ','@','@',' ',' ',' ','@','@',' ','@'},
    {'@',' ','@','@','@',' ',' ','@','@','@',' ','@','@',' ','@'},
    {'@',' ','@','@','@','@',' ','@','@','@',' ',' ',' ',' ','@'},
    {'@',' ',' ',' ','@','@',' ','@','@','@','@','@',' ','@','@'},
    {'@','@','@','@','@','@','@','@','@','@','@','@',' ','@','@'},
    {'@','@','@','@','@','@','@','@','@','@','@','@','@','@','@'}
  };


  struct Key key[KEYS];
  
  for(int k = 0; k < KEYS; k++){
    int posx1 = 0, posy1 = 0; 
    
    do{
      posx1 = rand() % MAZE_COLUMNS;
      posy1 = rand() % MAZE_ROWS;
    }while(maze[posy1][posx1] != ' ');

    key[k].posX = posx1;
    key[k].posY = posy1;
    key[k].symbol = '&';

    maze[posy1][posx1] = key[k].symbol; 
  }
  
  while(action != 'z') {
  maze[posY][posX] = '$';
    printf("\n");
    clearScreen();

    showCalcScore();
    for(int i = 0; i < MAZE_ROWS; i++){
      for(int j = 0; j < MAZE_COLUMNS; j++){
        printf(" %c", maze[i][j]);
      }
      printf("\n");
    }

    printf("\n Esquerda (a)\n Baixo (s)\n Cima (w)\n Direita (d)\n\n");
    scanf("%c", &action);

    if(action == 'w'){
      if(maze[posY - 1][posX] == ' ' || maze[posY - 1][posX] == '&'){
        maze[posY][posX] = ' ';
        posY--;
        if(maze[posY - 1][posX] == '&') quantKeys++;

      }
    }else if(action == 'a'){
      if(maze[posY][posX - 1] == ' ' || maze[posY][posX - 1] == '&'){
        maze[posY][posX] = ' ';
        posX--;
        if(maze[posY][posX - 1] == '&') quantKeys++;

      }
    }else if(action == 's'){
      if(maze[posY + 1][posX] == ' ' || maze[posY + 1][posX] == '&'){
        maze[posY][posX] = ' ';
        posY++;
        if(maze[posY + 1][posX] == '&') quantKeys++;
      }        
      
    }else if(action == 'd'){
      if(maze[posY][posX + 1] == ' ' || maze[posY][posX + 1] == '&'){
        maze[posY][posX] = ' ';
        posX++;
        if(maze[posY][posX + 1] == '&') quantKeys++;

      }
    }
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
