#include <stdio.h> 
#include <stdlib.h> // contem o NULL, calloc, malloc, free

void preencherVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite número %d:\n", i + 1);
        scanf("%d", &vetor[i]);
    }
    
}

void mostrarValor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Número %d: %d\n", i + 1, vetor[i]);
    }
    
}

int main() {
    int tamanho; 
    
    printf("Quantos número(s) você quer alocar?\n"); 
    scanf("%d", &tamanho); 
    
    int *vetor; 
    vetor = malloc(tamanho * sizeof(int));

    preencherVetor(vetor, tamanho);

    mostrarValor(vetor, tamanho);

    free(vetor);
    vetor = NULL; 
    
    return 0;
}