#include <stdio.h>

void soma_e_sub(int x, int y, int *sub) {
    int soma = x + y;
    *sub = x - y;

    puts("===> FUNÇÃO");
    printf("&x = %p, x = %d\n", &x, x);
    printf("&y = %p, y = %d\n", &y, y);
    printf("&sub = %p, z = %d\n\n", &sub, sub);
}


int main() {
    int a = 10;
    int b = 20;
    int c;
    int d;

    puts("### ANTES DE CHAMAR A FUNÇÃO");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&d = %p, d = %d\n\n", &d, d);

    soma_e_sub(a, b, &d);

    puts("### DEPOIS DE CHAMAR A FUNÇÃO");
    printf("&a = %p, a = %d\n", &a, a);
    printf("&b = %p, b = %d\n", &b, b);
    printf("&d = %p, d = %d\n\n", &d, d);

    return 0;
}