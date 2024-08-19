#include <stdio.h>

#define TAMANHO_FILAS 20
#define TAMANHO_POLTRONAS 4

#define OPCAO_A 'A'
#define OPCAO_B 'B'
#define OPCAO_C 'C'

#define OCUPADO 1
#define LIVRE 0

#define CONDICAO_PARADA_RESERVA -1

int main() {
    int lugar [TAMANHO_FILAS][TAMANHO_POLTRONAS] = {LIVRE};

    char opcao;

    // Entradas do usuario para fazer uma reserva
    int lugar_fila, lugar_poltrona;

    int i, j; // Iteradores da matriz de lugar
    int total_poltronas_ocupadas = 0;

    printf("Digite a opcao desejada abaixo:\n");
    printf("\nA) Fazer Reserva, B) Calcular ocupacao, C) Mostrar livres ou D) Sair\n\n");

    scanf("%c", &opcao);

    switch(opcao) {
        case OPCAO_A:
            while(lugar_fila != CONDICAO_PARADA_RESERVA) {
                printf("Digite a fila desejada (digite -1 para parar de fazer reservas):\n");
                scanf("%d", &lugar_fila);

                if (lugar_fila != CONDICAO_PARADA_RESERVA) {
                    printf("Digite a poltrona desejada:\n");
                    scanf("%d", &lugar_poltrona);

                    if (lugar[lugar_fila - 1][lugar_poltrona - 1] == LIVRE) {
                        lugar[lugar_fila - 1][lugar_poltrona - 1] = OCUPADO;

                        printf("\n\nLugar de fila %d e poltrona %d reservado!\n");
                    } else {
                        printf("\n\nLugar já ocupado!\n");
                    }
                }
            }

            break;
        case OPCAO_B:
            for (i = 0; i < TAMANHO_FILAS; i++) {
                for (j = 0; j < TAMANHO_POLTRONAS; j++) {
                    if(lugar[i][j] == OCUPADO) {
                        total_poltronas_ocupadas++;
                    }
                }
            }

            printf("\nTotal de poltronas ocupadas: %d\n", total_poltronas_ocupadas);

            break;
        case OPCAO_C:
            printf("\nLugares livres:\n\n");

            for (i = 0; i < TAMANHO_FILAS; i++) {
                for (j = 0; j < TAMANHO_POLTRONAS; j++) {
                    if(lugar[i][j] == LIVRE) {
                        printf("Fila %d | Poltrona %d\n", i + 1, j + 1);
                    }
                }
            }

            break;
        default:
            break;
    }

    return 0;
}
