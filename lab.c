#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab.h"

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

    // Visualizar maquina
    #ifdef DEBUG
    printf("\n");
    for (i = 0; i < dimensiones[0]; i++) {
        for (j = 0; j < dimensiones[1]; j++) {
            printf("%c ", maquina[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    #endif

    // Crear lista rodillo.
    lista rodillo;
    rodillo.inicio = NULL;
    rodillo.size = 0;
    rodillo = insertar(rodillo, maquina[0][0]);
    imprimir(rodillo.inicio);

    // Girar rodillo.
    srand(dimensiones[0] * dimensiones[1]);
    

    return 0;
}

// *** Funciones pertenecientes al programa ***
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

// *** Otras funciones ***
lista insertar(lista actual, char elemento) {
	nodo * nuevo = (nodo*)malloc(sizeof(nodo));
	nuevo->valor = elemento;
	nuevo->sgte = NULL;
	if (actual.size == 0) {
		actual.inicio = nuevo;
		actual.fin = nuevo;
		actual.size = 1;
	}
	else {
		nodo * aux = actual.inicio;
		int i;
		for (i = 0; i < actual.size-1; i++){
			aux = aux->sgte;
		}
		aux->sgte = nuevo;
		actual.fin = nuevo;
		actual.size++;
	}
	return actual;
}

void imprimir(nodo *lista){
	nodo *aux;
	aux = lista;
	while(aux->sgte != NULL){
		printf("%c", aux->valor);
		aux = aux->sgte;
	}
	printf("%c", aux->valor);
	printf("\n");
}