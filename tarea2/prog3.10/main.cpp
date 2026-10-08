#include <stdio.h>

/* Pares e impares.
El programa, al recibir como datos N números enteros, obtiene la suma de los
números pares y calcula el promedio de los impares.
I, N, NUM, SPA, SIM, CIM: variables de tipo entero. */

int main(void)
{
    int I, N, NUM, SPA = 0, SIM = 0, CIM = 0;

    printf("Ingrese el número de datos que se van a procesar:\t");
    scanf("%d", &N);

    if (N > 0)
    {
        for (I = 1; I <= N; I++)
        {
            printf("\nIngrese el número %d: ", I);
            scanf("%d", &NUM);

            /* Comprobación de paridad mediante el operador módulo */
            if (NUM % 2 == 0)
            {
                SPA = SPA + NUM; /* Suma de pares */
            }
            else
            {
                SIM = SIM + NUM; /* Suma de impares */
                CIM++;           /* Contador de impares */
            }
        }

        printf("\nLa suma de los números pares es: %d\n", SPA);

        /* Validación para evitar división entre cero al calcular el promedio */
        if (CIM > 0)
        {
            printf("El promedio de números impares es: %5.2f\n", (float)SIM / CIM);
        }
        else
        {
            printf("No se ingresaron números impares para calcular el promedio.\n");
        }
    }
    else
    {
        printf("\nEl valor de N es incorrecto (debe ser mayor que 0)\n");
    }

    return 0;
}
