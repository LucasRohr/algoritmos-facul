// Programa que recebe codigo e quantidade de acoes a serem compradas e retorna o quanto foi investido em cada pedido, bem como um resumo de compras em tabela

#include <stdio.h>

#define CODIGO_GERDAU 1
#define NOME_GERDAU "Gerdau"
#define ESTOQUE_INICIAL_GERDAU 5000
#define VALOR_UNIDADE_GERDAU 4.00

#define CODIGO_PETROBRAS 2
#define NOME_PETROBRAS "Petrobras"
#define ESTOQUE_INICIAL_PETROBRAS 4500
#define VALOR_UNIDADE_PETROBRAS 2.50

#define CODIGO_AZALEIA 3
#define NOME_AZALEIA "Azaleia"
#define ESTOQUE_INICIAL_AZALEIA 500
#define VALOR_UNIDADE_AZALEIA 2.50

#define CODIGO_GRENDENE 4
#define NOME_GRENDENE "Grendene"
#define ESTOQUE_INICIAL_GRENDENE 2000
#define VALOR_UNIDADE_GRENDENE 1.20

#define NUMERO_ITERACOES 5

int main() {
    int codigo_lote, quantidade_lote; // Dados de entrada do usuario para pedido
    int estoque_atual; // Estoque atual para a Atividade 01 (compra unica)

    int cont; // Contador do laço for de repeticao

    // Estoques para cada empresa ao longo das compras (Atividade 02)
    int estoque_atual_gerdau = ESTOQUE_INICIAL_GERDAU;
    int estoque_atual_petrobras = ESTOQUE_INICIAL_PETROBRAS;
    int estoque_atual_azaleia = ESTOQUE_INICIAL_AZALEIA;
    int estoque_atual_grendene = ESTOQUE_INICIAL_GRENDENE;

    int lotes_vendidos_gerdau = 0, lotes_vendidos_petrobras = 0, lotes_vendidos_azaleia = 0, lotes_vendidos_grendene = 0; // Armazena o total de lotes vendido para cada empresa
    float total_faturado_gerdau = 0, total_faturado_petrobras = 0, total_faturado_azaleia = 0, total_faturado_grendene = 0; // Armazena o total faturado para cada empresa

    float total_vendas = 0; // Guarda o valor numerico total da soma de precos vendidos
    int total_pedidos = 0; // Guarda o total da quantidade de produtos feitos nos pedidos
    float media_vendas = 0; // Divide o total das vendas por quantos pedidos foram feitos

    // === Atividade 01 ===

    // Tabela dos lotes

    printf("%s\t%s\t\t\t%s\t\t%s%\n", "Codigo", "Opcao", "Disponivel", "Valor (R$)");
    printf("%4d\t%s\t\t\t%6d\t\t\t%6.2f%\n", CODIGO_GERDAU, NOME_GERDAU, ESTOQUE_INICIAL_GERDAU, VALOR_UNIDADE_GERDAU);
    printf("%4d\t%s\t\t%6d\t\t\t%6.2f%\n", CODIGO_PETROBRAS, NOME_PETROBRAS, ESTOQUE_INICIAL_PETROBRAS, VALOR_UNIDADE_PETROBRAS);
    printf("%4d\t%s\t\t\t%6d\t\t\t%6.2f%\n", CODIGO_AZALEIA, NOME_AZALEIA, ESTOQUE_INICIAL_AZALEIA, VALOR_UNIDADE_AZALEIA);
    printf("%4d\t%s\t\t%6d\t\t\t%6.2f%\n", CODIGO_GRENDENE, NOME_GRENDENE, ESTOQUE_INICIAL_GRENDENE, VALOR_UNIDADE_GRENDENE);

    printf("\nDigite o codigo das acoes a serem compradas:");
    scanf("%d",&codigo_lote);

    printf("Digite a quantidade do acoes a serem compradas:");
    scanf("%d",&quantidade_lote);

    switch(codigo_lote) {
        case CODIGO_GERDAU:
            estoque_atual = ESTOQUE_INICIAL_GERDAU;

            if (quantidade_lote <= ESTOQUE_INICIAL_GERDAU && quantidade_lote >= 0) {
                estoque_atual = estoque_atual - quantidade_lote;
                total_vendas = quantidade_lote * VALOR_UNIDADE_GERDAU;

                printf("\nCompra efetuada:\n");
                printf("ID das acoes: %d\n", CODIGO_GERDAU);
                printf("Quantidade de lotes: %d\n", quantidade_lote);
                printf("Preco do investimento: R$ %.2f\n", total_vendas);
            } else {
                printf("\nA compra nao pode ser efetuada por falta de estoque :(");
            }

            break;
        case CODIGO_PETROBRAS:
            estoque_atual = ESTOQUE_INICIAL_PETROBRAS;

            if (quantidade_lote <= ESTOQUE_INICIAL_PETROBRAS && quantidade_lote >= 0) {
                estoque_atual = estoque_atual - quantidade_lote;
                total_vendas = quantidade_lote * VALOR_UNIDADE_PETROBRAS;

                printf("\nCompra efetuada:\n");
                printf("ID das acoes: %d\n", CODIGO_PETROBRAS);
                printf("Quantidade de lotes: %d\n", quantidade_lote);
                printf("Preco do investimento: R$ %.2f\n", total_vendas);
            } else {
                printf("\nA compra nao pode ser efetuada por falta de estoque :(");
            }

            break;
        case CODIGO_AZALEIA:
             estoque_atual = ESTOQUE_INICIAL_AZALEIA;

            if (quantidade_lote <= ESTOQUE_INICIAL_AZALEIA && quantidade_lote >= 0) {
                estoque_atual = estoque_atual - quantidade_lote;
                total_vendas = quantidade_lote * VALOR_UNIDADE_AZALEIA;

                printf("\nCompra efetuada:\n");
                printf("ID das acoes: %d\n", CODIGO_AZALEIA);
                printf("Quantidade de lotes: %d\n", quantidade_lote);
                printf("Preco do investimento: R$ %.2f\n", total_vendas);
            } else {
                printf("\nA compra nao pode ser efetuada por falta de estoque :(");
            }

            break;
        case CODIGO_GRENDENE:
             estoque_atual = ESTOQUE_INICIAL_GRENDENE;

            if (quantidade_lote <= ESTOQUE_INICIAL_GRENDENE && quantidade_lote >= 0) {
                estoque_atual = estoque_atual - quantidade_lote;
                total_vendas = quantidade_lote * VALOR_UNIDADE_GRENDENE;

                printf("\nCompra efetuada:\n");
                printf("ID das acoes: %d\n", CODIGO_GRENDENE);
                printf("Quantidade de lotes: %d\n", quantidade_lote);
                printf("Preco do investimento: R$ %.2f\n\n", total_vendas);
            } else {
                printf("\nA compra nao pode ser efetuada por falta de estoque :(");
            }

            break;
        default:
            printf("\nCodigo de lote invalido, tente novamente.");
    }

    total_vendas = 0;

    printf("\n\n=== COM LACO DE REPETICAO: ===\n\n");

    // === Atividade 02 ===

    for(cont = 0; cont < NUMERO_ITERACOES; cont++) {
        // Tabela dos lotes

        printf("%s\t%s\t\t\t%s\t\t%s%\n", "Codigo", "Opcao", "Disponivel", "Valor (R$)");
        printf("%4d\t%s\t\t\t%6d\t\t\t%6.2f%\n", CODIGO_GERDAU, NOME_GERDAU, estoque_atual_gerdau, VALOR_UNIDADE_GERDAU);
        printf("%4d\t%s\t\t%6d\t\t\t%6.2f%\n", CODIGO_PETROBRAS, NOME_PETROBRAS, estoque_atual_petrobras, VALOR_UNIDADE_PETROBRAS);
        printf("%4d\t%s\t\t\t%6d\t\t\t%6.2f%\n", CODIGO_AZALEIA, NOME_AZALEIA, estoque_atual_azaleia, VALOR_UNIDADE_AZALEIA);
        printf("%4d\t%s\t\t%6d\t\t\t%6.2f%\n", CODIGO_GRENDENE, NOME_GRENDENE, estoque_atual_grendene, VALOR_UNIDADE_GRENDENE);

        printf("\nDigite o codigo das acoes a serem compradas:");
        scanf("%d",&codigo_lote);

        printf("Digite a quantidade do acoes a serem compradas:");
        scanf("%d",&quantidade_lote);

        switch(codigo_lote) {
            case CODIGO_GERDAU:
                if (quantidade_lote <= estoque_atual_gerdau && quantidade_lote >= 0) {
                    estoque_atual_gerdau = estoque_atual_gerdau - quantidade_lote;

                    total_faturado_gerdau = total_faturado_gerdau + (quantidade_lote * VALOR_UNIDADE_GERDAU);
                    lotes_vendidos_gerdau = lotes_vendidos_gerdau + quantidade_lote;

                    total_vendas = (float) total_vendas + (quantidade_lote * VALOR_UNIDADE_GERDAU);
                    total_pedidos = total_pedidos + quantidade_lote;

                    printf("\nCompra efetuada:\n");
                    printf("ID das acoes: %d\n", CODIGO_GERDAU);
                    printf("Quantidade de lotes: %d\n", quantidade_lote);
                    printf("Preco do investimento: R$ %.2f\n\n", total_faturado_gerdau);
                } else {
                    printf("\nA compra nao pode ser efetuada por falta de estoque :(\n\n");
                }

                break;
            case CODIGO_PETROBRAS:
                if (quantidade_lote <= estoque_atual_petrobras && quantidade_lote >= 0) {
                    estoque_atual_petrobras = estoque_atual_petrobras - quantidade_lote;

                    total_faturado_petrobras = total_faturado_petrobras + (quantidade_lote * VALOR_UNIDADE_PETROBRAS);
                    lotes_vendidos_petrobras = lotes_vendidos_petrobras + quantidade_lote;

                    total_vendas = (float) total_vendas + (quantidade_lote * VALOR_UNIDADE_PETROBRAS);
                    total_pedidos = total_pedidos + quantidade_lote;

                    printf("\nCompra efetuada:\n");
                    printf("ID das acoes: %d\n", CODIGO_PETROBRAS);
                    printf("Quantidade de lotes: %d\n", quantidade_lote);
                    printf("Preco do investimento: R$ %.2f\n\n", total_vendas);
                } else {
                    printf("\nA compra nao pode ser efetuada por falta de estoque :(\n\n");
                }

                break;
            case CODIGO_AZALEIA:
                if (quantidade_lote <= estoque_atual_azaleia && quantidade_lote >= 0) {
                    estoque_atual_azaleia = estoque_atual_azaleia - quantidade_lote;

                    total_faturado_azaleia = total_faturado_azaleia + (quantidade_lote * VALOR_UNIDADE_AZALEIA);
                    lotes_vendidos_azaleia = lotes_vendidos_azaleia + quantidade_lote;

                    total_vendas = (float) total_vendas + (quantidade_lote * VALOR_UNIDADE_AZALEIA);
                    total_pedidos = total_pedidos + quantidade_lote;

                    printf("\nCompra efetuada:\n");
                    printf("ID das acoes: %d\n", CODIGO_AZALEIA);
                    printf("Quantidade de lotes: %d\n", quantidade_lote);
                    printf("Preco do investimento: R$ %.2f\n\n", total_vendas);
                } else {
                    printf("\nA compra nao pode ser efetuada por falta de estoque :(\n\n");
                }

                break;
            case CODIGO_GRENDENE:
                if (quantidade_lote <= estoque_atual_grendene && quantidade_lote >= 0) {
                    estoque_atual_grendene = estoque_atual_grendene - quantidade_lote;

                    total_faturado_grendene = total_faturado_grendene + (quantidade_lote * VALOR_UNIDADE_GRENDENE);
                    lotes_vendidos_grendene = lotes_vendidos_grendene + quantidade_lote;

                    total_vendas = (float) total_vendas + (quantidade_lote * VALOR_UNIDADE_GRENDENE);
                    total_pedidos = total_pedidos + quantidade_lote;

                    printf("\nCompra efetuada:\n");
                    printf("ID das acoes: %d\n", CODIGO_GRENDENE);
                    printf("Quantidade de lotes: %d\n", quantidade_lote);
                    printf("Preco do investimento: R$ %.2f\n\n", total_vendas);
                } else {
                    printf("\nA compra nao pode ser efetuada por falta de estoque :(\n\n");
                }

                break;
            default:
                printf("\nCodigo de lote invalido, tente novamente.\n\n");
        }
    }

    media_vendas = (float) (total_vendas / total_pedidos);

    printf("\n\n**************************************************************************\n");
    printf("*\t\t\t\tSTOCK MARCKET\t\t\t\t*");
    printf("\n**************************************************************************\n");
    printf("*\t%s\t\t%s\t\t%s\t\t*\n", "Empresa", "Lotes Vendidos", "Total Faturado");
    printf("*\t\t\t\t\t\t\t\t\t*\n");
    printf("*\t%d.%s\t\t%d\t\t\tR$ %.2f\t*\n", CODIGO_GERDAU, NOME_GERDAU, lotes_vendidos_gerdau, total_faturado_gerdau);
    printf("*\t%d.%s\t\t%d\t\t\tR$ %.2f\t*\n", CODIGO_PETROBRAS, NOME_PETROBRAS, lotes_vendidos_petrobras, total_faturado_petrobras);
    printf("*\t%d.%s\t\t%d\t\t\tR$ %.2f\t*\n", CODIGO_AZALEIA, NOME_AZALEIA, lotes_vendidos_azaleia, total_faturado_azaleia);
    printf("*\t%d.%s\t\t%d\t\t\tR$ %.2f\t*\n", CODIGO_GRENDENE, NOME_GRENDENE, lotes_vendidos_grendene, total_faturado_grendene);
    printf("**************************************************************************\n");
    printf("*\tTOTAL DE VENDAS DO DIA\t\t\t\t R$ %.2f\t*\n", total_vendas);
    printf("*\tMEDIA DAS VENDAS\t\t\t\t R$ %.2f\t*\n", media_vendas);
    printf("**************************************************************************\n");

    return 0;
}
