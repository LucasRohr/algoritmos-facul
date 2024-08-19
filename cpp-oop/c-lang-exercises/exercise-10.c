#include <stdio.h>

int main() {
    int value;
    int factorial = 1;

    printf("Digite o valor:\n");
    scanf("%d", &value);

    if (value < 0) {
        printf("Erro: Valor negativo");

        return 0;
    }

    for (int i = 1; i <= value; i++) {
        factorial *= i;
    }

    printf("Fatorial: %d\n", factorial);

    return 0;
}