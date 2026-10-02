#include <stdio.h>

int main() {
    // p++ aponta para o proximo elemento
    // p-- aponta pro elemento anterior
    // int *p = 2000; // 4 bytes
    // p++; // p = 2004

    int vet[] = {2000, 3000, 4000};
    int *p = vet; // aponta pro endereco do primeiro elemento do array

    printf("%d\n", *p); // 2000

    p++;

    printf("%d\n", *p); // 3000
}