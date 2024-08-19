// Programa que recebe codigos e quantidades de produtos indeterminados calculando as vendas dos produtos

#include <stdio.h>

#define CODIGO_LEITE_CONDENSADO 12
#define NOME_LEITE_CONDENSADO "Leite Condensado"
#define ESTOQUE_INICIAL_LEITE_CONDENSADO 50
#define PRECO_LEITE_CONDENSADO 6.20

#define CODIGO_CHOCOLATE 14
#define NOME_CHOCOLATE "Chocolate"
#define ESTOQUE_INICIAL_CHOCOLATE 20
#define PRECO_CHOCOLATE 8.50

#define CODIGO_CAFE 23
#define NOME_CAFE "Cafe em caixa"
#define ESTOQUE_INICIAL_CAFE 30
#define PRECO_CAFE 11.20

#define CODIGO_BISCOITO 38
#define NOME_BISCOITO "Biscoito maizena"
#define ESTOQUE_INICIAL_BISCOITO 10
#define PRECO_BISCOITO 4.50

#define CODIGO_PRODUTO_PARADA -1

int main() {
    // Dados de entrada
    int codigo_produto, quantidade_produto;

    // Preco total de um pedido para mostrar ao usuario
    float preco_total_pedido;

    // Segunda condicao para parar o laco
    int possui_estoque = 1;

    // Estoques para cada produto
    int estoque_atual_leite_condensado = ESTOQUE_INICIAL_LEITE_CONDENSADO;
    int estoque_atual_chocolate = ESTOQUE_INICIAL_CHOCOLATE;
    int estoque_atual_cafe = ESTOQUE_INICIAL_CAFE;
    int estoque_atual_biscoito = ESTOQUE_INICIAL_BISCOITO;

    // Preco total para cada produto, calculados no final de todas as iteracoes
    float preco_total_leite_condensado;
    float preco_total_chocolate;
    float preco_total_cafe;
    float preco_total_biscoito;

    // Preco total de todos os pedidos
    float preco_total;

    // Controle do numero de um pedido
    int numero_pedido = 0;
    int numero_pedido_final_leite = 0;
    int numero_pedido_final_chocolate = 0;
    int numero_pedido_final_cafe = 0;
    int numero_pedido_final_biscoito = 0;

    do {
        numero_pedido += 1;

        // Tabela dos produtos

        printf("%s\t%s\t\t\t%s\t\t%s%\n", "Codigo", "Produto", "Estoque", "Preco (R$)");
        printf("%4d\t%s\t%4d\t\t%6.2f%\n", CODIGO_LEITE_CONDENSADO, NOME_LEITE_CONDENSADO, estoque_atual_leite_condensado, PRECO_LEITE_CONDENSADO);
        printf("%4d\t%s\t\t%4d\t\t%6.2f%\n", CODIGO_CHOCOLATE, NOME_CHOCOLATE, estoque_atual_chocolate, PRECO_CHOCOLATE);
        printf("%4d\t%s\t\t%4d\t\t%6.2f%\n", CODIGO_CAFE, NOME_CAFE, estoque_atual_cafe, PRECO_CAFE);
        printf("%4d\t%s\t%4d\t\t%6.2f%\n", CODIGO_BISCOITO, NOME_BISCOITO, estoque_atual_biscoito, PRECO_BISCOITO);

        printf("\nDigite o codigo do produto a ser comprado:");
        scanf("%d",&codigo_produto);

        printf("Digite a quantidade do produto a ser comprado:");
        scanf("%d",&quantidade_produto);

        switch(codigo_produto) {
            case CODIGO_LEITE_CONDENSADO:
                if (quantidade_produto <= estoque_atual_leite_condensado) {
                    estoque_atual_leite_condensado -= quantidade_produto;
                    preco_total_pedido = quantidade_produto * PRECO_LEITE_CONDENSADO;

                    printf("\nCompra efetuada:\n");
                    printf("ID do produto: %d\n", codigo_produto);
                    printf("Quantidade do produto: %d\n", quantidade_produto);
                    printf("Preco a ser pago: R$ %.2f\n\n", preco_total_pedido);

                    if (estoque_atual_leite_condensado == 0) {
                        numero_pedido_final_leite = numero_pedido;
                    }
                } else {
                    printf("\nA compra nao pode ser efetuada por falta de estoque :(\n\n");
                }

                break;
            case CODIGO_CHOCOLATE:
                 if (quantidade_produto <= estoque_atual_chocolate) {
                    estoque_atual_chocolate -= quantidade_produto;
                    preco_total_pedido = quantidade_produto * PRECO_CHOCOLATE;

                    printf("\nCompra efetuada:\n");
                    printf("ID do produto: %d\n", codigo_produto);
                    printf("Quantidade do produto: %d\n", quantidade_produto);
                    printf("Preco a ser pago: R$ %.2f\n\n", preco_total_pedido);

                    if (estoque_atual_chocolate == 0) {
                        numero_pedido_final_chocolate = numero_pedido;
                    }
                } else {
                    printf("\nA compra nao pode ser efetuada por falta de estoque :(\n\n");
                }

                break;
            case CODIGO_CAFE:
                if (quantidade_produto <= estoque_atual_cafe) {
                    estoque_atual_cafe -= quantidade_produto;
                    preco_total_pedido = quantidade_produto * PRECO_CAFE;

                    printf("\nCompra efetuada:\n");
                    printf("ID do produto: %d\n", codigo_produto);
                    printf("Quantidade do produto: %d\n", quantidade_produto);
                    printf("Preco a ser pago: R$ %.2f\n\n", preco_total_pedido);

                    if (estoque_atual_cafe == 0) {
                        numero_pedido_final_cafe = numero_pedido;
                    }
                } else {
                    printf("\nA compra nao pode ser efetuada por falta de estoque :(\n\n");
                }

                break;
            case CODIGO_BISCOITO:
                if (quantidade_produto <= estoque_atual_biscoito) {
                    estoque_atual_biscoito -= quantidade_produto;
                    preco_total_pedido = quantidade_produto * PRECO_BISCOITO;

                    printf("\nCompra efetuada:\n");
                    printf("ID do produto: %d\n", codigo_produto);
                    printf("Quantidade do produto: %d\n", quantidade_produto);
                    printf("Preco a ser pago: R$ %.2f\n\n", preco_total_pedido);

                    if (estoque_atual_biscoito == 0) {
                        numero_pedido_final_biscoito = numero_pedido;
                    }
                } else {
                    printf("\nA compra nao pode ser efetuada por falta de estoque :(\n\n");
                }

                break;
            default:
                printf("\nCodigo de produto invalido, tente novamente.\n\n");
        }

        if (estoque_atual_leite_condensado == 0 && estoque_atual_chocolate == 0 && estoque_atual_cafe == 0 && estoque_atual_biscoito == 0) {
            possui_estoque = 0;
        }
    } while(codigo_produto != CODIGO_PRODUTO_PARADA && possui_estoque == 1);

    preco_total_leite_condensado = (ESTOQUE_INICIAL_LEITE_CONDENSADO - estoque_atual_leite_condensado) * PRECO_LEITE_CONDENSADO;
    preco_total_chocolate = (ESTOQUE_INICIAL_CHOCOLATE - estoque_atual_chocolate) * PRECO_CHOCOLATE;
    preco_total_cafe = (ESTOQUE_INICIAL_CAFE - estoque_atual_cafe) * PRECO_CAFE;
    preco_total_biscoito = (ESTOQUE_INICIAL_BISCOITO - estoque_atual_biscoito) * PRECO_BISCOITO;

    preco_total = preco_total_leite_condensado + preco_total_chocolate + preco_total_cafe + preco_total_biscoito;

    printf("\n\n--------------------------------------------------------------------------\n");
    printf("\t\t\tRelatorio de vendas do dia\t\t\t");
    printf("\n--------------------------------------------------------------------------\n");
    printf("%s\t\t\t%s\t\t  %s\t\n", "Produto", "Unidades Vendidas", "Total Faturado");
    printf("%s\t\t%4d\t\t\t\tR$ %.2f\n", NOME_LEITE_CONDENSADO, estoque_atual_leite_condensado, preco_total_leite_condensado);
    printf("%s\t\t\t%4d\t\t\t\tR$ %.2f\n", NOME_CHOCOLATE, estoque_atual_chocolate, preco_total_chocolate);
    printf("%s\t\t\t%4d\t\t\t\tR$ %.2f\n", NOME_CAFE, estoque_atual_cafe, preco_total_cafe);
    printf("%s\t\t%4d\t\t\t\tR$ %.2f\n", NOME_BISCOITO, estoque_atual_biscoito, preco_total_biscoito);
    printf("--------------------------------------------------------------------------\n");
    printf("Total\t\t\t\t\t\t\t\t R$ %.2f\n", preco_total);
    printf("--------------------------------------------------------------------------\n");

    printf("\n\n");

    printf("Numero do pedido final de leite condensado: %d\n", numero_pedido_final_leite);
    printf("Numero do pedido final de chocolate: %d\n", numero_pedido_final_chocolate);
    printf("Numero do pedido final de cafe: %d\n", numero_pedido_final_cafe);
    printf("Numero do pedido final de biscoito: %d\n", numero_pedido_final_biscoito);

    printf("\n\n");

    if (preco_total_leite_condensado > preco_total_chocolate && preco_total_leite_condensado > preco_total_cafe && preco_total_leite_condensado > preco_total_biscoito) {
        printf("O produto com maior faturamento foi: %s\n", NOME_LEITE_CONDENSADO);
    } else if(preco_total_chocolate > preco_total_leite_condensado && preco_total_chocolate > preco_total_cafe && preco_total_chocolate > preco_total_biscoito) {
        printf("O produto com maior faturamento foi: %s\n", NOME_CHOCOLATE);
    } else if (preco_total_cafe > preco_total_leite_condensado && preco_total_cafe > preco_total_chocolate && preco_total_cafe > preco_total_biscoito) {
        printf("O produto com maior faturamento foi: %s\n", NOME_CAFE);
    } else if (preco_total_cafe > preco_total_leite_condensado && preco_total_cafe > preco_total_chocolate && preco_total_cafe > preco_total_biscoito) {
        printf("O produto com maior faturamento foi: %s\n", NOME_BISCOITO);
    } else {
        printf("Nenhum pedido foi feito, logo nenhum produto foi o mais faturado\n\n");
    }

    return 0;
}

