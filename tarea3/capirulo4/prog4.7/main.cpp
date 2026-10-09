#include <stdio.h>  // Inclusión de la librería estándar para printf

/* Prueba de parámetros por valor. */
int f1(int); /* Prototipo de función: recibe un entero por valor */

int main(void)
{
    int I, K = 4;

    for (I = 1; I <= 3; I++)
    {
        // Se pre-incrementa K (++K) antes de imprimir
        printf("\n\nValor de K antes de llamar a la función: %d", ++K);

        // Se imprime el valor retornado por f1(K), pero K no cambia localmente
        printf("\nValor de K después de llamar a la función: %d", f1(K));
    }

    printf("\n");
    return 0;
}

int f1(int R) /* 'R' es una copia independiente de 'K' */
{
    R += R;   // Duplica el valor de la copia (R = R + R)
    return (R); /* Retorna el resultado */
}
