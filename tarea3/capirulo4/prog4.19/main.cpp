#include <stdio.h>  // Librería para la función printf

/* Variables globales */
int a, b, c, d;

/* Prototipos de funciones */
void funcion1(int, int *, int *);
int funcion2(int *, int);

int main(void)
{
    int a; /* Variable local 'a' (oculta a la global 'a' en main) */

    a = 1;
    b = 2;
    c = 3;
    d = 4;

    printf("\n%d %d %d %d", a, b, c, d);

    a = funcion2(&a, c);

    printf("\n%d %d %d %d\n", a, b, c, d);

    return 0;
}

void funcion1(int r, int *b, int *c)
{
    int d; /* Variable local 'd' en funcion1 */

    a = *c;           /* Asigna a la GLOBAL 'a' el valor apuntado por 'c' */
    d = a + 3 + *b;   /* 'd' local = a + 3 + *b */

    if (r) /* Como r = -1 (diferente de cero), se evalúa como VERDADERO */
    {
        *b = *b + 2;
        *c = *c + 3;
        printf("\n%d %d %d %d", a, *b, *c, d);
    }
    else
    {
        *b = *b + 5;
        *c = *c + 4;
        printf("\n%d %d %d %d", a, *b, *c, d);
    }
}

int funcion2(int *d, int c)
{
    int b; /* Variable local 'b' en funcion2 */

    a = 1; /* Asigna 1 a la GLOBAL 'a' */
    b = 7; /* Asigna 7 a la LOCAL 'b' */

    /* Llama a funcion1 enviando:
       r = -1
       *b en funcion1 apunta a la 'a' local de main (enviada como *d)
       *c en funcion1 apunta a la 'b' local de funcion2 (&b) */
    funcion1(-1, d, &b);

    printf("\n%d %d %d %d", a, b, c, *d);

    c += 3;    /* Incrementa la copia LOCAL 'c' */
    (*d) += 2; /* Incrementa la 'a' local de main (vía puntero *d) */

    printf("\n%d %d %d %d", a, b, c, *d);

    return (c); /* Retorna la 'c' local de funcion2 (3 + 3 = 6) */
}

