#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab.h"

int main () {

    int i, j;
    int dimensiones[2];
    char linea1[10];
    char *token;

    FILE *pArchivo;
    pArchivo = fopen("maquina.in", "r");
    fgets(linea1, 10, pArchivo);

    // Obtencion de las dimensiones de la maquina.
    dimensiones[0] = atoi(strtok(linea1, " "));
    dimensiones[1] = atoi(strtok(NULL, " "));

    // Creacion matriz.
    char linea2[(2 * dimensiones[1]) + 1];          // Por los espacios, el largo es (2 * Ancho), + 1 por el \0.
    char maquina[dimensiones[0]][dimensiones[1]];   // Alto X Ancho
    int contador1 = 0;
    int contador2;

    while (!feof(pArchivo)) {   // feof = end of file.
        fgets(linea2, (2 * dimensiones[1] + 1), pArchivo);
        token = strtok(linea2, " ");
        contador2 = 0;
        while (token != NULL) {
            maquina[contador1][contador2] = token[0];
            token = strtok(NULL, " ");
            contador2++;
        }
        contador1++;
    }

    fclose(pArchivo);

    // Solo para ver la matriz.
    for (i = 0; i < dimensiones[0]; i++) {
        for (j = 0; j < dimensiones[1]; j++) {
            printf("%c ", maquina[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
