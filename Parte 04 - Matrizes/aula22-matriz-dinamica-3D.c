    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int n_slice = 2;
        int n_rows = 2;
        int n_cols = 3;

        /***************** ALOCAÇÃO DINÂMICA DE MATRIZES ****************** */


        int ***m = (int***) calloc(n_slice, sizeof(int**));

        // para cada fatia (alocação)
        for (int k = 0; k < n_slice; k++) {
            m[k] = (int **) calloc(n_rows, sizeof(int*));

            // para cada linha (alocação)
            for(int i = 0; i < n_rows; i++) {
                m[k][i] = (int*) calloc(n_cols, sizeof(int));
            }
        }
        
        /****************************************************************** */

        int count = 0;

        printf("&m = %p, m = %p\n\n", &m, m);

        // para cada fatia (imprimindo)
        for (int k = 0; k < n_slice; k++) {
            printf("&m[%d] = %p, m[%d] = %p\n", k, &m[k], k, m[k]);

            // para cada linha (imprimindo)
            for (int i = 0; i < n_rows; i++) {
                printf("&m[%d][%d] = %p, m[%d][%d] = %p\n", 
                        k, i, &m[k][i], k, i, m[k][i]);
                
                // para cada coluna (colocando valores)
                for (int j = 0; j < n_cols; j++) {
                    m[k][i][j] = count++;

                    printf("&m[%d][%d][%d] = %p, m[%d][%d][%d] = %d\n",
                            k, i, j, &m[k][i][j],
                            k, i, j, m[k][i][j]);
                }
                puts("");
            }
            puts("");
        }

        // Falta desalocar matriz 3D dinâmica, veremos depois
        
        
        return 0;
    }


