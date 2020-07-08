// gcc ./Codigos/projeto_final/VersãoFinal/main.c -o exe -lm && ./exe

// inserindo bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// declarando constantes
const int MAZE_ROWS = 26;
const int MAZE_COLUMNS = 20;
const int KEYS = 3;
const int CANDY = 10;
const int WITCH = 1;
const int PORTA_X = 10;
const int PORTA_Y = 24;
const char FILEPATH[] = "/home/runner/COM110/Codigos/projeto_final/VersãoFinal/ranking.txt";
const char SPLIT_DELIMITER[] = ";";

// declarando funções
void showMenu();
void showGameStory();
void showGameOverTrap(char username[]);
void showGameOverWitch(char username[]);
void showGameClear(char username[], int score);
void showMaze(char username[]);
void insertUsername();
void showRanking();
void clearScreen();
void saveScore(char username[], int score);
void setPermissionFile();

// registro das chaves
struct Key 
{    
  char symbol; 
  int posX; 
  int posY; 
};

// registro dos doces
struct Candy 
{    
  char symbol; 
  int posX; 
  int posY; 
};

// registro da bruxa
struct Witch 
{    
  char symbol; 
  int posX;
  int posY;
};

// função principal
int main (){
  srand(time(0));     
  rand();
  setPermissionFile();
  showGameStory();
  return 0;
}

// função para gerar o labirinto e as funcionalidades do jogo
void showMaze(char username[]){

  // declaração das chaves, posição do jogador
  int quantKeys = 0, posX = 2, posY = 0;
  int posXelement = 0, posYelement = 0; 

  char action = ' ';
  
  // labirinto
  char maze[26][20] = {
      {'@','@',' ','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@'},
      {'@',' ',' ',' ',' ',' ',' ',' ','@',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','@'},
      {'@',' ','@','@','@',' ','@',' ','@',' ','@','@','@',' ','@','@','@','@',' ','@'},
      {'@',' ','@',' ',' ',' ','@',' ','@',' ','@','T','@',' ',' ',' ','T','@',' ','@'},
      {'@',' ','@',' ','@','@','@',' ','@',' ','@',' ','@','@','@','@','@','@',' ','@'},
      {'@',' ','@',' ','@','T','@',' ','@',' ','@',' ',' ',' ',' ',' ',' ',' ',' ','@'},
      {'@',' ','@',' ','@',' ','@',' ',' ',' ','@',' ','@',' ','@','@','@','@','@','@'},
      {'@',' ','@',' ',' ',' ','@',' ','@','@','@',' ','@',' ',' ',' ',' ',' ',' ','@'},
      {'@',' ','@','@','@','@','@',' ','@',' ',' ',' ','@',' ','@','@','@','@',' ','@'},
      {'@',' ',' ',' ','@',' ',' ',' ','@',' ','@','@','@',' ','@',' ',' ',' ',' ','@'},
      {'@','@','@',' ','@',' ','@','@','@',' ','@',' ',' ',' ','@',' ','@','@','@','@'},
      {'@','T','@',' ','@',' ','@',' ',' ',' ','@',' ','@','@','@',' ',' ',' ','T','@'},
      {'@',' ','@',' ','@',' ','@','@','@','@','@',' ','@',' ','@',' ','@','@','@','@'},
      {'@',' ',' ',' ','@',' ','@',' ',' ',' ','@',' ','@',' ',' ',' ',' ',' ',' ','@'},
      {'@',' ','@','@','@',' ','@',' ','@',' ','@',' ','@','@','@','@','@','@',' ','@'},
      {'@',' ','@','T','@',' ',' ',' ','@',' ','@',' ',' ',' ',' ',' ',' ',' ',' ','@'},
      {'@',' ',' ',' ','@',' ','@',' ','@',' ','@','@','@','@',' ','@','@','@',' ','@'},
      {'@','@','@','@','@',' ','@','T','@',' ',' ',' ',' ','@',' ','@','T','@',' ','@'},
      {'@',' ',' ',' ',' ',' ','@','@','@','@','@','@',' ','@',' ','@',' ','@',' ','@'},
      {'@',' ','@','@','@',' ',' ',' ',' ',' ',' ','@',' ','@',' ','@',' ','@',' ','@'},
      {'@',' ','@','T','@',' ','@','@','@','@',' ','@',' ','@',' ','@',' ','@',' ','@'},
      {'@',' ','@',' ','@',' ',' ',' ',' ','@',' ','@',' ','@',' ',' ',' ','@',' ','@'},
      {'@',' ','@',' ','@','@','@','@',' ','@',' ','@',' ','@','@','@','@','@',' ','@'},
      {'@',' ',' ',' ','@','T',' ',' ',' ','@',' ','@',' ',' ',' ',' ',' ',' ',' ','@'},
      {'@','@','@','@','@','@','@','@','@','@','X','@','@','@','@','@','@','@','@','@'},
      {'@','@','@','@','@','@','@','@','@','@','Y','@','@','@','@','@','@','@','@','@'}
  };

  // onde o jogador começa no labirinto
  maze[posY][posX] = '$';

  // cria os vetores suas quantidades seus atributos do registro
  struct Key key[KEYS];
  struct Candy candy[CANDY];
  
  // cria a bruxa com seus atributos do registro
  struct Witch witch;
  
  // gera as chaves aleatoriamente no mapa
  for(int k = 0; k < KEYS; k++){
    do{
      posXelement = rand() % MAZE_COLUMNS;
      posYelement = rand() % MAZE_ROWS;
    }while(maze[posYelement][posXelement] != ' ');

    key[k].posX = posXelement;
    key[k].posY = posYelement;
    key[k].symbol = '&';

    maze[posYelement][posXelement] = key[k].symbol; 
  }
  
  // gera os doces aleatoriamente no mapa
  for(int l = 0; l < CANDY; l++){    
    do{
      posXelement = rand() % MAZE_COLUMNS;
      posYelement = rand() % MAZE_ROWS;
    }while(maze[posYelement][posXelement] != ' ');

    candy[l].posX = posXelement;
    candy[l].posY = posYelement;
    candy[l].symbol = 'o';

    maze[posYelement][posXelement] = candy[l].symbol; 
  }
  
  // gera a bruxa aleatoriamente no mapa
  do{
    posXelement = rand() % MAZE_COLUMNS;
    posYelement = rand() % MAZE_ROWS;
  }while(maze[posYelement][posXelement] != ' ');

  witch.posX = posXelement;
  witch.posY = posYelement;
  witch.symbol = 'B';

  maze[posYelement][posXelement] = witch.symbol; 

  int score = 0;
  int newPositionWitch = 0;

  // funcionamento principal do jogo
  while(1) {

    // bruxa troca de posição a cada 6 movimentos do jogador
    if(newPositionWitch == 12){
      maze[witch.posY][witch.posX] = ' ';
      do{
        witch.posX = rand() % MAZE_COLUMNS;
        witch.posY = rand() % MAZE_ROWS;
      }while(maze[witch.posY][witch.posX] != ' ');
      maze[witch.posY][witch.posX] = witch.symbol;
      newPositionWitch = 0;
    }
    maze[posY][posX] = '$';

    printf("\n");
    clearScreen();

    // mostra o username e o score do jogador
    printf("Jogador: %s\n\n", username);
    printf("Score: %d\n", score);

    // mostra as chaves coletadas
    printf("Chaves coletadas: %d\n\n", quantKeys);

      if(quantKeys == KEYS){
        printf("Você coletou todas as chaves! A casa da bruxa foi aberta!\n\n");
      }else if (quantKeys == KEYS - 1){
        printf("Resta apenas 1 chave para ser coletada!\n\n");
      }else{
        printf("Restam %d chaves para serem coletadas!\n\n", KEYS - quantKeys);
      }

    // desenha o labirinto
    for(int i = 0; i < MAZE_ROWS; i++){
      for(int j = 0; j < MAZE_COLUMNS; j++){
        printf(" %c", maze[i][j]);
      }
      printf("\n");
    }

    // ações do jogador
    printf("\n Cima (w)\n Esquerda (a)\n Baixo (s)\n Direita (d)\n\n");
    scanf("%c", &action);

    int x = posX, y = posY;

    switch(action){
      case 'w':
        y = posY - 1;
        x = posX;
        break;
      case 'a':
        y = posY;
        x = posX - 1;
        break;
      case 's':
        y = posY + 1;
        x = posX;
        break;
      case 'd':
        y = posY;
        x = posX + 1;
        break;
    }

    if(maze[y][x] == ' ' || maze[y][x] == '&' || maze[y][x] == 'o'){
      maze[posY][posX] = ' ';
      if(maze[y][x] == '&') quantKeys++;
      if(maze[y][x] == 'o') score = score + 100;
        
      switch(action){
        case 'w':
          posY--;
          break;
        case 'a':
          posX--;
          break;
        case 's':
          posY++;
          break;
        case 'd':
          posX++;
          break;
      }

    // a casa é aberta quando o jogador adquire todas as chaves
    if(quantKeys == KEYS){
      maze[PORTA_Y][PORTA_X] = ' ';
    }

    // game over
    }else if(maze[y][x] == witch.symbol){
      showGameOverWitch(username);
      break;
    }else if(maze[y][x] == 'T'){
      showGameOverTrap(username);
      break;

    // game clear
    }else if(maze[y][x] == 'Y'){
      showGameClear(username, score);
      break;
    }

    newPositionWitch++;
  }
}

// função para mostrar a história do jogo
void showGameStory(){
  printf("\n=============================================");
  printf("\n==                                         ==");
  printf("\n==   João e Maria são filhos de um pobre   ==");
  printf("\n==    lenhador que morava na floresta.     ==");
  printf("\n==                                         ==");
  printf("\n==  Certo dia, a madrasta dos irmãos sai   ==");
  printf("\n==   para colher amoras e finalizar sua    ==");
  printf("\n==   torta, deixando os irmaõs sozinhos.   ==");
  printf("\n==                                         ==");
  printf("\n==                  x para prosseguir...   ==");
  printf("\n==                                         ==");
  printf("\n=============================================\n");

  while(getchar()!='x');
  clearScreen();

  printf("\n=============================================");
  printf("\n==                                         ==");
  printf("\n==   Quando ela volta, a casa está toda    ==");
  printf("\n==  bagunçada e sua torta caída no chão... ==");
  printf("\n==                                         ==");
  printf("\n==  Ela fica muito brava e os expulsa de   ==");
  printf("\n==     casa, mandando eles irem colher     ==");
  printf("\n==         mais amoras na floresta.        ==");
  printf("\n==                                         ==");
  printf("\n==                  x para prosseguir...   ==");
  printf("\n==                                         ==");
  printf("\n=============================================\n");

  while(getchar()!='x');
  clearScreen();

  printf("\n=============================================");
  printf("\n==                                         ==");
  printf("\n==    Na procura pelas amoras, os dois     ==");
  printf("\n==       acham uma trilha de doces.        ==");
  printf("\n==                                         ==");
  printf("\n==                                         ==");
  printf("\n==    Assim, João e Maria se separam...    ==");
  printf("\n==                                         ==");
  printf("\n==                                         ==");
  printf("\n==                  x para prosseguir...   ==");
  printf("\n==                                         ==");
  printf("\n=============================================\n");

  while(getchar()!='x');
  clearScreen();

  printf("\n=============================================");
  printf("\n==                                         ==");
  printf("\n==    Maria segue outro caminho e acaba    ==");
  printf("\n==    entrando em uma casa abandonada.     ==");
  printf("\n==                                         ==");
  printf("\n==  Uma bruxa aparece, tranca ela na casa  ==");
  printf("\n==         e sai em busca de João!         ==");
  printf("\n==                                         ==");
  printf("\n==                                         ==");
  printf("\n==                  x para prosseguir...   ==");
  printf("\n==                                         ==");
  printf("\n=============================================\n");

  while(getchar()!='x');
  clearScreen();

  printf("\n=============================================");
  printf("\n==                                         ==");
  printf("\n==       Você tomará o papel de João!      ==");
  printf("\n==                                         ==");
  printf("\n==     - Procure pelas chaves da porta     ==");
  printf("\n==        - Não caia nas armadilhas        ==");
  printf("\n==             - Fuja da bruxa             ==");
  printf("\n==             - Colete doces              ==");
  printf("\n==                                         ==");
  printf("\n==             Salve sua irmã!             ==");
  printf("\n==                                         ==");
  printf("\n==                  x para prosseguir...   ==");
  printf("\n==                                         ==");
  printf("\n=============================================\n");

  while(getchar()!='x');
  showMenu();
}

// função para gerar o menu principal
void showMenu(){
  char option = ' ';

  clearScreen();
  printf("\n========================================");
  printf("\n======== BEM VINDO AO LABIRINTO ========");
  printf("\n========================================");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n==              JOGAR   (1)           ==");
  printf("\n==             RANKING  (2)           ==");
  printf("\n==              SAIR    (3)           ==");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n========================================\n");

  scanf("%c", &option);
  if(option == '1'){
    insertUsername();
  }else if(option == '2'){
    showRanking();
  }
}

// função para gerar a tela de fim de jogo caso o jogador seja pego pela bruxa
void showGameOverWitch(char username[]){
  clearScreen();

  char option = ' ';

  printf("\n========================================");
  printf("\n========= A BRUXA TE PEGOU 😔  ==========");
  printf("\n========================================");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n==              MENU    (1)           ==");
  printf("\n==             RESTART  (2)           ==");
  printf("\n==              SAIR    (3)           ==");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n========================================\n");

  scanf("%c", &option);
  if(option == '1'){
    showMenu();
  }else if(option == '2'){
    showMaze(username);
  }
}

// função para gerar a tela de fim de jogo caso o jogador caia na armadilha
void showGameOverTrap(char username[]){
  clearScreen();

  char option = ' ';
  
  printf("\n========================================");
  printf("\n====== VOCÊ CAIU NA ARMADILHA 😔  =======");
  printf("\n========================================");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n==              MENU    (1)           ==");
  printf("\n==             RESTART  (2)           ==");
  printf("\n==              SAIR    (3)           ==");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n========================================\n");

  scanf("%c", &option);
  if(option == '1'){
    showMenu();
  }else if(option == '2'){
    showMaze(username);
  }
}

// função para gerar a tela de game clear
void showGameClear(char username[], int score){
  clearScreen();

  char option = ' ';

  printf("\n========================================");
  printf("\n=========== VOCÊ GANHOU 😊  =============");
  printf("\n========================================");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n==              MENU    (1)           ==");
  printf("\n==             RANKING  (2)           ==");
  printf("\n==              SAIR    (3)           ==");
  printf("\n==                                    ==");
  printf("\n==                                    ==");
  printf("\n========================================\n");
  saveScore(username, score);

  scanf("%c", &option);
  if(option == '1'){
    showMenu();
  }else if(option == '2'){
    showRanking();
  }
}

void saveScore(char username[], int score){
  FILE *rankingFile;
  rankingFile = fopen(FILEPATH, "a");
  char scoreString[5] = "";
  char username1[50] = "";
  if(rankingFile != NULL){
    sprintf(scoreString, "%d", score);
    strcat(username1, username);
    strcat(username1, SPLIT_DELIMITER);
    strcat(username1, scoreString);
    strcat(username1, "\n");

    fputs(username1, rankingFile);
    
    fclose(rankingFile);
    
  }else{
    printf("Não foi possível abrir o arquivo");
  }
}

// função para mostrar o ranking dos usuários
void showRanking(){
  clearScreen();

  char option = ' ';

  FILE *rankingFile;
  rankingFile = fopen(FILEPATH, "r");

  if(rankingFile != NULL){
    char usersScore[100] = "";
    printf("\n========================================\n");
    printf("\t\t\t\tRANKING");
    printf("\n========================================\n\n");
    
    while(fgets(usersScore, 100, rankingFile)){
      char * userNameScore = strtok(usersScore, SPLIT_DELIMITER);
      printf("\t\t\t %s", userNameScore);
      userNameScore = strtok(NULL, " ");
      printf(" - %s", userNameScore );
      userNameScore = strtok(NULL, " ");
    }
    //printf("\n\n\n\t\tAperte x para voltar ao menu...\n");
    printf("\n========================================\n");

    fclose(rankingFile);
    system("pause");
  }else{
    printf("Não foi possível abrir o arquivo");
  }
}

// função para pegar o apelido do usuário
void insertUsername(){
  clearScreen();
  char username[6];

  printf("\n========== INSIRA SEU APELIDO ==========\n");
  scanf("%s", username);
  showMaze(username);
}

// função para limpar a tela
void clearScreen(){
  system("clear");
}

// função para garantir todas as permissões do arquivo
void setPermissionFile(){
  system("chmod -R 777 ranking.txt");
}