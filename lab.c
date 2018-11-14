#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab.h"

#define DEBUG

//Main
int main() {

    // Obtencion matriz maquina.
    int dimensiones[2];
    obtenerDimensiones(dimensiones);
    srand(dimensiones[0] * dimensiones[1]);

    // Creacion maquina.
    int i, j, k;
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

    // Girar rodillo.
    for (j = 0; j < dimensiones[1]; j++) {
        lista rodillo;
        rodillo.inicio = NULL;
        rodillo.size = 0;
        for (i = 0; i < dimensiones[0]; i++) {
            rodillo = insertarLista(rodillo, maquina[i][j]);
        }
        rodillo = girarRodillo(rodillo);

        // Devolver los valores a la matriz.
        nodo *aux = rodillo.inicio;
        for (i = 0; i < dimensiones[0]; i++) {
            maquina[i][j] = aux->valor;
            aux = aux->sgte;
        }
        borrarLista(rodillo);
    }

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

lista girarRodillo(lista rodillo) {
    int i, giros;
    nodo *aux = rodillo.inicio;
    giros = (rand() % 10) + 1;  // Rango 1-10
    for (i = 0; i < giros; i++) {
        aux = aux->sgte;
    }
    rodillo.inicio = aux;

    return rodillo;
}

// *** Otras funciones ***
lista insertarLista(lista rodillo, char elemento) {
	nodo *nuevo = (nodo *)malloc(sizeof(nodo));
	nuevo->valor = elemento;
	nuevo->sgte = NULL;
	if (rodillo.size == 0) {
		rodillo.inicio = nuevo;
		rodillo.size = 1;
	}
	else {
		nodo *aux = rodillo.inicio;
		int i;
		for (i = 0; i < (rodillo.size-1); i++){
			aux = aux->sgte;
		}
		aux->sgte = nuevo;
        nuevo->sgte = rodillo.inicio;
		rodillo.size++;
	}

	return rodillo;
}

lista borrarLista(lista rodillo) {
    int i;
    nodo *aux = rodillo.inicio;
    for (i = 0; i < (rodillo.size - 1); i++) {
        aux = aux->sgte;
    }
    aux->sgte = NULL;   // Dejar de ser lista enlazada circular.

    aux = rodillo.inicio;
    while (aux->sgte != NULL) {
        rodillo.inicio = aux->sgte;
        free(aux);
        aux = rodillo.inicio;
    }
    free(aux);

    return rodillo;
}

void imprimirLista(nodo *lista){
    int i;
	nodo *aux = lista;
	for (i = 0; i < 4; i++){
		printf("%c", aux->valor);
		aux = aux->sgte;
	}
	printf("%c", aux->valor);
	printf("\n");

    return;
}

//look at my face step in my soul while i get u stupify WOAH