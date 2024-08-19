#include <stdio.h>

#define VALOR_PARADA 0

int main() {
    float media_harmonica;
    float total_denominador = 0.0;

    int valor;
    int contador_numeros = 0;

    while(valor != VALOR_PARADA) {
        printf("Digite o valor X%d:\n", contador_numeros + 1);
        scanf("%d", &valor);

        if (valor > 0) {
            contador_numeros++;
            total_denominador += (float) (1.0 / valor);
        } else {
            printf("\n\nO valor digitado deve ser positivo!\n");
        }
    }

    media_harmonica = (float) (contador_numeros / total_denominador);

    printf("\n\nA media harmonica eh: %.2f\n", media_harmonica);

    return 0;
}