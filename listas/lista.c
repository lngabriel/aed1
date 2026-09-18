#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int cod;
    char nome[10];
    float preco;
} Dados;

typedef struct Nodo {
    Dados info;
    struct Nodo *prox;
} Nodo;

typedef struct {
    Nodo *pFirst;
} Head;

Nodo *criaNo(Dados dado);
void inserir_inicio(Head *lista, Dados dado);
void inserir_final(Head *lista, Dados dado);
void remover_inicio(Head *lista);
void remover_final(Head *lista);
void imprimir_lista(Head *lista);

int main() {
    Head lista;
    lista.pFirst = NULL;

    Dados d1 = {1, "mouse", 50.00};
    Dados d2 = {2, "teclado", 70.00};
    Dados d3 = {3, "escova", 5.00};
    Dados d4 = {4, "fone", 40.00};

    inserir_final(&lista, d1);
    inserir_final(&lista, d2);
    inserir_inicio(&lista, d3);
    inserir_final(&lista, d4);

    printf("lista apos inserir dados:\n");
    imprimir_lista(&lista);

    remover_inicio(&lista);
    printf("lista apos remover do inicio:\n");
    imprimir_lista(&lista);

    remover_final(&lista);
    printf("lista apos remover do final:\n");
    imprimir_lista(&lista);

}

Nodo *criaNo(Dados dado) {
    Nodo *novo = malloc(sizeof(Nodo));

    novo->info = dado;
    novo->prox = NULL;

    return novo;
}

void inserir_inicio(Head *lista, Dados dado) {
    Nodo *novo = criaNo(dado);
    novo->prox = lista->pFirst;
    lista->pFirst = novo;
}

void inserir_final(Head *lista, Dados dado) {
    Nodo *novo = criaNo(dado);

    /*
    SE A LISTA ESTIVER APENAS COM O HEAD, O HEAD VAI APONTAR PRO NOVO NODO
    */
    if (lista->pFirst == NULL) {
        lista->pFirst = novo;
        return;
    }

    Nodo *atual = lista->pFirst;

    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;
}

void remover_inicio(Head *lista) {
    if (lista->pFirst == NULL) {
        return;
    }

    Nodo *remover = lista->pFirst;

    lista->pFirst = lista->pFirst->prox;

    free(remover);
}

void remover_final(Head *lista) {
    if (lista->pFirst == NULL) {
        return;
    }

    if (lista->pFirst->prox == NULL) {
        free(lista->pFirst);
        lista->pFirst = NULL;
        return;
    }

    Nodo *atual = lista->pFirst;

    while (atual->prox->prox != NULL) {
        atual = atual->prox;
    }

    Nodo *remover = atual->prox;

    atual->prox = NULL;

    free(remover);
}

void imprimir_lista(Head *lista) {
    Nodo *atual = lista->pFirst;

    while (atual != NULL) {
        printf("codigo: %d\n", atual->info.cod);
        printf("nome: %s\n", atual->info.nome);
        printf("preco: %.2f\n", atual->info.preco);
        printf("------------------\n");

        atual = atual->prox;
    }
}