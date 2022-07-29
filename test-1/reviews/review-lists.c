#include <stdio.h>

#define TAMANHO_LISTA_PRODUTO 4

int main() {
    int lista_produto [TAMANHO_LISTA_PRODUTO];
    float valores_produtos [TAMANHO_LISTA_PRODUTO] = {0};

    float maior_valor = 0;
    float codigo_produto_maior_valor;

    int codigo_busca;
    float valor_produto_codigo_busca;

    int i;

    // Preencher lista e achar o codigo do maior produto

    for(i = 0; i < TAMANHO_LISTA_PRODUTO; i++) {
        printf("Digite o codigo do produto %d\n", i + 1);
        scanf("%d", &lista_produto[i]);

        printf("Digite o valor do produto de codigo %d\n", lista_produto[i]);
        scanf("%f", &valores_produtos[i]);

        if (valores_produtos[i] > maior_valor) {
            maior_valor = valores_produtos[i];
            codigo_produto_maior_valor = lista_produto[i];
        }
    }

    // Achar o valor produto com codigo informado

    i = 0;

    printf("Digite o codigo de busca\n");
    scanf("%d", &codigo_busca);

    while(i < TAMANHO_LISTA_PRODUTO && lista_produto[i] != codigo_busca) {
        i++;
    }

    if (i < TAMANHO_LISTA_PRODUTO) {
        printf("\n\nO produto de codigo %d tem valor %.2f\n", codigo_busca, valores_produtos[i]);
    } else {
        printf("\n\nO produto de codigo %d nao foi encontrado\n", codigo_busca);
    }

    return 0;
}