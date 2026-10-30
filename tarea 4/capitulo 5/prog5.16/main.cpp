#include <stdio.h>

/* Apuntadores y arreglos */
int main(void)
{
    /* Nota: Al declarar V2[4] = {6}, por defecto las posiciones restantes se inicializan en 0: {6, 0, 0, 0} */
    int V1[4] = {2, 3, 4, 7}, V2[4] = {6};
    int *AX, *AY;

    AX = &V1[3]; /* AX apunta a V1[3] (valor 7) */
    AY = &V2[2]; /* AY apunta a V2[2] (valor 0) */

    V1[V2[0] - V1[2]] = *AY;
    /* V2[0] es 6, V1[2] es 4. El índice es 6 - 4 = 2.
       Por lo tanto, V1[2] toma el valor de *AY (0). V1[2] ahora vale 0. */

    *AY = *AX - V1[0];
    /* El valor al que apunta AY (V2[2]) se modifica:
       *AX es V1[3] (7), V1[0] es 2. 7 - 2 = 5. V2[2] ahora vale 5. */

    /* Primera impresión */
    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    V2[1] = ++*AX;
    /* Pre-incremento: Se incrementa el valor al que apunta AX (V1[3]) de 7 a 8,
       y ese nuevo valor se asigna a V2[1]. V1[3] = 8, V2[1] = 8. */

    V2[3] = (*AY)++;
    /* Post-incremento: Se asigna el valor actual de *AY (V2[2], que es 5) a V2[3].
       Luego, *AY se incrementa a 6. V2[3] = 5, V2[2] = 6. */

    *AX += 2;
    /* Al valor al que apunta AX (V1[3], que ahora es 8) se le suman 2.
       V1[3] ahora vale 10. */

    /* Segunda impresión */
    printf("\nV1[0]=%d V1[1]=%d V1[2]=%d V1[3]=%d \tV2[0]=%d V2[1]=%d V2[2]=%d V2[3]=%d\n",
           V1[0], V1[1], V1[2], V1[3], V2[0], V2[1], V2[2], V2[3]);

    return 0;
}
