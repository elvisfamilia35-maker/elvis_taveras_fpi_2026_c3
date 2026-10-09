#include <stdio.h>  // Librería para entrada y salida (printf)
#include <math.h>   // Librería para funciones matemáticas (pow)

/* Expresión.
El programa escribe los valores de T, P y Q que satisfacen la expresión:
15*(T^4) + 12*(P^5) + 9*(Q^6) < 5500 */

int Expresion(int, int, int); /* Prototipo de función */

int main(void)
{
    int EXP, T = 0, P = 0, Q = 0;

    EXP = Expresion(T, P, Q);

    while (EXP < 5500)
    {
        while (EXP < 5500)
        {
            while (EXP < 5500)
            {
                printf("\nT: %d, P: %d, Q: %d, Resultado: %d", T, P, Q, EXP);
                Q++;
                EXP = Expresion(T, P, Q);
            }
            P++;
            Q = 0;
            EXP = Expresion(T, P, Q);
        }
        T++;
        P = 0;
        Q = 0;
        EXP = Expresion(T, P, Q);
    }

    printf("\n");
    return 0;
}

int Expresion(int T, int P, int Q)
/* Calcula el resultado de 15*T^4 + 12*P^5 + 9*Q^6 */
{
    int RES;
    RES = 15 * (int)pow(T, 4) + 12 * (int)pow(P, 5) + 9 * (int)pow(Q, 6);
    return RES;
}
