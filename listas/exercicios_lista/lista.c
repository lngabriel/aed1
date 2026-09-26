#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

Head *criaLista() {
    // aloca memoria para a struct head
    Head *lista = malloc(sizeof(Head));
    lista->pFirst = NULL;
    //retorna o ponteiro para a struct head criada
    return lista;
}

int listaVazia(Head *lista) {
    if (lista->pFirst == NULL) {
        return 1; // lista vazia
    }
    return 0; // lista não vazia
}

void inserirInicio(Head *lista, Dados dado) {
    // aloca memoria pro novo nodo
    Nodo *novo = malloc(sizeof(Nodo));

    // copia os dados recebidos para dentro do novo nodo
    novo->info = dado;

    // novo nodo aponta para o atual primeiro elemento da lista
    novo->prox = lista->pFirst;

    // head passa apontar para o novo nodo como o primeiro
    lista->pFirst = novo;
}

void inserirFinal(Head *lista, Dados dado) {
    // aloca memoria pro novo nodo
    Nodo *novo = malloc(sizeof(Nodo));
    novo->info = dado;
    novo->prox = NULL;

    // verifica se a lista é vazia e se for insere o novo nodo
    if (listaVazia(lista)) {
        lista->pFirst = novo;
        return;
    }

    // cria um navegador "atual" e coloca ele apontando para o primeiro nodo da lista
    Nodo *atual = lista->pFirst;

    // enquanto o navegador não chegar no ultimo nodo da lista
    while (atual->prox != NULL) {
        // passa pro proximo nodo
        atual = atual->prox;
    }

    // ultimo nodo vai apontar pro novo ultimo nodo
    atual->prox = novo;
}

int removerInicio(Head *lista) {
    if (listaVazia(lista)) {
        return 0;
    }

    // cria um nodo que vai conter o primeiro nodo da lista
    Nodo *remover = lista->pFirst;

    // head vai apontar para o segundo elemento que virou o primeiro elemento pq o primeiro vai ser removido
    lista->pFirst = lista->pFirst->prox;

    // libera o antigo primeiro nodo
    free(remover);
    return 1;
}

int removerFinal(Head *lista) {
    if (listaVazia(lista)) {
        return 0;
    }

    // se o primeiro nodo nao aponta pra nada, ele é o ultimo nodo, então vamos remover ele
    if (lista->pFirst->prox == NULL) {
        free(lista->pFirst);
        lista->pFirst = NULL;
        return 1;
    }


    // cria um navegador "atual" e coloca ele apontando para o primeiro nodo da lista
    Nodo *atual = lista->pFirst;

    // percorrendo a lista até que pare no penúltimo nodo
    while (atual->prox->prox != NULL) {
        // passa pro proximo nodo
        atual = atual->prox;
    }

    // cria o nodo que vai conter o ultimo nodo da lista
    Nodo *remover = atual->prox;

    // faz o ultimo nodo apontar pra null
    atual->prox = NULL;

    // libera o antigo ultimo nodo
    free(remover);

    return 1;
}

int buscar(Head *lista, int cod, Dados *resultado) {
    if (listaVazia(lista)) {
        return 0;
    }
    
    // cria o navegador
    Nodo *atual = lista->pFirst;

    // enquanto nao chegar no fim da lista
    while (atual != NULL) {
        // se o cod do nodo atual for igual o cod que estamos buscando
        if (atual->info.cod == cod) {
            // pegue o struct dados inteiro que está em atual.info e copie ele para dentro do endereço que resultado esta apontando
            *resultado = atual->info;
            //resultado->cod = atual->info.cod;
            //strcpy(resultado->nome, atual->info.nome);
            //resultado->preco = atual->info.preco;
            return 1;
        }
        atual = atual->prox;
    }

    return 0;    
}

void imprimirLista(Head *lista) {
    if (listaVazia(lista)) {
        return;
    }

    int i = 1;

    Nodo *atual = lista->pFirst;

    while (atual != NULL) {
        printf("item %d:\n", i);
        printf("codigo: %d\n", atual->info.cod);
        printf("nome: %s\n", atual->info.nome);
        printf("preco: %.2f\n", atual->info.preco);
        printf("---------------\n\n");
        atual = atual->prox;
        i++;
    }
}

void liberaLista(Head *lista) {
    Nodo *atual = lista->pFirst;
    
    while (atual != NULL) {
        Nodo *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(lista);
}

int contagem_nodos(Head *lista) {
    int contagem = 0;
    
    Nodo *atual = lista->pFirst;
    
    while (atual != NULL) {
        contagem++;
        atual = atual->prox;
    }
    return contagem;
}

int qtd_maior(Head *lista, int v) {
    int contagem = 0;

    Nodo *atual = lista->pFirst;
    
    while (atual != NULL) {
        if (atual->info.preco > v) {
            contagem++;
        }
        atual = atual->prox;
    }
    return contagem;
}

void remover_por_cod(Head *lista, int cod) {
    Nodo *atual = lista->pFirst;
    Nodo *anterior = NULL;

    while (atual != NULL) {
        if (atual->info.cod == cod) {
            Nodo *remover = atual;

            if (anterior == NULL) {
                // é o primeiro no da lista
                lista->pFirst = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            atual = atual->prox;
            free(remover);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }
}

void inverter_lista(Head *lista) {
    Nodo *anterior = NULL;
    Nodo *atual = lista->pFirst;
    Nodo *proximo = NULL;
    
    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;

        anterior = atual;
        atual = proximo;
    }

    lista->pFirst = anterior;
}

void inverter_primeiros_n(Head *lista, int n) {
    Nodo *anterior = NULL;
    Nodo *atual = lista->pFirst;
    Nodo *proximo = NULL;

    // contador de nos ja invertidos
    int i = 0;
    
    if (n < 0 || n > contagem_nodos(lista)) {
        printf("numero invalido.\n");
        return;
    }

    while (atual != NULL &&  i < n) {
        // guarda o proximo no para nao perder
        proximo = atual->prox;

        // inverter a ligacao do no atual
        atual->prox = anterior;

        // avanca anterior para o no atual
        anterior = atual;   

        // avanca atual para o proximo no original
        atual = proximo;
        i++;
    }

    lista->pFirst->prox = atual;
    lista->pFirst = anterior;
}

void intercalar(Head *lista1, Head *lista2) {
    Nodo *atual_l1 = lista1->pFirst;
    Nodo *atual_l2 = lista2->pFirst;
    Nodo *prox_l1, *prox_l2;

    if (atual_l1 == NULL) {
        lista1->pFirst = atual_l2;
        lista2->pFirst = NULL;
        return;
    }

    while (atual_l1 != NULL && atual_l2 != NULL) {
        prox_l1 = atual_l1->prox;
        prox_l2 = atual_l2->prox;

        atual_l1->prox = atual_l2;

        if (prox_l1 != NULL)
            atual_l2->prox = prox_l1;

        atual_l1 = prox_l1;
        atual_l2 = prox_l2;
    }

    lista2->pFirst = NULL;
}