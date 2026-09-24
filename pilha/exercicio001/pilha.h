#ifndef PILHA_H
#define PILHA_H

typedef struct {
    float value;
} Elem;

typedef struct pilha Pilha;

typedef struct Nodo {
    Elem elem;
    struct Nodo *prox;
} Nodo;

typedef struct pilha {
    Nodo *topo;
    int tamanho;
} Pilha;

void reset(Pilha *pilha);
int empty(Pilha *pilha);
int size(Pilha *pilha);
void push(Pilha *pilha, Elem elem);
Elem pop(Pilha *pilha);
void top(Pilha *pilha);
void clear(Pilha *pilha);
void print(Pilha *pilha);

#endif