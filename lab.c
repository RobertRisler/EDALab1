#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab.h"

void crearMatriz ();

int main () {

    crearMatriz();

    //PRUEBAS


    //
    
    return 0;
}

void crearMatriz () {

    int i;
    int dimensiones[2];
    char linea[100];
    char *token;

    FILE *pArchivo;
    pArchivo = fopen("maquina.in", "r");
    fgets(linea, 10, pArchivo);

    // Obtencion de las dimensiones de la maquina.
    token = strtok(linea, " ");
    dimensiones[0] = atoi(token);
    token = strtok(NULL, " ");
    dimensiones[1] = atoi(token);

    printf("%d %d", dimensiones[0], dimensiones[1]);

    // Creacion matriz.
    char maquina[dimensiones[0]][dimensiones[1]];
    

    

    fclose(pArchivo);
    return;
}
