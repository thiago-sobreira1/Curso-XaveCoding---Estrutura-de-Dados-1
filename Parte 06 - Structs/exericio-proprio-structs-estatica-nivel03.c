#include <stdio.h>
#include <string.h>

typedef struct produto {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

void cadastrarProduto (Produto *produtos, int *totalProdutos) {
    float validarPreco;
    int validarEstoque;

    printf("------------ 1 - Cadastrar produto ------------ \n");
    printf("Digite o nome do produto: \n");
    scanf("%49s", produtos[*totalProdutos].nome);

    printf("Digite o preço: \n");
    scanf("%f", &validarPreco);

    while (validarPreco <= 0) {
        printf("Digite um valor válido!\n");
        scanf("%f", &validarPreco);
    }
    
    produtos[*totalProdutos].preco = validarPreco;
    /* if redudante
    if (validarPreco > 0) {
        produtos[*totalProdutos].preco = validarPreco;
    }
    */

    printf("Digite a quantidade: \n");
    scanf("%d", &validarEstoque);

    while (validarEstoque < 0){
        printf("Digite uma quantidade válida: \n");
        scanf("%d", &validarEstoque);
    }

    produtos[*totalProdutos].quantidade = validarEstoque;
    /* if redudante
    if (validarEstoque >= 0) {
        produtos[*totalProdutos].quantidade = validarEstoque;
    }
    */

    // maneiras diferentes de incrementar: 
    // 1 -  (*totalProdutos)++; 
    //(os parênteses forçam a desreferência antes da soma)
    
    // 2 - *totalProdutos += 1;
    // (mais legível e sem risco de erro de precedência)
    
    *totalProdutos = *totalProdutos + 1; 
    // (explícito e seguro)
    
}

void listarProdutos(Produto *produtos, int totalProdutos) {
    printf("------------ 2 - Listar produtos ------------ \n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Produto %d: %s\n", i + 1, produtos[i].nome);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Preço: %.2f\n\n", produtos[i].preco);
    }
}

void buscarProduto (Produto *produtos, int totalProdutos) {
    // receber o parametro nome do usuário
    // percorre o vetor com for
    // em cada posição comparamos as strings
    // se achar a combinação nós exibimos
    // se não encontramos colocamos um aviso de não encontrado

    // strcmp: 0 (são iguais), menor que 0 (), maior que 0 ()

    char nomeProduto[50];
    int achouProduto = 0;
    int indice;

    printf("------------ 3 - Buscar produtos ------------ \n");
    
    printf("Digite o nome do produto a ser localizado: ");
    scanf("%49s", nomeProduto);

    /*
    while (achouProduto == 0) {
        
    }
    */

    do
    {
        for (int i = 0; i < totalProdutos; i++) {
            if (strcmp(produtos[i].nome, nomeProduto) == 0) {
                /* printf("Produto encontrado:\n");
                printf("%s\n", produtos[i].nome);
                printf("%d\n", produtos[i].quantidade);
                printf("%.2f\n", produtos[i].preco); */ 
                achouProduto = 1;
                indice = i;
            }
        }
        if (achouProduto == 0) {
            printf("Produto não encontrado!\n");
            printf("Tente novamente!\n\n");
            scanf("%49s", nomeProduto);
        }
    } while (achouProduto == 0);

    printf("%s\n", produtos[i].nome);
    printf("%d\n", produtos[i].quantidade);
    printf("%.2f\n", produtos[i].preco);
    
    /*
    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(produtos[i].nome, nomeProduto) == 0) {
            printf("Produto encontrado!\n");
            printf("%s\n", produtos[i].nome);
            printf("%d\n", produtos[i].quantidade);
            printf("%.2f\n", produtos[i].preco);
            achouProduto = 1;
        }
    }
    /*

    /*
    if (achouProduto == 0) {
        printf("Produto não encontrado!\n");
    }
    */
}

void atualizarQuantidade(Produto *produtos, int totalProdutos) {
    int opcaoEscolhida;
    int novaQuantidade;

    printf("------------ 4 - Atualizar quantidade ------------ \n");

    for (int i = 0; i < totalProdutos; i++) {
        printf("Produto %d: %s\n", i + 1, produtos[i].nome);
    } 

    printf("Escolha o produto que deseja atualizar o estoque: \n");
    scanf("%d", &opcaoEscolhida);

    while (opcaoEscolhida <= 0 || opcaoEscolhida > totalProdutos) {
        printf("Digite um produto existente! \n");
        scanf("%d", &opcaoEscolhida);
    }
    
    printf("Digite a nova quantidade do produto: \n");
    scanf("%d", &novaQuantidade);

    while (novaQuantidade < 0) {
        printf("Digite a nova quantidade válida: \n");
        scanf("%d", &novaQuantidade);
    }

    produtos[opcaoEscolhida - 1].quantidade = novaQuantidade;
    /* if redudante
    if (opcaoEscolhida > 0 && opcaoEscolhida <= totalProdutos) {    
        produtos[opcaoEscolhida - 1].quantidade = novaQuantidade;
    }
    */
}
    
void valorTotalEstoque (Produto *produtos, int totalProdutos) {

    printf("------------ 5 - Valor total do estoque ------------ \n");

    float valorAtual = 0;

    for (int i = 0; i < totalProdutos; i++) {
        valorAtual += produtos[i].preco * produtos[i].quantidade;
    }

    printf("Valor total do estoque: R$ %.2f\n", valorAtual);

}

int main() {

    Produto produtos[5];

    int totalProdutos = 0;

    int opcao;

    do {
        printf("\n===== SISTEMA DE ESTOQUE =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto\n");
        printf("4 - Atualizar quantidade\n");
        printf("5 - Valor total do estoque\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: \n");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: 
                if (totalProdutos < 5) {
                    cadastrarProduto(produtos, &totalProdutos);
                } else {
                    printf("Número de cadastros de produtos chegou ao máximo!\n");
                }
                break;
            case 2: 
                if (totalProdutos > 0) {
                    listarProdutos(produtos, totalProdutos);
                } else {
                    printf("\nCadastre o primeiro produto!\n");
                }
                break;
            case 3: 
                buscarProduto(produtos, totalProdutos);
                break;
            case 4: 
                if (totalProdutos > 0) {
                    atualizarQuantidade(produtos, totalProdutos);
                } else {
                    printf("Ainda não existe produto cadastrado!\n");
                }
                break;
            case 5: 
                if (totalProdutos > 0) {
                    valorTotalEstoque(produtos, totalProdutos);
                }
                
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0); 
    
    return 0;
}