#include <stdio.h>  // Inclusión de la librería estándar para printf y scanf

/* Números perfectos.
El programa, al recibir como dato un número entero positivo como límite, obtiene
los números perfectos que hay entre 1 y ese número, y además imprime cuántos
números perfectos hay en el intervalo.
I, J, NUM, SUM, C: variables de tipo entero. */

int main(void)
{
    int I, J, NUM, SUM, C = 0;

    printf("Ingrese el número límite: ");
    scanf("%d", &NUM);

    // Empezamos desde 2 ya que el 1 no es un número perfecto
    for (I = 2; I <= NUM; I++)
    {
        SUM = 0;

        // Buscamos los divisores propios hasta I / 2
        for (J = 1; J <= (I / 2); J++)
        {
            if ((I % J) == 0)
            {
                SUM += J;
            }
        }

        // Si la suma de los divisores es igual al número, es perfecto
        if (SUM == I)
        {
            printf("\n%d es un número perfecto", I);
            C++;
        }
    }

    printf("\n\nEntre 1 y %d hay %d número(s) perfecto(s).\n", NUM, C);

    return 0;
}

