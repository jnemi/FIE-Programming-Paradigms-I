#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 100
#define TEXTO 100

int validarInt(int, int);
void cargar_equipos(char[N][TEXTO], int);
void cargar_resultados(int[N][7], char[N][TEXTO], int);
void calcular_resultados(int[N][7], int);
void mostrar_resultados(int[N][7], char[N][TEXTO], int);
void ganador(int[N][7], char[N][TEXTO], int);

int main()
{
    char equipos[N][TEXTO];
    int resultados[N][7];
    int cantEquipos;

    printf("Ingrese la cantidad de equipos: ");
    cantEquipos = validarInt(1, N);
    cargar_equipos(equipos, cantEquipos);
    cargar_resultados(resultados, equipos, cantEquipos);
    calcular_resultados(resultados, cantEquipos);
    mostrar_resultados(resultados, equipos, cantEquipos);
    ganador(resultados, equipos, cantEquipos);

    return 0;
}

int validarInt(int valorMin, int valorMax)
{
    int entrada = valorMin - 1;
    do
    {
        scanf("%d", &entrada);
        if (entrada < valorMin || entrada > valorMax)
            printf("Error. Intente nuevamente...\n");
    } while (entrada < valorMin || entrada > valorMax);

    return entrada;
}

void cargar_equipos(char e[N][TEXTO], int cantEquipos)
{
    char txt[TEXTO];
    printf("Ingrese los equipos\n");
    gets(txt); //ESTE TEXTO NO HACE NADA PERO LO NECESITO PARA EVITAR QUE ME SALTEE EL EQUIPO 1
    for (int i = 0; i < cantEquipos; i++)
    {
        printf("Equipo %d: ", i+1);
        gets(e[i]);
    }
    system("cls");
}

void cargar_resultados(int r[N][7], char e[N][TEXTO], int cantEquipos)
{
    for (int i = 0; i < cantEquipos; i++)
    {
        printf("Ingrese los resultados de %s \n\n", e[i]);
        printf("Partidos ganados: ");
        scanf("%d", &r[i][1]);
        printf("Partidos empatados: ");
        scanf("%d", &r[i][2]);
        printf("Partidos perdidos: ");
        scanf("%d", &r[i][3]);
        printf("Goles a favor: ");
        scanf("%d", &r[i][4]);
        printf("Goles en contra: ");
        scanf("%d", &r[i][5]);

        system("cls");
    }
}

void calcular_resultados(int resultados[N][7], int cantEquipos)
{
    for (int i = 0; i < cantEquipos; i++)
    {
        resultados[i][0] = 3*resultados[i][1] + resultados[i][2]; //PUNTOS
        resultados[i][6] = resultados[i][4] - resultados[i][5]; //DIFERENCIA DE GOLES
    }
}

void mostrar_resultados(int r[N][7], char e[N][TEXTO], int cantEquipos)
{
    printf("Equipo                        PTS  PG   PE   PP   GF   GC   DIF\n");
    printf("-----------------------------------------------------------------\n");

    for (int i = 0; i < cantEquipos; i++)
    {
        printf("%-30s", e[i]);
        for (int j = 0; j < 7; j++)
            printf("%-5d", r[i][j]);
        printf("\n");
    }
}

void ganador(int r[N][7], char e[N][TEXTO], int cantEquipos)
{
    int ganador = -1, puntos = -1;
    for (int i = 0; i < cantEquipos; i++)
    {
        if (r[i][0] > puntos)
        {
            ganador = i;
            puntos = r[i][0];
        }else if (r[i][0] = puntos)
        {
            if (r[i][6] > r[ganador][6])
                ganador = i;
        }
    }

    printf("\n\nEl ganador es el %s\n", e[ganador]);
}
