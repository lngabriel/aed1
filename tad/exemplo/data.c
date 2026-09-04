#include "data.h"
#include <stdlib.h>

struct Data {
    int dia;
    int mes;
    int ano;
};

Data* criar_data(int dia, int mes, int ano) {
    Data* d = malloc(sizeof(Data));
    if (d != NULL) {
        d->dia = dia;
        d->mes = mes;
        d->ano = ano;
    }
    return d;
}

int obter_dia(Data* d) {
    return d->dia;
}
int obter_mes(Data* d) {
    return d->mes;
}
int obter_ano(Data* d) {
    return d->ano;
}

void destruir_data(Data* d) {
    free(d);
}