#include <stdio.h>
int main()
{
    float a, b, c;
    printf("Velocidade do veiculo e velocidade maxima da via: ");
    scanf("%f %f", &a, &b);
    if (a > b)
    {
        c = ((100 * a) / b) - 100;
        if (c <= 20)
        {
            printf("\n Velocidade até 20%% acima do permitido: O valor da multa é R$ 85,13.");
        }
        else if (c > 20 && c <= 50)
        {
            printf("\n Velocidade entre 20%% e 50%% acima do permitido: O valor da multa é R$ 127,69.");
        }
        else
        {
            printf("\n Velocidade acima de 50%% do permitido: O valor da multa é R$ 574,62");
        }
    }
    else
    {
        printf("\n Velocidade igual ou menor que o limite permitido: Não houve multa.");
    }
    return 0;
}