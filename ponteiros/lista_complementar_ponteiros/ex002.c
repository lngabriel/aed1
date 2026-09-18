#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

Produto *criar_estoque(int n);

int main() {
    Produto *p = criar_estoque(2);
    int i;
    for (i = 0; i < 2; i++) {
        printf("Nome: "); scanf(" %[^\n]", p[i].nome);
        printf("Preco: "); scanf("%f", &p[i].preco);
        printf("Quantidade: "); scanf("%d", &p[i].quantidade);
    }
    for (i = 0; i < 2; i++) {
        printf("Nome: %s\nPreco: %.2f\nQuantidade: %d\n", p[i].nome, p[i].preco, p[i].quantidade);
    }
    free(p);
}

Produto *criar_estoque(int n) {
    Produto *p = (Produto *)malloc(sizeof(Produto) * n);
    if (p == NULL) exit (1);
    return p;
}