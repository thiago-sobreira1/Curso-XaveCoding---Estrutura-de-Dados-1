#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _aluno {
    char nome[100];
    int idade;
    float nota;
} Aluno;

// como se fosse um "construtor" para livros
Aluno* create_aluno(const char *nome, int idade, float nota) {
    Aluno *aluno = (Aluno*) calloc(1, sizeof(Aluno));

    strcpy(aluno -> nome, nome);
    aluno -> idade = idade;
    aluno -> nota = nota;

    return aluno;
}

void printf_aluno(const Aluno *aluno) {
    printf("Nome: %s\n", aluno -> nome);
    printf("Idade: %d\n", aluno -> idade);
    printf("Nota: %.2f\n\n", aluno -> nota);
}

void desalocar(Aluno **aluno_ref) {
    Aluno *aluno = *aluno_ref;
    free(aluno);
    *aluno_ref = NULL;
};


int main() {

    Aluno **vet = (Aluno**) calloc(3, sizeof(Aluno));

    vet[0] = create_aluno("James", 26, 9.8);
    vet[1] = create_aluno("Agatha", 24, 9.9);
    vet[2] = create_aluno("Daniel", 22, 6.5);

    for (int i = 0; i < 3; i++) {
        printf_aluno(vet[i]);
    }
    
    for (int i = 0; i < 3; i++) {
        desalocar(&vet[i]);
    }
    
    free(vet);
    vet = NULL;

    return 0;
}