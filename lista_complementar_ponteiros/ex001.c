#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Ponto;

Ponto *criar_ponto(int x, int y);
void destruir_ponto(Ponto *p);

int main() {
    int x = 2, y = 4;
    Ponto *p = criar_ponto(x, y);
    printf("ponto x = %d\nponto y = %d\n", p->x, p->y);
    destruir_ponto(p);
}

Ponto *criar_ponto(int x, int y) {
    /* aloca memoria na heap para um ponto */
    /* cria um ponteiro que aponta para esse ponto na heap */
    Ponto *p = (Ponto *)malloc(sizeof(Ponto));

    if (p == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    /* atribui os valores */
    p->x = x;
    p->y = y;

    return p;
}

void destruir_ponto(Ponto *p) {
    free(p);
}