#include <stdio.h>

void main() {
    int val1;
    int val2;
    int oddSum = 0;
    int evenSum = 0;

    printf("Digite o valor 1:\n");
    scanf("%d", &val1);

    printf("Digite o valor 2:\n");
    scanf("%d", &val2);

    for (int i = val1; i <= val2; i++) {
        if (i % 2 == 0) {
            evenSum += i;
        } else {
            oddSum += i;
        }
    }

    printf("Soma dos pares: %d\n", evenSum);
    printf("\nSoma dos impares: %d\n", oddSum);
}