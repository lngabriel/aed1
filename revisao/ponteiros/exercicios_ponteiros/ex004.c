#include <stdio.h>

int main () {
    int v[5] = {2, 4, 6, 8, 10};

    int *p = v;

    printf("%d\n", *p);
    printf("%d\n", *(p + 2)); // aritmetica de ponteiros, avancando 2 elemetos apos p
    printf("%d\n", p[3]);
    printf("%d\n", *p + 1); // conteudo de p somado com 1, 2+1
    printf("%d\n", *(v + 4)); // aritmetica de ponteiros, elemento 0 + 4 elementos = 10
}