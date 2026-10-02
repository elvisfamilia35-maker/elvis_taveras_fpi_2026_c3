#include <stdio.h>

/* Par, impar o nulo.
El programa evalúa si un número entero es cero (nulo), par o impar.
NUM: variable de tipo entero. */

int main(void)
{
    int NUM;

    printf("Ingrese el número: ");
    scanf("%d", &NUM);

    if (NUM == 0)
    {
        printf("\nNulo\n");
    }
    else if (NUM % 2 == 0)
    {
        printf("\nPar\n");
    }
    else
    {
        printf("\nImpar\n");
    }

    return 0;
}
