#include <stdio.h>

/*
 * Ejemplos de punteros
 * valor -> es el valor guardado en memoria
 * &valor -> es la direccion donde está guardado el valor en memoria
 */
int main () {

    int numero = 40;
    int *p_numero;
    p_numero = &numero;

    printf("\nEl dato es:\n %i\n", numero);
    printf("El dato tambien es:\n %i\n\n", *p_numero);

    printf("La posicion es:\n %p\n", &numero);
    printf("La posicion tambien es:\n %p\n\n", p_numero);

    return 0;
}
