#include <stdio.h>

/* Lanzamiento de martillo.
El programa, al recibir como dato N lanzamientos de martillo, calcula el promedio
de los lanzamientos de la atleta cubana.
I, N: variables de tipo entero.
LAN, SLA, PRO: variables de tipo real. */

int main(void)
{
    int I, N;
    float LAN, SLA = 0.0f, PRO;

    /* Validación del número de lanzamientos (debe estar entre 1 y 11) */
    do
    {
        printf("Ingrese el número de lanzamientos (1-11):\t");
        scanf("%d", &N);
    }
    while (N < 1 || N > 11);

    /* Captura de los lanzamientos y acumulación de los valores */
    for (I = 1; I <= N; I++)
    {
        printf("\nIngrese el lanzamiento %d: ", I);
        scanf("%f", &LAN);
        SLA = SLA + LAN;
    }

    PRO = SLA / N;

    printf("\nEl promedio de lanzamientos es: %.2f\n", PRO);

    return 0;
}
