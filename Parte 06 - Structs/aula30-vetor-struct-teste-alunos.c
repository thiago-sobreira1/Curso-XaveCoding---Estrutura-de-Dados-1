#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct _aluno {
    char nome[100];
    int idade;
    float nota;
} Aluno;

typedef struct vetor_alunos {
    Aluno **vet; // ponteiro para um vetor de ponteiros de Aluno
    int size; // quantidade de elementos
} VetorAluno;


// como se fosse um "construtor" para livros
// Recebe o número de elementos diretamente por parâmetro
VetorAluno *create_vetor(int tamanho) {
    if (tamanho <= 0) return NULL;
    
    VetorAluno *v = (VetorAluno *) malloc(sizeof(VetorAluno));
    if (v == NULL) return NULL;

    v -> size = tamanho;
        v -> vet = (Aluno **) malloc(tamanho * sizeof(Aluno *));

    if (v -> vet == NULL) {
        free(v);
        return NULL;
    }
    
    for (int i = 0; i < tamanho; i++) {
        v -> vet[i] = (Aluno *) malloc(sizeof(Aluno));
    }

    return v;
}

void desalocar_aluno(VetorAluno *v) {
    if (v == NULL) return;

    for (int i = 0; i < v -> size; i++) {
        free(v -> vet[i]);
    }
    free(v -> vet);
    free(v);    
}


int main() {

    VetorAluno *turma = create_vetor(3);

    if (turma == NULL) {
        printf("Erro ao criar vetor!\n");
        return 1;
    }

    strcpy(turma -> vet[0] -> nome, "James");
    turma -> vet[0] -> idade = 26;
    turma -> vet[0] -> nota = 9.0;
    
    strcpy(turma -> vet[1] -> nome, "Agatha");
    turma -> vet[1] -> idade = 24;
    turma -> vet[1] -> nota = 9.5;
    
    strcpy(turma -> vet[2] -> nome, "Donias");
    turma -> vet[2] -> idade = 22;
    turma -> vet[2] -> nota = 5.0;

    desalocar_aluno(turma);
     
    return 0;
}