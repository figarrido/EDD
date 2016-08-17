#include "heap.c"

typedef struct heap Heap;
Heap* iniciarHeap();
void agregarElemento(Heap*, int);
void printHeap(Heap*);
