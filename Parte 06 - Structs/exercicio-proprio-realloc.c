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

    // 1. Preencher os 3 produtos
    for (int i = 0; i < n; i++) {
        printf("Digite o nome do produto %d: \n", i + 1);
        scanf("%49s", produto[i].nome);

        printf("Digite o preço do produto %d: \n", i + 1);
        scanf("%f", &produto[i].preco);

        puts("");
    }

    puts("");

    // 2. Exibir os 3 produtos
    for (int i = 0; i < n; i++) {
        printf("Produto %d: %s\n", i + 1, produto[i].nome);
        printf("Preço produto %d: %.2f\n\n", i + 1, produto[i].preco);
    }

    // 3. Alterar n para 5
    n = 5;

    // 4. Utilizar realloc
    Produto *temp = realloc(produto, n * sizeof(*produto));

    // 5. Tratar a falha do realloc
    if (temp == NULL) {
        printf("Nao foi possivel aumentar o vetor.\n");
        free(produto);
        return 1;
    } 

    // 6. Atualizar produto se o realloc tiver sucesso
    produto = temp;

    // 7. Preencher os 2 novos produtos
    for(int i = 3; i < 5; i++) {
        printf("Digite o nome do produto %d: \n", i + 1);
        scanf("%49s", produto[i].nome);

        printf("Digite o preço do produto %d: \n", i + 1);
        scanf("%f", &produto[i].preco);

        puts("");
    }

    puts("");

    // 8. Exibir os 5 produtos
    for (int i = 0; i < n; i++) {
        printf("Produto %d: %s\n", i + 1, produto[i].nome);
        printf("Preço produto %d: %.2f\n\n", i + 1, produto[i].preco);
    }

    free(produto);
    return 0;
}