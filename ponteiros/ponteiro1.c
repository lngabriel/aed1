#include <stdio.h>

int main() {
    int *ponteiro = NULL, variavel1 = 10, variavel2 = 25;

    ponteiro = &variavel2;
    *ponteiro = 50;
    variavel1 = *ponteiro;

    printf("Endereço da variavel2: %p\n", &variavel2);
    printf("Endereço do que ponteiro está guardando: %p\n", ponteiro);
    printf("Conteudo da variavel2: %d\n", variavel2);
    printf("Conteudo da variavel1: %d\n", variavel1);
}