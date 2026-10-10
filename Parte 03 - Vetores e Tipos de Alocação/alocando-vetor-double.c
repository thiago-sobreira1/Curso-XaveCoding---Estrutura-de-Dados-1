    #include <stdio.h>
    #include <stdlib.h> // contem o NULL, calloc, malloc, free

    double* vetorDeDouble(int n) {
        double *v = malloc(n * sizeof(double));
        if (v == NULL){
            return NULL;
        }

        return v;
    }

    int main() {
        int n = 5;
        double *vetor = NULL;

        vetor = vetorDeDouble(n);
        
        for (int i = 0; i < n; i++){
            vetor[i] = i * 10;
            printf("vetor[%d] = %.2f\n", i, vetor[i]);
        }
        
        free(vetor);
        vetor = NULL;
        
        return 0;
    }