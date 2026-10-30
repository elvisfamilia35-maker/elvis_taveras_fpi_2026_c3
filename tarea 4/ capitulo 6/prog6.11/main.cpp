#include <stdio.h>

/* Casa de bolsa.
   El programa, al recibir como datos los precios mensuales de las acciones de sus
   cinco fondos de inversión, además del precio de las acciones al 31 de diciembre
   del 2003, genera información estadística importante para la empresa. */

/* Prototipos de funciones. */
void LecturaM(float [][12], int, int);
void LecturaV(float *, int);
void F1(float [][12], int, int, float *, float *);
void F2(float [][12], int, int);
void F3(float *, int);

int main(void)
{
    float FON[5][12], PRE[5], REN[5];
    /* FON: Matriz de 5 fondos x 12 meses de precios
       PRE: Precios al 31/12/2003 para cada fondo
       REN: Arreglo para almacenar el rendimiento anual de cada fondo */

    LecturaM(FON, 5, 12);
    LecturaV(PRE, 5);

    F1(FON, 5, 12, PRE, REN);
    F2(FON, 5, 12);
    F3(REN, 5);

    printf("\n");
    return 0;
}

void LecturaM(float A[][12], int F, int C)
/* Esta función se utiliza para leer un arreglo bidimensional de tipo real de F
   filas (fondos) y C columnas (meses). */
{
    int I, J;
    printf("\n--- Registro de Precios Mensuales de los Fondos ---\n");
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < C; J++)
        {
            printf("Precio fondo %d \t mes %d: ", I + 1, J + 1);
            scanf("%f", &A[I][J]);
        }
    }
}

void LecturaV(float A[], int T)
/* Esta función se utiliza para leer un arreglo unidimensional de tipo real de T
   elementos (precios base iniciales). */
{
    int I;
    printf("\n--- Registro de Precios Base (31/12/2003) ---\n");
    for (I = 0; I < T; I++)
    {
        printf("Precio Fondo %d al 31/12/2003: ", I + 1);
        scanf("%f", &A[I]);
    }
}

void F1(float A[][12], int F, int C, float B[], float V[])
/* La función F1 se utiliza para calcular el rendimiento anual de los fondos de
   inversión comparando el último mes contra el precio base.
   El resultado se almacena en el arreglo unidimensional V. */
{
    int I;
    printf("\n========================================");
    printf("\n   RENDIMIENTOS ANUALES DE LOS FONDOS   ");
    printf("\n========================================");

    for (I = 0; I < F; I++)
    {
        /* Fórmula de rendimiento porcentual: ((Precio Final - Precio Base) / Precio Base) * 100 */
        V[I] = (A[I][C - 1] - B[I]) / B[I] * 100;
        printf("\nFondo %d: %6.2f%%", I + 1, V[I]);
    }
}

void F2(float A[][12], int F, int C)
/* Esta función calcula el promedio anualizado (precio medio mensual) de las
   acciones de los diferentes fondos a lo largo de los 12 meses. */
{
    int I, J;
    float SUM, PRO;

    printf("\n\n========================================");
    printf("\n  PROMEDIO MENSUAL DE CADA FONDO       ");
    printf("\n========================================");

    for (I = 0; I < F; I++)
    {
        SUM = 0.0;
        for (J = 0; J < C; J++)
        {
            SUM += A[I][J];
        }
        PRO = SUM / C; /* Promedio de los 12 meses para el fondo I */
        printf("\nFondo %d - Promedio mensual: %8.2f", I + 1, PRO);
    }
}

void F3(float A[], int C)
/* Esta función analiza el arreglo de rendimientos (REN) para identificar
   cuál fue el mejor fondo (mayor rendimiento) y cuál el peor (menor rendimiento). */
{
    int I, M = 0, P = 0;
    float ME = A[0], PE = A[0];

    for (I = 1; I < C; I++)
    {
        /* Buscando el máximo (Mejor fondo) */
        if (A[I] > ME)
        {
            ME = A[I];
            M = I;
        }
        /* Buscando el mínimo (Peor fondo) */
        if (A[I] < PE)
        {
            PE = A[I];
            P = I;
        }
    }

    printf("\n\n========================================");
    printf("\n     MEJOR Y PEOR FONDO DE INVERSIÓN    ");
    printf("\n========================================");
    printf("\nMejor fondo:  %d \t Rendimiento: %6.2f%%", M + 1, ME);
    printf("\nPeor fondo:   %d \t Rendimiento: %6.2f%%\n", P + 1, PE);
    printf("========================================\n");
}
