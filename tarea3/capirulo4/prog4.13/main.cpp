#include <stdio.h>  // Entrada y salida estándar (printf, scanf)
#include <math.h>   // Funciones matemáticas (pow)

/* Pares e impares.
El programa, al recibir como datos N números enteros, calcula cuántos
de ellos son pares y cuántos impares, con la ayuda de una función. */

void parimp(int, int *, int *); /* Prototipo de función */

int main(void)
{
    int I, N, NUM, PAR = 0, IMP = 0;

    printf("Ingresa el número de datos: ");
    scanf("%d", &N);

    for (I = 1; I <= N; I++)
    {
        printf("Ingresa el número %d: ", I);
        scanf("%d", &NUM);

        // Se pasa NUM por valor, y las direcciones de PAR e IMP por referencia (&)
        parimp(NUM, &PAR, &IMP);
    }

    printf("\nNúmero de pares: %d", PAR);
    printf("\nNúmero de impares: %d\n", IMP);

    return 0;
}

void parimp(int NUM, int *P, int *I)
/* La función incrementa el parámetro *P o *I por referencia según sea par o impar. */
{
    int RES;

    // (-1)^NUM da 1 para pares y -1 para impares
    RES = (int)pow(-1, NUM);

    if (RES > 0)
        *P += 1; // Incrementa el contador de pares en la dirección apuntada por P
    else if (RES < 0)
        *I += 1; // Incrementa el contador de impares en la dirección apuntada por I
}
