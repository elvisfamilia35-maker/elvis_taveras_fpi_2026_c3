#include <stdio.h>
#include <math.h>

/* Expresión.
El programa, al recibir como datos tres valores enteros, establece si los
mismos satisfacen una expresión determinada (R^4 - T^3 + 4*Q^2 < 820).
R, T y Q: variables de tipo entero.
RES: variable de tipo real. */

int main(void)
{
    float RES;
    int R, T, Q;

    printf("Ingrese los valores de R, T y Q: ");
    scanf("%d %d %d", &R, &T, &Q);

    /* Evaluación de la expresión matemática: R^4 - T^3 + 4*(Q^2) */
    RES = pow(R, 4) - pow(T, 3) + 4 * pow(Q, 2);

    if (RES < 820)
    {
        printf("\nSatisfacen la condición (RES = %.2f < 820):", RES);
        printf("\nR = %d\tT = %d\tQ = %d\n", R, T, Q);
    }
    else
    {
        printf("\nNo satisfacen la condición (RES = %.2f >= 820).\n", RES);
    }

    return 0;
}
