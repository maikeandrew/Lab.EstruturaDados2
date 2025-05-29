#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool ePalindromo(char str[]);
void limparBuffer();

int main()
{
    char texto[100];

    bool resultado;

    printf("Verificador de Palindromo \n");
    printf("Digite uma palavra ou frase: ");

    fgets(texto, sizeof(texto), stdin);

    texto[strcspn(texto, "\n")] = 0;

    resultado = ePalindromo(texto);

    if (resultado)
    {
        printf("A string \"%s\" E um palindromo!\n", texto);
    }
    else
    {
        printf("A string \"%s\" NAO e um palindromo.\n", texto);
    }

    return 0;
}

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

bool ePalindromo(char str[])
{
    int esquerda = 0;
    int direita = strlen(str) - 1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }

    while (esquerda < direita)
    {

        while (esquerda < direita && !isalnum(str[esquerda]))
        {
            esquerda++;
        }

        while (esquerda < direita && !isalnum(str[direita]))
        {
            direita--;
        }

        if (str[esquerda] != str[direita])
        {
            return false;
        }

        esquerda++;
        direita--;
    }

    return true;
}