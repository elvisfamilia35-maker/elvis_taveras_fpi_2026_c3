#include <stdio.h>

/* Alumnos.
   El programa, al recibir un arreglo bidimensional que contiene información
   sobre calificaciones de alumnos en cuatro materias/exámenes diferentes,
   obtiene resultados estadísticos. */

const int MAX = 50;
const int EXA = 4;

/* Prototipos de funciones. */
void Lectura(float [MAX][EXA], int);
void Funcion1(float [MAX][EXA], int);
void Funcion2(float [MAX][EXA], int);

int main(void)
{
    int NAL;
    float ALU[MAX][EXA];

    /* Se verifica que el número de alumnos del grupo sea válido (entre 1 y 50). */
    do
    {
        printf("Ingrese el número de alumnos del grupo (1-50): ");
        scanf("%d", &NAL);
    }
    while (NAL > MAX || NAL < 1);

    Lectura(ALU, NAL);

    printf("\n--- Promedios por Alumno ---");
    Funcion1(ALU, NAL);

    printf("\n\n--- Promedios por Examen y Análisis General ---");
    Funcion2(ALU, NAL);

    return 0;
}

void Lectura(float A[][EXA], int N)
/* La función Lectura se utiliza para leer un arreglo bidimensional de tipo
   real de N filas (alumnos) y EXA columnas (exámenes). */
{
    int I, J;
    printf("\n");
    for (I = 0; I < N; I++)
    {
        for (J = 0; J < EXA; J++)
        {
            printf("Ingrese la calificación del examen %d del alumno %d: ", J + 1, I + 1);
            scanf("%f", &A[I][J]);
        }
    }
}

void Funcion1(float A[][EXA], int T)
/* Esta función se utiliza para obtener el promedio de cada estudiante. */
{
    int I, J;
    float SUM, PRO;

    for (I = 0; I < T; I++)
    {
        SUM = 0.0;
        for (J = 0; J < EXA; J++)
        {
            SUM += A[I][J]; /* Suma las 4 calificaciones de la fila actual */
        }
        PRO = SUM / EXA; /* Calcula el promedio dividiendo entre el número de exámenes */
        printf("\nEl promedio del alumno %d es: %5.2f", I + 1, PRO);
    }
}

void Funcion2(float A[][EXA], int T)
/* Esta función calcula el promedio de cada examen a nivel grupal e identifica
   cuál de los exámenes obtuvo el promedio más alto. */
{
    int I, J, MAY = 0;
    float SUM, PRO, MPRO = 0.0;

    for (J = 0; J < EXA; J++)
    {
        SUM = 0.0;
        /* Se recorren las filas (alumnos) fijando la columna (examen) */
        for (I = 0; I < T; I++)
        {
            SUM += A[I][J];
        }
        PRO = SUM / T; /* Promedio del examen J para todo el grupo */

        /* Se evalúa cuál examen tiene el mayor promedio */
        if (PRO > MPRO)
        {
            MPRO = PRO;
            MAY = J; /* Guarda el índice del examen con mejor promedio */
        }

        printf("\nEl promedio del examen %d es: %5.2f", J + 1, PRO);
    }

    printf("\n\nEl examen con mayor promedio es: Examen %d \t Promedio: %5.2f\n", MAY + 1, MPRO);
}
