#include <stdio.h>
#include "data.h"

int main() {
    Data* d;
    d = criar_data(4, 9, 2026);
    printf("%d/%d/%d\n", obter_dia(d), obter_mes(d), obter_ano(d));
    destruir_data(d);
}