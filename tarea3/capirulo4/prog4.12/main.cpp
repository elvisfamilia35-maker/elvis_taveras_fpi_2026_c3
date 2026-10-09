#include <stdio.h>  // Inclusión de la librería estándar para printf y scanf

/* Máximo común divisor.
El programa, al recibir como datos dos números enteros, calcula el máximo
común divisor de dichos números. */

int mcd(int, int); /* Prototipo de función */

int main(void)
{
    int NU1, NU2, RES;

    printf("Ingresa los dos números enteros (separados por un espacio): ");
    scanf("%d %d", &NU1, &NU2);

    RES = mcd(NU1, NU2);

    printf("\nEl máximo común divisor de %d y %d es: %d\n", NU1, NU2, RES);

    return 0;
}

int mcd(int N1, int N2)
/* Esta función calcula el máximo común divisor de N1 y N2. */
{
    int I;

    // Se determina el menor de los dos números
    I = (N1 < N2) ? N1 : N2;

    // El bucle busca desde el menor número hacia abajo (decreciente)
    // Se detiene cuando I divide exactamente a AMBOS números ((N1 % I != 0) || (N2 % I != 0))
    while ((N1 % I != 0) || (N2 % I != 0))
    {
        I--;
    }

    return I;
}
