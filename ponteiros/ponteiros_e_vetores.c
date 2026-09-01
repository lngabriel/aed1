#include <stdio.h>

int main() {
    int v[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *p = NULL, *q = NULL;
    p = &v[2]; // 30
    q = p + 3; // 30 + 3 passos no vetor = 60
    p += 6; // 30 + 6 passos no vetores = 90
}