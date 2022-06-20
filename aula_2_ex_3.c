// Program that takes three products IDs and quantities to calculate their total value given constant prices

#include <stdio.h>

#define P_PRICE 3.25
#define T_PRICE 9.88
#define W_PRICE 0.45

int main() {
    char product_one_code;
    char product_two_code;
    char product_three_code;

    float product_one_quantity;
    float product_two_quantity;
    float product_three_quantity;

    float total_price;

    // First product entries

    printf("Informe o código do primeiro produto:\n");
    scanf(" %c", &product_one_code);

    printf("Informe a quantidade do primeiro produto:\n");
    scanf("%f", &product_one_quantity);

    // Second product entries

    printf("Informe o código do segundo produto:\n");
    scanf(" %c", &product_two_code);

    printf("Informe a quantidade do segundo produto:\n");
    scanf("%f", &product_two_quantity);

    // Third product entries

    printf("Informe o código do terceiro produto:\n");
    scanf(" %c", &product_three_code);

    printf("Informe a quantidade do terceiro produto:\n");
    scanf("%f", &product_three_quantity);

    // Price calculation

    total_price = (product_one_quantity * P_PRICE) + (product_two_quantity * T_PRICE) + (product_three_quantity * W_PRICE);

    printf("Preço total dos produtos: R$ %.2f", total_price);

    return 0;
}
