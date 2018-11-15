/********** Estructuras **********/
typedef struct Nodo {
	char valor;
	struct Nodo *sgte;
} nodo;

typedef struct ListaEnlazada {
	nodo *inicio;
	nodo *fin;
	int size;
} lista;

/********** Prototipos **********/
void obtenerDimensiones(int *dimensiones);
void crearMaquina(char **maquina, int ancho);
lista girarRodillo(lista rodillo, int j);
long encontrarCombinaciones(char **maquina, int alto, int ancho);

lista insertarLista(lista actual, char elemento);
lista borrarLista(lista rodillo);
void imprimirLista(nodo *lista, int tamano);