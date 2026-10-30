#include <stdio.h>

/* Ordenación por inserción directa. */
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
/* La función Ordena utiliza el método de inserción directa para ordenar
   los elementos del arreglo unidimensional A de forma ascendente. */
{
    int AUX, L, I;

    for (I = 1; I < T; I++) /* Comienza desde el segundo elemento (índice 1) */
    {
        AUX = A[I]; /* Se guarda temporalmente el elemento a evaluar */
        L = I - 1;  /* L apunta al último elemento de la sub-lista ordenada */

        /* Desplaza hacia la derecha los elementos mayores que AUX */
        while ((L >= 0) && (AUX < A[L]))
        {
            A[L + 1] = A[L];
            L--;
        }

        /* Inserta el elemento AUX en la posición correcta */
        A[L + 1] = AUX;
    }
}
