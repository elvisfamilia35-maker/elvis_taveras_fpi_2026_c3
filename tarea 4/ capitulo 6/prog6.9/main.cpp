#include <stdio.h>

/* Asigna.
   El programa, al recibir un arreglo bidimensional cuadrado, asigna elementos en
   función del módulo (residuo) a un arreglo unidimensional. */

void Lectura(int [][10], int);
void Calcula(int [][10], float [], int);
float Mod0(int [][10], int, int);
float Mod1(int [][10], int); /* Prototipos de funciones. */
float Mod2(int [][10], int, int);
void Imprime(float [10], int);

int main(void)
{
    int MAT[10][10], TAM;
    float VEC[10];

    /* Se verifica que el tamaño de la matriz sea válido (1 a 10) */
    do
    {
        printf("Ingrese el tamaño de la matriz (1-10): ");
        scanf("%d", &TAM);
    }
    while (TAM > 10 || TAM < 1);

    printf("\n--- Lectura de la Matriz ---");
    Lectura(MAT, TAM);

    Calcula(MAT, VEC, TAM);

    printf("\n--- Impresión del Arreglo Resultante ---");
    Imprime(VEC, TAM);

    return 0;
}

void Lectura(int A[][10], int N)
/* La función Lectura se utiliza para leer un arreglo bidimensional cuadrado
   de tipo entero de N por N. */
{
    int I, J;
    printf("\n");
    for (I = 0; I < N; I++)
    {
        for (J = 0; J < N; J++)
        {
            printf("Ingrese el elemento [%d][%d]: ", I + 1, J + 1);
            scanf("%d", &A[I][J]);
        }
    }
}

void Calcula(int A[][10], float B[], int N)
/* Esta función evalúa el residuo del índice I entre 3 (I % 3) mediante un switch
   para decidir qué operación matemática aplicar para cada elemento del vector B. */
{
    int I;
    for (I = 0; I < N; I++)
    {
        switch (I % 3)
        {
            case 1:
                B[I] = Mod1(A, I);
                break;
            case 2:
                B[I] = Mod2(A, I, N);
                break;
            default: /* case 0 */
                B[I] = Mod0(A, I, N);
                break;
        }
    }
}

float Mod0(int A[][10], int K, int M)
/* Esta función calcula el cociente entre una productoria y una sumatoria
   de los elementos de una columna K específica. */
{
    int I;
    float PRO = 1.0, SUM = 0.0;

    for (I = 0; I < M; I++)
    {
        PRO *= A[I][K]; /* Productoria de la columna K */
        SUM += A[I][K]; /* Sumativa de la columna K */
    }

    /* Evitar división por cero si la suma da 0 (recomendación de seguridad) */
    if (SUM == 0.0) return 0.0;

    return (PRO / SUM);
}

float Mod1(int A[][10], int N)
/* Esta función obtiene el resultado de una sumatoria de los elementos
   de la fila N desde la columna 0 hasta la columna N. */
{
    int I;
    float SUM = 0.0;

    for (I = 0; I <= N; I++)
    {
        SUM += A[N][I];
    }

    return (SUM);
}

float Mod2(int A[][10], int N, int M)
/* Esta función obtiene el resultado de la productoria de los elementos
   de la columna N desde la fila N hasta el final de la matriz (M). */
{
    int I;
    float PRO = 1.0;

    for (I = N; I < M; I++)
    {
        PRO *= A[I][N];
    }

    return (PRO);
}

void Imprime(float B[], int N)
/* Esta función se utiliza para escribir un arreglo unidimensional de tipo
   real de N elementos. */
{
    int I;
    printf("\n");
    for (I = 0; I < N; I++)
    {
        printf("Elemento [%d]: %.2f\n", I, B[I]);
    }
}
