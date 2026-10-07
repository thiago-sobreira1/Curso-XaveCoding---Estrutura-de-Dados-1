    #include <stdio.h>
    #include <stdlib.h> // contem o NULL, calloc, malloc, free
 
    int main() {
        int tamanho;

        printf("Quantos número(s) você quer alocar?\n");
        scanf("%d", &tamanho);

        int *vetor;
        vetor = malloc(tamanho * sizeof(int));

        for (int i = 0; i < tamanho; i++) {
            printf("Digite o número %d\n", i);
            scanf("%d\n", vetor[i]);
        }

        for (int i = 0; i < tamanho; i++) {
            printf("Número: %d\n", i);
        }

        free(vetor);
        vetor = NULL;

        
        return 0;
    }