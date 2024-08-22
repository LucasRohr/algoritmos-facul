#include <stdio.h>

float maior_valor(int value1, int value2, int value3) {
    if (value1 > value2 && value1 > value3) {
        return value1;
    } else if (value2 > value1 && value2 > value3) {
        return value2;
    }

    return value3;
}

int main() {
    int result = maior_valor(4, 8, 1);

    printf("%d", result);
}