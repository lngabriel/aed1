#include <stdio.h>

void passagem_por_valor(int x, int y);
void passagem_por_referencia(int *x, int *y);

int main() {
    int x = 10, y = 20;

    passagem_por_valor(x, y);
    passagem_por_referencia(&x, &y);
}

void passagem_por_valor(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void passagem_por_referencia(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}