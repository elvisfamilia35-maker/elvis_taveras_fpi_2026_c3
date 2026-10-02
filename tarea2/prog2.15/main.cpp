#include <stdio.h>

/* Spa.
El programa, al recibir como datos el tipo de tratamiento, la edad y el
número de días de internación de un cliente en un spa, calcula el costo
total del tratamiento.
TRA, EDA, DIA: variables de tipo entero.
COS: variable de tipo real. */

int main(void)
{
    int TRA, EDA, DIA;
    float COS;

    printf("Ingrese tipo de tratamiento, edad y días: ");
    scanf("%d %d %d", &TRA, &EDA, &DIA);

    switch(TRA)
    {
        case 1: COS = DIA * 2800.0f; break;
        case 2: COS = DIA * 1950.0f; break;
        case 3: COS = DIA * 2500.0f; break;
        case 4: COS = DIA * 1150.0f; break;
        default: COS = -1.0f; break;
    }

    if (COS != -1.0f)
    {
        /* Aplicación de descuentos según la edad */
        if (EDA >= 60)
            COS = COS * 0.75f; /* 25% de descuento para adultos mayores */
        else if (EDA <= 25)
            COS = COS * 0.85f; /* 15% de descuento para jóvenes */

        printf("\nClave tratamiento: %d\t Días: %d\t Costo total: %8.2f\n", TRA, DIA, COS);
    }
    else
    {
        printf("\nLa clave del tratamiento es incorrecta.\n");
    }

    return 0;
}

