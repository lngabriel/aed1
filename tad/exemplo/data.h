#ifndef DATA_H
#define DATA_H

typedef struct Data Data;

Data *criar_data(int dia, int mes, int ano);

int obter_dia(Data* d);
int obter_mes(Data* d);
int obter_ano(Data* d);

void destruir_data(Data* d);

#endif

