#include <stdio.h>

/* Billete de ferrocarril.
El programa calcula el costo de un billete de ferrocarril teniendo en
cuenta la distancia entre las dos ciudades y el tiempo de permanencia
del pasajero.
DIS y TIE: variables de tipo entero.
BIL: variable de tipo real. */

int main(void)
{
    int DIS, TIE;
    float BIL;

    printf("Ingrese la distancia entre ciudades (en km) y el tiempo de estancia (en días): ");
    scanf("%d %d", &DIS, &TIE);

    /* Si el viaje de ida y vuelta supera los 500 km y la estancia es mayor a 10 días,
       se aplica un 20% de descuento (multiplicando por 0.8). */
    if ((DIS * 2 > 500) && (TIE > 10))
    {
        BIL = DIS * 2 * 0.19 * 0.8;
    }
    else
    {
        BIL = DIS * 2 * 0.19;
    }

    printf("\nCosto del billete: %7.2f\n", BIL);

    return 0;
}



