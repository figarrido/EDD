#include "../Nodo/nodoDoble.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct listaD{
  Nodo* head;
  Nodo* tail;
  int count;
} ListaD;

ListaD* iniciarLista(){
    ListaD* list = (ListaD*) malloc(sizeof(ListaD));
    list->head = NULL;
    list->tail = NULL;
    list->count = 0;
    return list;
}

int vacio(ListaD* list){
  return (list->head == NULL) ? 1 : 0;
}

int largo(ListaD* list){
  return list->count;
}

Nodo* insertar(ListaD* list, int value){
  if (list->head == NULL){
    list->head = (Nodo*) malloc(sizeof(Nodo));
    list->head->value = value;
    list->head->next = NULL;
    list->head->back = NULL;
    list->tail = list->head;
  }else{
    Nodo* node = list->tail;
    node->next = (Nodo*) malloc(sizeof(Nodo));
    node->next->value = value;
    node->next->next = NULL;
    node->next->back = node;
    list->tail = node->next;
  }
  list->count++;
  return list->tail;
}

Nodo* insertarEn(ListaD* list, int value, int index){
  if (index > list->count || index < 0){
    fprintf(stderr, "Index fuera de rango\n");
    exit(2);
  }

  Nodo* node;
  if(index == list->count){
    return insertar(list, value);
  }
  else{
    node = list->head;
    for (int i = 0; (i < index) && (node->next != NULL); i++) node = node->next;
  }

  Nodo* newNode = (Nodo*) malloc(sizeof(Nodo));
  newNode->value = value;

  if (node->back != NULL) node->back->next = newNode;
  newNode->back = node->back;
  newNode->next = node;
  node->back = newNode;

  if (index == 0) list->head = newNode;
  list->count++;
  return newNode;
}

void eliminar(ListaD* list, int index){
  if (index >= list->count || index < 0){
    fprintf(stderr, "Index fuera de rango\n");
    exit(2);
  }

  Nodo* node = list->head;
  for (int i = 0; i < index; i++) node = node->next;

  if (node->back != NULL) node->back->next = node->next;
  else list->head = node->next;

  if (node->next != NULL) node->next->back = node->back;
  else list->tail = node->back;

  free(node);
  list->count--;
}

void printLista(ListaD* list){
  for (Nodo* node = list->head; node->next != NULL; node = node->next)
    printf("%c -> ", node->value);
  printf("%c\n", list->tail->value);
}

void printListaInversa(ListaD* list){
  for (Nodo* node = list->tail; node->back != NULL; node = node->back)
    printf("%c <- ", node->value);
  printf("%c\n", list->head->value);
}
