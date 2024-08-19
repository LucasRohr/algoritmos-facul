// Program that takes a product code and quantity to simulate a buy process in a market given stock quantities and products prices

#include <stdio.h>

#define CONDENSED_MILK_CODE 12
#define CONDENSED_MILK_STOCK 50
#define CONDENSED_MILK_NAME "Leite Condensado"
#define CONDENSED_MILK_PRICE 6.20

#define CHOCOLATE_CODE 14
#define CHOCOLATE_STOCK 20
#define CHOCOLATE_NAME "Chocolate"
#define CHOCOLATE_PRICE 8.50

#define COFFEE_CODE 23
#define COFFEE_STOCK 30
#define COFFEE_NAME "Cafe em caixa"
#define COFFEE_PRICE 11.20

#define COOKIE_CODE 38
#define COOKIE_STOCK 10
#define COOKIE_NAME "Biscoito maizena"
#define COOKIE_PRICE 4.50

int main() {
    int product_code, product_quantity;
    int current_stock;

    float total_price;

    // Products data table

    printf("%s\t%s\t\t\t%s\t\t%s%\n", "Codigo", "Produto", "Estoque", "Preco (R$)");
    printf("%d\t%s\t%d\t\t%.2f%\n", CONDENSED_MILK_CODE, CONDENSED_MILK_NAME, CONDENSED_MILK_STOCK, CONDENSED_MILK_PRICE);
    printf("%d\t%s\t\t%d\t\t%.2f%\n", CHOCOLATE_CODE, CHOCOLATE_NAME, CHOCOLATE_STOCK, CHOCOLATE_PRICE);
    printf("%d\t%s\t\t%d\t\t%.2f%\n", COFFEE_CODE, COFFEE_NAME, COFFEE_STOCK, COFFEE_PRICE);
    printf("%d\t%s\t%d\t\t%.2f%\n", COOKIE_CODE, COOKIE_NAME, COOKIE_STOCK, COOKIE_PRICE);

    printf("\nDigite o codigo do produto a ser comprado:");
    scanf("%d",&product_code);

    printf("Digite a quantidade do produto a ser comprado:");
    scanf("%d",&product_quantity);

    if (product_code == CONDENSED_MILK_CODE) {
        current_stock = CONDENSED_MILK_STOCK;

        if (product_quantity <= CONDENSED_MILK_STOCK && product_quantity >= 0) {
            current_stock = current_stock - product_quantity;
            total_price = product_quantity * CONDENSED_MILK_PRICE;

            printf("\nCompra efetuada:\n");
            printf("ID do produto: %d\n", CONDENSED_MILK_CODE);
            printf("Quantidade do produto: %d\n", product_quantity);
            printf("Preco a ser pago: R$ %.2f\n", total_price);

            // Products report

            printf("\n--------------------------------------------------------------------------\n");
            printf("\t\t\tRelatorio de Vendas do Dia\t\t\t\n");
            printf("%s\t\t\t%s\t\t%s\n", "Produto", "Unidades Vendidas", "Total Faturado");
            printf("%s\t\t\t%d\t\t\tR$ %.2f\n", CONDENSED_MILK_NAME, product_quantity, total_price);
            printf("%s\t\t\t\t%d\t\t\tR$ %.2f\n", CHOCOLATE_NAME, product_quantity, total_price);
            printf("%s\t\t\t\t%d\t\t\tR$ %.2f\n", COFFEE_NAME, product_quantity, total_price);
            printf("%s\t\t\t%d\t\t\tR$ %.2f\n", COOKIE_NAME, product_quantity, total_price);
            printf("--------------------------------------------------------------------------\n");
            printf("Total\t\t\t\t\t\t\t\t R$ %.2f\n", total_price);
            printf("--------------------------------------------------------------------------\n");
        } else {
            printf("\nA compra nao pode ser efetuada por falta de estoque :(");
        }
    } else if (product_code == CHOCOLATE_CODE) {
        current_stock = CHOCOLATE_STOCK;

        if (product_quantity <= CHOCOLATE_STOCK && product_quantity >= 0) {
            current_stock = current_stock - product_quantity;
            total_price = product_quantity * CHOCOLATE_PRICE;

            printf("\nCompra efetuada:\n");
            printf("ID do produto: %d\n", CHOCOLATE_CODE);
            printf("Quantidade do produto: %d\n", product_quantity);
            printf("Preco a ser pago: %.2f\n", total_price);

            // Products report

            printf("\n--------------------------------------------------------------------------\n");
            printf("\t\t\tRelatorio de Vendas do Dia\t\t\t\n");
            printf("%s\t\t\t%s\t\t%s\n", "Produto", "Unidades Vendidas", "Total Faturado");
            printf("%s\t\t\t%d\t\t\tR$ %.2f\n", CONDENSED_MILK_NAME, product_quantity, total_price);
            printf("%s\t\t\t\t%d\t\t\tR$ %.2f\n", CHOCOLATE_NAME, product_quantity, total_price);
            printf("%s\t\t\t\t%d\t\t\tR$ %.2f\n", COFFEE_NAME, product_quantity, total_price);
            printf("%s\t\t\t%d\t\t\tR$ %.2f\n", COOKIE_NAME, product_quantity, total_price);
            printf("--------------------------------------------------------------------------\n");
            printf("Total\t\t\t\t\t\t\t\t R$ %.2f\n", total_price);
            printf("--------------------------------------------------------------------------\n");
        } else {
            printf("A compra nao pode ser efetuada por falta de estoque :(");
        }
    } else if (product_code == COFFEE_CODE) {
        current_stock = COFFEE_STOCK;

        if (product_quantity <= COFFEE_STOCK && product_quantity >= 0) {
            current_stock = current_stock - product_quantity;
            total_price = product_quantity * COFFEE_PRICE;

            printf("\nCompra efetuada:\n");
            printf("ID do produto: %d\n", COFFEE_CODE);
            printf("Quantidade do produto: %d\n", product_quantity);
            printf("Preco a ser pago: %.2f\n", total_price);

            // Products report

            printf("\n--------------------------------------------------------------------------\n");
            printf("\t\t\tRelatorio de Vendas do Dia\t\t\t\n");
            printf("%s\t\t\t%s\t\t%s\n", "Produto", "Unidades Vendidas", "Total Faturado");
            printf("%s\t\t\t%d\t\t\tR$ %.2f\n", CONDENSED_MILK_NAME, product_quantity, total_price);
            printf("%s\t\t\t\t%d\t\t\tR$ %.2f\n", CHOCOLATE_NAME, product_quantity, total_price);
            printf("%s\t\t\t\t%d\t\t\tR$ %.2f\n", COFFEE_NAME, product_quantity, total_price);
            printf("%s\t\t\t%d\t\t\tR$ %.2f\n", COOKIE_NAME, product_quantity, total_price);
            printf("--------------------------------------------------------------------------\n");
            printf("Total\t\t\t\t\t\t\t\t R$ %.2f\n", total_price);
            printf("--------------------------------------------------------------------------\n");
        } else {
            printf("A compra nao pode ser efetuada por falta de estoque :(");
        }
    } else if (product_code == COOKIE_CODE) {
        current_stock = COOKIE_STOCK;

        if (product_quantity <= COOKIE_STOCK && product_quantity >= 0) {
            current_stock = current_stock - product_quantity;
            total_price = product_quantity * COOKIE_PRICE;

            printf("\nCompra efetuada:\n");
            printf("ID do produto: %d\n", COOKIE_CODE);
            printf("Quantidade do produto: %d\n", product_quantity);
            printf("Preco a ser pago: %.2f\n", total_price);

            // Products report

            printf("\n--------------------------------------------------------------------------\n");
            printf("\t\t\tRelatorio de Vendas do Dia\t\t\t\n");
            printf("%s\t\t\t%s\t\t%s\n", "Produto", "Unidades Vendidas", "Total Faturado");
            printf("%s\t\t\t%d\t\t\tR$ %.2f\n", CONDENSED_MILK_NAME, product_quantity, total_price);
            printf("%s\t\t\t\t%d\t\t\tR$ %.2f\n", CHOCOLATE_NAME, product_quantity, total_price);
            printf("%s\t\t\t\t%d\t\t\tR$ %.2f\n", COFFEE_NAME, product_quantity, total_price);
            printf("%s\t\t\t%d\t\t\tR$ %.2f\n", COOKIE_NAME, product_quantity, total_price);
            printf("--------------------------------------------------------------------------\n");
            printf("Total\t\t\t\t\t\t\t\t R$ %.2f\n", total_price);
            printf("--------------------------------------------------------------------------\n");
        } else {
            printf("A compra nao pode ser efetuada por falta de estoque :(");
        }
    } else {
        printf("\nCodigo de produto invalido, tente novamente!\n");
    }

    return 0;
}
