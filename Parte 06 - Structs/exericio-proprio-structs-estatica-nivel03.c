#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct produto {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

void cadastrarProduto (Produto *produtos, int *totalProdutos) {
    Produto *novoProduto = produtos;

    int indice = *totalProdutos;

    if (indice < 5) {
        printf("------------ 1 - Cadastrar produto ------------ \n");
        printf("Digite o nome do produto: \n");
        scanf("%49s", novoProduto[indice].nome);

        printf("Digite o preço: \n");
        scanf("%f", &novoProduto[indice].preco);

        printf("Digite a quantidade: \n");
        scanf("%d", &novoProduto[indice].quantidade);
    }    
}

void listarProdutos(Produto *produtos, int totalProdutos) {
    printf("------------ 2 - Listar produtos ------------ \n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("Produto %d: %s\n", i + 1, produtos[i].nome);
        printf("Quantidade: %d\n", produtos[i].quantidade);
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
    int achouProduto;

    printf("------------ 3 - Buscar produtos ------------ \n");
    
    printf("Digite o nome do produto a ser localizado: ");
    scanf("%s49", nomeProduto);

    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(produtos[i].nome, nomeProduto) == 0) {
            printf("Produto encontrado!\n");
            printf("%s\n", produtos[i].nome);
            achouProduto = 1;
        }
    }

    if (achouProduto == 0) {
        printf("Produto não encontrado!\n");
    }
    
}

void atulizarQuantidade(Produto *produtos, int totalProdutos) {
    // exibir todos os produtos cadastrados (até o momento)
    // usuário escolher o produto que quer atualizar somente o ESTOQUE
    // receber o vetor como parametro
    // mudar a quantidade exatamente do produto escolhido 

    int opcaoEscolhida;
    int novaQuantidade;

    printf("------------ 4 - Atualizar quantidade ------------ \n");

    for (int i = 0; i < totalProdutos; i++) {
        printf("Produto %d: %s\n", i + 1, produtos[i].nome);
    } 

    printf("Escolha o produto que deseja atualizar o estoque: \n");
    scanf("%d", &opcaoEscolhida);
    
    if (opcaoEscolhida > 0 && opcaoEscolhida <= totalProdutos) {
        printf("Digite a nova quantidade do produto: \n");
        scanf("%d", &novaQuantidade);
    } else {
        printf("Número inválido, tente novamente!\n");
    }

    produtos[opcaoEscolhida - 1].quantidade = novaQuantidade;
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

    int opção;

    do {
        printf("\n===== SISTEMA DE ESTOQUE =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Buscar produto\n");
        printf("4 - Atualizar quantidade\n");
        printf("5 - Valor total do estoque\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: \n");
        scanf("%d", &opção);

        switch(opção) {
            case 1: 
                if (totalProdutos < 5) {
                    cadastrarProduto(produtos, &totalProdutos);
                    totalProdutos++;
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
                    atulizarQuantidade(produtos, totalProdutos);
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
    } while (opção != 0); 
    
    return 0;
}