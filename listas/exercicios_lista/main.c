#include <stdio.h>
#include "lista.h"

int main() {
    Head *lista = criaLista();
    Dados d1 = {3, "mouse", 70.00};
    Dados d2 = {4, "teclado", 90.00};
    inserirFinal(lista, d1);
    inserirFinal(lista, d2);
    remover_pares(lista);
    imprimirLista(lista);
}