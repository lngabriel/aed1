#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

Produto **criar_estoque_ptrs(int n);
void liberar_estoque_ptrs(Produto **estoque, int n);

int main() {
    Produto **p = criar_estoque_ptrs(2);
    int i;
    for (i = 0; i < 2; i++) {
        printf("nome: %s\n", p[i]->nome);
        printf("preco: %.2f\n", p[i]->preco);
        printf("quantidade: %d\n", p[i]->quantidade);
    }
    liberar_estoque_ptrs(p, 2);
}

Produto **criar_estoque_ptrs(int n) {
    Produto **p = (Produto **)malloc(sizeof(Produto *) * n);
    if (p == NULL) exit(1);
    int i;
    for (i = 0; i < n; i++) {
        p[i] = (Produto *)malloc(sizeof(Produto));
        if (p[i] == NULL) exit(1);

        scanf(" %[^\n]", p[i]->nome);
        scanf("%f", &p[i]->preco);
        scanf("%d", &p[i]->quantidade);
    }
    return p;
}

void liberar_estoque_ptrs(Produto **estoque, int n) {
    int i;
    for (i = 0; i < n; i++) {
        free(estoque[i]);
    }
    free(estoque);
}