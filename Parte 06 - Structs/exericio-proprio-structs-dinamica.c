#include <stdio.h>
#include <stdlib.h>

typedef struct _produto {
    char nome[50];
    float preco;
} Produto;

int main() {
    int n = 3;
    Produto *produto = (Produto*) malloc(n * sizeof(Produto));

    if (produto == NULL) {
        printf("Falha na alocacao de memoria!\n");
        return 1;
    }

    printf("--- RESULTADO ---");
    for(int i = 0; i < n; i++) {
        printf("Digite o nome do produto %d: \n", i + 1);
        scanf("%49s", produto[i].nome);

        printf("Digite o preco do produto %d: \n", i + 1);
        scanf("%f", &(produto + i)->preco);
    }

    for (int i = 0; i < n; i++) {
        printf("Produto %d: %s\n", i + 1, produto[i].nome);

        printf("Preço %d: %f\n", i + 1, produto[i].preco);
    }

    free(produto);
    produto = NULL;

    return 0;
}