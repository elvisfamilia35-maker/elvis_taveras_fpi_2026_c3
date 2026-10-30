#include <stdio.h>

/* Universidad.
   El programa, al recibir información sobre el número de alumnos que han ingresado
   a sus ocho diferentes carreras en los dos semestres lectivos de los últimos
   cinco años, obtiene información útil para el departamento escolar. */

const int F = 8, C = 2, P = 5;
/* Se declaran constantes para:
   F = Filas (Carreras, 8)
   C = Columnas (Semestres, 2)
   P = Profundidad (Años, 5) */

/* Prototipo de funciones. Cada prototipo corresponde a uno de los incisos. */
void Lectura(int [][C][P], int, int, int);
void Funcion1(int [][C][P], int, int, int);
void Funcion2(int [][C][P], int, int, int);
void Funcion3(int [][C][P], int, int, int);

int main(void)
{
    int UNI[F][C][P];

    Lectura(UNI, F, C, P);
    Funcion1(UNI, F, C, P);
    Funcion2(UNI, F, C, P);

    /* Se pasa '6' como parámetro de filas ya que corresponde a la clave
       de la carrera de Ingeniería en Computación (índice 5). */
    Funcion3(UNI, 6, C, P);

    printf("\n");
    return 0;
}

void Lectura(int A[][C][P], int FI, int CO, int PR)
/* La función Lectura se utiliza para leer un arreglo tridimensional entero
   de FI filas, CO columnas y PR profundidad. Se necesitan tres ciclos anidados. */
{
    int K, I, J;
    for (K = 0; K < PR; K++)
    {
        printf("\n--- Año %d ---\n", K + 1);
        for (I = 0; I < FI; I++)
        {
            for (J = 0; J < CO; J++)
            {
                printf("  Carrera %d, Semestre %d - Alumnos ingresados: ", I + 1, J + 1);
                scanf("%d", &A[I][J][K]);
            }
        }
    }
}

void Funcion1(int A[][C][P], int FI, int CO, int PR)
/* Esta función determina en qué año la universidad en su conjunto
   recibió el mayor número de alumnos. */
{
    int K, I, J, MAY = 0, AO = -1, SUM;

    for (K = 0; K < PR; K++)
    {
        SUM = 0;
        for (I = 0; I < FI; I++)
        {
            for (J = 0; J < CO; J++)
            {
                SUM += A[I][J][K];
            }
        }

        if (SUM > MAY)
        {
            MAY = SUM;
            AO = K;
        }
    }

    printf("\n\n[Informe 1] Año con mayor ingreso total de alumnos: Año %d (Total: %d alumnos)", AO + 1, MAY);
}

void Funcion2(int A[][C][P], int FI, int CO, int PR)
/* Esta función determina qué carrera recibió el mayor número de
   alumnos durante el último año registrado (PR - 1). */
{
    int I, J, MAY = 0, CAR = -1, SUM;

    for (I = 0; I < FI; I++)
    {
        SUM = 0;
        /* Se evalúa únicamente el último año (PR - 1) sumando sus semestres */
        for (J = 0; J < CO; J++)
        {
            SUM += A[I][J][PR - 1];
        }

        if (SUM > MAY)
        {
            MAY = SUM;
            CAR = I;
        }
    }

    printf("\n[Informe 2] Carrera con mayor número de alumnos en el último año: Carrera %d (Total: %d alumnos)", CAR + 1, MAY);
}

void Funcion3(int A[][C][P], int FI, int CO, int PR)
/* Esta función determina en qué año la carrera específica especificada
   en FI (Ingeniería en Computación, valor 6 -> índice 5) recibió más alumnos. */
{
    int K, J, MAY = 0, AO = -1, SUM;
    int carrera_idx = FI - 1; /* Ajuste a índice base 0 (6 - 1 = 5) */

    for (K = 0; K < PR; K++)
    {
        SUM = 0;
        for (J = 0; J < CO; J++)
        {
            SUM += A[carrera_idx][J][K];
        }

        if (SUM > MAY)
        {
            MAY = SUM;
            AO = K;
        }
    }

    printf("\n[Informe 3] Ingeniería en Computación - Año con mayor ingreso: Año %d (Total: %d alumnos)\n", AO + 1, MAY);
}
