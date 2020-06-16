// inserindo bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// declarando constantes
const int MAZE_ROWS = 25;
const int MAZE_COLUMNS = 20;
const int KEYS = 4;
const int COINS = 10;

// declarando funções
void showMenu();
void showGameOver();
void showGameClear();
void showCalcScore();
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

  // declaração das chaves, posição do jogador e da porta de saida
  int quantKeys = 0, posX = 2, posY = 0, portaX = 10, portaY = 24;

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

    showCalcScore();
    printf("Chaves coletadas: %d\n\n", quantKeys);

      if(quantKeys == KEYS){
        printf("Você coletou todas as chaves! A saída da floresta foi desbloqueada!\n\n");
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

    // abre a porta de saida quando o jogador adquire todas as chaves
    if(quantKeys == 4){
      maze[portaY][portaX] = ' ';
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

/*
ʕ•ᴥ•ʔ  checklist  ʕ•ᴥ•ʔ

gcc ./Codigos/projeto_final/Versão\ 1/main.c -o exe -lm && ./exe

fantasminha: 
[ ] => gamer over quando relar no fantasminha
[ ] => deixar 4* fixos no mapa
[ ] => Fazer logica para ele sumir de loop em loop
[ ] => Fazer logica para ele spawnar aleatoriamente

unicode: 
[ ] => arrumar iconezinho pra tudo
[ ] => colocar nesse main.c
[ ] => ajustar os if usando os codigos do unicode

moedinha:
[ ] => 10 moedinhas random no mapa
[ ] => if posBonequinho == posMoedinha {score++}

labirinto: 
[x] => aumentar ele (25x20 tá ok)

ʕっ•ᴥ•ʔっ me da um abraço po favo <3
*/
