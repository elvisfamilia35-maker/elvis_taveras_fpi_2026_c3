#include <stdio.h>

/* Suma cuadrados.
El programa, al recibir como datos un grupo de enteros positivos, obtiene el
cuadrado de los mismos y la suma correspondiente a dichos cuadrados. */

int main(void)
{
    int NUM;
    long CUA, SUC = 0;

    printf("\nIngrese un número entero -0 para terminar-:\t");
    scanf("%d", &NUM);

    while (NUM != 0)
    /* La condición es verdadera mientras el entero sea diferente de cero. */
    {
        CUA = (long)NUM * NUM; /* Cálculo directo del cuadrado */
        printf("%d al cuadrado es %ld\n", NUM, CUA);

        SUC = SUC + CUA;

        printf("\nIngrese un número entero -0 para terminar-:\t");
        scanf("%d", &NUM);
    }

    printf("\nLa suma de los cuadrados es %ld\n", SUC);

    return 0;
}
