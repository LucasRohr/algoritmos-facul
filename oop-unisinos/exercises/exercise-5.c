#include <stdio.h>

#define BASE_TAX 1.1
#define MEDIUM_TAX 1.2
#define HIGH_TAX 1.5

int main() {
    int value;
    float taxedValue;

    printf("Digite o valor:\n");
    scanf("%d", &value);

    if (value < 0) {
        printf("Erro: Valor negativo");

        return 0;
    }

    if (value < 100) {
        taxedValue = value * BASE_TAX;
    } else if (value >= 100 && value < 300) {
        taxedValue = value * MEDIUM_TAX;
    } else if (value >= 300 && value < 1000) {
        taxedValue = value * HIGH_TAX;
    } else {
        taxedValue = value;
    }

    printf("Valor com taxa: %.2f", taxedValue);

    return 0;
}