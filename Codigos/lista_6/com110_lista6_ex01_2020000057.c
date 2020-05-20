#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    
    int vetor[7], i, j;
    
    printf("Entre com 8 valores para preencher um vetor: \n");
    for(i=1; i<=8; i++){
    	printf("Vetor[%d]: ", i);
    	scanf("%d", &vetor[i]);
    }
    
    for(i=1; i<=8; i++){
        for(j=i+1; j<=8; j++){
            if(vetor[i] > vetor[j]){
                int x = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = x;
            }
        }
    }
    
    printf("\nO vetor foi reorganizado em ordem crescente!");
    for(i=1; i<=8; i++){
        printf("\nVetor[%d]: %d", i, vetor[i]);
    }
    
    return 0;
}
