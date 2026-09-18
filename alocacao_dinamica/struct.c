#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

int main() {
    Pessoa *p = NULL;
    p = (Pessoa *)malloc(sizeof(Pessoa));

    scanf(" %[^\n]", (*p).nome);
    scanf("%d", &(*p).idade);

    printf("Nome: %s\n", (*p).nome);
    printf("Idade: %d\n", (*p).idade);

    free(p);
}