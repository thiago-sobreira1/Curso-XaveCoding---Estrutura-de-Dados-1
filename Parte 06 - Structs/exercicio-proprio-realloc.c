#include <stdio.h>
#include <stdlib.h>

typedef struct _produto {
    char nome[50];
    float preco;
} Produto;

int main() {
    int n = 3;

    Produto *produto = malloc(n * sizeof(*produto));

    if (produto == NULL) {
        printf("Falha na alocacao!\n");
        return 1;
    }

    n = 5;

    Produto *temp = realloc(produto, n * sizeof(*produto));
    if(temp == NULL) {
        free(produto);
        return 1;
    }

    produto = temp;

    free(produto);
    return 0;
}