// inserindo bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// declarando constantes
const int MAZE_ROWS = 25;
const int MAZE_COLUMNS = 20;
const int KEYS = 3;
const int COINS = 10;
const int PORTA_X = 10;
const int PORTA_Y = 24;

// declarando funções
void showMenu();
void showGameOver();
void showGameClear();
void showMaze();
void clearScreen();

// registro das chaves
struct Key 
{    
  char symbol; 
  int posX; 
  int posY; 
};

// função principal
int main (){
  srand(time(0));     
  rand();
  showMenu();
  return 0;
}

// função para gerar o labirinto e as funcionalidades do jogo
void showMaze(){

  // declaração das chaves, posição do jogador
  int quantKeys = 0, posX = 2, posY = 0;

  // labirinto
  char action = ' ', maze[25][20] = {
      {'@','@',' ','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@'},
      {'@',' ',' ',' ',' ',' ',' ',' ','@',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','@'},
      {'@',' ','@','@','@',' ','@',' ','@',' ','@','@','@',' ','@','@','@','@',' ','@'},
      {'@',' ','@',' ',' ',' ','@',' ','@',' ','@',' ','@',' ',' ',' ',' ','@',' ','@'},
      {'@',' ','@',' ','@','@','@',' ','@',' ','@',' ','@','@','@','@','@','@',' ','@'},
      {'@',' ','@',' ','@',' ','@',' ','@',' ','@',' ',' ',' ',' ',' ',' ',' ',' ','@'},
      {'@',' ','@',' ','@',' ','@',' ',' ',' ','@',' ','@',' ','@','@','@','@','@','@'},
      {'@',' ','@',' ',' ',' ','@',' ','@','@','@',' ','@',' ',' ',' ',' ',' ',' ','@'},
      {'@',' ','@','@','@','@','@',' ','@',' ',' ',' ','@',' ','@','@','@','@',' ','@'},
      {'@',' ',' ',' ','@',' ',' ',' ','@',' ','@','@','@',' ','@',' ',' ',' ',' ','@'},
      {'@','@','@',' ','@',' ','@','@','@',' ','@',' ',' ',' ','@','@','@','@','@','@'},
      {'@',' ','@',' ','@',' ','@',' ',' ',' ','@',' ','@','@','@',' ',' ',' ',' ','@'},
      {'@',' ','@',' ','@',' ','@','@','@','@','@',' ','@',' ',' ',' ','@','@','@','@'},
      {'@',' ',' ',' ','@',' ','@',' ',' ',' ','@',' ','@',' ',' ',' ',' ',' ',' ','@'},
      {'@',' ','@','@','@',' ','@',' ','@',' ','@',' ','@','@','@','@','@','@',' ','@'},
      {'@',' ','@',' ','@',' ',' ',' ','@',' ','@',' ',' ',' ',' ',' ',' ',' ',' ','@'},
      {'@',' ',' ',' ','@',' ','@',' ','@',' ','@','@','@','@',' ','@','@','@',' ','@'},
      {'@','@','@','@','@',' ','@',' ','@',' ',' ',' ',' ','@',' ','@',' ','@',' ','@'},
      {'@',' ',' ',' ',' ',' ','@','@','@','@','@','@',' ','@',' ','@',' ','@',' ','@'},
      {'@',' ','@','@','@',' ',' ',' ',' ',' ',' ','@',' ','@',' ','@',' ','@',' ','@'},
      {'@',' ','@',' ','@',' ','@','@','@','@',' ','@',' ','@',' ','@',' ','@',' ','@'},
      {'@',' ','@',' ','@',' ',' ',' ',' ','@',' ','@',' ','@',' ',' ',' ','@',' ','@'},
      {'@',' ','@',' ','@','@','@','@',' ','@',' ','@',' ','@','@','@','@','@',' ','@'},
      {'@',' ',' ',' ','@',' ',' ',' ',' ','@',' ','@',' ',' ',' ',' ',' ',' ',' ','@'},
      {'@','@','@','@','@','@','@','@','@','@','X','@','@','@','@','@','@','@','@','@'}
  };

  // onde o jogador começa no labirinto
  maze[posY][posX] = '$';

  // cria o vetor key com a quantidade de chaves e com os atributos do registro
  struct Key key[KEYS];
  
  // gera as chaves aleatoriamente no mapa
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
  
  // enquanto o usuário não apertar o comando para sair, o jogo continua
  while(action != 'z') {
    maze[posY][posX] = '$';
    printf("\n");
    clearScreen();

    // mostrar o score do jogador
    int score = 1;
    printf("Score: %d\n", score);

    // mostrar as chaves coletadas
    printf("Chaves coletadas: %d\n\n", quantKeys);

      if(quantKeys == KEYS){
        printf("Você coletou todas as chaves! A casa da bruxa foi aberta!\n\n");
      }else if (quantKeys == KEYS - 1){
        printf("Resta apenas 1 chave para ser coletada!\n\n");
      }else{
        printf("Restam %d chaves para serem coletadas!\n\n", KEYS - quantKeys);
      }

    for(int i = 0; i < MAZE_ROWS; i++){
      for(int j = 0; j < MAZE_COLUMNS; j++){
        printf(" %c", maze[i][j]);
      }
      printf("\n");
    }

    // ações do jogador
    printf("\n Cima (w)\n Esquerda (a)\n Baixo (s)\n Direita (d)\n\n");
    scanf("%c", &action);

    if(action == 'w'){
      if(maze[posY - 1][posX] == ' ' || maze[posY - 1][posX] == '&'){
        maze[posY][posX] = ' ';
        if(maze[posY - 1][posX] == '&') quantKeys++;
        posY--;
      }
    }else if(action == 'a'){
      if(maze[posY][posX - 1] == ' ' || maze[posY][posX - 1] == '&'){
        maze[posY][posX] = ' ';
        if(maze[posY][posX - 1] == '&') quantKeys++;
        posX--;
      }
    }else if(action == 's'){
      if(maze[posY + 1][posX] == ' ' || maze[posY + 1][posX] == '&'){
        maze[posY][posX] = ' ';
        if(maze[posY + 1][posX] == '&') quantKeys++;
        posY++;
      }        
      
    }else if(action == 'd'){
      if(maze[posY][posX + 1] == ' ' || maze[posY][posX + 1] == '&'){
        maze[posY][posX] = ' ';
        if(maze[posY][posX + 1] == '&') quantKeys++;
        posX++;
      }
    }

    // a casa é aberta quando o jogador adquire todas as chaves
    if(quantKeys == KEYS){
      maze[PORTA_Y][PORTA_X] = ' ';
    }    
  }
}

// função para gerar o menu principal
void showMenu(){
  char option = ' ';

  clearScreen();
  printf("\n======== BEM VINDO AO LABIRINTO ========");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n==              START(1)              ==");
  printf("\n==                                    ==");
  printf("\n==              SAIR (2)              ==");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n========================================");printf("\n");

  scanf("%c", &option);
  if(option == '1'){
    showMaze();
  }
}

// função para gerar a tela de fim de jogo
void showGameOver(){
  clearScreen();
  printf("\n========================================");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n==                VOCÊ                ==");
  printf("\n==               PERDEU               ==");
  printf("\n==                 😔                  ==");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n==  aperte x para jogar novamente...  ==");
  printf("\n==                                    ==");
  printf("\n========================================");printf("\n");
}

// função para limpar a tela
void clearScreen(){
  system("clear");
}