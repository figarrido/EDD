typedef struct nodo{
  int value;
  int balanced;
  int count;
  struct nodo* left;
  struct nodo* right;
  struct nodo* parent;
} Nodo;
