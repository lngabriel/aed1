#include <stdio.h>

int main() {
    int *p = NULL, *q = NULL, num;

    p = &num;
    q = p; // q recebe o endereco que p aponta (num)
    printf("Endereco de num: %p\n", &num);

    printf("Endereco que esta guardado em p: %p\n", p);
    printf("Endereco que esta guardado em q: %p\n", q);

    *p = 10; // conteudo do endereco que p aponta vai receber 10 (p aponta para endereco de num)
    printf("Conteudo de num: %d\n", num);

    *q = 20;
    printf("Conteudo de num: %d\n", num);
}