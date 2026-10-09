#include <stdio.h>  // Inclusión de la librería para printf

/* Cubo-3.
El programa calcula el cubo de los 10 primeros números naturales con la
ayuda de una función y utilizando parámetros por valor. */

int cubo(int); /* Prototipo de función. Recibe un entero como parámetro. */

int main(void)
{
    int I;

    for (I = 1; I <= 10; I++)
    {
        // Se pasa 'I' como argumento por valor y se imprime su valor con %d
        printf("\nEl cubo de %d es: %d", I, cubo(I));
    }

    printf("\n");
    return 0;
}

int cubo(int K) /* K recibe una copia del valor enviado desde main */
{
    return (K * K * K); /* Calcula y retorna el cubo de K */
}
