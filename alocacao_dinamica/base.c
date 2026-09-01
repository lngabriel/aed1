#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho_vetor = 2;
    int *vetor = NULL;

    // *vetor guarda o endereco do primeiro elemento do bloco alocado na heap
    vetor = (int *)malloc(sizeof(int) * tamanho_vetor);
    
    // liberando a memoria da heap
    free(vetor);
}