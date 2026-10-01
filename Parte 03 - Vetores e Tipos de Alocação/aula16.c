    #include <stdio.h>
    #include <stdlib.h> // contem o NULL, calloc, malloc, free

    int main() {
        puts("### Vetor Estático ###");
        // alocação de um vetor estático (memória STACK)
        int vs[5] = {0, 10, 20, 30, 40};
        printf("&vs = %p, vs = %p\n", &vs, vs);
        
        for (int i = 0; i < 5; i++) {
            printf("&VS[%d] = %p, vs[%d] = %d\n", i, &vs[i], i, vs[i]);
        }
        puts("\n");
        

        puts("### Vetor Dinâmico ###");
        // alocação de um vetor dinâmico usando malloc (memória HEAP)

        int *vh_mal = (int *) malloc(5 * sizeof(int)); // todos os elementos possuem lixo de memória
        printf("&vh_mal = %p, vh_mal = %p\n", &vh_mal, vh_mal);

        for (int i = 0; i < 5; i++) {
            printf("&vh_mal[%d] = %p, vh_mal[%d] = %d\n", i, &vh_mal[i], i, vh_mal[i]);
        }
        puts("\n");


        // alocação de um vetor dinâmico usando calloc (memória HEAP)
        // todo bloco alocado possue bits 0 (zero)
        // isto é, garante que todos os elementos alocados terão valor 0 (zero)
        int *vh_cal = (int *) calloc(5, sizeof(int));
        printf("&vh_cal = %p, vh_cal = %p\n", &vh_cal, vh_cal);

        for (int i = 0; i < 5; i++) {
            printf("&vh_cal[%d] = %p, vh_cal[%d] = %d\n", i, &vh_cal[i], i, vh_cal[i]);
        }
        puts("\n");

        // NÃO ESTAMOS DESALOCANDO OS VETORES DINÂMICOS


        
        return 0;
    }


