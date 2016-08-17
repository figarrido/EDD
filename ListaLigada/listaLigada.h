#include "listaLigada.c"

typedef struct lista Lista;
Lista* crearLista();
void enqueue(Lista*, int);
void printLista(Lista*);
void destruirLista(Lista*);
int obtenerElemento(Lista*, int);
void eliminarPorValor(Lista*, int);
void eliminarPorIndice(Lista*, int);
int dequeue(Lista*);
int vacio(Lista*);
