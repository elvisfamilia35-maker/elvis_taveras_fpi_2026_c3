#include <stdio.h>

/* Apuntadores y arreglos */
int main(void)
{
    /* V1 tiene 4 elementos, V2 tiene {2, 4} (las posiciones restantes V2[2] y V2[3] se inicializan en 0) */
    int V1[4] = {1, 3, 5, 7}, V2[4] = {2, 4};
    int *AX, *AY;

    AX = &V1[2]; /* AX apunta a V1[2] (valor 5) */
    AY = &V2[2]; /* AY apunta a V2[2] (valor 0) */

    V2[2] = *(AX + 1);
    /* AX apunta a V1[2]. (AX + 1) apunta a V1[3] (valor 7).
       Por lo tanto, V2[2] toma el valor 7. V2[2] ahora es 7. */

    V2[3] = *AX;
    /* *AX es V1[2] (valor 5).
       V2[3] toma el valor 5. V2[3] ahora es 5. */

    AX = AX + 1;
    /* AX ahora apunta al siguiente elemento, es decir, V1[3] (valor 7). */

    V1[0] = *AX;
    /* V1[0] toma el valor al que apunta AX (V1[3], que es 7).
       V1[0] ahora vale 7. (V1 queda como {7, 3, 5, 7}). */

    /* Primera impresión (corregida) */
    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    V1[2] = *AY;
    /* *AY apunta a V2[2] (que ahora vale 7).
       V1[2] toma el valor 7. V1[2] ahora es 7. (V1 queda como {7, 3, 7, 7}). */

    V1[1] --*AY; /* Nota: Corregido a V1[1] = --*AY (Pre-decremento) */
    V1[1] = --*AY;
    /* Pre-decremento sobre *AY (V2[2]): su valor baja de 7 a 6.
       Luego, V1[1] toma ese nuevo valor (6). V1[1] = 6, V2[2] = 6. */

    AX = AX + 1;
    /* AX apuntaba a V1[3]. Al sumarle 1, ahora apunta fuera del arreglo V1 (a la posición V1[4],
       lo cual genera un comportamiento de desbordamiento de memoria o valor basura). */

    V1[3] = *AX;
    /* V1[3] intenta tomar el valor de esa celda de memoria incorrecta/basura. */

    /* Segunda impresión */
    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d\n",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    return 0;
}
