#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _livro {
    char titulo[100];
    unsigned int num_paginas;
    float preco;
} Livro;

typedef struct _aluno {
    char nome[100];
    int idade;
    Livro *livro_fav; // ponteiro para outra struct de Livro
} Aluno;


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

Livro *copy_livro(const Livro *livro) {
    return create_livro(livro -> titulo, livro -> num_paginas, livro -> preco);
}


void print_livro (const Livro *livro) {
    printf("Título: %s\n", livro->titulo);
    printf("Número de páginas: %d\n", livro->num_paginas);
    printf("Preço: R$ %.2f reais\n\n", livro->preco);
}

// vamos retornar na função um ponteiro de aluno
Aluno *create_aluno(const char *nome, int idade, const Livro *livro_fav) {
    Aluno *aluno = (Aluno*) calloc(1, sizeof(Aluno));

    strcpy(aluno -> nome, nome);
    aluno -> idade = idade;
    aluno -> livro_fav = copy_livro(livro_fav);

    return aluno;
}

void desalocar_aluno(Aluno **aluno_ref) {
    Aluno *aluno = *aluno_ref;

    desalocar_livro(&aluno -> livro_fav);

    free(aluno);
    *aluno_ref = NULL;
}


void print_aluno(const Aluno *aluno) {
    printf("Nome: %s\n", aluno -> nome);
    printf("Idade: \n", aluno -> idade);
    puts("Livro favorito:");
    puts("---------------");
    print_livro(aluno -> livro_fav);
}

bool eh_o_mesmo_titulo(const Livro *livro_01, const Livro *livro_02) {
    if (strcmp(livro_01 -> titulo, livro_02 -> titulo) == 0) {
        return true;
    } else {
        return false;
    }
}


int main() {

    Livro *livro_harry = create_livro("Harry Potter 01", 200, 25);

    print_livro(livro_harry);
    livro_harry -> preco = 10;
    print_livro(livro_harry);
    
    Aluno *ted = create_aluno("Ted", 25, livro_harry);
    print_aluno(ted); 
    
    // os exemplares são iguais?
    puts("\nos examplares são iguais?");
    if (ted -> livro_fav == livro_harry) {
        puts("TRUE");
    } else {
        puts("FALSE");
    }
    puts("\n");
    
    // a obra é a mesma?
    puts("\na obra é a mesma?");
    if (eh_o_mesmo_titulo(ted->livro_fav, livro_harry)) {
        puts("TRUE");
    } else {
        puts("FALSE");
    }
    puts("\n");
    
    
    desalocar_livro(&livro_harry);
    
    print_aluno(ted); 

    desalocar_aluno(&ted);
 
    return 0;
}