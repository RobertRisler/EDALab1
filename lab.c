#include <stdio.h>
#include <stdlib.h>
#include "cosas.h"

int main () {
    
    FILE * pArchivo;
    pArchivo = fopen("maquina.in", "r");
    char linea [100];

    while (!feof(pArchivo)) {
        fgets(linea, 100, pArchivo);
        puts(linea);
    }

    fclose(pArchivo);
    return 0;
}
