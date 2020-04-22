#include <stdio.h>
int main()
{
    int ndia = 0, nmes = 0, nano = 0;
    int dia = 0, mes = 0, ano = 0;
    printf("Insira uma data de nascimento (formato: dia mês ano): ");
    scanf("%d %d %d", &ndia, &nmes, &nano);
    printf("\nInsira a data de hoje (formato: dia mês ano): ");
    scanf("%d %d %d", &dia, &mes, &ano);
    ano = ano - nano;
    mes = mes - nmes;
    dia = dia - ndia;
    printf("\nEssa pessoa tem %.d ano(s), %.d mês/meses e %d dia(s) de idade", ano, mes, dia);
    return 0;
}