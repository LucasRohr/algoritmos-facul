#include <stdio.h>
#include <math.h>

#define TAMANHO_LISTA 50
#define TAMANHO_ITERACOES_SOMA 25

int main() {
    int lista_valores [TAMANHO_LISTA];

    int soma_valores = 0;
    int i; // Iterador do for

    for(i = 0; i < TAMANHO_LISTA; i++) {
        printf("Digite o valor %d:\n", i + 1);
        scanf("%d", &lista_valores[i]);
    }

    for(i = 0; i < TAMANHO_ITERACOES_SOMA; i++) {
        // Soma ao total atual o quadrado da diferenca do valor atual com
        // o valor da ultima posicao - indice atual
        soma_valores += pow(lista_valores[i] - lista_valores[TAMANHO_LISTA - i - 1], 2);
    }

    printf("\n\nA soma dos valores calculados conforme a fórmula S é: %d", soma_valores);

    return 0;
}