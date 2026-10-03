#include <stdio.h>

void trocar (int *z, int *h) {
    int temp = *z;
    *z = *h;
    *h = temp;
}


int main() {
    int a = 10;
    int b = 20;

    printf("ANTES DE CHAMAR A FUNÇÃO\n");
    printf("a = %d, &a = %p\n", a, &a);
    printf("b = %d, &b = %p\n", b, &b);

    trocar(&a, &b);

    printf("\nDEPOIS DE CHAMAR A FUNÇÃO\n");
    printf("a = %d, &a = %p\n", a, &a);
    printf("b = %d, &b = %p\n", b, &b);
    
    return 0;
}
