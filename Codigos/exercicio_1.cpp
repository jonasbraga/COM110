#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define VAZIO ' '
#define PAREDE '|'
#define OBSTACULO 'o'
#define JOGADOR '^'
#define DISPARO 'š'
#define POWERUP 'P'

int modo = 0, score = 0;

void inicializaMapa(char m[20][20]){

    int i, j;
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
            m[i][j] = VAZIO;
        }
    }
    for(i=0;i<20;i++){
        m[i][0] = PAREDE;
        m[i][19] = PAREDE;
    }
    }
void desenhaMapa(char m[20][20], int jog){

    int i,j;
    system("cls");
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){
                if(i == 19 && j == jog){
                    printf("%c", JOGADOR);
                }
                else{ printf("%c", m[i][j]);}
    }
    if(i == 0){
        printf("Score: %d", score);
    }
    printf("\n");
    }
    printf("                                    Comandos:\n                                                  E para atirar\n                                                  A para ir para a esquerda\n                                                  D para ir para direita\n                                                  W para ficar parado\n \n                                                    Colete o P para um powerup =O\n\n");
    }
void atualizaMapa(char m[20][20]){

    int i, j, posCarro, powerup;
    for(i=0;i<20;i++){
        for(j=0;j<20;j++){

    if((m[i][j] == OBSTACULO) && (m[i][j] == DISPARO || m[i - 1][j] == DISPARO || m[i + 1][j] == DISPARO)){
    m[i][j] = VAZIO;
    m[i - 1][j] = VAZIO;
    score = score + 50;
    }
    if((m[i][j] == OBSTACULO) && (m[i -1][j] == OBSTACULO) && (m[i][j] == DISPARO || m[i - 1][j] == DISPARO || m[i + 1][j] == DISPARO)){
    m[i][j] = VAZIO;
    m[i - 1][j] = VAZIO;
    score = score + 100;
    }
    if(m[i][j] == DISPARO){
        m[i - 2][j] = m[i][j];
        m[i][j] = VAZIO;
    }
    }
    }
    for (i = 18; i >= 0; i--){
    for (j = 0; j < 20; j++){

    m[i + 1][j] = m[i][j];
    }
    }
    for(j=0;j<20;j++){
        m[0][j] = VAZIO;
    }
        m[0][0] = PAREDE;
        m[0][19] = PAREDE;

    if ((rand() % 100) < 50) {
 posCarro = 1 + (rand() % 18);
 m[0][posCarro] = OBSTACULO;
    }
    if ((rand() % 100) < 5) {
 powerup = 1 + (rand() % 18);
 m[0][powerup] = POWERUP;
    }
    }

void atirar(char m[20][20], int jog){

    if(modo == 0){
    m[19][jog] = DISPARO;
    }
    if(modo == 1 && jog > 1 && jog < 18){
    m[19][jog] = DISPARO;
    m[19][jog - 1] = DISPARO;
    m[19][jog + 1] = DISPARO;
    }
    if(modo == 1 && jog == 1){
    m[19][jog] = DISPARO;
    m[19][jog + 1] = DISPARO;
    }
    if(modo == 1 && jog == 18){
    m[19][jog] = DISPARO;
    m[19][jog - 1] = DISPARO;
    }
    }
int main()
{
    char dig, mapa[20][20];
    int col_parede, col_jogador = 10, s = 0;
    srand(time(NULL));
    inicializaMapa(mapa);

    atualizaMapa(mapa);
    desenhaMapa(mapa, col_jogador);
    while(mapa[19][col_jogador] != OBSTACULO){

        if(mapa[18][col_jogador] == POWERUP){
    modo = 1;
    }

    scanf("%c", &dig);

    if((dig == 'a' || dig == 'A') && (col_jogador > 1)){

    col_jogador--;
    atualizaMapa(mapa);
    desenhaMapa(mapa, col_jogador);
    }
    if((dig == 'd' || dig == 'D') && (col_jogador < 18)){
    col_jogador++;
    atualizaMapa(mapa);
    desenhaMapa(mapa, col_jogador);
    }
    if((dig == 'w' || dig == 'W') && (col_jogador < 20)){
    atualizaMapa(mapa);
    desenhaMapa(mapa, col_jogador);
    }
    if(dig == 'e' || dig == 'E'){
        if(modo == 1){
      s++;
      if(s == 6){
        modo = 0;
        s = 0;
    }
    }
    atirar(mapa, col_jogador);
    atualizaMapa(mapa);
    desenhaMapa(mapa, col_jogador);
    }
    }
    return 0;
    }