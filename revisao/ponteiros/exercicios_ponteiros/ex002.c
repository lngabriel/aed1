#include <stdio.h>

int main() {
    int i = 3, j = 5;
    int *p = NULL, *q = NULL;

    p = &i;
    q = &j;
    //*p = *p + *q;
    q = &i; 
    *q = 100;
    
    //printf("Conteudo de p apos *p = *q: %d\n", *p = *q);
    //printf("endereco de p: %p\nendereco de q: %p\nendereco de i: %p\nendereco de j:%p\n", p, q, &i, &j);
    //printf("p = q: %p\n", p = q);
    //printf("*p = *p + *q = %d\n", *p);
    printf("conteudo do ponteiro q: %d\n", *q);
    printf("conteudo de i: %d\n", i);
}