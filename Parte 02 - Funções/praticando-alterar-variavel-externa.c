#include <stdio.h>

void aumentar(int a, int b, int *z) {
    *z = a + b;
}


int main() {
    int a = 10;
    int b = 20;
    int c = 0;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    aumentar(a, b, &c);

    printf("\na = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);

    return 0;
}