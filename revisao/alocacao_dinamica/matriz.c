#include <stdio.h>
#include <stdlib.h>

int main() {
    int **M;
    int i;
    int num_colunas = 5, num_linhas = 6;

    M = (int **)malloc(num_linhas * sizeof(int *));

    for (i = 0; i < num_linhas; i++)
        M[i] = (int *)malloc(num_colunas * sizeof(int));
    
    for (i = 0; i < num_linhas; i++)
        free(M[i]);
    
    free(M);
}