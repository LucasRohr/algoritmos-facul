// Program that takes three products IDs and values to calculate their IPI total value

#include <stdio.h>
#define IPI 7
#define IPI_PERCENTAGE_MULTIPLIER 0.01

int main() {
    char product_one_id;
    char product_two_id;
    char product_three_id;

    float product_one_price;
    float product_two_price;
    float product_three_price;

    float products_average;

    float ipi_value;

    // First product entries

    printf("Informe o ID do primeiro produto:\n");
    scanf(" %c", &product_one_id);

    printf("Informe o preço do primeiro produto:\n");
    scanf("%f", &product_one_price);

    // Second product entries

    printf("Informe o ID do segundo produto:\n");
    scanf(" %c", &product_two_id);

    printf("Informe o preço do segundo produto:\n");
    scanf("%f", &product_two_price);

    // Third product entries

    printf("Informe o ID do terceiro produto:\n");
    scanf(" %c", &product_three_id);

    printf("Informe o preço do terceiro produto:\n");
    scanf("%f", &product_three_price);

    // IPI calculation

    products_average = (product_one_price + product_two_price + product_three_price) / 3;
    ipi_value = products_average * IPI * IPI_PERCENTAGE_MULTIPLIER;

    printf("Valor do IPI: R$ %.2f", ipi_value);

    return 0;
}
