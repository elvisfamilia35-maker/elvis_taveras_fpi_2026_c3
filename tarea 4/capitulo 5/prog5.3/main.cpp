#include <stdio.h>

/* Apuntadores, variables y valores. */
int main(void)
{
    /* Declaración e inicialización de variables y arreglo
       (deducida a partir de los comentarios del ejercicio original) */
    int X = 3, Y = 5;
    int Z[5] = {2, 4, 6, 8, 10};
    int *IX; /* IX representa un apuntador a un entero. */

    /* Primer estado */
    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = &X; /* IX apunta a X. IX tiene la dirección de X. */
    Y = *IX; /* Y toma el valor de X, ahora vale 3. */
    *IX = 1; /* X se modifica, ahora vale 1. */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = &Z[2]; /* IX apunta al tercer elemento del arreglo Z. */
    Y = *IX; /* Y toma el valor de Z[2], ahora vale 6. */
    *IX = 15; /* Z[2] se modifica, ahora vale 15. */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    X = *IX + 5; /* X se modifica, ahora vale Z[2] + 5 = 20. */
    *IX = *IX - 5; /* Z[2] se modifica, ahora vale 10. */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    ++*IX; /* Z[2] se modifica, se incrementa en 1. Z[2] ahora vale 11. */
    *IX += 1; /* Z[2] se vuelve a modificar, ahora vale 12. */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    X = *(IX + 1); /* X toma el valor de Z[3] (8). IX no se reasigna. */
    Y = *IX; /* Y se modifica, toma el valor actual de Z[2] (12). */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = IX + 1; /* IX ahora apunta al cuarto elemento de Z (Z[3]). */
    Y = *IX; /* Y toma el valor de Z[3] (8). */

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    /* Advertencia: Los siguientes bloques mueven el apuntador fuera de los límites del arreglo,
       lo que genera un comportamiento indefinido (lectura de basura en memoria). */
    IX = IX + 4;
    Y = *IX;

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    IX = &X;
    IX = IX + 1;
    X = *IX;

    printf("\nX = %d \t Y = %d \t Z[0] = %d \t Z[1] = %d \t Z[2] = %d \t Z[3] = %d \t Z[4] = %d\n",
           X, Y, Z[0], Z[1], Z[2], Z[3], Z[4]);

    return 0;
}
