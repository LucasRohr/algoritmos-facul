#include <time.h> // Biblioteca necessária para random
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUMPROD 4
#define TAMSTR 50

#define CODIGO_PRODUTO_PARADA -1

#define NOME_DESCONTO "Paulo Ulisses"
#define DESCONTO_VOUCHER 50.0

int main() {
    // Dados de entrada
    int codigo_compra, quantidade_produto;

    int estoque[NUMPROD];
    int estoque_inicial[NUMPROD];

    float preco[NUMPROD];
    float valor_venda[NUMPROD] = {};
    char nome_cliente[TAMSTR];

    const int VALOR_MAXIMO = 20; //valor máximo para número randômicos
    int i; // Indices de for

    int total_estoque = 1; // Total de estoque para verificar condicao de parar o laco
    float total_faturado;

    srand(time(0));

    for (i = 0; i < NUMPROD; i++) {
        estoque[i] = (int) (rand() / (double) RAND_MAX * (VALOR_MAXIMO + 1));
        estoque_inicial[i] = estoque[i];
        preco[i]= (rand() / (float) RAND_MAX * (VALOR_MAXIMO + 1));
    }

    printf("Digite o nome do cliente:");
    gets(nome_cliente);

    do {
        printf("\n\n%s\t\t%s\t\t%s%\n", "Codigo", "Estoque", "Preco (R$)");
        for (i = 0; i < NUMPROD; i++) {
            printf("%5d\t\t%3d\t\t%4.2f%\n", i + 1, estoque[i], preco[i]);
        }

        printf("\n\nDigite o codigo de compra:");
        scanf("%d",&codigo_compra);

        if (codigo_compra >= 1 && codigo_compra <= NUMPROD) {
            printf("Digite a quantidade do produto a ser comprado:");
            scanf("%d",&quantidade_produto);

            if (estoque[codigo_compra - 1] >= quantidade_produto) {
                estoque[codigo_compra - 1] -= quantidade_produto;

                valor_venda[codigo_compra - 1] = (float) quantidade_produto * preco[codigo_compra - 1];
                total_faturado +=  valor_venda[codigo_compra - 1];

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

    printf("\n\n-----------------------------------------------------------\n");
    printf("\t\tRelatorio de vendas do Cliente\t\t");
    printf("\n-----------------------------------------------------------\n");
    printf("%s\t\t%s\t%s\t\n", "Codigo", "Unidades Vendidas", "Total Faturado");

    for (i = 0; i < NUMPROD; i++) {
        printf("%5d\t\t\t%d\t\tR$ %.2f\n", i + 1, estoque_inicial[i] - estoque[i], valor_venda[i]);
    }

    printf("-----------------------------------------------------------\n");
    printf("Total\t\t\t\t\t R$ %.2f\n", total_faturado);
    printf("-----------------------------------------------------------\n");

    if (strcmp(nome_cliente, NOME_DESCONTO) == 0) {
        total_faturado -= DESCONTO_VOUCHER;

        printf("\n\nTotal com desconto\t\t\t R$ %.2f\n", total_faturado);
    }

    return 0;
}
