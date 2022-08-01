#include <stdio.h>

#define TAMANHO_PRODUTOS_VENDIDOS 50
#define TAMANHO_LOJAS 4
#define ESTOQUE_MINIMO_RELATORIO 10

int main() {
    int estoque [TAMANHO_PRODUTOS_VENDIDOS][TAMANHO_LOJAS];
    int estoque_total [TAMANHO_PRODUTOS_VENDIDOS] = {0};

    int i, j; // Iteradores da matriz de estoque

    for(i = 0; i < TAMANHO_PRODUTOS_VENDIDOS; i++) {
        for(j = 0; j < TAMANHO_LOJAS; j++) {
            printf("Digite o estoque do produto %d na loja %d:\n", i + 1, j + 1);
            scanf("%d", &estoque[i][j]);
        }
    }

    for(i = 0; i < TAMANHO_PRODUTOS_VENDIDOS; i++) {
        for(j = 0; j < TAMANHO_LOJAS; j++) {
            // soma ao estoque total do produto de i todos os estoques do produto
            // para todas as lojas de j
            estoque_total[i] += estoque[i][j];
        }
    }

    for(i = 0; i < TAMANHO_PRODUTOS_VENDIDOS; i++) {
        for(j = 0; j < TAMANHO_LOJAS; j++) {
            if(estoque[i][j] < ESTOQUE_MINIMO_RELATORIO) {
                printf("O produto de codigo %d possui menos de %d unidades na loja %d", i + 1, ESTOQUE_MINIMO_RELATORIO, j + 1);
            }
        }
    }

    return 0;
}
