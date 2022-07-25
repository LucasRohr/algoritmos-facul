#include <stdio.h>
#include <string.h>
#include <time.h> // Biblioteca necessária para random
#include <stdlib.h>

#define NUM 4
#define TAMANHO_STRING 100
#define NUM_MESES 12
#define NUM_MES_JULHO 6

int main() {
    char produtos [NUM][TAMANHO_STRING];
    int vendas [NUM][NUM_MESES];

    int i, j;
    const int VALOR_MAXIMO = 200; //valor máximo para número randômicos

    char nome_produto [TAMANHO_STRING];
    int indice_produto_busca = 0;

    int soma_unidades_vendidas = 0;

    char nome_novo_produto [TAMANHO_STRING];
    char nome_produto_existente [TAMANHO_STRING];

    // 1)

    for (i = 0; i < NUM; i++) {
        printf("Digite o nome do produto %d:", i + 1);
        gets(produtos[i]);
    }

    // 2)

    for (i = 0; i < NUM; i++) {
        for (j = 0; j < NUM_MESES; j++) {
            vendas[i][j] = (int) (rand() / (double) RAND_MAX * (VALOR_MAXIMO + 1));
        }
    }

    // 3)

    printf("Digite o nome do produto a ser encontrado:");
    gets(nome_produto);

    while(indice_produto_busca < NUM && strcmp(nome_produto, produtos[indice_produto_busca]) != 0) {
        indice_produto_busca++;
    }

    if (indice_produto_busca < NUM) {
        printf("\n\nO produto %s esta localizado no indice %d do arranjo\n\n", nome_produto, indice_produto_busca);
    } else {
        printf("\n\nProduto %s nao encontrado :(\n\n", nome_produto);
        indice_produto_busca = -1;
    }

    // 4)

    if (indice_produto_busca != -1) {
        for (j = NUM_MES_JULHO; j < NUM_MESES; j++) {
            soma_unidades_vendidas += vendas[indice_produto_busca][j];
        }

        printf("A soma de unidades vendidas do produto %s entre Julho e Dezembro eh: %d\n\n", nome_produto, soma_unidades_vendidas);
    } else {
        printf("\n\nO produto %s nao esta contido na listagem de produtos vendidos, logo nao ha vendas!\n\n", nome_produto);
    }

    // 5)

    printf("Digite o nome de um novo produto:");
    gets(nome_novo_produto);

    printf("Digite o nome de um produto que ja existe na listagem:");
    gets(nome_produto_existente);

    indice_produto_busca = 0;

     while(indice_produto_busca < NUM && strcmp(nome_produto_existente, produtos[indice_produto_busca]) != 0) {
        indice_produto_busca++;
    }

    if (indice_produto_busca < NUM) {
        strcpy(produtos[indice_produto_busca], nome_novo_produto);
 
        for (j = 0; j < NUM_MESES; j++) {
            vendas[indice_produto_busca][j] = 0;
        }

         printf("\n\nNova matriz de vendas:\n\n");

        for (i = 0; i < NUM; i++) {
            printf("|");
            for (j = 0; j < NUM_MESES; j++) {
                printf("\t%d\t|", vendas[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\n\nO nome de produto existente informado nao existe na lista :(\n\n");
        indice_produto_busca = -1;
    }

    return 0;
}