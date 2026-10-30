#include <stdio.h>

/* Diagonal principal.
   El programa, al recibir como dato una matriz de tipo entero, escribe la
   diagonal principal. */

const int TAM = 10;

/* Prototipos de funciones. */
void Lectura(int A[][TAM], int F);
void Imprime(int A[][TAM], int F);
/* Observa que siempre es necesario declarar el número de columnas (TAM). Si no lo
   haces, el compilador marcará un error de sintaxis. */

int main(void)
{
    int MAT[TAM][TAM];

    Lectura(MAT, TAM);
    Imprime(MAT, TAM);

    return 0;
}

void Lectura(int A[][TAM], int F)
/* La función Lectura se utiliza para leer un arreglo bidimensional. Observa
   que sólo se requiere pasar el número de filas (o tamaño total) ya que la matriz
   es cuadrada. */
{
    int I, J;
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < F; J++)
        {
            printf("Ingrese el elemento [%d][%d]: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
    }
}

void Imprime(int A[][TAM], int F)
/* La función Imprime se utiliza para escribir los elementos de la diagonal principal
   de una matriz cuadrada de F filas y columnas. */
{
    int I, J;

    printf("\n--- Elementos de la Diagonal Principal ---\n");
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < TAM; J++)
        {
            /* La condición clave: la diagonal principal ocurre exactamente
               cuando el número de fila es igual al número de columna (I == J). */
            if (I == J)
            {
                printf("Diagonal [%d][%d]: %d\n", I, J, A[I][J]);
            }
        }
    }
}

