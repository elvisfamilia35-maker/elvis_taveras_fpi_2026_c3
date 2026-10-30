#include <stdio.h>

/* Empresa textil.
   El programa, al recibir un arreglo tridimensional que contiene información
   sobre las ventas mensuales de tres departamentos en los últimos ocho años,
   genera información estadística valiosa para la empresa. */

const int MES = 12;
const int DEP = 3;
const int AÑO = 8;
/* Prototipos de funciones. */
void Lectura(float [][DEP][AÑO], int, int, int);
void Funcion1(float [][DEP][AÑO], int, int, int);
void Funcion2(float [][DEP][AÑO], int, int, int);
void Funcion3(float [][DEP][AÑO], int, int, int);

int main(void)
{
    float PRO[MES][DEP][AÑO];

    Lectura(PRO, MES, DEP, AÑO);

    /* Se pasa '2' como cuarto argumento para evaluar específicamente el segundo año */
    Funcion1(PRO, MES, DEP, 2);

    Funcion2(PRO, MES, DEP, AÑO);
    Funcion3(PRO, MES, DEP, AÑO);

    printf("\n");
    return 0;
}

void Lectura(float A[][DEP][AÑO], int F, int C, int P)
/* La función Lectura se utiliza para leer un arreglo tridimensional de tipo
   real de F filas (meses), C columnas (departamentos) y P planos de profundidad (años). */
{
    int K, I, J;
    printf("\n--- Registro de Ventas de la Empresa Textil ---\n");
    for (K = 0; K < P; K++)
    {
        for (I = 0; I < F; I++)
        {
            for (J = 0; J < C; J++)
            {
                printf("Año: %d \t Mes: %d \t Departamento: %d - Ventas: ", K + 1, I + 1, J + 1);
                scanf("%f", &A[I][J][K]);
            }
        }
    }
}

void Funcion1(float A[][DEP][AÑO], int F, int C, int P)
/* Esta función se utiliza para obtener las ventas totales de la empresa
   en el año indicado por el parámetro P (en este caso, el segundo año -> P = 2). */
{
    int I, J;
    float SUM = 0.0;

    /* Nota: Se utiliza P - 1 para convertir el número de año al índice base 0 (año 2 -> índice 1) */
    for (I = 0; I < F; I++)
    {
        for (J = 0; J < C; J++)
        {
            SUM += A[I][J][P - 1];
        }
    }

    printf("\n========================================");
    printf("\nVentas totales de la empresa en el año %d: %.2f", P, SUM);
    printf("\n========================================");
}

void Funcion2(float A[][DEP][AÑO], int F, int C, int P)
/* Esta función se utiliza para obtener el departamento que tuvo las mayores
   ventas en el último año registrado (P - 1). Genera además el importe de las ventas. */
{
    int I, J;
    float SUM1 = 0.0, SUM2 = 0.0, SUM3 = 0.0;

    for (I = 0; I < F; I++)
    {
        for (J = 0; J < C; J++)
        {
            switch (J + 1)
            {
                case 1:
                    SUM1 += A[I][J][P - 1]; /* Departamento 1: Hilos */
                    break;
                case 2:
                    SUM2 += A[I][J][P - 1]; /* Departamento 2: Lanas */
                    break;
                case 3:
                    SUM3 += A[I][J][P - 1]; /* Departamento 3: Licra */
                    break;
            }
        }
    }

    printf("\n\n--- Análisis del Último Año ---");
    if (SUM1 > SUM2)
    {
        if (SUM1 > SUM3)
        {
            printf("\nDepartamento con mayores ventas en el último año: Hilos");
            printf("\nVentas: %.2f", SUM1);
        }
        else
        {
            printf("\nDepartamento con mayores ventas en el último año: Licra");
            printf("\nVentas: %.2f", SUM3);
        }
    }
    else
    {
        if (SUM2 > SUM3)
        {
            printf("\nDepartamento con mayores ventas en el último año: Lanas");
            printf("\nVentas: %.2f", SUM2);
        }
        else
        {
            printf("\nDepartamento con mayores ventas en el último año: Licra");
            printf("\nVentas: %.2f", SUM3);
        }
    }
}

void Funcion3(float A[][DEP][AÑO], int F, int C, int P)
/* Esta función se utiliza para obtener el departamento, mes y año exactos con la mayor
   venta individual registrada en todo el histórico. Escribe también el monto de las ventas. */
{
    int K, I, J, DE = 0, ME = 0, AN = 0;
    float VEN = -1.0;

    /* Tres ciclos anidados para recorrer completamente el cubo de datos (Años, Meses, Departamentos) */
    for (K = 0; K < P; K++)
    {
        for (I = 0; I < F; I++)
        {
            for (J = 0; J < C; J++)
            {
                if (A[I][J][K] > VEN)
                {
                    VEN = A[I][J][K];
                    DE = J; /* Guarda el índice del departamento */
                    ME = I; /* Guarda el índice del mes */
                    AN = K; /* Guarda el índice del año */
                }
            }
        }
    }

    printf("\n\n--- Récord Histórico de Ventas Máximas ---");
    printf("\nAño: %d \t Mes: %d \t Departamento: %d", AN + 1, ME + 1, DE + 1);
    printf("\nMonto máximo de ventas: %.2f\n", VEN);
}
