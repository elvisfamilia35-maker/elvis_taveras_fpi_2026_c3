#include <stdio.h>

/* Ordenación por selección directa. */
const int MAX = 100;

/* Prototipos de funciones. */
void Lectura(int *, int);
void Ordena(int *, int);
void Imprime(int *, int);

int main(void)
{
    int TAM, VEC[MAX];

    do
    {
        printf("Ingrese el tamaño del arreglo (1-100): ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1); /* Se verifica que el tamaño del arreglo sea correcto. */

    Lectura(VEC, TAM);
    Ordena(VEC, TAM);

    printf("\n--- Arreglo Ordenado ---");
    Imprime(VEC, TAM);

    return 0;
}

void Lectura(int A[], int T)
/* La función Lectura se utiliza para leer un arreglo unidimensional de T
   elementos de tipo entero. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

void Imprime(int A[], int T)
/* Esta función se utiliza para escribir un arreglo unidimensional
   ordenado de T elementos de tipo entero. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("\nA[%d]: %d", I, A[I]);
    }
    printf("\n");
}

void Ordena(int A[], int T)
/* La función Ordena utiliza el método de selección directa para ordenar
   los elementos del arreglo unidimensional A de forma ascendente. */
{
    int I, J, MEN, L;

    for (I = 0; I < (T - 1); I++)
    {
        MEN = A[I]; /* Se asume temporalmente que el elemento actual es el menor */
        L = I;      /* Se guarda la posición del menor */

        /* Se busca en el resto del arreglo un elemento que sea menor al actual */
        for (J = (I + 1); J < T; J++)
        {
            if (A[J] < MEN)
            {
                MEN = A[J];
                L = J;
            }
        }

        /* Se realiza el intercambio (swap) de los valores */
        A[L] = A[I];
        A[I] = MEN;
    }
}
