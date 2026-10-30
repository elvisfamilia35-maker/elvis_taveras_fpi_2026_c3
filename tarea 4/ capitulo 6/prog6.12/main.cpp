#include <stdio.h>

/* Lluvias.
   El programa, al recibir como dato un arreglo tridimensional que contiene
   información sobre lluvias, genera información estadística. */

const int PRO = 24;  /* Provincias (Filas) */
const int MES = 12;  /* Meses (Columnas) */
const int AÑO = 10;  /* Años (Profundidad) */

/* Prototipos de funciones. */
void Lectura(float [PRO][MES][AÑO], int, int, int);
void Funcion1(float [PRO][MES][AÑO], int, int, int);
void Funcion2(float [PRO][MES][AÑO], int, int, int);
void Funcion3(float [PRO][MES][AÑO], int, int, int);

int main(void)
{
    float LLU[PRO][MES][AÑO];

    Lectura(LLU, PRO, MES, AÑO);
    Funcion1(LLU, PRO, MES, AÑO);
    Funcion2(LLU, PRO, MES, AÑO);

    /* Se pasa '18' como parámetro de provincia y '5' como parámetro de año */
    Funcion3(LLU, 18, MES, 5);

    printf("\n");
    return 0;
}

void Lectura(float A[][MES][AÑO], int F, int C, int P)
/* Esta función se utiliza para leer un arreglo tridimensional de tipo real de
   F filas (provincias), C columnas (meses) y P planos de profundidad (años). */
{
    int K, I, J;
    printf("\n--- Registro de Datos Climatológicos ---\n");
    for (K = 0; K < P; K++)
    {
        for (I = 0; I < F; I++)
        {
            for (J = 0; J < C; J++)
            {
                printf("Año: %d \t Provincia: %d \t Mes: %d - Lluvia (mm): ", K + 1, I + 1, J + 1);
                scanf("%f", &A[I][J][K]);
            }
        }
    }
}

void Funcion1(float A[][MES][AÑO], int F, int C, int P)
/* Esta función localiza la provincia que tuvo el mayor promedio de precipitación
   pluvial a lo largo de los últimos 10 años. */
{
    int I, K, J, EMAY = -1;
    float ELLU = -1.0, SUM;

    for (I = 0; I < F; I++)
    {
        SUM = 0.0;
        /* Se recorren todos los años y todos los meses de la provincia I */
        for (K = 0; K < P; K++)
        {
            for (J = 0; J < C; J++)
            {
                SUM += A[I][J][K];
            }
        }
        /* Se calcula el promedio histórico general por mes para esa provincia */
        SUM /= (P * C);

        if (SUM > ELLU)
        {
            ELLU = SUM;
            EMAY = I;
        }
    }

    printf("\n==================================================");
    printf("\n[Informe 1] Provincia con mayor promedio histórico de lluvias: Provincia %d", EMAY + 1);
    printf("\nPromedio mensual registrado: %.2f mm", ELLU);
}

void Funcion2(float A[][MES][AÑO], int F, int C, int P)
/* Esta función localiza la provincia que tuvo el menor registro
   de lluvias durante el último año registrado (P - 1). */
{
    int I, J, EMEN = -1;
    float ELLU = 10000.0, SUM; /* Se inicializa con un valor alto para buscar el mínimo */

    for (I = 0; I < F; I++)
    {
        SUM = 0.0;
        /* Se suman los 12 meses exclusivamente del último año (P - 1) */
        for (J = 0; J < C; J++)
        {
            SUM += A[I][J][P - 1];
        }
        SUM /= C; /* Promedio mensual del último año */

        if (SUM < ELLU)
        {
            ELLU = SUM;
            EMEN = I;
        }
    }

    printf("\n[Informe 2] Provincia con menor registro anual de lluvias en el último año: Provincia %d", EMEN + 1);
    printf("\nPromedio mensual en el último año: %.2f mm", ELLU);
}

void Funcion3(float A[][MES][AÑO], int F, int C, int P)
/* Esta función localiza el mes con mayor registro de lluvias en una
   provincia específica (F = 18 -> índice 17) durante un año específico (P = 5 -> índice 4). */
{
    int J, EMES = -1;
    float ELLU = -1.0;

    int prov_idx = F - 1; /* Conversión a índice base 0 (18 - 1 = 17) */
    int año_idx = P - 1;  /* Conversión a índice base 0 (5 - 1 = 4) */

    for (J = 0; J < C; J++)
    {
        /* Se evalúan los 12 meses de esa provincia y año en específico */
        if (A[prov_idx][J][año_idx] > ELLU)
        {
            ELLU = A[prov_idx][J][año_idx];
            EMES = J;
        }
    }

    printf("\n[Informe 3] Provincia 18, Año 5 - Mes más lluvioso: Mes %d", EMES + 1);
    printf("\nPrecipitación máxima: %.2f mm\n", ELLU);
    printf("==================================================\n");
}
