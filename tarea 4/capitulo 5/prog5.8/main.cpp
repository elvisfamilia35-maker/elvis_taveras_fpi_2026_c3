#include <stdio.h>

/* Primos.
   El programa almacena en un arreglo unidimensional los primeros 100 números primos. */

const int TAM = 100;

/* Prototipos de funciones corregidos */
void Imprime(int Primos[], int T);
void Primo(int A, int *B);

int main(void)
{
    int P[TAM] = {1, 2}; /* Se inicializan las dos primeras posiciones */
    int FLA, J = 2, PRI = 3;

    /* Nota: Se usa J < TAM para evitar desbordamiento, ya que P tiene índices de 0 a 99 */
    while (J < TAM)
    {
        FLA = 1;
        Primo(PRI, &FLA); /* Se llama a la función que determina si PRI es primo. */

        if (FLA) /* Si FLA es 1, entonces PRI es primo. */
        {
            P[J] = PRI;
            J++;
        }
        PRI += 2; /* Se evalúan solo números impares siguientes */
    }

    Imprime(P, TAM);

    return 0;
}

void Primo(int A, int *B)
/* Esta función determina si A es primo, en cuyo caso el valor de *B no se altera (permanece en 1).
   Si encuentra un divisor, *B se vuelve 0. */
{
    int DI = 3;
    while (*B && (DI < (A / 2)))
    {
        if ((A % DI) == 0)
        {
            *B = 0;
        }
        DI++;
    }
}

void Imprime(int Primos[], int T)
/* Esta función imprime el arreglo unidimensional de números primos. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("\nPrimos[%d]: %d", I, Primos[I]);
    }
    printf("\n");
}
