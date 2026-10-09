#include <stdio.h>  // Librería estándar para printf

/* Paso de una función como parámetro mediante un puntero a función. */

int Suma(int X, int Y)
/* Regresa la suma de X e Y. */
{
    return (X + Y);
}

int Resta(int X, int Y)
/* Regresa la resta de X e Y. */
{
    return (X - Y);
}

/* Control recibe:
   1. int (*apf)(int, int): Un puntero a una función que recibe dos enteros y devuelve un entero.
   2. int X, int Y: Los dos operandos enteros. */
int Control(int (*apf)(int, int), int X, int Y)
{
    int RES;
    RES = (*apf)(X, Y); /* Llama a la función apuntada por 'apf' (Suma o Resta) */
    return (RES);
}

int main(void)
{
    int R1, R2;

    // Se pasa el nombre de la función (que actúa como su dirección de memoria)
    R1 = Control(Suma, 15, 5);  // Evalúa Suma(15, 5) -> 20
    R2 = Control(Resta, 10, 4); // Evalúa Resta(10, 4) -> 6

    printf("\nResultado 1: %d", R1);
    printf("\nResultado 2: %d\n", R2);

    return 0;
}
