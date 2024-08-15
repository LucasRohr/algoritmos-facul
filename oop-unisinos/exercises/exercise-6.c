#include <stdio.h>

void main() {
    int qtde;
    int inputValue;

    printf("Digite a quantidade:\n");
    scanf("%d", &qtde);

    for (int i = 0; i < qtde; i++) {
        printf("\nDigite um numero:\n");
        scanf("%d", &inputValue);

        if (inputValue > 0) {
            printf("\nPositivo");
        } else if (inputValue < 0) {
            printf("\nNegativo");
        } else {
            printf("\nZero :)");
        }
    }
}