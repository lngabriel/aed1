#include <stdio.h>

int main() {
    int v[5];
    int *p;

    //p = v; // p aponta pro endereco do primeiro elemento do vetor v
    //p = &v; // tenta apontar pro endereco do vetor inteiro, da warnings
    //p = &v[0]; // aponta para o endereco de um elemento que desejar do vetor, nesse caso o 0
    // v = p;
    // p = v + 2; // aponta pro endereco do elemento 0+2 do vetor
}