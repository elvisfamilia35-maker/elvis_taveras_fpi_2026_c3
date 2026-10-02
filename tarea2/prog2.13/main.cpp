#include <stdio.h>
#include <math.h>

/* Función.
El programa, al recibir como dato un valor entero, calcula el resultado de
una función.
Y: variable de tipo entero.
X: variable de tipo real. */

int main(void)
{
    float X;
    int Y;

    printf("Ingrese el valor de Y: ");
    scanf("%d", &Y);

    if (Y < 0 || Y > 50)
    {
        X = 0;
    }
    else if (Y == 0)
    {
        /* Protección contra la división por cero */
        printf("\nError: No se puede dividir entre cero cuando Y = 0.\n");
        return 1;
    }
    else if (Y <= 10)
    {
        /* Se usa 4.0f para forzar la división flotante */
        X = 4.0f / Y - Y;
    }
    else if (Y <= 25)
    {
        X = pow(Y, 3) - 12;
    }
    else
    {
        X = pow(Y, 2) + pow(Y, 3) - 18;
    }

    printf("\nY = %d\tX = %8.2f\n", Y, X);

    return 0;
}
