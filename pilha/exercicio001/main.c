#include <stdio.h>
#include "pilha.h"

int main() {
    Pilha pilha;
    Elem e = {2.5};
    Elem e2 = {3.2};
    reset(&pilha);
    push(&pilha, e);
    push(&pilha, e2);
    top(&pilha);
    Elem teste = pop(&pilha);
    printf("retirado do topo: %.2f\n", teste.value);
    top(&pilha);
}