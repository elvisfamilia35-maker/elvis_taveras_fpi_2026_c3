#include <stdio.h>

/* Conflicto de variables con el mismo nombre en C++ */
void f1(void); /* Prototipo de función. */
int K = 5;     /* Variable global. */

int main(void)
{
    int I;
    for (I = 1; I <= 3; I++)
    {
        f1();
    }
    return 0;
}

void f1(void)
{
    int K = 2; /* Variable local K que oculta a la global K */

    K += K;    /* K local pasa a ser 4 (2 + 2) */
    printf("\n\nEl valor de la variable local es: %d", K);

    ::K = ::K + K; /* ::K global (inicialmente 5) + K local (4) = 9 */
    printf("\nEl valor de la variable global es: %d", ::K);
}
