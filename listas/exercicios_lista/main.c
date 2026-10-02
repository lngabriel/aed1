#include <stdio.h>
#include "lista.h"

int main() {
    Head *lista = criaLista();
    Head *destino = criaLista();
    Dados d1 = {1, "mouse", 70.00};
    Dados d2 = {2, "teclado", 90.00};
    inserirFinal(lista, d1);
    inserirFinal(lista, d2);
    copia(lista, destino);
    imprimirLista(lista);
}