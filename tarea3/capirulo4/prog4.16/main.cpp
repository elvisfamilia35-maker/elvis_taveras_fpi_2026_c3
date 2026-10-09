#include <stdio.h>  // Inclusión de la librería estándar para printf y scanf

/* Productoria.
El programa calcula la productoria de los N primeros números naturales. */

unsigned long long Productoria(int); /* Prototipo: usa unsigned long long para evitar desbordamiento temprano */

int main(void)
{
    int NUM;

    /* Ciclo do-while para validar que el número esté en el rango [1, 20] */
    do
    {
        printf("Ingresa el número del cual quieres calcular la productoria (1-20): ");
        scanf("%d", &NUM);
    }
    while (NUM < 1 || NUM > 20); /* Repite la lectura si el número es menor a 1 o mayor a 20 */

    printf("\nLa productoria de %d es: %llu\n", NUM, Productoria(NUM));

    return 0;
}

unsigned long long Productoria(int N)
/* La función calcula la productoria (factorial) de N. */
{
    int I;
    unsigned long long PRO = 1;

    for (I = 1; I <= N; I++)
    {
        PRO *= I; /* Multiplicación acumulada: PRO = PRO * I */
    }

    return (PRO);
}
