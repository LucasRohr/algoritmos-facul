// Programa para revisar for, while e do while

#include <stdio.h>

#define NUM_PRODUTOS 4

int main() {
    int i; // Variavel de iteracao dos lacos

    float valor_produto;
    int quantidade_produto;

    int quantidade_vendas = 0;
    float valor_venda;
    float media_vendas = 0.0;

    // for

    // for(i = 0; i < NUM_PRODUTOS; i++) {
    //     printf("\nDigite o valor do produto:\n");
    //     scanf("%f", &valor_produto);

    //     printf("\nDigite a quantidade do produto:\n");
    //     scanf("%d", &quantidade_produto);

    //     valor_venda = (float) (valor_produto * quantidade_produto);
    //     media_vendas += valor_venda;
    //     quantidade_vendas++;
        
    //     if (valor_venda < 30) {
    //         printf("\nValor da venda R$ %.2f, compre mais!\n", valor_venda);
    //     } else {
    //         printf("\nValor da venda R$ %.2f, bom cliente!\n", valor_venda);
    //     }
    // }

    // while

    i = 0;
    media_vendas = 0;
    quantidade_vendas = 0;

    // while(i < NUM_PRODUTOS) {
    //     i++;

    //     printf("\nDigite o valor do produto:\n");
    //     scanf("%f", &valor_produto);

    //     printf("\nDigite a quantidade do produto:\n");
    //     scanf("%d", &quantidade_produto);

    //     valor_venda = (float) (valor_produto * quantidade_produto);
    //     media_vendas += valor_venda;
    //     quantidade_vendas++;
        
    //     if (valor_venda < 30) {
    //         printf("\nValor da venda R$ %.2f, compre mais!\n", valor_venda);
    //     } else {
    //         printf("\nValor da venda R$ %.2f, bom cliente!\n", valor_venda);
    //     }
    // }

    i = 0;
    media_vendas = 0;
    quantidade_vendas = 0;

     do{
        i++;

        printf("\nDigite o valor do produto:\n");
        scanf("%f", &valor_produto);

        printf("\nDigite a quantidade do produto:\n");
        scanf("%d", &quantidade_produto);

        valor_venda = (float) (valor_produto * quantidade_produto);
        media_vendas += valor_venda;
        quantidade_vendas++;
        
        if (valor_venda < 30) {
            printf("\nValor da venda R$ %.2f, compre mais!\n", valor_venda);
        } else {
            printf("\nValor da venda R$ %.2f, bom cliente!\n", valor_venda);
        }
    } while(i < NUM_PRODUTOS);

    media_vendas = media_vendas / quantidade_vendas;

    printf("Media de vendas R$ %.2f", media_vendas);

    return 0;
}