#include <stdio.h>
#include <string.h>
#include <time.h> // Biblioteca necessária para random
#include <stdlib.h>

#define FILIAL 6
#define STRP 100
#define NUMPROD 4

#define CODIGO_PRODUTO_PARADA -1

int main() {
    // ======== Declaracoes ========

    char lista_prod [NUMPROD][STRP];
    int vendas [NUMPROD][FILIAL];

    char nome_cliente [STRP];
    char nome_prod [STRP];

    int i, j;
    const int VALOR_MAXIMO = 100; //valor máximo para número randômicos

    // Dados de entrada
    int codigo_compra, quantidade_produto;

    int estoque[NUMPROD];
    float preco[NUMPROD];

    float valor_venda[NUMPROD] = {};

    int total_estoque = 1; // Total de estoque para verificar condicao de parar o laco

    int total_vendas_produtos [NUMPROD] = {0};

    int maior_media_vendas = 0;
    char nome_produto_maior_media [STRP];

    int indice_produto_busca = 0;

    int diagonal_vendas [NUMPROD];

    int inicio_intervalo_media = 0;
    int fim_intervalo_medo = 0;

    int codigo_prod_busca = 0;

    // ================================

    printf("Digite o nome do cliente:");
    gets(nome_cliente);

    // Preenchimento de vendas

    for (i = 0; i < NUMPROD; i++) {
        for (j = 0; j < FILIAL; j++) {
            vendas[i][j] = (int) (rand() / (double) RAND_MAX * (VALOR_MAXIMO + 1));
        }
    }

    printf("\n\n");

    // Entrada de dados nos arrays

    for (i = 0; i < NUMPROD; i++) {
        printf("Digite o nome do produto %d:", i+ 1);
        gets(lista_prod[i]);

        estoque[i] = (int) (rand() / (double) RAND_MAX * (VALOR_MAXIMO + 1));
        preco[i]= (rand() / (float) RAND_MAX * (VALOR_MAXIMO + 1));
    }

    // Laco de vendas

    do {
        printf("\n\n%s\t%s\t\t%s\t\t%s%\n", "Codigo", "Produto", "Estoque", "Preco (R$)");
        for (i = 0; i < NUMPROD; i++) {
            printf("%5d\t%s\t\t%d\t\t%4.2f%\n", i + 1, lista_prod[i], estoque[i], preco[i]);
        }

        printf("\n\nDigite o codigo de compra:");
        scanf("%d",&codigo_compra);

        if (codigo_compra >= 1 && codigo_compra <= NUMPROD) {
            printf("Digite a quantidade do produto a ser comprado:");
            scanf("%d",&quantidade_produto);

            if (estoque[codigo_compra - 1] >= quantidade_produto) {
                estoque[codigo_compra - 1] -= quantidade_produto;

                valor_venda[codigo_compra - 1] = (float) quantidade_produto * preco[codigo_compra - 1];

                printf("\nValor da venda R$ %.2f\n\n", valor_venda[codigo_compra - 1]);
            } else {
                printf("\n\nNao ha produtos suficientes para venda\n\n");
            }
        } else {
            printf("Codigo invalido\n\n");
        }

        total_estoque = 0;

        for (i = 0; i < NUMPROD; i++) {
            total_estoque += estoque[i];
        }
    } while(codigo_compra != CODIGO_PRODUTO_PARADA && total_estoque > 0);

    // Calculo de produtos vendidos nas filiais

    printf("Digite o valor do inicio do intervalo de busca nas filiais:");
    scanf("%d",&inicio_intervalo_media);

    printf("\n\nDigite o valor do fim do intervalo de busca nas filiais:");
    scanf("%d",&fim_intervalo_medo);

    if (inicio_intervalo_media >= 0 && fim_intervalo_medo <= FILIAL && inicio_intervalo_media < fim_intervalo_medo) {
        for (i = 0; i < NUMPROD; i++) {
            for (j = inicio_intervalo_media; j < fim_intervalo_medo; j++) {
                total_vendas_produtos[i] += vendas[i][j];
            }

            if ((total_vendas_produtos[i] / FILIAL) > maior_media_vendas) {
                maior_media_vendas = (total_vendas_produtos[i] / FILIAL);
            }
        }

        while(indice_produto_busca < NUMPROD && (total_vendas_produtos[indice_produto_busca] / FILIAL) != maior_media_vendas) {
            indice_produto_busca++;
        }

        strcpy(nome_produto_maior_media, lista_prod[indice_produto_busca]);

        printf("\n\nO produto com a maior media de total de vendas nas filiais eh: %s\n\n", nome_produto_maior_media);
    } else {
        printf("\n\nIntervalo invalido de filiais\n\n");
    }

    // Substituicao de produto

    indice_produto_busca = 0;

    fflush(stdin);

    printf("Digite o nome do produto a ser encontrado:");
    gets(nome_prod);

    printf("Digite o codigo do produto a ser encontrado:");
    scanf("%d",&codigo_prod_busca);

    while(indice_produto_busca < NUMPROD && strcmp(nome_prod, lista_prod[indice_produto_busca]) != 0) {
        indice_produto_busca++;
    }

    if (indice_produto_busca < NUMPROD) {
        printf("\n\nO produto %s ja existe no arranjo\n\n", nome_prod);
    } else {
        strcpy(lista_prod[codigo_prod_busca], nome_prod);

        for (j = 0; j < FILIAL; j++) {
            vendas[codigo_prod_busca][j] = 0;
        }
    }

    // Diagonais da matriz de vendas

    printf("\n\nDiagonal principal de vendas:\n\n");

    for (i = 0; i < NUMPROD; i++) {
        diagonal_vendas[i] = vendas[i][i];

        printf("Indice [%d][%d] = %d\n", i, i, diagonal_vendas[i]);
    }

    printf("\n\nDiagonal secundaria de vendas:\n\n");

    for (i = 0; i < NUMPROD; i++) {
        diagonal_vendas[i] = vendas[i][NUMPROD - 1 - i];

        printf("Indice  [%d][%d] = %d\n", i, NUMPROD - 1 - i, diagonal_vendas[i]);
    }

    return 0;
}
