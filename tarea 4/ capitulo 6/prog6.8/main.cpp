#include <stdio.h>

/* Traspuesta.
   El programa calcula la traspuesta de una matriz. */

const int MAX = 50;

/* Prototipos de funciones. */
void Lectura(int [][MAX], int, int);
void Traspuesta(int [][MAX], int [][MAX], int, int);
void Imprime(int [][MAX], int, int);

int main(void)
{
    int MAT[MAX][MAX], TRA[MAX][MAX];
    int FIL, COL;

    /* Se verifica que el número de filas sea correcto (1-50). */
    do
    {
        printf("Ingrese el número de filas de la matriz: ");
        scanf("%d", &FIL);
    }
    while (FIL > MAX || FIL < 1);

    /* Se verifica que el número de columnas sea correcto (1-50). */
    do
    {
        printf("Ingrese el número de columnas de la matriz: ");
        scanf("%d", &COL);
    }
    while (COL > MAX || COL < 1);

    printf("\n--- Lectura de la Matriz Original ---");
    Lectura(MAT, FIL, COL);

    Traspuesta(MAT, TRA, FIL, COL);

    printf("\n--- Impresión de la Matriz Transpuesta ---");
    /* Nota: Como es transpuesta, ahora el número de filas es COL y el de columnas es FIL */
    Imprime(TRA, COL, FIL);

    return 0;
}

void Lectura(int A[][MAX], int F, int C)
/* Esta función se utiliza para leer una matriz de tipo entero de F filas y C columnas. */
{
    int I, J;
    printf("\n");
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < C; J++)
        {
            printf("Ingrese el elemento [%d][%d]: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
    }
}

void Traspuesta(int M1[][MAX], int M2[][MAX], int F, int C)
/* Esta función se utiliza para calcular la traspuesta intercambiando filas por columnas. */
{
    int I, J;
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < C; J++)
        {
            /* El elemento en la posición [I][J] de la matriz original M1
               se coloca en la posición invertida [J][I] de la matriz transpuesta M2. */
            M2[J][I] = M1[I][J];
        }
    }
}

void Imprime(int A[][MAX], int F, int C)
/* Esta función se utiliza para escribir una matriz de tipo entero de F filas
   y C columnas (en este caso la transpuesta). */
{
    int I, J;
    printf("\n");
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < C; J++)
        {
            printf("Elemento [%d][%d]: %d\n", I + 1, J + 1, A[I][J]);
        }
    }
}
