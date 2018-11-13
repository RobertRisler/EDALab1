// Estructuras
typedef struct Nodo {
	char valor;
	struct Nodo *sgte;
} nodo;

typedef struct ListaEnlazada {
	nodo *inicio;
	nodo *fin;
	int size;
} lista;

// Prototipos
void obtenerDimensiones(int *dimensiones);
void crearMaquina(char **maquina, int ancho);
void girarRodillos();

lista insertar(lista actual, char elemento);
void imprimir(nodo*lista);