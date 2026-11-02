#include <stdio.h>
#include <stdlib.h>


int **create_int_matrix(size_t n_rows, size_t n_cols) {
    int **m = (int **) calloc(n_rows, sizeof(int*));

    // para cada linha (alocação)
    for(int i = 0; i < n_rows; i++) {
        // para cada coluna
        m[i] = (int *) calloc(n_cols, sizeof(int));
    }

    return m;
}

void print_int_matrix (const int **m, int nrows, int ncols) {
    printf("&m = %p, m = %p\n\n", &m, m);

    for (int i = 0; i < nrows; i++) {
        printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);

        for (int j = 0; j < ncols; j++) {
            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n",
                        i, j, &m[i][j],
                        i, j, m[i][j]);
        }
        puts("");
    }
}

void add_scalar_into_int_matrix (int **m, int nrows, int ncols, int scalar) {
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            m[i][j] += scalar;
        }
        
    }
    
}

void destroy_int_matrix(int ***mat, int nrows, int ncols) {
    int **aux = *mat;


    for(int i = 0; i < nrows; i++) {
            free(aux[i]);
        }
        free(aux);
        *mat = NULL ;
}


// arg (argumento) + c (contador) / v (valor) / * (vetor)
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("ERROR!\n%s nrows ncols scalar\n", argv[0]);
        exit(-1);
    }

    puts("PASSEI!");

    int nrows = atoi(argv[1]);
    int ncols = atoi(argv[2]);
    int scalar = atoi(argv[3]);
    
    printf("nrows = %d, ncols = %d\n\n", nrows, ncols);

    // Alocação da matriz

    int **m = create_int_matrix(nrows, ncols);

    // Atribuição de valores para a matriz
    int count = 0;

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            m[i][j] = count++;
        }
        
    }

    // Imprimindo matriz
    print_int_matrix((const int**) m, nrows, ncols);

    // adiciona scalar

    add_scalar_into_int_matrix(m, nrows, ncols, scalar);
    print_int_matrix((const int**) m, nrows, ncols);

    // desalocar matriz
    destroy_int_matrix(&m, nrows, ncols);
    printf("\nm is NULL? %d\n", m == NULL);


    return 0;
}


