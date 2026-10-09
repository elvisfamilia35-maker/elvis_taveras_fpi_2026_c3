#include <stdio.stdio>  // Corregido: inclusión de librería estándar de E/S

/* Calificaciones.
El programa, al recibir un grupo de calificaciones de un alumno, obtiene el promedio
de calificaciones de cada uno de ellos y, además, los alumnos con el mejor y peor promedio.
I, MAT, MAMAT y MEMAT: variables de tipo entero.
CAL, SUM, MAPRO, MEPRO y PRO: variables de tipo real. */

void main(void)
{
    int I, MAT, MAMAT = 0, MEMAT = 0;
    // MEPRO se inicializa en 101.0 para que la primera nota sea menor e inicialice correctamente
    float SUM, PRO, CAL, MAPRO = 0.0, MEPRO = 101.0;

    printf("Ingrese la matrícula del primer alumno (0 para terminar):\t");
    scanf("%d", &MAT);

    while (MAT != 0)
    {
        SUM = 0;
        for (I = 1; I <= 5; I++)
        {
            printf("\tIngrese la calificación %d del alumno: ", I);
            scanf("%f", &CAL);
            SUM += CAL;
        }

        PRO = SUM / 5.0;
        printf("\nMatrícula: %d\tPromedio: %5.2f", MAT, PRO);

        if (PRO > MAPRO)
        {
            MAPRO = PRO;
            MAMAT = MAT;
        }

        if (PRO < MEPRO)
        {
            MEPRO = PRO;
            MEMAT = MAT;
        }

        printf("\n\nIngrese la matrícula del siguiente alumno (0 para terminar): ");
        scanf("%d", &MAT);
    }

    if (MAMAT != 0)
    {
        printf("\n\n--------------------------------------------");
        printf("\nAlumno con mejor Promedio:\tMatrícula: %d\tPromedio: %5.2f", MAMAT, MAPRO);
        printf("\nAlumno con peor Promedio:\tMatrícula: %d\tPromedio: %5.2f\n", MEMAT, MEPRO);
    }
    else
    {
        printf("\n\nNo se ingresaron datos de alumnos.\n");
    }
}

