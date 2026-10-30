#include <stdio.h>

/* Búsqueda secuencial en arreglos desordenados. */
const int MAX = 100;

/* Prototipos de funciones */
void Lectura(int A[], int T);
int Busca(int A[], int T, int K);

int main(void)
{
    int RES, ELE, TAM, VEC[MAX];

    do
    {
        printf("Ingrese el tamaño del arreglo (1-100): ");
        scanf("%d", &TAM);
    }
    while (TAM > MAX || TAM < 1); /* Se verifica que el tamaño del arreglo sea correcto. */

    Lectura(VEC, TAM);

    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);

    RES = Busca(VEC, TAM, ELE); /* Se llama a la función que busca en el arreglo. */

    if (RES)
    {
        /* Si RES tiene un valor verdadero —diferente de 0—, se escribe la posición
           en la que se encontró el elemento. */
        printf("\nEl elemento se encuentra en la posición %d\n", RES);
    }
    else
    {
        printf("\nEl elemento no se encuentra en el arreglo\n");
    }

    return 0;
}

void Lectura(int A[], int T)
/* La función Lectura se utiliza para leer un arreglo unidimensional de T
   elementos de tipo entero. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("Ingrese el elemento %d: ", I + 1);
        scanf("%d", &A[I]);
    }
}

int Busca(int A[], int T, int K)
/* Esta función localiza en el arreglo un elemento determinado. Si el elemento
   es encontrado, regresa la posición correspondiente. En caso contrario, regresa 0. */
{
    int I = 0, BAN = 0, RES;

    while (I < T && !BAN)
    {
        if (A[I] == K)
        {
            BAN++; /* Se activa la bandera */
        }
        else
        {
            I++;   /* Se avanza al siguiente elemento solo si no hubo coincidencia */
        }
    }

    if (BAN)
    {
        RES = I + 1; /* Se asigna I+1 dado que las posiciones humanas comienzan desde 1
                        mientras que los índices en C comienzan desde 0. */
    }
    else
    {
        RES = BAN; /* Retorna 0 indicando que no se encontró */
    }

    return (RES);
}
