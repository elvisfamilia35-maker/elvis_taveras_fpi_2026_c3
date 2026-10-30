#include <stdio.h>

/* Fábrica de lácteos.
   El programa, al recibir como datos las ventas mensuales de diferentes
   productos, obtiene información estadística valiosa para la empresa. */

/* Prototipos de funciones. */
void Lectura1(int [15][12]);
void Lectura2(float [], int);
void Funcion1(int [][12], int, int, float [], float []);
void Funcion2(float [], int);
void Funcion3(float [], int);

int main(void)
{
    int FAB[15][12] = {0}; /* Inicialización en 0 de la matriz (15 productos x 12 meses). */
    float COS[15], VEN[15]; /* COS = costo/precio por producto, VEN = venta total anual por producto */

    Lectura1(FAB);
    Lectura2(COS, 15);

    printf("\n--- Reporte de Ventas por Producto ---");
    Funcion1(FAB, 15, 12, COS, VEN);

    Funcion2(VEN, 15);
    Funcion3(VEN, 15);

    printf("\n");
    return 0;
}

void Lectura1(int A[][12])
/* Esta función se utiliza para almacenar en el arreglo bidimensional las
   diferentes transacciones que representan las ventas de los diferentes
   productos. El fin de datos está dado por –1 en cualquiera de los valores. */
{
    int MES, PRO, CAN;

    printf("Ingrese mes (1-12), tipo de producto (1-15) y cantidad vendida (-1 para terminar):\n");
    printf("Ejemplo: 3 5 120 (Marzo, Producto 5, 120 unidades)\n");
    printf("-> ");
    scanf("%d %d %d", &MES, &PRO, &CAN);

    while (MES != -1 && PRO != -1 && CAN != -1)
    {
        /* Se acumulan las cantidades en la matriz usando índices basados en 0 (-1) */
        A[MES - 1][PRO - 1] += CAN;

        printf("-> ");
        scanf("%d %d %d", &MES, &PRO, &CAN);
    }
}

void Lectura2(float A[], int N)
/* Esta función se utiliza para leer los precios de venta de los diferentes productos. */
{
    int I;
    printf("\n--- Registro de Precios Unitarios ---\n");
    for (I = 0; I < N; I++)
    {
        printf("Ingrese el precio del producto %d: ", I + 1);
        scanf("%f", &A[I]);
    }
}

void Funcion1(int A[][12], int F, int C, float V1[], float V2[])
/* Esta función se utiliza para calcular el monto de venta anual de cada uno
   de los productos. El resultado se almacena en el arreglo unidimensional V2. */
{
    int I, J, SUM;
    printf("\n");

    for (I = 0; I < F; I++)
    {
        SUM = 0;
        for (J = 0; J < C; J++)
        {
            SUM += A[I][J]; /* Suma las cantidades vendidas en los 12 meses para el producto I */
        }

        /* Multiplica el total de unidades vendidas por su precio unitario (V1[I]) */
        V2[I] = V1[I] * SUM;
        printf("\nTotal de ventas monetarias del producto %d: $%8.2f", I + 1, V2[I]);
    }
}

void Funcion2(float A[], int C)
/* Esta función se utiliza para calcular el monto total de ventas globales de la fábrica. */
{
    int I;
    float SUM = 0.0;

    for (I = 0; I < C; I++)
    {
        SUM += A[I];
    }

    printf("\n\n========================================");
    printf("\nTotal general de ventas de la fábrica: $%.2f", SUM);
    printf("\n========================================");
}

void Funcion3(float A[], int C)
/* Esta función se utiliza para obtener el tipo de producto que más dinero ha generado
   en ventas y el monto de las mismas. */
{
    int I, TPR = 0;
    float VEN = A[0];

    for (I = 1; I < C; I++)
    {
        if (VEN < A[I])
        {
            TPR = I;
            VEN = A[I];
        }
    }

    printf("\n\nTipo de Producto más exitoso en ventas: Producto %d \t Monto: $%.2f\n", TPR + 1, VEN);
}
