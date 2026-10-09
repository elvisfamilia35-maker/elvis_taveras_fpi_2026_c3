#include <stdio.h>  // Inclusión de la librería estándar para printf

/* Prueba de parámetros por referencia. */
void f1(int *); /* Prototipo de función: recibe un puntero a entero */

int main(void)
{
    int I, K = 4;

    for (I = 1; I <= 3; I++)
    {
        // Se pre-incrementa K (++K) antes de imprimir
        printf("\n\nValor de K antes de llamar a la función: %d", ++K);

        // Se llama a la función pasando la dirección de memoria de K
        f1(&K);

        // Se imprime el valor de K ya modificado por la función
        printf("\nValor de K después de llamar a la función: %d", K);
    }

    printf("\n");
    return 0;
}

void f1(int *R) /* R recibe la dirección de memoria de K */
{
    // Modifica directamente el contenido de la memoria apuntada por R
    *R += *R;   // Es equivalente a: *R = *R + *R; (duplica el valor)
}
