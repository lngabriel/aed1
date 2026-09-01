#include <stdio.h>

void troca_vizinhos(int *a, int *b);

int main() {
    int vet[6] = {10, 20, 30, 40, 50, 60};
    int i;
    for (i = 0; i < 6; i += 2) {
        troca_vizinhos(&vet[i], &vet[i + 1]);
    }
    for (i = 0; i < 6; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void troca_vizinhos(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}