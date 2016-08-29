#include "ListaDobleLigada.c"

typedef struct listaD ListaD;

ListaD* iniciarLista();
Nodo* insertar(ListaD*, int);
Nodo* insertarEn(ListaD*, int, int);
int largo(ListaD*);
void printLista(ListaD*);
void printListaInversa(ListaD*);
void eliminar(ListaD*, int);
