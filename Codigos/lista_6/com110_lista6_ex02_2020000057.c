#include <stdio.h>
int main()
{

  int alunos_respostas[10][8] = {0}, gabarito[8] = {0}, questoes_corretas[8] = {0}, aprovados = 0;

  printf("\n --- As alternativas são 1, 2, 3 ou 4 --- \n");

  for(int k = 0; k < 8; k++){
    do{
      printf("\nEntre com o gabarito questao %d: ", k + 1);
      scanf("%d", &gabarito[k]);
    }while(gabarito[k] > 4 || gabarito[k] < 1);
  }

  for(int i = 0; i < 10; i++){
    printf("\n-- Entre com as notas para o %dº aluno --", i + 1);
    for(int j = 0; j < 8; j++){
      do{
        printf("\nEntre com a resposta da questao %d: ", j + 1);
        scanf("%d", &alunos_respostas[i][j]);
      }while(alunos_respostas[i][j] > 4 || alunos_respostas[i][j] < 1);
      if(alunos_respostas[i][j] == gabarito[j]){
        questoes_corretas[i]++;
      }
    }
  }
    printf("\n\n-- Resultados --");
  for(int l = 0; l < 10; l++){
    if(questoes_corretas[l] >= 6){
      aprovados++;
    }
    printf("\nNota do %dº aluno: %d", l + 1, questoes_corretas[l]);
  }
  printf("\n%d0%% dos alunos foram aprovados!\n", aprovados);

  return 0;
}