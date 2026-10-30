#include <stdio.h>

/* Apuntadores y arreglos */
int main(void)
{
    int X = 5, Y = 8, V[5] = {1, 3, 5, 7, 9};
    int *AY, *AX;

    AY = &Y;          /* AY apunta a la variable Y */
    X = *AY;          /* X toma el valor de Y (ahora X = 8) */
    *AY = V[3] + V[2]; /* Y toma la suma de V[3] (7) + V[2] (5). Y ahora vale 12 */

    /* Primera impresión */
    printf("\nX=%d \t Y=%d \t V[0]=%d \t V[1]=%d \t V[2]=%d \t V[3]=%d \t V[4]=%d",
           X, Y, V[0], V[1], V[2], V[3], V[4]);

    AX = &V[V[0] * V[1]]; /* V[0]*V[1] es 1 * 3 = 3. AX apunta a la posición V[3] */
    X = *AX;              /* X toma el valor al que apunta AX (V[3], que es 7) */
    Y = *AX * V[1];       /* Y se actualiza a V[3] * V[1] = 7 * 3 = 21 */
    *AX = *AY - 3;        /* El valor al que apunta AX (V[3]) se modifica: 21 - 3 = 18 */

    /* Segunda impresión */
    printf("\nX=%d \t Y=%d \t V[0]=%d \t V[1]=%d \t V[2]=%d \t V[3]=%d \t V[4]=%d\n",
           X, Y, V[0], V[1], V[2], V[3], V[4]);

    return 0;
}
