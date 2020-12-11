#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TEXTO 100

int esCapicua(char[TEXTO]);

int main()
{
    int contador = 0;
    char frase[TEXTO];
    char *palabra;
    printf("Ingrese una frase: ");
    gets(frase);

    palabra = strtok(frase, " ,.!?:;");

    while (palabra != NULL)
    {
        if (esCapicua(palabra))
            contador += 1;
        palabra = strtok(NULL, " ?.!,':;");
    }

    if (contador > 1)
        printf("Hay %d palabras capicua\n", contador);
    else if (contador == 1)
        printf("Hay una palabra capicua\n");
    else
        printf("No hay palabras capicua\n");

    return 0;
}

int esCapicua(char texto[TEXTO])
{
    int capicua = 1;
    int tam = strlen(texto);

    for (int i = 0; i < (tam/2); i++)
    {
        if (!(texto[i]-32 == texto[tam-1-i] || texto[i] == texto[tam-1-i] || texto[i]+32 == texto[tam-1-i]))
            capicua = 0;
    }

    return capicua;
}
