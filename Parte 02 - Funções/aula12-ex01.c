#include <stdio.h>

void troca(int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
}

int main() {
    int a = 10;
    int b = 20;

    puts("### ANTES DE CHAMAR A FUNCAO");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n\n", &b, b);

    troca(&a, &b);

    puts("### DEPOIS DE CHAMAR A FUNCAO");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);

    return 0;
}