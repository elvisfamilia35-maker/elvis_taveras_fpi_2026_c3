#include <stdio.h>

/* Fibonacci.
El programa calcula y escribe los primeros 50 números de la serie de Fibonacci.
I: variable entera para el contador.
PRI, SEG, SIG: variables enteras sin signo de 64 bits para evitar desbordamientos. */

int main(void)
{
    int I;
    unsigned long long PRI = 0, SEG = 1, SIG;

    printf("Los primeros 50 números de la serie de Fibonacci son:\n\n");
    printf("%llu\t%llu", PRI, SEG);

    for (I = 3; I <= 50; I++)
    {
        SIG = PRI + SEG;
        PRI = SEG;
        SEG = SIG;

        printf("\t%llu", SIG);

        /* Salto de línea cada 5 números para mejorar la visualización */
        if (I % 5 == 0)
        {
            printf("\n");
        }
    }

    printf("\n");

    return 0;
}
