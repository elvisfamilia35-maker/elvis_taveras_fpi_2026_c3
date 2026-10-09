#include <stdio.h>

// La función recibe una variable entera 'n' como parámetro
int cubo(int n);

int main(void)
{
    int i, cub;

    for (i = 1; i <= 10; i++)
    {
        cub = cubo(i); /* Se pasa 'i' como argumento por valor */
        printf("\nEl cubo de %d es: %d", i, cub);
    }

    printf("\n");
    return 0;
}

int cubo(int n)
{
    return (n * n * n);
}
