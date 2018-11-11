#include <stdio.h>
#include <stdlib.h>

/*
 * Ejemplo de como crear una matriz de tamaño ingresado por el usuario,
 * que los datos que se ingresen por el usuario se guarden en la matriz,
 * y que se imprima la matriz. 
 */

int main () {
    int alto, ancho;
    printf("Ingrese el alto y el ancho de la maquina:\n");
    scanf("%d%d", &alto, &ancho);
    char matrizMaquina[alto][ancho]; // matriz[filas][columnas]

    int i, j;
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            printf("Ingrese el dato para la posicion [%d, %d]\n", i, j);
            scanf(" %c", &matrizMaquina[i][j]);
        }
    }
    printf("\n");

    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            printf("%c ", matrizMaquina[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
