#include <stdio.h>

int main(void)
{
    float horas;
    float velocidade;
    float litros;

    scanf("%f", &horas);
    scanf("%f", &velocidade);

    litros = (velocidade*horas)/12;

    printf("Litros = %f\n", litros);

    return 0;
}

