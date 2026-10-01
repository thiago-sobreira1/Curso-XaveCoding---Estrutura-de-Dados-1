#include <stdio.h>

void trocar(int *a, int *b) {
    a = b;
    b = a;
}

int main() {
    int aa = 10;
    int bb = 20;

    printf("&aa = %p, aa = %d\n", &aa, aa);
    printf("&bb = %p, bb = %d\n", &bb, bb);

    trocar(&aa, &bb);

    printf("&aa = %p, aa = %d\n", &aa, aa);
    printf("&bb = %p, bb = %d\n", &bb, bb);
}