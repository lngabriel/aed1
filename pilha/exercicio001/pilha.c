#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void reset(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

int empty(Pilha *pilha) {
    if (pilha->tamanho == 0) {
        return 1;
    }
    return 0;
}

int size(Pilha *pilha) {
    return pilha->tamanho;
}

void push(Pilha *pilha, Elem elem) {
    Nodo *novo = malloc(sizeof(Nodo));

    novo->elem = elem;
    novo->prox = pilha->topo;

    pilha->topo = novo;
    pilha->tamanho++;
}

Elem pop(Pilha *pilha) {
    Nodo *remover;
    Elem valor;

    remover = pilha->topo;
    pilha->topo = remover->prox;
    valor = remover->elem;
    free(remover);
    
    pilha->tamanho--;
    return valor;
}

void top(Pilha *pilha) {
    if (empty(pilha)) {
        printf("pilha vazia.\n");
        return;
    }

    printf("topo da pilha: %.2f\n", pilha->topo->elem.value);
}

// void clear(Pilha)
