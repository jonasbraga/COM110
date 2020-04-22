#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c;
    printf("Cateto oposto e Cateto adjascente: ");
    scanf("%f %f", &a, &b);
    c = (a * a) + (b * b);
    printf("Hipotenusa: %0.2f", sqrt(c));
    return 0;
}