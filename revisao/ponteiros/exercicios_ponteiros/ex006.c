#include <stdio.h>

int soma(int *v, int n);

int main() {
    int vetor[5] = {10, 10, 10, 5, 5};
    printf("soma dos elementos do vetor: %d\n", soma(vetor, 5));
}

int soma(int *v, int n) {
    int *ini = v;
    int *fim = v + n - 1;
    int soma = 0;

    while (ini <= fim) {
        soma += *ini;
        ini++;
    }
    return soma;
}