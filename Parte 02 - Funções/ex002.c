#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int valorA = 10;
    int valorB = 20;

    printf("&valorA = %p, valorA = %d\n", &valorA, valorA);
    printf("&valorB = %p, valorB = %d\n", &valorB, valorB);

    trocar(&valorA, &valorB);

    printf("&valorA = %p, valorA = %d\n", &valorA, valorA);
    printf("&valorB = %p, valorB = %d\n", &valorB, valorB);

    return 0;
}