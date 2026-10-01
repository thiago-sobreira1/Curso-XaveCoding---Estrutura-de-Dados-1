#include <stdio.h>

void dobrarValor(int *v, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        v[i] = v[i] * 2;
    }
}

int main() {
    int numeros[5] = {1, 2, 3 , 4, 5};

    for (int i = 0; i < 5; i++) {
        printf("%d \n", numeros[i]);   
    } 

    dobrarValor(numeros, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d \n", numeros[i]);
    }

    return 0;

}