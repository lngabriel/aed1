#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    float valor;
    int quantidade;
} Produto;

int total_produtos = 0;
void menu(int *opcao);
void cadastrar_produto(Produto *produto);
void exibir_relatorio(Produto *produto);

int main() {
    Produto *estoque = NULL;
    
    int opcao;

    do {
        menu(&opcao);

        switch (opcao) {
            case 1: {
                if (estoque == NULL) {
                    estoque = (Produto *) malloc(sizeof(Produto));
                } else {
                    estoque = (Produto *) realloc(estoque, (total_produtos + 1) * sizeof(Produto));
                }

                if (estoque == NULL) {
                    printf("Erro ao alocar memória.\n");
                    return 1;
                }

                cadastrar_produto(&estoque[total_produtos]);
                total_produtos++;
                break;
            }

            case 2: {
                exibir_relatorio(estoque);
                printf("\n");
                break;
            }

            case 0: {
                printf("Encerrando o programa...\n");
                break;
            }

            default: {
                printf("Opcao invalida!\n");
                break;
            }
        }
    } while (opcao != 0);

    free(estoque);
    return 0;
    
}

void menu(int *opcao) {
    printf("\n#### CONTROLE DE ESTOQUE ####\n");
    printf("1 - Adicionar produto\n2 - Listar produtos\n0 - Sair\n");
    printf("Opcao: ");
    scanf("%d", opcao);
}

void cadastrar_produto(Produto *produto) {
    printf("Nome: ");
    scanf(" %[^\n]", produto->nome);

    printf("Valor: ");
    scanf("%f", &produto->valor);

    printf("Quantidade: ");
    scanf("%d", &produto->quantidade);
}

void exibir_relatorio(Produto *produto) {
    printf("\n#### RELATORIO DO ESTOQUE ####\n");
    for (int i = 0; i < total_produtos; i++) {
        printf("Nome: %s; Valor: R$ %.2f; Quantidade: %d; Valor Total: R$ %.2f\n",
           produto[i].nome, produto[i].valor, produto[i].quantidade, produto[i].valor * produto[i].quantidade);

    }
}