#include <stdio.h>

/* Cuadrado mágico.
   El programa genera un cuadrado mágico siguiendo los criterios enunciados anteriormente. */

const int MAX = 50;

/* Prototipos de funciones. */
void Cuadrado(int [][MAX], int);
void Imprime(int [][MAX], int);

int main(void)
{
    int CMA[MAX][MAX], TAM;

    do
    {
        printf("Ingrese el tamaño impar de la matriz (1-49): ");
        scanf("%d", &TAM);
    }
    /* Se verifica que el tamaño esté dentro del rango válido (1 a 50)
       Y que el número sea estrictamente impar (! (TAM % 2)). */
    while ((TAM > MAX || TAM < 1) || !(TAM % 2));

    Cuadrado(CMA, TAM);

    printf("\n--- Cuadrado Mágico Generado ---");
    Imprime(CMA, TAM);

    return 0;
}

void Cuadrado(int A[][MAX], int N)
/* Esta función se utiliza para formar el cuadrado mágico utilizando el método de De La Loubère. */
{
    int I = 1, FIL = 0, COL = N / 2, NUM = N * N;

    /* Inicializar toda la matriz en ceros por seguridad */
    int f, c;
    for(f = 0; f < N; f++)
        for(c = 0; c < N; c++)
            A[f][c] = 0;

    while (I <= NUM)
    {
        A[FIL][COL] = I;

        /* Si el número no es múltiplo de N, nos movemos diagonalmente hacia arriba y a la derecha */
        if (I % N != 0)
        {
            /* Las operaciones aritméticas modulares con (+ N) evitan índices negativos */
            FIL = (FIL - 1 + N) % N;
            COL = (COL + 1) % N;
        }
        else
        {
            /* Si es múltiplo de N, simplemente bajamos una fila */
            FIL++;
        }
        I++;
    }
}

void Imprime(int A[][MAX], int N)
/* Esta función se utiliza para escribir el cuadrado mágico en forma matricial estética. */
{
    int I, J;
    printf("\n");
    for (I = 0; I < N; I++)
    {
        for (J = 0; J < N; J++)
        {
            printf("%4d ", A[I][J]); /* Formato alineado en columnas */
        }
        printf("\n");
    }
}
