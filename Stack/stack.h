#include "stack.c"

typedef struct stack Stack;
Stack* iniciarStack();
void push(Stack*, int);
void printStack(Stack*);
int pop(Stack*);
int vacio(Stack*);
void destruirStack(Stack*);
