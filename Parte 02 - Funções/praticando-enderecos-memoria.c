#include <stdio.h>

int main() {
    int a = 50;
    int *p = &a;

    // mostre o valor de a
    // mostre o endereço de a
    // mostre o valor de p
    // mostre o valor apontado por p
    
    printf("Valor de a = %d\n", a);
    printf("Endereço de a = %p\n", &a);
    printf("Valor de p = %p\n", (void*)p);
    printf("Valor apontado por p = %d\n", *p);
    
    return 0;
}
