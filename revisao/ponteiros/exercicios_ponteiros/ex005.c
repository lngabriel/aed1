#include <stdio.h>

void inverter(int *v, int n);

int main() {
    int vetor[5] = {10, 20, 30, 40, 50};
    printf("antes:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    inverter(vetor, 5);
    printf("depois:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void inverter(int *v, int n) {
    int *inicio = v;
    int *fim = v + n - 1;
    int temp;

    while (inicio < fim) {
        temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        inicio++;
        fim--;
    }
}