#include <stdio.h>
#include "lista.h"

int main() {
    Head *lista = criaLista();

    Dados d1 = {1, "mouse", 70.00};
    Dados d2 = {2, "teclado", 90.00};
    
    Head *lista2 = criaLista();
    Dados x1 = {8, "teclado", 90.00};
    Dados x2 = {4, "pendrive", 20.00};

    criaLista();

    inserirFinal(lista, d1);
    inserirFinal(lista, d2);
    inserirFinal(lista2, x1);
    inserirFinal(lista2, x2);

    intercalar(lista, lista2);

    imprimirLista(lista);
    
}