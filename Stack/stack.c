#include <stdlib.h>
#include <stdio.h>
#include "../Nodo/nodoSimple.h"

typedef struct stack{
  Nodo* top;
} Stack;

Stack* iniciarStack(){
  Stack* stack = (Stack*) malloc(sizeof(Stack));
  stack->top = NULL;
  return stack;
}

void push(Stack* stack, int value){
  if (stack->top == NULL){
    stack->top = (Nodo*) malloc(sizeof(Nodo));
    stack->top->value = value;
    stack->top->link = NULL;
  }else{
    Nodo* node = (Nodo*) malloc(sizeof(Nodo));
    node->value = value;
    node->link = stack->top;
    stack->top = node;
  }
}

void printStack(Stack* stack){
  if (stack->top == NULL) exit(EXIT_FAILURE);
  Nodo* node;
  for (node = stack->top; node->link != NULL; node = node->link)
    printf("%d -> ", node->value);
  printf("%d\n", node->value);
}

int vacio(Stack* stack){
  return (stack->top == NULL) ? 1 : 0;
}

int pop(Stack* stack){
  if (stack->top == NULL) exit(EXIT_FAILURE);
  Nodo* tmp = stack->top;
  int out = tmp->value;
  stack->top = tmp->link;
  free(tmp);
  return out;
}

void destruirStack(Stack* stack){
  while (!vacio(stack)) pop(stack);
  free(stack);
}
