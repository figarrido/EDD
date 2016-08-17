#include <stdlib.h>
#include <stdio.h>
#include "../Nodo/nodoBinario.h"

typedef struct heap{
  Nodo* root;
} Heap;

Heap* iniciarHeap(){
  Heap* heap = (Heap*) malloc(sizeof(Heap));
  heap->root = NULL;
  return heap;
}

Nodo* _crearNodo(Nodo* parent, int value){
  Nodo* node = (Nodo*) malloc(sizeof(Nodo));
  node->parent = parent;
  node->left = NULL;
  node->right = NULL;
  node->value = value;
  node->count = 0;
  node->balanced = 1;
  return node;
}

void _agregar(Nodo* node, int value){
  node->count++;
  if (node->left == NULL){
    node->left = _crearNodo(node, value);
    node->balanced = 0;
    if (node->left->value > node->value){
      int aux = node->value;
      node->value = node->left->value;
      node->left->value = aux;
    }
    return;
  }
  else if (node->right == NULL){
    node->right = _crearNodo(node, value);
    node->balanced = 1;
    if (node->right->value > node->value){
      int aux = node->value;
      node->value = node->right->value;
      node->right->value = aux;
    }
    return;
  }

  if (node->left->balanced && (node->left->count > node->right->count))
    _agregar(node->right, value);
  else
    _agregar(node->left, value);

  if (!node->left->balanced || !node->right->balanced || (node->left->count > node->right->count))
    node->balanced = 0;
  else
    node->balanced = 1;

  if (node->left->value > node->value){
    int aux = node->value;
    node->value = node->left->value;
    node->left->value = aux;
  }else if (node->right->value > node->value){
    int aux = node->value;
    node->value = node->right->value;
    node->right->value = aux;
  }
}

void agregarElemento(Heap* heap, int value){
  if (heap->root == NULL) heap->root = _crearNodo(NULL, value);
  else _agregar(heap->root, value);
}

void _printHeap(Nodo* node){
  if (node->left != NULL) _printHeap(node->left);
  printf("%d ", node->value);
  if (node->right != NULL) _printHeap(node->right);
}

void printHeap(Heap* heap){
  _printHeap(heap->root);
  printf("\n");
}

int vacio(Heap* heap){
  return (heap->root != NULL) ? 0 : 1;
}
