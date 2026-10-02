#include <stdio.h>
#include <stdlib.h>

int *copia_vetor(int *v, int n);

int main() {
    int vet[5] = {3, 5, 7, 9, 4};
    int i;
    int *copia = copia_vetor(vet, 5);

    for (i = 0; i < 5; i++) {
        printf("%d ", vet[i]);
    }

    printf("\n");

    for (i = 0; i < 5; i++) {
        printf("%d ", copia[i]);
    }
    
    free(copia);
}

int *copia_vetor(int *v, int n) {
    int i, *novo_vet = NULL;

    novo_vet = (int *)malloc(sizeof(int) * n);

    if (novo_vet == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        novo_vet[i] = v[i];
    }

    return novo_vet;
}