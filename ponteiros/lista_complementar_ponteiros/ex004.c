#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int inserir_produto(Produto **estoque, int *n, Produto novo);
void mostrar_estoque(Produto *estoque, int n);

int main() {
    Produto *estoque = NULL;
    int n = 0;
    int opcao;

    do {
        printf("cadastrar produto? (1)\nsair (0):\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1: {
            Produto novo;
            scanf(" %[^\n]", novo.nome);
            scanf("%f", &novo.preco);
            scanf("%d", &novo.quantidade);

            if (inserir_produto(&estoque, &n, novo)) {
                printf("produto inserido com sucesso\n");
            } else {
                printf("erro ao alocar memoria\n");
            }

            break;
        }
        case 0: {
            printf("encerrando o programa...\n");
        }
        default:
            printf("opcao invalida\n");
            break;
        }
    } while (opcao != 0);

    free(estoque);
}

int inserir_produto(Produto **estoque, int *n, Produto novo) {
    Produto *temp = realloc(*estoque, (*n + 1) * sizeof(Produto));
    if (temp == NULL) return 0;

    *estoque = temp;
    (*estoque)[*n] = novo;
    (*n)++;
    return 1;
}

void mostrar_estoque(Produto *estoque, int n) {
    printf("--- estoque atual ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d) %s | preco: %.2f | qtd: %d\n",
               i + 1, estoque[i].nome, estoque[i].preco, estoque[i].quantidade);
    }
    printf("----------------------\n");
}