#include <stdio.h>

#define TAMANHO_PRODUTOS_VENDIDOS 50
#define TAMANHO_LOJAS 4

int main() {
    int estoque [TAMANHO_PRODUTOS_VENDIDOS][TAMANHO_LOJAS];
    int estoque_total [TAMANHO_PRODUTOS_VENDIDOS] = {0};
    int codigos_estoques_inferiores [TAMANHO_PRODUTOS_VENDIDOS];

    int i, j;

    for(i = 0; i < TAMANHO_PRODUTOS_VENDIDOS; i++) {
        for(j = 0; j < TAMANHO_LOJAS; j++) {
            printf("Digite o estoque do produto %d na loja %d:\n", i + 1, j + 1);
            scanf("%d", &estoque[i][j]);
        }
    }

    for(i = 0; i < TAMANHO_PRODUTOS_VENDIDOS; i++) {
        for(j = 0; j < TAMANHO_LOJAS; j++) {
            estoque_total[i] += estoque[i][j];
        }
    }

    for(i = 0; i < TAMANHO_PRODUTOS_VENDIDOS; i++) {
        for(j = 0; j < TAMANHO_LOJAS; j++) {
            // ver se o codigo já está na lista ou não para adicionar
            if(estoque[i][j] < 10) {
                codigos_estoques_inferiores[i] = i;
            }
        }
    }

    return 0;
}
