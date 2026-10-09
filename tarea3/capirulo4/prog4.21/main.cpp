#include <stdio.h>  // Librería para printf y scanf

/* Funciones y parámetros. */

int z, y; /* Variables globales */

int F1(float);
void F2(float, int *); /* Prototipos de funciones */

int main(void)
{
    int w;
    float x;

    z = 5;
    y = 7;
    w = 2;

    x = (float)y / z; /* 7.0 / 5 = 1.40 */

    printf("\nPrograma Principal: %d %d %.2f %d", z, y, x, w);

    F2(x, &w);

    printf("\nPrograma Principal: %d %d %.2f %d\n", z, y, x, w);

    return 0;
}

int F1(float x)
{
    int k;

    if (x != 0)
    {
        k = z - y;
        x++;
    }
    else
    {
        k = z + y;
    }

    printf("\nF1: %d %d %.2f %d", z, y, x, k);

    return k;
}

void F2(float t, int *r)
{
    int y; /* Variable local 'y' en F2 */

    y = 5;
    z = 0; /* Modifica la variable GLOBAL 'z' */

    printf("\nF2: %d %d %.2f %d", z, y, t, *r);

    if (z == 0)
    {
        z = (*r) * 2;       /* z global = 2 * 2 = 4 */
        t = (float)z / 3;   /* t local = 4.0 / 3 = 1.33 */

        printf("\nIngresa el valor: ");
        scanf("%d", r);     /* Se ingresa el valor 6 (modifica 'w' de main) */

        printf("\nF2: %d %d %.2f %d", z, y, t, *r);
    }
    else
    {
        z = (*r) * 2;
        printf("\nF2: %d %d %.2f %d", z, y, t, *r);
    }

    *r = F1(t); /* Llama a F1(1.33) y asigna el retorno a 'w' de main */
}
