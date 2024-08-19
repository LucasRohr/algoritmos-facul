#include <stdio.h>

void main() {
    int num, i, resultado = 0;
 
    printf("Digite um numero: ");
    scanf("%d", &num);
 
    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            resultado++;
            break;
        }
    }
 
    if (resultado == 0) {
        printf("O numero eh primo\n");
    } else {
        printf("O numero nao eh primo\n");
    }
}