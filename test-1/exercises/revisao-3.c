// Programa que gerencia e altera lugares de um teatro com base em uma matriz de lugares

#include <stdio.h>

#define TAMANHO_FILAS 20
#define TAMANHO_POLTRONAS 15

#define OCUPADO 1
#define LIVRE 0

#define VALOR_PARADA_RESERVA -1

#define OPCAO_A 'A'
#define OPCAO_B 'B'
#define OPCAO_C 'C'

int main() {
    int lugar [TAMANHO_FILAS][TAMANHO_POLTRONAS] = {LIVRE};

    int i, j; // Iteradores da matriz
    int fila_entrada, poltrona_entrada;
    int total_ocupadas = 0, total_livres = 0;

    char opcao;

    printf("Digite a opcao desejada:\n");
    scanf("%c", &opcao);

    switch(opcao) {
        case OPCAO_A:
            while(fila_entrada != VALOR_PARADA_RESERVA) {
                printf("Digite a fila desejada (digite -1 para parar de reservar):\n");
                scanf("%d", &fila_entrada);

                if (fila_entrada != VALOR_PARADA_RESERVA) {
                    printf("Digite a poltrona desejada:\n");
                    scanf("%d", &poltrona_entrada);

                    if (lugar[fila_entrada - 1][poltrona_entrada -1] == LIVRE) {
                        lugar[fila_entrada - 1][poltrona_entrada -1] = OCUPADO;
                        total_ocupadas++;

                        printf("\n\nLugar de fila %d e poltrona %d reservado\n", fila_entrada, poltrona_entrada);
                    } else {
                         printf("\n\nLugar já ocupado\n")
                    }
                }
            }

            total_livres = (TAMANHO_FILAS * TAMANHO_POLTRONAS) - total_ocupadas;

            printf("\n\nTotal de poltronas livres: %d\n", total_livres);
            printf("Total de poltronas ocupadas: %d\n", total_ocupadas);

            break;
        case OPCAO_B:
            printf("\n\nMapa de ocupacao dos lugares:\n\n");

            for(i = 0; i < TAMANHO_FILAS; i++) {
                printf("Fila %d: ", i + 1);

                for(j = 0; j < TAMANHO_POLTRONAS; j++) {
                    printf("|%d|", j + 1);
                }

                printf("\n");
            }

            break;
        case OPCAO_C:
            printf("Digite a fila da poltrona desejada:\n");
            scanf("%d", &fila_entrada);

            printf("Digite o numero poltrona desejada:\n");
            scanf("%d", &poltrona_entrada);

            if (lugarp[fila_entrada - 1][poltrona_entrada - 1] == OCUPADO) {
                printf("\nLugar ocupado!\n");
            } else {
                printf("\nLugar livre!\n");
            }

            break;
        default:
            break;
    }

    return 0;
}
