#include <stdio.h>
#include "lista.h"

int main() {
    Head *lista = criaLista();

    Dados d1 = {1, "mouse", 70.00};
    Dados d2 = {2, "teclado", 90.00};
    Dados d3 = {3, "fone", 50.00};
    Dados d4 = {4, "monitor", 120.00};

    criaLista();

    inserirFinal(lista, d1);
    inserirFinal(lista, d2);
    inserirFinal(lista, d3);
    inserirFinal(lista, d4);

    imprimirLista(lista);

    printf("\n");

    printf("LISTA INVERTIDA:\n\n");

    inverter_lista(lista);

    imprimirLista(lista);
    
}