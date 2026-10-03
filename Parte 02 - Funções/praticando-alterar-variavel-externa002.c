#include <stdio.h>

void aumentar(int *a) {
    *a = 100;
}


int main() {
    int numero = 50;

    printf("numero = %d\n", numero);

    aumentar(&numero);

    printf("numero = %d\n", numero);

    return 0;
}