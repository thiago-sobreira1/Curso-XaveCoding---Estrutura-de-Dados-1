#include <stdio.h>

void dobrar(int *x) {
    *x = *x * 2;
}

int main() {
    int a = 10;
    dobrar(&a); 
}