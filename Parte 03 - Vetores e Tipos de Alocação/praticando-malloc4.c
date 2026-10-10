#include <stdio.h>
#include <stdlib.h>

int* criaVetor(int n) {
    int *vetor = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        vetor[i] = i * i;
    }
    return vetor;
}

void imprimeVetor(int *vetor, int n) {
    for(int i = 0; i < n; i++) {
        printf("Vetor[%d] = %d\n", i, vetor[i]);
    }

}

void liberarVetor(int **vetor) {
    free(*vetor);
    *vetor = NULL;
}

int main(void) {
    int n;

    int *vetor = NULL;

    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &n);

    vetor = criaVetor(n);

    if (vetor == NULL) {
        printf("Erro, não foi possível alocar memória!\n");
        return 1;
    }

    imprimeVetor(vetor, n);

    liberarVetor(&vetor);

    return 0;
}

