    #include <stdio.h>
    #include <stdlib.h> // contem o NULL, calloc, malloc, free

    int main() {
        int *p;

        p = (int*) malloc(sizeof(int));

        printf("&p = %p, p = %d\n", (void*)p, *p);

        *p = 42;

        printf("&p = %p, p = %d\n", (void*)p, *p);

        free(p);
        p = NULL;
        
        return 0;
    }