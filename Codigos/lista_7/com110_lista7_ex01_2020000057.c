#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    
    int M[2][2], i=0, j=0, maior=0, R[2][2]; 
    
    /*preenchendo a matriz*/
    for(i=0; i<2; i++) {
        for(j=0; j<2; j++) {
            printf("Insira o valor da posição M[%d][%d]: ", i+1, j+1);
            scanf("%d", &M[i][j]);
           
           /*maior elemento*/
            if(M[i][j] > maior){
                maior = M[i][j];
            }
        }
    }
    
    system("clear");
    
    /*matriz gerada*/
    printf("A matriz gerada é:");
    for(i=0; i<2; i++) {
        for(j=0; j<2; j++) {
            printf("\nM[%d][%d]: %d", i+1, j+1, M[i][j]);
        }
    }
    
    /*matriz R*/
    printf("\n\nA matriz R, resultante da multiplicação dos elementos de M pelo seu maior elemento, é:");
    for(i=0; i<2; i++) {
        for(j=0; j<2; j++) {
            R[i][j] = M[i][j]*maior;
            printf("\nR[%d][%d]: %d", i+1, j+1, R[i][j]);
        }
    }
    return 0;
}
