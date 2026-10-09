#include <stdio.h>

/* Combinación de variables globales y locales, y parámetros por valor y por referencia. */

int a, b, c, d; /* Variables globales (inicializadas automáticamente en 0) */

void funcion1(int *, int *);
int funcion2(int, int *);

int main(void)
{
    int a; /* Variable local 'a' (oculta a la global 'a' dentro de main) */

    a = 1; /* Asigna 1 a la variable local 'a' */
    b = 2; /* Asigna valores a las variables globales b, c y d */
    c = 3;
    d = 4;

    printf("\n%d %d %d %d", a, b, c, d);

    funcion1(&b, &c);
    printf("\n%d %d %d %d", a, b, c, d);

    a = funcion2(c, &d);
    printf("\n%d %d %d %d\n", a, b, c, d);

    return 0;
}

void funcion1(int *b, int *c)
{
    int d; /* Variable local 'd' (oculta a la global 'd' dentro de funcion1) */

    a = 5; /* Modifica la variable GLOBAL 'a' (ya que no hay 'a' local aquí) */
    d = 3; /* Modifica la variable LOCAL 'd' */

    (*b)++;    /* Incrementa la global 'b' por referencia (2 + 1 = 3) */
    (*c) += 2; /* Incrementa la global 'c' por referencia (3 + 2 = 5) */

    printf("\n%d %d %d %d", a, *b, *c, d);
}

int funcion2(int c, int *d)
{
    int b; /* Variable local 'b' (oculta a la global 'b' dentro de funcion2) */

    a++;    /* Incrementa la GLOBAL 'a' (pasa de 5 a 6) */
    b = 7;  /* Asigna 7 a la LOCAL 'b' */
    c += 3; /* Modifica la LOCAL 'c' (parámetro por valor: 5 + 3 = 8) */
    (*d) += 2; /* Modifica la GLOBAL 'd' por referencia (4 + 2 = 6) */

    printf("\n%d %d %d %d", a, b, c, *d);

    return (c); /* Retorna 8 */
}
