#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Estructuras-3.
El programa muestra la manera en que se declara una estructura anidada, así
como la forma de acceso a los campos de las variables o apuntadores de tipo
estructura, tanto para lectura como para escritura. Se utiliza además una
function que recibe como parámetro un apuntador de tipo estructura. */

typedef struct { /* Declaración de la estructura domicilio utilizando un typedef. */
    char calle[20];
    int numero;
    int cp;
    char localidad[20];
} domicilio;

struct empleado { /* Declaración de la estructura anidada empleado. */
    char nombre[20];
    char departamento[20];
    float sueldo;
    domicilio direccion; /* direccion es un campo de tipo estructura domicilio. */
};

void Lectura(struct empleado *a)
/* Función que permite leer los campos de un apuntador de tipo estructura empleado. */
{
    printf("\nIngrese el nombre del empleado: ");
    fgets(a->nombre, sizeof(a->nombre), stdin);
    a->nombre[strcspn(a->nombre, "\n")] = '\0';

    printf("Ingrese el departamento de la empresa: ");
    fgets(a->departamento, sizeof(a->departamento), stdin);
    a->departamento[strcspn(a->departamento, "\n")] = '\0';

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &a->sueldo);
    while (getchar() != '\n' && getchar() != EOF); /* Limpiar búfer */

    printf("----Ingrese la dirección del empleado----\n");
    printf("\tCalle: ");
    fgets(a->direccion.calle, sizeof(a->direccion.calle), stdin);
    a->direccion.calle[strcspn(a->direccion.calle, "\n")] = '\0';

    printf("\tNúmero: ");
    scanf("%d", &a->direccion.numero);

    printf("\tCódigo Postal: ");
    scanf("%d", &a->direccion.cp);
    while (getchar() != '\n' && getchar() != EOF);

    printf("\tLocalidad: ");
    fgets(a->direccion.localidad, sizeof(a->direccion.localidad), stdin);
    a->direccion.localidad[strcspn(a->direccion.localidad, "\n")] = '\0';
}

int main(void)
{
    /* Inicialización corregida para estructura anidada en C */
    struct empleado e0 = {"Arturo", "Compras", 15500.75, {"San Jeronimo", 120, 3490, "Toluca"}};
    struct empleado *e1, *e2;
    struct empleado e3, e4;

    /* Asignación de memoria dinámica usando malloc (en lugar de new) */
    e1 = (struct empleado *)malloc(sizeof(struct empleado));
    if (e1 == NULL) return 1;

    printf("\nIngrese el nombre del empleado 1: ");
    fgets(e1->nombre, sizeof(e1->nombre), stdin);
    e1->nombre[strcspn(e1->nombre, "\n")] = '\0';

    printf("Ingrese el departamento de la empresa: ");
    fgets(e1->departamento, sizeof(e1->departamento), stdin);
    e1->departamento[strcspn(e1->departamento, "\n")] = '\0';

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e1->sueldo);
    while (getchar() != '\n' && getchar() != EOF);

    printf("----Ingrese la dirección del empleado----\n");
    printf("\tCalle: ");
    fgets(e1->direccion.calle, sizeof(e1->direccion.calle), stdin);
    e1->direccion.calle[strcspn(e1->direccion.calle, "\n")] = '\0';

    printf("\tNúmero: ");
    scanf("%d", &e1->direccion.numero);

    printf("\tCódigo Postal: ");
    scanf("%d", &e1->direccion.cp);
    while (getchar() != '\n' && getchar() != EOF);

    printf("\tLocalidad: ");
    fgets(e1->direccion.localidad, sizeof(e1->direccion.localidad), stdin);
    e1->direccion.localidad[strcspn(e1->direccion.localidad, "\n")] = '\0';


    /* Lectura de los campos de la variable e3 */
    printf("\nIngrese el nombre del empleado 3: ");
    fgets(e3.nombre, sizeof(e3.nombre), stdin);
    e3.nombre[strcspn(e3.nombre, "\n")] = '\0';

    printf("Ingrese el departamento de la empresa: ");
    fgets(e3.departamento, sizeof(e3.departamento), stdin);
    e3.departamento[strcspn(e3.departamento, "\n")] = '\0';

    printf("Ingrese el sueldo del empleado: ");
    scanf("%f", &e3.sueldo);
    while (getchar() != '\n' && getchar() != EOF);

    printf("----Ingrese la dirección del empleado----\n");
    printf("\tCalle: ");
    fgets(e3.direccion.calle, sizeof(e3.direccion.calle), stdin);
    e3.direccion.calle[strcspn(e3.direccion.calle, "\n")] = '\0';

    printf("\tNúmero: ");
    scanf("%d", &e3.direccion.numero);

    printf("\tCódigo Postal: ");
    scanf("%d", &e3.direccion.cp);
    while (getchar() != '\n' && getchar() != EOF);

    printf("\tLocalidad: ");
    fgets(e3.direccion.localidad, sizeof(e3.direccion.localidad), stdin);
    e3.direccion.localidad[strcspn(e3.direccion.localidad, "\n")] = '\0';


    /* Asignación de memoria dinámica para e2 */
    e2 = (struct empleado *)malloc(sizeof(struct empleado));
    if (e2 == NULL) {
        free(e1);
        return 1;
    }

    /* Uso de la función Lectura */
    Lectura(e2);
    Lectura(&e4);

    printf("\nDatos del empleado 1\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n", e1->nombre, e1->departamento, e1->sueldo,
           e1->direccion.calle, e1->direccion.numero, e1->direccion.cp, e1->direccion.localidad);

    printf("\nDatos del empleado 4\n");
    printf("%s\t%s\t%.2f\t%s\t%d\t%d\t%s\n", e4.nombre, e4.departamento, e4.sueldo,
           e4.direccion.calle, e4.direccion.numero, e4.direccion.cp, e4.direccion.localidad);

    /* Liberar la memoria dinámica asignada */
    free(e1);
    free(e2);

    return 0;
}
