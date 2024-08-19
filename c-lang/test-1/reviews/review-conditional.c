// Programa para revisar expressoes logicas, if, if else e switch

#include <stdio.h>

#define OPCAO_1 'A'
#define OPCAO_2 'B'
#define OPCAO_3 'C'

#define VERDADEIRO 1
#define FALSO 0

int main() {
    char opcao;

    int nota_1;
    int nota_2;
    int nota_3;

    float media_ponderada;

    int possui_ponto_extra = FALSO;

    printf("Digite a primeira nota:\n");
    scanf("%d", &nota_1);

    printf("\n\nDigite a segunda nota:\n");
    scanf("%d", &nota_2);

    printf("\n\nDigite a terceira nota:\n");
    scanf("%d", &nota_3);

    fflush(stdin);

    printf("\n\nA) Media ponderada - B) Verificar ponto extra - C) Verificar conceito\n\n");

    printf("\n\nDigite a opcao desejada:\n");
    scanf("%c", &opcao);

    switch(opcao) {
        case OPCAO_1:
            media_ponderada = (float) ((nota_1 * 1) + (nota_2 * 2) + (nota_3 * 3)) / 6;
            
            if (media_ponderada >= 6) {
                printf("parabens, voce passou com media %.2f!", media_ponderada);
            } else {
                printf("recuperacao :(");
            }

            break;
        case OPCAO_2:
            if ((nota_1 + nota_2) > nota_3) {
                possui_ponto_extra = VERDADEIRO;
                printf("ponto extra!");
            }

            break;
        case OPCAO_3:
            media_ponderada = (float) ((nota_1 * 1) + (nota_2 * 2) + (nota_3 * 3)) / 6;

            if (media_ponderada < 6) {
                printf("\n\fnao passastes");
            } else if (media_ponderada >= 6 && media_ponderada <= 8) {
                printf("\n\npassou");
            } else {
                printf("\n\npassou bem !");
            }

            break;
        default:
            printf("Opcao invalida");
    }

    return 0;
}
