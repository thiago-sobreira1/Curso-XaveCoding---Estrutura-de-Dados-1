#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _livro {
    char titulo[100];
    unsigned int num_paginas;
    float preco;
} Livro;

typedef struct _vetor_livros {
    Livro **vet; // nosso vetor
    int size; // número de elementos
} VetorLivro;


// como se fosse um "construtor" para livros
Livro *create_livro(const char *titulo, unsigned int num_paginas, float preco) {
    // declaração de livro com o tipo de dado Livro 
    Livro *livro = (Livro*) calloc(1, sizeof(Livro));

    strcpy(livro -> titulo, titulo);
    livro -> num_paginas = num_paginas;
    livro -> preco = preco;

    return livro;
}

void desalocar_livro(Livro **livro_ref) {
    Livro *livro = *livro_ref;
    free(livro);
    *livro_ref = NULL;
}


void print_livro (const Livro *livro) {
    printf("Título: %s\n", livro->titulo);
    printf("Número de páginas: %d\n", livro->num_paginas);
    printf("Preço: R$ %.2f reais\n\n", livro->preco);
}


int main() {

    Livro **vet = (Livro **) calloc(3, sizeof(Livro));
    vet[0] = create_livro("Harry Potter 01", 200, 25);
    vet[1] = create_livro("A Batalha do Apocalipse", 600, 40);
    vet[2] = create_livro("O Senhor dos Anéis", 500, 15);

    for (int i = 0; i < 3; i++) {
        print_livro(vet[i]);
    }
    
    //desalocar
    for (int i = 0; i < 3; i++) {
        desalocar_livro(&vet[i]);
    }
    free(vet);
    vet = NULL;
     
    return 0;
}