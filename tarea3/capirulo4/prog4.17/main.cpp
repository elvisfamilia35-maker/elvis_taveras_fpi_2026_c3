#include <stdio.h>  // Inclusión de la librería estándar para entrada y salida

/* Temperaturas.
El programa recibe como datos 24 números reales que representan las
temperaturas en el exterior en un período de 24 horas. Calcula el
promedio del día y las temperaturas máxima y mínima con la hora en la
que se registraron. */

void Acutem(float);
void Maxima(float, int); /* Prototipos de funciones */
void Minima(float, int);

/* Variables globales */
float ACT = 0.0;
float MAX = -50.0;
float MIN = 60.0;
int HMAX;
int HMIN;

int main(void)
{
    float TEM;
    int I;

    for (I = 1; I <= 24; I++)
    {
        printf("Ingresa la temperatura de la hora %d: ", I);
        scanf("%f", &TEM);

        Acutem(TEM);
        Maxima(TEM, I); /* Llamada a las funciones. Paso de parámetros por valor. */
        Minima(TEM, I);
    } // Se cierra el bucle for tras leer las 24 horas

    // Los resultados finales se imprimen UNA SOLA VEZ al terminar el ciclo
    printf("\nPromedio del día: %5.2f", (ACT / 24.0));
    printf("\nMáxima del día: %5.2f \tHora: %d", MAX, HMAX);
    printf("\nMínima del día: %5.2f \tHora: %d\n", MIN, HMIN);

    return 0;
} // Se cierra la función main

void Acutem(float T)
/* Acumula las temperaturas en la variable global ACT. */
{
    ACT += T;
}

void Maxima(float T, int H)
/* Almacena la temperatura máxima y la hora en las variables globales MAX y HMAX. */
{
    if (MAX < T)
    {
        MAX = T;
        HMAX = H;
    }
}

void Minima(float T, int H)
/* Almacena la temperatura mínima y la hora en las variables globales MIN y HMIN. */
{
    if (MIN > T)
    {
        MIN = T;
        HMIN = H;
    }
}
