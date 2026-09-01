#include <stdio.h>

int main() {
    int x = 10, *p1 = NULL, **p2 = NULL;

    p1 = &x;
    p2 = &p1;
    
    printf("%d\n", **p2);
    printf("%d\n", *p1);
}