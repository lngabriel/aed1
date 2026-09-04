#include <stdio.h>
#include <stdlib.h>

void amostra_e_ajusta(int **vetor, int capacidade_inicial, int *tamanho_final);
void gera_relatorio(int *vetor, int tamanho);

int main() {
    int *vet = NULL;
    int s, y;

    scanf("%d", &s);

    while (s < 0 || (s % 5 != 0)) {
        printf("digite novamente: ");
        scanf("%d", &s);
    }

    vet = (int *)malloc(sizeof(int) * s);
    amostra_e_ajusta(vet, s, &y);
    
    gera_relatorio(vet, s);

    free(vet);
}

void amostra_e_ajusta(int **vetor, int capacidade_inicial, int *tamanho_final) {
    int min = (capacidade_inicial * 80) / 100;
    int max = (capacidade_inicial * 120) / 100;
    int i = 0;
    
    while (i < max) {
        scanf("%d", (*vetor)[i]);

        if (i >= min && (*vetor)[i] == 0) {
            printf("encerrando...\n");
            break;
        }

        i++;

        if (i == capacidade_inicial) {
            *vetor = realloc(*vetor, sizeof(int) * max);
        }
        
    }

    *tamanho_final = i;
    
    return vetor;
}

void gera_relatorio(int *vetor, int tamanho) {
    int i, soma = 0, media = 0, leituras_criticas = 0;
    for (i = 0; i < tamanho; i++) {
        soma += vetor[i];
        if (vetor[i] >= 200) {
            leituras_criticas++;
        }
    }
    media = soma / tamanho;
    printf("relatorio do sensor:\n");
    printf("tempo medio: %d\n", media);
    printf("leituras criticas: %d\n", leituras_criticas);
}