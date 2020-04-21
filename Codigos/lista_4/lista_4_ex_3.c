#include <stdio.h>
int main()
{
	float n1=0, n2=0, n3=0;
	int i=0;
	printf("\n1. Praia\n");
	printf("2. Cinema\n");
	printf("3. Parque\n");
	do{
		printf("\nEscolha um lugar acima para ir: ");
		scanf("%d", &i);
		if(i==1){
			printf("\nVocê escolheu ir para a praia!");
		}
		if(i==2){
			printf("\nVocê escolheu ir para o cinema!");
		}
		if(i==3){
			printf("\nVocê escolheu ir para o parque!");
		}
	}while(i!=1 && i!=2 && i!=3);
	return 0;
}