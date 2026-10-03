#include <stdio.h>

void calcular(int numero, int *dobro, int *triplo) {
    *dobro = numero * 2;
    *triplo = numero *3;
}


int main() {
    int numero = 10;
    int dobro = 0;
    int triplo = 0;

    printf("numero = %d\n", numero);
    printf("dobro = %d\n", dobro);
    printf("triplo = %d\n", triplo);

    calcular(numero, &dobro, &triplo);

    printf("numero = %d\n", numero);
    printf("dobro = %d\n", dobro);
    printf("triplo = %d\n", triplo);

    return 0;
}