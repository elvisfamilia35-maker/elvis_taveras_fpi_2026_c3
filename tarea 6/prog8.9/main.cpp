#include <stdio.h>
#include <string.h>

/* Hospital.
El programa genera información acerca de los pacientes de un hospital. */

typedef struct { /* Declaración de la estructura domicilio. */
    char cal[20]; /* Calle. */
    int num;      /* Número. */
    char col[20]; /* Colonia. */
    char cp[5];   /* Código Postal. */
    char ciu[20]; /* Ciudad. */
} domicilio;

typedef struct { /* Declaración de la estructura paciente. */
    char nom[20];  /* Nombre y apellido. */
    int edad;
    char sexo;
    int con;       /* Condición. */
    domicilio dom; /* Campo dom de tipo estructura domicilio. */
    char tel[10];  /* Teléfono. */
} paciente;

/* Prototipos de funciones. */
void Lectura(paciente *, int);
void F1(paciente *, int);
void F2(paciente *, int);
void F3(paciente *, int);

int main(void)
{
    paciente HOSPITAL[100]; /* Arreglo unidimensional de tipo estructura paciente. */
    int TAM;

    do
    {
        printf("Ingrese el número de pacientes (1-50): ");
        scanf("%d", &TAM);
    }
    while (TAM > 50 || TAM < 1); /* Se verifica que el tamaño del arreglo sea correcto. */

    Lectura(HOSPITAL, TAM);
    F1(HOSPITAL, TAM);
    F2(HOSPITAL, TAM);
    F3(HOSPITAL, TAM);

    return 0;
}

void Lectura(paciente A[], int T)
/* Esta función se utiliza para leer un arreglo unidimensional de tipo
estructura paciente de T elementos de forma segura. */
{
    int I;
    for (I = 0; I < T; I++)
    {
        printf("\n\t\tPaciente %d\n", I + 1);

        while (getchar() != '\n' && getchar() != EOF); /* Limpiar búfer previo */

        printf("Nombre: ");
        fgets(A[I].nom, sizeof(A[I].nom), stdin);
        A[I].nom[strcspn(A[I].nom, "\n")] = '\0';

        printf("Edad: ");
        scanf("%d", &A[I].edad);

        while (getchar() != '\n' && getchar() != EOF);
        printf("Sexo (F-M): ");
        scanf("%c", &A[I].sexo);

        printf("Condición (1..5): ");
        scanf("%d", &A[I].con);

        while (getchar() != '\n' && getchar() != EOF);
        printf("\tCalle: ");
        fgets(A[I].dom.cal, sizeof(A[I].dom.cal), stdin);
        A[I].dom.cal[strcspn(A[I].dom.cal, "\n")] = '\0';

        printf("\tNúmero: ");
        scanf("%d", &A[I].dom.num);

        while (getchar() != '\n' && getchar() != EOF);
        printf("\tColonia: ");
        fgets(A[I].dom.col, sizeof(A[I].dom.col), stdin);
        A[I].dom.col[strcspn(A[I].dom.col, "\n")] = '\0';

        printf("\tCódigo Postal: ");
        fgets(A[I].dom.cp, sizeof(A[I].dom.cp), stdin);
        A[I].dom.cp[strcspn(A[I].dom.cp, "\n")] = '\0';

        printf("\tCiudad: ");
        fgets(A[I].dom.ciu, sizeof(A[I].dom.ciu), stdin);
        A[I].dom.ciu[strcspn(A[I].dom.ciu, "\n")] = '\0';

        printf("Teléfono: ");
        fgets(A[I].tel, sizeof(A[I].tel), stdin);
        A[I].tel[strcspn(A[I].tel, "\n")] = '\0';
    }
}

void F1(paciente A[], int T)
/* Función de ejemplo para procesar o mostrar estadísticas de los pacientes (F1). */
{
    int I, c_graves = 0;
    for (I = 0; I < T; I++)
    {
        if (A[I].con == 5) /* Suponiendo condición 5 como gravedad alta */
            c_graves++;
    }
    printf("\n--- REPORTE F1 ---\n");
    printf("Número de pacientes en condición crítica (5): %d\n", c_graves);
}

void F2(paciente A[], int T)
/* Función de ejemplo para procesar o mostrar estadísticas de los pacientes (F2). */
{
    int I, c_edad = 0;
    for (I = 0; I < T; I++)
    {
        if (A[I].edad > 60)
            c_edad++;
    }
    printf("\n--- REPORTE F2 ---\n");
    printf("Número de pacientes mayores de 60 años: %d\n", c_edad);
}

void F3(paciente A[], int T)
/* Función de ejemplo para listar los nombres de todos los pacientes registrados (F3). */
{
    int I;
    printf("\n--- REPORTE F3 (LISTADO DE PACIENTES) ---\n");
    for (I = 0; I < T; I++)
    {
        printf("%d. Nombre: %s \t Edad: %d \t Ciudad: %s\n", I + 1, A[I].nom, A[I].edad, A[I].dom.ciu);
    }
}
