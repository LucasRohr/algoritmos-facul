#include <stdio.h>

void main() {
    int value1;
    int value2;
    int value3;
    int value4;
    int value5;

    int sum = 0;
    int product = 1;

    printf("Digite o valor 1:\n");
    scanf("%d", &value1);

    printf("Digite o valor 2:\n");
    scanf("%d", &value2);

    printf("Digite o valor 3:\n");
    scanf("%d", &value3);

    printf("Digite o valor 4:\n");
    scanf("%d", &value4);

    printf("Digite o valor 5:\n");
    scanf("%d", &value5);

    sum = value1 + value2 + value3 + value4 + value5;
    product = value1 * value2 * value3 * value4 * value5;

    printf("\nSoma: %d\n", sum);
    printf("\nProduto: %d\n", product);
}