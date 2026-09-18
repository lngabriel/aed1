#include <stdio.h>
#include <stdlib.h>

int *concatenar(int *v1, int n1, int *v2, int n2, int *n3);

int main() {
    int n1 = 3, n2 = 2, n3;
    int *v1 = NULL, *v2 = NULL;

    v1 = (int *)malloc(n1 * sizeof(int));
    v1[0] = 10;
    v1[1] = 20;
    v1[2] = 30;

    v2 = (int *)malloc(n2 * sizeof(int));
    v2[0] = 40;
    v2[1] = 50;

    int *v3 = concatenar(v1, n1, v2, n2, &n3);

    for (int i = 0; i < n3; i++) {
        printf("%d ", v3[i]);
    }

    printf("\n");
}

int *concatenar(int *v1, int n1, int *v2, int n2, int *n3) {
    *n3 = n1 + n2;
    int *v3 = (int *)malloc((*n3) * sizeof(int));
    if (n3 == NULL) exit(1);
    int i;
    for (i = 0; i < n1; i++) {
        v3[i] = v1[i];
    }
    for (i = 0; i < n2; i++) {
        v3[n1 + i] = v2[i]; 
    }
    return v3;
}