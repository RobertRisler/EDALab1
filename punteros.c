#include <stdio.h>

/*
 * Ejemplos de punteros
 * valor -> es el valor guardado en memoria
 * &valor -> es la direccion donde está guardado el valor en memoria
 */

int main () {

    // Formas basicas de punteros
    int numero = 40;
    int * pNumero = &numero;

    printf("Direccion \t Nombre \t Valor \n\n");
    printf("%p \t %s \t %d \n", &numero, "numero", numero);     // Direccion
    printf("%p \t %s \t %d \n\n", pNumero, "numero", *pNumero); // Dereferenciar
    // -------------------------------------------------------------------------------------------------------


    // Punteros y arreglos
    int i;
    int arreglo[3] = {2, 3, 4};

    for (i = 0; i < 3; i++) {
        printf("arreglo[%d] \t %p \t %d \n", i, &arreglo[i], arreglo[i]);
    }

    printf("\narreglo \t %p \t %d", arreglo, *arreglo); // Nombres de arreglos son punteros al primer elemento
    printf("\n(arreglo+2) \t %p \t %d \n\n", arreglo, *(arreglo+2));
    // -------------------------------------------------------------------------------------------------------


    // Punteros y strings
    char juego1[] = "Red Dead Redemption";      // juego1 es una constante y no se puede cambiar.
    char * juego2 = "Red Dead Redemption 2";    // Al hacer juego2 un puntero, es variable.
    // juego2 apunta solamente al primer elemento del string.

    // juego1 = "Crackdown";    **ERROR**
    puts(juego2); // Imprime cada char hasta encontrar un null (similar al concepto de listas enlazadas).
    juego2 = "Crackdown 2";
    puts(juego2);
    // -------------------------------------------------------------------------------------------------------

    return 0;
}
