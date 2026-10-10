/*
 * UNIVERSIDADE FEDERAL DE PELOTAS
 * Centro de Desenvolvimento Tecnologico
 * Algoritmos e Estruturas de Dados I - Listas Encadeadas
 *
 * Nome: ______________________________   Matricula: ______________
 *
 * QUESTAO - RECEBIMENTO DE CARGA DE MEDICAMENTOS            (10,0 pontos)
 *
 * Uma farmacia universitaria controla os lotes de um medicamento em uma
 * lista encadeada simples. Cada lote possui uma data de validade, no formato
 * AAAAMMDD, e uma quantidade de unidades. Para evitar perdas por vencimento,
 * a farmacia deve dispensar sempre primeiro os lotes mais proximos do
 * vencimento. Por isso, o sistema de dispensacao retira os lotes sempre pelo
 * INICIO da lista, e precisa que o lote que vence primeiro esteja na frente.
 *
 * Acontece que o cadastro antigo da farmacia mantem o estoque ordenado por
 * validade DECRESCENTE (o lote de maior validade fica na frente), o oposto
 * do que a dispensacao precisa. Sempre que uma nova carga chega, tambem em
 * ordem decrescente, o farmaceutico executa o programa de recebimento: ele
 * descarta do estoque os lotes que nao podem mais ser dispensados (vencidos
 * ou esgotados) e reorganiza tudo em uma unica lista, pronta para a
 * dispensacao. Dentro de uma mesma lista nao ha validades repetidas.
 *
 * Implemente a funcao:
 *
 *   Lote *recebeCarga(Lote *estoque, Lote *carga, int hoje);
 *
 * A lista carga NUNCA e vazia (possui pelo menos um lote) e tambem esta
 * ordenada por validade decrescente. Todos os seus lotes estao dentro da
 * validade e tem quantidade maior que zero. Alem disso, a validade de TODOS
 * os lotes da carga e maior que a validade de qualquer lote do estoque. O
 * estoque, por sua vez, pode estar vazio. A funcao deve:
 *
 *   1) Remover do estoque todos os lotes vencidos (validade < hoje) ou
 *      esgotados (qtd == 0), em qualquer posicao, liberando os nos
 *      removidos com free.
 *
 *   2) CONCATENAR o estoque restante e a carga em uma unica lista, com a
 *      carga na frente do estoque.
 *
 *   3) INVERTER a lista obtida, de modo que o resultado fique ordenado por
 *      validade CRESCENTE, isto e, com o lote mais proximo do vencimento
 *      na frente. A inversao deve ser feita religando os nos existentes.
 *
 *   4) Retornar o inicio da lista resultante.
 *
 * A funcao recebeCarga nao pode utilizar vetores nem alocar novos nos e deve
 * utilizar apenas espaco auxiliar O(1). Ela deve funcionar corretamente para
 * quaisquer listas que respeitem as condicoes acima, inclusive estoque vazio
 * e outros casos-limite.
 *
 * Exemplo 1 (hoje = 20261009):
 *
 *   Estoque: [20290301|20] -> [20280101|0] -> [20271010|3]
 *            -> [20260105|8] -> [20250310|5] -> NULL
 *   Carga:   [20310601|30] -> [20300101|15] -> NULL
 *
 *   Resultado:
 *   [20271010|3] -> [20290301|20] -> [20300101|15] -> [20310601|30]
 *   -> NULL
 *
 * Exemplo 2 (hoje = 20261009), todo o estoque deve ser descartado:
 *
 *   Estoque: [20270101|0] -> [20250101|4] -> NULL
 *   Carga:   [20270601|10] -> NULL
 *
 *   Resultado: [20270601|10] -> NULL
 *
 * INSTRUCOES
 * - Implemente SOMENTE a funcao recebeCarga (marcada com TODO).
 * - Nao altere a struct, as funcoes auxiliares nem a assinatura de recebeCarga.
 * - O main fornecido testa apenas o Exemplo 1. Teste sua solucao tambem
 *   com outras situacoes, alterando o main para os seus testes. A correcao
 *   usara outros casos.
 * - Compilar: gcc -Wall -Wextra -o prova prova_a_base.c
 *   (os avisos de "parametro nao utilizado" desaparecem quando voce implementar a funcao.)
 * - ATENCAO: CODIGOS QUE NAO COMPILAREM NAO SERAO CONSIDERADOS NA AVALIACAO!
 * - Salve o arquivo com o seu nome (ex.: joao_silva.c) antes de entregar.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Lote {
    int validade;    /* formato AAAAMMDD */
    int qtd;         /* quantidade de unidades */
    struct Lote *prox;
} Lote;

/* Insere um novo lote ao final da lista e retorna o inicio da lista. */
Lote *insereFinal(Lote *lista, int validade, int qtd) {
    Lote *novo = (Lote *) malloc(sizeof(Lote));
    if (novo == NULL) {
        printf("Erro de alocacao.\n");
        exit(1);
    }
    novo->validade = validade;
    novo->qtd = qtd;
    novo->prox = NULL;

    if (lista == NULL)
        return novo;

    Lote *p = lista;
    while (p->prox != NULL)
        p = p->prox;
    p->prox = novo;
    return lista;
}

/* Imprime a lista no formato [validade|qtd] -> ... -> NULL */
void imprimeLista(Lote *lista) {
    for (Lote *p = lista; p != NULL; p = p->prox)
        printf("[%d|%d] -> ", p->validade, p->qtd);
    printf("NULL\n");
}

/* Libera todos os nos da lista. */
void liberaLista(Lote *lista) {
    while (lista != NULL) {
        Lote *tmp = lista;
        lista = lista->prox;
        free(tmp);
    }
}

/*
 * TODO: implemente a funcao recebeCarga.
 * Consulte o enunciado no inicio deste arquivo.
 *
 * Topicos essenciais:
 *  - LIMPEZA: remova do estoque os lotes vencidos (validade < hoje) ou
 *    esgotados (qtd == 0), em qualquer posicao, usando free. Atencao a
 *    remocao da cabeca e de lotes consecutivos.
 *  - CONCATENAR: coloque a carga na frente do estoque ja limpo.
 *  - INVERTER: religue os nos existentes para obter a ordem crescente.
 *  - A carga NUNCA e vazia, mas o estoque pode estar vazio (inclusive
 *    depois da limpeza).
 *  - Nao use vetores, nao aloque nos e use apenas espaco auxiliar O(1).
 *  - Retorne o inicio da lista resultante.
 */
Lote *recebeCarga(Lote *estoque, Lote *carga, int hoje) {
    /* escreva sua solucao aqui */
    Lote *atual = estoque;
    Lote *anterior = NULL;


    while (atual != NULL) {
        if (atual->validade < hoje || atual->qtd == 0) {
            Lote *remover = atual;
            anterior->prox = atual->prox;
            atual = atual->prox;
            free(remover);
        } else {
            anterior = atual;
            atual = atual->prox;
        }
    }

    // concatenação
    Lote *a = estoque;
    while (a->prox != NULL) {   
        a = a->prox;
    }
    a->prox = carga;

    // inverter lista
    Lote *prox = NULL;
    Lote *curr = estoque;
    Lote *ant = NULL;
    while (curr != NULL) {
        prox = curr->prox;
        curr->prox = ant;

        ant = curr;
        curr = prox;
    }
    estoque = ant;
    
    return estoque;
}

int main(void) {
    Lote *estoque = NULL;
    Lote *carga = NULL;
    int hoje = 20261009;

    /* construcao das listas (Exemplo 1) */
    estoque = insereFinal(estoque, 20290301, 20);
    estoque = insereFinal(estoque, 20280101, 0);
    estoque = insereFinal(estoque, 20271010, 3);
    estoque = insereFinal(estoque, 20260105, 8);
    estoque = insereFinal(estoque, 20250310, 5);

    carga = insereFinal(carga, 20310601, 30);
    carga = insereFinal(carga, 20300101, 15);

    printf("Estoque antes: ");
    imprimeLista(estoque);
    printf("Carga:         ");
    imprimeLista(carga);

    /* recebimento da carga */
    estoque = recebeCarga(estoque, carga, hoje);
    carga = NULL;   /* os nos da carga agora pertencem ao estoque */

    /* exibicao do resultado */
    printf("\nEstoque depois: ");
    imprimeLista(estoque);

    /* liberacao: so o estoque, pois ele contem os nos da carga */
    liberaLista(estoque);
    estoque = NULL;

    return 0;
}
