#include <stdio.h>

void main() {
    int value;

    printf("Digite o valor:\n");
    scanf("%d", &value);

    if (value % 2 == 0) {
        printf("Valor par");
    } else {
        printf("Valor impar");
    }
}