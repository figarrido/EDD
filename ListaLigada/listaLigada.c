#include <stdio.h>
#include <stdlib.h>
#include "../Nodo/nodoSimple.h"

typedef struct lista{
  Nodo* first;
  Nodo* last;
} Lista;

Lista* crearLista(){
  Lista* list = (Lista*) malloc(sizeof(Lista));
  list->first = NULL;
  list->last = NULL;
  return list;
}

void printLista(Lista* list){
  Nodo* node;
  printf("[");
  for (node = list->first; node->link != NULL; node = node->link)
    printf("%d, ", node->value);
  printf("%d]\n", node->value);
}

void destruirLista(Lista* list){
  Nodo* node = list->first;
  while (node != NULL){
    Nodo* tmp = node->link;
    free(node);
    node = tmp;
  }
  free(list);
}

int vacio(Lista* list){
  return (list->first == NULL) ? true : false;
}

int largo(Lista* list){
  Nodo* node = list->first;
  if (node == NULL) return 0;
  int length = 1;
  while (node->link != NULL){
    length++;
    node = node->link;
  }
  return length;
}

void enqueue(Lista* list, int value){
  if (list->first == NULL){
    list->first = (Nodo*) malloc(sizeof(Nodo));
    list->first->value = value;
    list->first->link = NULL;
    list->last = list->first;
  }else{
    Nodo* node = list->last;
    node->link = (Nodo*) malloc(sizeof(Nodo));
    node->link->value = value;
    node->link->link = NULL;
    list->last = node->link;
  }
}

int obtenerElemento(Lista* list, int index){
  if (list->first == NULL) exit(EXIT_FAILURE);
  Nodo* node = list->first;
  int i = 0;
  while (node->link != NULL){
    if (i == index) break;
    node = node->link;
    i++;
  }
  return node->value;
}

void eliminarPorValor(Lista* list, int value){
  if (list->first == NULL) exit(EXIT_FAILURE);
  Nodo* node = list->first;
  if (node->value == value){
    list->first = node->link;
    free(node);
    return;
  }
  while (node->link != NULL){
    if (node->link->value == value){
        Nodo* tmp = node->link;
        node->link = tmp->link;
        free(tmp);
        return;
    }
    node = node->link;
  }
}

void eliminarPorIndice(Lista* list, int index){
  if (list->first == NULL) exit(EXIT_FAILURE);
  Nodo* node = list->first;
  if (index == 0){
    list->first = node->link;
    free(node);
    return;
  }
  while (node->link != NULL){
    if (index == 1){
      Nodo* tmp = node->link;
      node->link = node->link->link;
      free(tmp);
      return;
    }
    node = node->link;
    index--;
  }
}

int dequeue(Lista* list){
  if (list->first == NULL) exit(EXIT_FAILURE);
  int value = obtenerElemento(list, 0);
  eliminarPorIndice(list, 0);
  return value;
}
