#include <stdio.h>

int main() {
    int i = 3, j = 5;
    int *p = NULL, *q = NULL;

    p = &i;
    q = &j;
    printf("Conteudo de p: %d\n", *p);
    printf("*p - *q = %d\n", *p - *q);
    printf("**&p = %d\n", **&p);
    printf(" 3 - *p / (*q) + 7 = %d\n", 3 - *p / (*q) + 7);
}