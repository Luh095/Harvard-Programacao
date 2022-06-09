#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Instanciando variavel altura
    int altura;
    do
    {
    //Vamos pedir ao usuario a altura
        altura = get_int("Altura: ");
    }
    //Validar para que seja maior 1 e menor que 8
    while (altura < 1 || altura > 8);

    //A = 0, sendo menor que a altura adiciona +1 e continua
    for (int a = 0; a < altura; a++)
    {
        //B = 0, sendo menor que a altura adiciona +1 e continua
        for (int b = 0; b < altura; b++)
        {
            //Se o A+B for menor que Altura - 1 vai adicionar um espaço
            if (a + b < altura - 1)
            {
                printf(" ");
            }
            //Caso contrario vai adicionar "#"
            else
            {
                printf("#");
            }
        }
        // Voltando a primeira linha
        printf("  #");

        //Seguindo mesma logica anterior
        //B = 0, sendo menor que a altura adiciona +1 e continua
        for (int b = 0; b < altura; b++)
        {
            //Se o A+B for MAIOR que a altura - 1 vamos adicionar "#"
            if (a + b > altura - 1)
            {
                printf("#");
            }
        }
        //Nova linha
        printf("\n");
    }
}