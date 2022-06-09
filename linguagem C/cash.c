#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float reais;
    int moedas = 0;

    do
    {
        reais = get_float("Troca devida: ");
    }
    while (reais < 0);

    int centavos = round(reais * 100);

    while (centavos >= 25)
    {
        moedas++;
        centavos = centavos - 25;
    }

    while (centavos >= 10)
    {
        moedas++;
        centavos = centavos - 10;
    }

    while (centavos >= 5)
    {
        moedas++;
        centavos = centavos - 5;
    }

    while (centavos >= 1)
    {
        moedas++;
        centavos = centavos - 1;
    }

    printf("%i\n", moedas);
}