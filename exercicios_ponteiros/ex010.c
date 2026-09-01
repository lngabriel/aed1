#include <stdio.h>
#include <stdlib.h>

void min_max(int *v, int n, int *min, int *max);

int main() {
    int i = 0, *vet = NULL;
    int valor, tam_vetor = 0;
    int min, max;

    vet = (int *)malloc(sizeof(int));

    if (vet == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    do {
        scanf("%d", &valor);
        if (valor == -1) break;

        tam_vetor++;

        vet = (int *)realloc(vet, tam_vetor * sizeof(int));

        if (vet == NULL) {
            printf("Erro ao alocar memoria.\n");
            exit(1);
        }

        vet[i] = valor;
        i++;
    } while (1);

    for (i = 0; i < tam_vetor; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
    
    printf("quantidade de elementos: %d", tam_vetor);
    printf("\n");

    if (tam_vetor > 0) {
        min_max(vet, tam_vetor, &min, &max);
        printf("menor valor: %d\n", min);
        printf("maior valor: %d\n", max);
    }

    free(vet);
}

void min_max(int *v, int n, int *min, int *max) {
    if (n <= 0) return;

    *max = *v;
    *min = *v;
    int *ini = v;
    int *fim = v + n - 1;

    while (ini <= fim) {
        if (*ini < *min) {
            *min = *ini;
        }
        if (*ini > *max) {
            *max = *ini;
        }
        ini++;
    }
}