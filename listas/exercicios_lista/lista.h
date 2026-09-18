#ifndef LISTA_H
#define LISTA_H

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

Head *criaLista();
int listaVazia(Head *lista);
void inserirInicio(Head *lista, Dados dado);
void inserirFinal(Head *lista, Dados dado);
int removerInicio(Head *lista);
int removerFinal(Head *lista);
int buscar(Head *lista, int cod, Dados *resultado);
void imprimirLista(Head *lista);
void liberaLista(Head *lista);
int contagem_nodos(Head *lista);
int qtd_maior(Head *lista, int v);
void remover_por_cod(Head *lista, int cod);
void inverter_lista(Head *lista);

#endif