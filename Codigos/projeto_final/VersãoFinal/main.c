// gcc ./Codigos/projeto_final/VersãoFinal/main_2.c -o exe -lm && ./exe

// ----- declaração dos caracteres especiais unicode ----- //
#define KEY 0X1F5DD
#define MARIA 0x1F467  
#define JOAO 0x1F466
#define TREE 0x1F332
#define SPACE 0x0020
#define TRAP 0x1F578
#define DOOR 0x1F6AA
#define CANDY_U 0x1F36D
#define WITCH_U 0x1F47F

// ----- inserção das bibliotecas ----- //
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<wchar.h>
#include<locale.h>

// ----- declaração das constantes ----- //
const int MAZE_ROWS = 26;
const int MAZE_COLUMNS = 20;
const int KEYS = 3;
const int CANDY = 10;
const int WITCH = 1;
const int PORTA_X = 10;
const int PORTA_Y = 24;
const int WITCH_MOVES = 6;
const char FILEPATH[] = "/home/runner/COM110/Codigos/projeto_final/VersãoFinal/ranking.txt";
const char SPLIT_DELIMITER[] = ";";

// ----- declaração das funções ----- //
void showGameStory();
void showMenu();
void insertUsername();
void showMaze(char username[]);
void showRanking();
void showGameOverWitch(char username[]);
void showGameOverTrap(char username[]);
void showGameClear(char username[], int score);
void saveScore(char username[], int score);
void setPermissionFile();
void clearBuffer();
void clearScreen();

// ----- registros ----- //
// chaves
struct Key 
{    
  wchar_t symbol;
  int posX;
  int posY;
};

// doces
struct Candy 
{    
  wchar_t symbol;
  int posX;
  int posY;
};

// bruxa
struct Witch 
{    
  wchar_t symbol; 
  int posX;
  int posY;
};

// ----- função principal ----- //
int main (){
  setlocale(LC_CTYPE, "");
  srand(time(0));     
  rand();
  setPermissionFile();
  showGameStory();

  return 0;
}

// ----- função para mostrar a história do jogo ----- //
void showGameStory(){
  clearScreen();
  wprintf(L"\n=============================================");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==   João e Maria são filhos de um pobre   ==");
  wprintf(L"\n==    lenhador que morava na floresta.     ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==  Certo dia, a madrasta dos irmãos sai   ==");
  wprintf(L"\n==   para colher amoras e finalizar sua    ==");
  wprintf(L"\n==   torta, deixando os irmaõs sozinhos.   ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==                  x para prosseguir...   ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n=============================================\n");

  while(getchar()!='x');
  clearScreen();

  wprintf(L"\n=============================================");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==   Quando ela volta, a casa está toda    ==");
  wprintf(L"\n==  bagunçada e sua torta caída no chão... ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==  Ela fica muito brava e os expulsa de   ==");
  wprintf(L"\n==     casa, mandando eles irem colher     ==");
  wprintf(L"\n==         mais amoras na floresta.        ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==                  x para prosseguir...   ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n=============================================\n");

  while(getchar()!='x');
  clearScreen();

  wprintf(L"\n=============================================");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==    Na procura pelas amoras, os dois     ==");
  wprintf(L"\n==       acham uma trilha de doces.        ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==    Assim, João e Maria se separam...    ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==                  x para prosseguir...   ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n=============================================\n");

  while(getchar()!='x');
  clearScreen();

  wprintf(L"\n=============================================");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==    Maria segue outro caminho e acaba    ==");
  wprintf(L"\n==    entrando em uma casa abandonada.     ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==  Uma bruxa aparece, tranca ela na casa  ==");
  wprintf(L"\n==         e sai em busca de João!         ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==                  x para prosseguir...   ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n=============================================\n");

  while(getchar()!='x');
  clearScreen();

  wprintf(L"\n=============================================");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==       Você tomará o papel de João!      ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==     - Procure pelas chaves da porta     ==");
  wprintf(L"\n==        - Não caia nas armadilhas        ==");
  wprintf(L"\n==             - Fuja da bruxa             ==");
  wprintf(L"\n==             - Colete doces              ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==             Salve sua irmã!             ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n==                  x para prosseguir...   ==");
  wprintf(L"\n==                                         ==");
  wprintf(L"\n=============================================\n");

  while(getchar()!='x');
  showMenu();
}

// ----- função para gerar o menu principal ----- //
void showMenu(){
  char option = ' ';

  clearScreen();
  wprintf(L"\n========================================");
  wprintf(L"\n======== BEM VINDO AO LABIRINTO ========");
  wprintf(L"\n========================================");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n==              JOGAR   (1)           ==");
  wprintf(L"\n==             RANKING  (2)           ==");
  wprintf(L"\n==              SAIR    (3)           ==");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n========================================\n");

  clearBuffer();
  scanf("%c", &option);
  
  if(option == '1'){
    insertUsername();
  }else if(option == '2'){
    showRanking();
  }
}

// ----- função para pegar o apelido do usuário ----- //
void insertUsername(){
  clearScreen();
  char username[6];

  wprintf(L"\n========== INSIRA SEU APELIDO ==========\n");
  clearBuffer();
  scanf("%s", username);
  showMaze(username);
}

// ----- função para gerar o labirinto e as funcionalidades do jogo ----- //
void showMaze(char username[]){

  // declaração das chaves, posição do jogador
  int quantKeys = 0, posX = 2, posY = 0;
  int posXelement = 0, posYelement = 0; 

  char action = ' ';
  
  // labirinto
  wchar_t maze[26][20] = {
      {TREE,TREE,SPACE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE},
      {TREE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,TREE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,TREE},
      {TREE,SPACE,TREE,TREE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE,TREE,TREE,SPACE,TREE,TREE,TREE,TREE,SPACE,TREE},
      {TREE,SPACE,TREE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,SPACE,TREE,TRAP,TREE,SPACE,SPACE,SPACE,TRAP,TREE,SPACE,TREE},
      {TREE,SPACE,TREE,SPACE,TREE,TREE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE,TREE,TREE,TREE,TREE,TREE,SPACE,TREE},
      {TREE,SPACE,TREE,SPACE,TREE,TRAP,TREE,SPACE,TREE,SPACE,TREE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,TREE},
      {TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,SPACE,TREE,TREE,TREE,TREE,TREE,TREE},
      {TREE,SPACE,TREE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,TREE,TREE,SPACE,TREE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,TREE},
      {TREE,SPACE,TREE,TREE,TREE,TREE,TREE,SPACE,TREE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,TREE,TREE,TREE,SPACE,TREE},
      {TREE,SPACE,SPACE,SPACE,TREE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,TREE,TREE,SPACE,TREE,SPACE,SPACE,SPACE,SPACE,TREE},
      {TREE,TREE,TREE,SPACE,TREE,SPACE,TREE,TREE,TREE,SPACE,TREE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,TREE,TREE,TREE},
      {TREE,TRAP,TREE,SPACE,TREE,SPACE,TREE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,TREE,TREE,SPACE,SPACE,SPACE,TRAP,TREE},
      {TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE,TREE,TREE,TREE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE,TREE,TREE,TREE},
      {TREE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,TREE},
      {TREE,SPACE,TREE,TREE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE,TREE,TREE,TREE,TREE,TREE,SPACE,TREE},
      {TREE,SPACE,TREE,TRAP,TREE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,TREE},
      {TREE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE,TREE,TREE,TREE,SPACE,TREE,TREE,TREE,SPACE,TREE},
      {TREE,TREE,TREE,TREE,TREE,SPACE,TREE,TRAP,TREE,SPACE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,TRAP,TREE,SPACE,TREE},
      {TREE,SPACE,SPACE,SPACE,SPACE,SPACE,TREE,TREE,TREE,TREE,TREE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE},
      {TREE,SPACE,TREE,TREE,TREE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE},
      {TREE,SPACE,TREE,TRAP,TREE,SPACE,TREE,TREE,TREE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE},
      {TREE,SPACE,TREE,SPACE,TREE,SPACE,SPACE,SPACE,SPACE,TREE,SPACE,TREE,SPACE,TREE,SPACE,SPACE,SPACE,TREE,SPACE,TREE},
      {TREE,SPACE,TREE,SPACE,TREE,TREE,TREE,TREE,SPACE,TREE,SPACE,TREE,SPACE,TREE,TREE,TREE,TREE,TREE,SPACE,TREE},
      {TREE,SPACE,SPACE,SPACE,TREE,TRAP,SPACE,SPACE,SPACE,TREE,SPACE,TREE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,SPACE,TREE},
      {TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,DOOR,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE},
      {TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,MARIA,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE,TREE}
  };

    // desenha o labirinto
    for(int i = 0; i < MAZE_ROWS; i++){
      for(int j = 0; j < MAZE_COLUMNS; j++){
        wprintf(L" %lc", maze[i][j]);
      }
      wprintf(L"\n");
    }

  // onde o jogador começa no labirinto
  maze[posY][posX] = JOAO;

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
    }while(maze[posYelement][posXelement] != SPACE);

    key[k].posX = posXelement;
    key[k].posY = posYelement;
    key[k].symbol = KEY;

    maze[posYelement][posXelement] = key[k].symbol; 
  }
  
  // gera os doces aleatoriamente no mapa
  for(int l = 0; l < CANDY; l++){    
    do{
      posXelement = rand() % MAZE_COLUMNS;
      posYelement = rand() % MAZE_ROWS;
    }while(maze[posYelement][posXelement] != SPACE);

    candy[l].posX = posXelement;
    candy[l].posY = posYelement;
    candy[l].symbol = CANDY_U;

    maze[posYelement][posXelement] = candy[l].symbol; 
  }
  
  // gera a bruxa aleatoriamente no mapa
  do{
    posXelement = rand() % MAZE_COLUMNS;
    posYelement = rand() % MAZE_ROWS;
  }while(maze[posYelement][posXelement] != SPACE);

  witch.posX = posXelement;
  witch.posY = posYelement;
  witch.symbol = WITCH_U;

  maze[posYelement][posXelement] = witch.symbol; 

  int score = 0;
  int newPositionWitch = 0;

  // funcionamento principal do jogo
  while(1) {

    // bruxa troca de posição a cada 6 movimentos do jogador
    if(newPositionWitch == WITCH_MOVES){
      maze[witch.posY][witch.posX] = SPACE;
      do{
        witch.posX = rand() % MAZE_COLUMNS;
        witch.posY = rand() % MAZE_ROWS;
      }while(maze[witch.posY][witch.posX] != SPACE);
      maze[witch.posY][witch.posX] = witch.symbol;
      newPositionWitch = 0;
    }
    maze[posY][posX] = JOAO;

    wprintf(L"\n");
    clearScreen();

    // mostra o username e o score do jogador
    wprintf(L"Jogador: %s\n\n", username);
    wprintf(L"Score: %d\n", score);

    // mostra as chaves coletadas
    wprintf(L"Chaves coletadas: %d\n\n", quantKeys);

      if(quantKeys == KEYS){
        wprintf(L"Você coletou todas as chaves! A casa da bruxa foi aberta!\n\n");
      }else if (quantKeys == KEYS - 1){
        wprintf(L"Resta apenas 1 chave para ser coletada!\n\n");
      }else{
        wprintf(L"Restam %d chaves para serem coletadas!\n\n", KEYS - quantKeys);
      }

    // desenha o labirinto
    for(int i = 0; i < MAZE_ROWS; i++){
      for(int j = 0; j < MAZE_COLUMNS; j++){
        wprintf(L" %lc", maze[i][j]);
      }
      wprintf(L"\n");
    }

    // ações do jogador
    wprintf(L"\n Cima (w)\n Esquerda (a)\n Baixo (s)\n Direita (d)\n\n");
    clearBuffer();
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
 
    if(maze[y][x] == SPACE || maze[y][x] == KEY || maze[y][x] == CANDY_U){
      maze[posY][posX] = SPACE;
      if(maze[y][x] == KEY) quantKeys++;
      if(maze[y][x] == CANDY_U) score = score + 100;
        
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
      maze[PORTA_Y][PORTA_X] = SPACE;
    }

    // game over
    }else if(maze[y][x] == witch.symbol){
      showGameOverWitch(username);
      break;
    }else if(maze[y][x] == TRAP){
      showGameOverTrap(username);
      break;

    // game clear
    }else if(maze[y][x] == MARIA){
      showGameClear(username, score);
      break;
    }

    newPositionWitch++;
  }
}

// ----- função para mostrar o ranking dos usuários ----- //
void showRanking(){
  clearScreen();

  char option = ' ';

  FILE *rankingFile;
  rankingFile = fopen(FILEPATH, "r");

  if(rankingFile != NULL){
    char usersScore[100] = "";
    wprintf(L"\n========================================\n");
    wprintf(L"\t\t\t\tRANKING");
    wprintf(L"\n========================================\n\n");
    
    while(fgets(usersScore, 100, rankingFile)){
      char * userNameScore = strtok(usersScore, SPLIT_DELIMITER);
      wprintf(L"\t\t\t %s", userNameScore);
      userNameScore = strtok(NULL, " ");
      wprintf(L" - %s", userNameScore );
      userNameScore = strtok(NULL, " ");
    }
    wprintf(L"\n\t\tAperte x para voltar ao menu...\n");
    wprintf(L"\n========================================\n");

    clearBuffer();
    while(getchar()!='x');
    showMenu();

    fclose(rankingFile);
  }else{
    wprintf(L"Não foi possível abrir o arquivo");
  }
}

// ----- função para gerar a tela de fim de jogo caso o jogador seja pego pela bruxa ----- //
void showGameOverWitch(char username[]){
  clearScreen();

  char option = ' ';

  wprintf(L"\n========================================");
  wprintf(L"\n========= A BRUXA TE PEGOU 😔  ==========");
  wprintf(L"\n========================================");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n==              MENU    (1)           ==");
  wprintf(L"\n==             RESTART  (2)           ==");
  wprintf(L"\n==              SAIR    (3)           ==");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n========================================\n");

  clearBuffer();
  scanf("%c", &option);
  
  if(option == '1'){
    showMenu();
  }else if(option == '2'){
    showMaze(username);
  }
}

// ----- função para gerar a tela de fim de jogo caso o jogador caia na armadilha ----- //
void showGameOverTrap(char username[]){
  clearScreen();

  char option = ' ';
  
  wprintf(L"\n========================================");
  wprintf(L"\n====== VOCÊ CAIU NA ARMADILHA 😔  =======");
  wprintf(L"\n========================================");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n==              MENU    (1)           ==");
  wprintf(L"\n==             RESTART  (2)           ==");
  wprintf(L"\n==              SAIR    (3)           ==");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n========================================\n");

  clearBuffer();
  scanf("%c", &option);

  if(option == '1'){
    showMenu();
  }else if(option == '2'){
    showMaze(username);
  }
}

// ----- função para gerar a tela de game clear ----- //
void showGameClear(char username[], int score){
  clearScreen();

  char option = ' ';

  wprintf(L"\n========================================");
  wprintf(L"\n=========== VOCÊ GANHOU 😊  =============");
  wprintf(L"\n========================================");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n==              MENU    (1)           ==");
  wprintf(L"\n==             RANKING  (2)           ==");
  wprintf(L"\n==              SAIR    (3)           ==");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n==                                    ==");
  wprintf(L"\n========================================\n");
  
  saveScore(username, score);
  clearBuffer();
  scanf("%c", &option);

  if(option == '1'){
    showMenu();
  }else if(option == '2'){
    showRanking();
  }
}

// ----- função para garantir todas as permissões do arquivo ----- //
void setPermissionFile(){
  system("chmod -R 777 ranking.txt");
} 

// ----- função para salvar a pontuação do jogador ----- //
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

// ----- função para limpar a tela ----- //
void clearScreen(){
  system("clear");
}

// ----- função para limpar o buffer ----- //
void clearBuffer(){
  char c;
  while ((c = getchar()) != '\n' && c != EOF);
}