#include <stdio.h>  // Librería estándar de entrada y salida (printf, scanf)

/* Rango de calificaciones.
El programa, al recibir como datos un grupo de calificaciones de un examen,
obtiene la frecuencia de cada rango de calificación establecido.
R1, R2, R3, R4, R5: variables de tipo entero para almacenar los contadores.
CAL: variable de tipo real para la calificación. */

int main(void)
{
    int R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0;
    float CAL;

    printf("Ingresa la primera calificación (-1 para terminar): ");
    scanf("%f", &CAL);

    while (CAL != -1.0)
    {
        if (CAL >= 0.0 && CAL < 6.0)
            R1++;
        else if (CAL >= 6.0 && CAL < 7.5)
            R2++;
        else if (CAL >= 7.5 && CAL < 8.5)
            R3++;
        else if (CAL >= 8.5 && CAL < 9.5)
            R4++;
        else if (CAL >= 9.5 && CAL <= 10.0)
            R5++;
        else
            printf("\nCalificación inválida (debe estar entre 0.0 y 10.0)\n");

        printf("\nIngresa la siguiente calificación (-1 para terminar): ");
        scanf("%f", &CAL);
    }

    printf("\n\n--- RESULTADOS POR RANGO ---");
    printf("\n[0.0 - 5.9] Reprobados:\t\t%d", R1);
    printf("\n[6.0 - 7.4] Regulares:\t\t%d", R2);
    printf("\n[7.5 - 8.4] Buenas:\t\t%d", R3);
    printf("\n[8.5 - 9.4] Muy Buenas:\t\t%d", R4);
    printf("\n[9.5 - 10.0] Excelentes:\t%d\n", R5);

    return 0;
}
