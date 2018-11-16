#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "simulador.h"

/********** Main **********/
int main() {

    // Obtencion matriz maquina.
    int dimensiones[2];
    obtenerDimensiones(dimensiones);
    srand(2018);

    // Creacion maquina.
    if (dimensiones[0] < dimensiones[1]) {
        int i, j;
        char maquina[dimensiones[0]][dimensiones[1]];
        char *filas[dimensiones[0]];
        for (i = 0; i < dimensiones[0]; i++) {
            filas[i] = maquina[i];
        }
        crearMaquina(filas, dimensiones[1]);

        // Girar rodillo.
        for (j = 0; j < dimensiones[1]; j++) {
            lista rodillo;
            rodillo.inicio = NULL;
            rodillo.size = 0;
            for (i = 0; i < dimensiones[0]; i++) {
                rodillo = insertarLista(rodillo, maquina[i][j]);
            }
            rodillo = girarRodillo(rodillo, j);

            // Devolver los valores a la matriz.
            nodo *aux = rodillo.inicio;
            for (i = 0; i < dimensiones[0]; i++) {
                maquina[i][j] = aux->valor;
                aux = aux->sgte;
            }
            borrarLista(rodillo);
        }

        // Calcular puntaje total.
        long puntajeAcumulado;
        puntajeAcumulado = encontrarCombinaciones(filas, dimensiones[0], dimensiones[1]);

        // Creacion y relleno de archivo resultados.out
        crearArchivoResultados(puntajeAcumulado);
    }
    else {
        printf("El programa se encuentra desactivado para máquinas con un alto mayor o igual al ancho");
    }

    return 0;
}



/********** Funciones pertenecientes al programa **********/
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
    while (!feof(pArchivo)) {   // end of file.
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

lista girarRodillo(lista rodillo, int j) {

    int i, giros;
    nodo *aux = rodillo.inicio;
    giros = (rand() % 10) + 1;  // Rango 1-10.
    
    if (giros == 1) {
        printf("El rodillo %d giro %d vez.\n", j + 1, giros);
    }
    else {
        printf("El rodillo %d giro %d veces.\n", j + 1, giros);
    }
    
    for (i = 0; i < giros; i++) {
        aux = aux->sgte;
    }
    rodillo.inicio = aux;

    return rodillo;
}

long encontrarCombinaciones(char **maquina, int alto, int ancho) {
    int i, j, k, l, contador;
    long acumulado = 0;
    char elemento1, elemento2;
    
    // Encontrar combinaciones solo hacia la derecha.
    for (i = 0; i < alto; i++) {
        for (j = 0; j < (ancho - 2); j++) {
            contador = 1;
            k = j + 1;
            elemento1 = maquina[i][j];
            elemento2 = maquina[i][k];
            while ((elemento1 == elemento2) && (k < ancho)) {
                contador++;
                k++;
                elemento2 = maquina[i][k];
            }
            if (contador > 2) {
                acumulado += (50 * (pow(contador, 1.5)));
                j = k;
            }
        }
    }

    if (alto < ancho) {

        lista diagonal;

        // Encontrar las combinaciones diagonales hacia la derecha-abajo.
        // Esquina inferior izquierda.
        for (i = (alto - 3); i > 0; i--) {
            k = i;
            diagonal.inicio = NULL;
            diagonal.size = 0;
            for (j = 0; j < (alto - i); j++) {
                diagonal = insertarLista(diagonal, maquina[k][j]);
                k++;
            }
            acumulado += encontrarPuntaje(diagonal);
            borrarLista(diagonal);
        }

        // Centro.
        for (j = 0; j < (ancho - alto + 1); j++) {
            l = j;
            diagonal.inicio = NULL;
            diagonal.size = 0;
            for(i = 0; i < alto; i++) {
                diagonal = insertarLista(diagonal, maquina[i][l]);
                l++;
            }
            acumulado += encontrarPuntaje(diagonal);
            borrarLista(diagonal);
        }

        // Esquina superior derecha.
        int valorMax = alto - 2;
        for (j = (ancho - alto + 1); j < (ancho - 2); j++) {
            l = j;
            diagonal.inicio = NULL;
            diagonal.size = 0;
            for(i = 0; i <= valorMax; i++) {
                diagonal = insertarLista(diagonal, maquina[i][l]);
                l++;
            }
            valorMax--;
            acumulado += encontrarPuntaje(diagonal);
            borrarLista(diagonal);
        }

        // Encontrar las combinaciones diagonales hacia la izquierda-abajo.
        // Esquina superior izquierda.
        for (j = 2; j <= (alto - 2); j++) {
            l = j;
            diagonal.inicio = NULL;
            diagonal.size = 0;
            for (i = 0; i <= j; i++) {
                diagonal = insertarLista(diagonal, maquina[i][l]);
                l--;
            }
            acumulado += encontrarPuntaje(diagonal);
            borrarLista(diagonal);
        }

        // Centro.
        for (j = (alto - 1); j < ancho; j++) {
            l = j;
            diagonal.inicio = NULL;
            diagonal.size = 0;
            for (i = 0; i < alto; i++) {
                diagonal = insertarLista(diagonal, maquina[i][l]);
                l--;
            }
            acumulado += encontrarPuntaje(diagonal);
            borrarLista(diagonal);
        }

        // Esquina inferior derecha.
        valorMax = ancho - alto + 1;
        for (i = 1; i < (alto - 2); i++) {
            k = i;
            diagonal.inicio = NULL;
            diagonal.size = 0;
            for (j = (ancho - 1); j >= valorMax; j--) {
                diagonal = insertarLista(diagonal, maquina[k][j]);
                k++;
            }
            valorMax++;
            acumulado += encontrarPuntaje(diagonal);
            borrarLista(diagonal);
        }
    }

    else {
        // Maquinas de alto > ancho no implementado.
    }

    return acumulado;
}

long encontrarPuntaje(lista diagonal) {

    nodo *aux;
    nodo *aux2;
    int contador;
    long acumAux = 0;

    // Hacer que deje de ser lista enlazada circular.
    aux = diagonal.inicio;
    while (aux != diagonal.fin) {
        aux = aux->sgte;
    }
    aux->sgte = NULL;

    // Busqueda.
    aux = diagonal.inicio;
    aux2 = diagonal.inicio;
    contador = 1;
    while (aux2->sgte != NULL) {
        aux2 = aux2->sgte;
        if (aux->valor == aux2->valor) {
            contador++;
        }
        else {
            if (contador > 2) {
                acumAux += (50 * (pow(contador, 1.5)));
                contador = 1;
            }
            else {
                contador = 1;
            }
            aux = aux2;
        }
    }
    if (contador > 2) {
        acumAux += (50 * (pow(contador, 1.5)));
    }

    return acumAux;
}

void crearArchivoResultados (long puntajeObtenido) {

    FILE *pArchivoIN, *pArchivoOUT;
    pArchivoIN = fopen("premios.in", "r");
    pArchivoOUT = fopen("resultados.out", "w");

    fprintf(pArchivoOUT, "Puntaje obtenido: %ld\n", puntajeObtenido);
    fprintf(pArchivoOUT, "Premio: ");

    int puntajeAnterior, puntajeActual;
    char premioAnterior[100], premioActual[100];

    fscanf(pArchivoIN, "%d %s", &puntajeAnterior, premioAnterior);
    if (puntajeObtenido < puntajeAnterior) {
        fprintf(pArchivoOUT, "Nada");
        fclose(pArchivoIN);
        fclose(pArchivoOUT);
        return;
    }
    else {
        while (fscanf(pArchivoIN, "%d %s", &puntajeActual, premioActual) != EOF) {
            if (puntajeObtenido > puntajeAnterior && puntajeObtenido < puntajeActual) {
                fprintf(pArchivoOUT, "%s", premioAnterior);
                fclose(pArchivoIN);
                fclose(pArchivoOUT);
                return;
            }
            else {
                puntajeAnterior = puntajeActual;
                strcpy(premioAnterior, premioActual);
            }
        }
        fprintf(pArchivoOUT, "%s", premioAnterior);
        fclose(pArchivoIN);
        fclose(pArchivoOUT);
        return;
    }
}



/********** Otras funciones **********/
lista insertarLista(lista rodillo, char elemento) {

	nodo *nuevo = (nodo *)malloc(sizeof(nodo));
	nuevo->valor = elemento;
	nuevo->sgte = NULL;

	if (rodillo.size == 0) {
		rodillo.inicio = nuevo;
        rodillo.fin = nuevo;
		rodillo.size = 1;
	}
	else {
		nodo *aux = rodillo.inicio;
		int i;
		for (i = 0; i < (rodillo.size - 1); i++){
			aux = aux->sgte;
		}
		aux->sgte = nuevo;
        rodillo.fin = nuevo;
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
        rodillo.size--;
        aux = rodillo.inicio;
    }
    free(aux);

    return rodillo;
}

void imprimirLista(nodo *lista, int tamano) {

    int i;
	nodo *aux = lista;
	for (i = 0; i < (tamano - 1); i++){
		printf("%c", aux->valor);
		aux = aux->sgte;
	}
	printf("%c", aux->valor);
	printf("\n");

    return;
}
