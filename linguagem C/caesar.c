#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testarArgumento(int argc, int k);
void CriptografarTexto(string textoSimples, int k);


int main(int argc, string argv[])
{
    int k = atoi(argv[1]);
    // Testar se tem apenas um argumento da linha de comando e se é um valor positivo.
    int teste = testarArgumento(argc, k);
    // Retorna 1 se falhar no teste.
    if (teste == 1)
        return 1;
    // Caso o K seja maior que 26 recebe o resto da divisão por 26, o que torna o valor <= a 26.
    if (k > 26)
        k = k % 26;

    string textoSimples = get_string("Digite o texto a ser criptografado: ");
    CriptografarTexto(textoSimples, k);
    printf("\n");

}


int testarArgumento(int argc, int k)
{
    if (argc == 2 && k > 0)
        return 0;
    else
    {
        printf("ERRO : Insira um inteiro positivo\n");
        return 1;
    }
}


void CriptografarTexto(string textoSimples, int k)
{
    int n = strlen(textoSimples);

    for (int i = 0; i <= n; i++)
    {
        // Diminui o valor de 'a' para que chegue fique um valor de 0 a 26, depois soma k e pega o resto da divisao por 26, depois soma o valor de 'a' para que fique com o valor dentro da tabela ASCII
        if (textoSimples[i] >= 'a' && textoSimples[i] <= 'z')
            printf("%c", (((textoSimples[i] - 'a') + k) % 26) + 'a');
        else if (textoSimples[i] >= 'A' && textoSimples[i] <= 'Z')
            printf("%c", (((textoSimples[i] - 'A') + k) % 26) + 'A');
        else
            printf("%c", textoSimples[i]);
    }
}