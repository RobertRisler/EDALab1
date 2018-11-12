#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab.h"

// Prototipos
void obtenerDimensiones(int *dimensiones);
void crearMaquina(char **maquina, int ancho);
void girarRodillos();

//Main
int main() {

    // Obtencion matriz maquina.
    int dimensiones[2];
    obtenerDimensiones(dimensiones);

    // Creacion maquina.
    int i, j;
    char maquina[dimensiones[0]][dimensiones[1]];
    char *filas[dimensiones[0]];
    for (i = 0; i < dimensiones[0]; i++) {
        filas[i] = maquina[i];
    }
    crearMaquina(filas, dimensiones[1]);

    /*
    // Visualizar maquina.
    for (i = 0; i < dimensiones[0]; i++) {
        for (j = 0; j < dimensiones[1]; j++) {
            printf("%c ", maquina[i][j]);
        }
        printf("\n");
    }
    */

    // Girar rodillos.
    srand(dimensiones[0] * dimensiones[1]);


    return 0;
}

// Funciones
void obtenerDimensiones(int *arreglo) {

    char linea[10];
    char *token;

    FILE *pArchivo;
    pArchivo = fopen("maquina.in", "r");
    fgets(linea, 10, pArchivo);

    arreglo[0] = atoi(strtok(linea, " "));
    arreglo[1] = atoi(strtok(NULL, " "));

    fclose(pArchivo);

    return; 
}

void crearMaquina(char **maquina, int ancho) {
    
    char linea[(2 * ancho) + 1];
    int contador1, contador2, i;
    
    FILE *pArchivo;
    pArchivo = fopen("maquina.in", "r");
    fgets(linea, (2 * ancho) + 1, pArchivo);

    contador1 = 0;
    while (!feof(pArchivo)) {
        contador2 = 0;
        fgets(linea, (2 * ancho) + 1, pArchivo);
        for (i = 0; i < (2 * ancho); i = i + 2) {
            maquina[contador1][contador2] = linea[i];
            contador2++;
        }
        contador1++;
    }

    fclose(pArchivo);

    return;
}

void girarRodillos() {

    return;
}