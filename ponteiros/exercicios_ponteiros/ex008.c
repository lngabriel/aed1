#include <stdio.h>

void min_max(int *v, int n, int *min, int *max);

int main() {
    int vet[5] = {2, 2, 3, 4, 5};
    int min, max;
    min_max(vet, 5, &min, &max);
    printf("menor = %d\n", min);
    printf("maior = %d\n", max);
}

void min_max(int *v, int n, int *min, int *max) {
    int i; 

    *min = v[0];
    *max = v[0];

    for (i = 1; i < n; i++) {
        if (v[i] < *min) {
            *min = v[i];
        }
        if (v[i] > *max) {
            *max = v[i];
        }
    }
}