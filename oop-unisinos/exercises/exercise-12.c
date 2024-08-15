#include <stdio.h>

void printValues(int x) {
    for (int i = 1; i <= x; i++) {
        printf("%d\n", i);
    }
}

void main() {
    printValues(10);
}