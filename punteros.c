#include <stdio.h>

/*
 * Ejemplos de punteros
 * valor -> es el valor guardado en memoria
 * &valor -> es la direccion donde está guardado el valor en memoria
 */

int main () {

    int numero = 40;
    int *pNumero = &numero;

    printf("\nDireccion \t Nombre \t Valor \n\n");
    printf("%p \t %s \t %d \n", &numero, "numero", numero);     // Direccion
    printf("%p \t %s \t %d \n\n", pNumero, "numero", *pNumero); // Dereferenciar


    int i;
    int arreglo[3] = {2, 3, 4};

    for (i = 0; i < 3; i++) {
        printf("arreglo[%d] \t %p \t %d \n", i, &arreglo[i], arreglo[i]);
    }

    printf("\narreglo \t %p \t %d", arreglo, *arreglo); // Nombres de arreglos son punteros al primer elemento
    printf("\n(arreglo+2) \t %p \t %d \n", arreglo, *(arreglo+2));

    return 0;
}
