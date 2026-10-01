    #include <stdio.h>
    #include <stdlib.h> // contem o NULL, calloc, malloc, free

    double* aloca_vetor(int n) {
        double *v = (double*) malloc(n * sizeof(double));
        return v;
    }

    int main() {
        int n = 5;
        double *vetor = aloca_vetor(n);

        if (vetor == NULL) {
            printf("Erro ao alocar memória!\n");
            return 1;
        }

        for (int i = 0; i < n; i++) {
            vetor[i] = i * 1.5;
            printf("vetor[%d] = %.2f, &vetor[%d] = %p\n", i, vetor[i], i, &vetor[i]);
        }
        
        free(vetor);
        vetor = NULL;
        
        return 0;
    }