#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    
    float M[4][7], menor=50, minmax=0;
    int i=0, j=0, linha=0, coluna=0;
    
    srand(time(0));
    
    /*preenchendo a matriz com valores aleatórios*/
    for(i=0; i<4; i++) {
        for(j=0; j<7; j++) {
            M[i][j] = rand()%51;
            
            /*pegando o menor elemento e sua linha*/
            if(menor > M[i][j]){
                menor = M[i][j];
                linha = i;
            }
        }
    }
    
    /*matriz gerada*/
    printf("A matriz gerada aleatoriamente é:");
    for(i=0; i<4; i++) {
        for(j=0; j<7; j++) {
            printf("\nM[%d][%d]: %.2f", i+1, j+1, M[i][j]);
            
            if(j==6)
            printf("\n");
        }
    }
    
    /*pegando o maior valor na linha do menor valor da matriz*/
    for(j=0; j<7; j++) {
        if(M[linha][j] > minmax){
            minmax = M[linha][j];
            coluna = j;
        }
    }

    printf("\nMINMAX[%d][%d] = %.2f", linha+1, coluna+1, minmax);
    
    return 0;
}
