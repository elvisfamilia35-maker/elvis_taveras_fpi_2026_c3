
#include <stdio.h>  // Inclusión de la librería estándar de entrada y salida

/* Múltiplo.
El programa, al recibir como datos dos números enteros, determina si
el segundo es múltiplo del primero. */

int multiplo(int, int); /* Prototipo de función */

int main(void)
{
    int NU1, NU2, RES;

    printf("Ingresa los dos números (separados por un espacio): ");
    scanf("%d %d", &NU1, &NU2);

    RES = multiplo(NU1, NU2);

    if (RES)
    {
        printf("\nEl segundo número (%d) es múltiplo del primero (%d).\n", NU2, NU1);
    }
    else
    {
        printf("\nEl segundo número (%d) NO es múltiplo del primero (%d).\n", NU2, NU1);
    }

    return 0;
}

int multiplo(int N1, int N2)
/* Determina si N2 es múltiplo de N1. Devuelve 1 si es verdadero, 0 si es falso. */
{
    // Validación para evitar la división entre cero
    if (N1 == 0)
    {
        return 0;
    }

    if ((N2 % N1) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
