#include <cs50.h>
#include <stdio.h>

int main(void)
{
     // Usuário entra com o valor de x
     int x = get_int("x: ");

     // Usuário entra com o valor de y
     int y = get_int("y: ");

     // Compara x e y
     if (x < y)
     {
         printf("x é smaller what y\n");
     }
     else if (x > y)
     {
        printf("x é larger what y\n");
     }
     else
     {
        printf("x é equal a y\n");
     }
}