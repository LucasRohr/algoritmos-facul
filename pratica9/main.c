#include <stdio.h>
#include "raylib.h"
#include <time.h>
#include <stdlib.h>

#define LARGURA_TELA 850
#define ALTURA_TELA 450

#define NUM_ARANHA 3
#define TAMANHO_POSICAO_ARANHA 2

#define PASSO_ARANHA 10

#define DIRECAO_0 0
#define DIRECAO_1 1
#define DIRECAO_2 2
#define DIRECAO_3 3
#define DIRECAO_4 4
#define DIRECAO_5 5
#define DIRECAO_6 6
#define DIRECAO_7 7

#define ESC 27

void gera_aranha(int aranhas[][NUM_ARANHA]) {
    int i, j;

    for(i = 0; i < TAMANHO_POSICAO_ARANHA; i++) {
        for (j = 0; j < NUM_ARANHA; j++) {
            if (i == 0) {
                aranhas[i][j] = (int) (rand() / (double) RAND_MAX * LARGURA_TELA);
            } else {
                aranhas[i][j] = (int) (rand() / (double) RAND_MAX * ALTURA_TELA);
            }
        }
    }
}

void inverte_movimento(int *x, int *y, int *direcao) {
    switch(*direcao) {
        case(DIRECAO_0):
            *direcao = (int) (rand() % (DIRECAO_5 - DIRECAO_3 + 1)) + DIRECAO_3;
            break;
        case(DIRECAO_1):
            *direcao = (int) (rand() % (DIRECAO_7 - DIRECAO_3 + 1)) + DIRECAO_3;
            break;
        case(DIRECAO_2):
            *direcao = (int) (rand() % (DIRECAO_7 - DIRECAO_5 + 1)) + DIRECAO_5;
            break;
        case(DIRECAO_3):
            *direcao = (int) (rand() % (DIRECAO_7 - DIRECAO_5 + 1)) + DIRECAO_5;
            break;
        case(DIRECAO_4):
            *direcao = DIRECAO_7;
            break;
        case(DIRECAO_5):
            *direcao = (int) (rand() % (DIRECAO_3 - DIRECAO_0 + 1)) + DIRECAO_0;
            break;
        case(DIRECAO_6):
            *direcao = (int) (rand() % (DIRECAO_3 - DIRECAO_1 + 1)) + DIRECAO_1;
            break;
        case(DIRECAO_7):
            *direcao = (int) (rand() % (DIRECAO_5 - DIRECAO_1 + 1)) + DIRECAO_1;
            break;
        default:
            break;
    }
}

int checa_colisao(int x_elemento, int y_elemento, int x_obstaculo, int y_obstaculo) {
    if (x_elemento == x_obstaculo || y_elemento == y_obstaculo) {
        return 1;
    } else {
        return 0;
    }
}

void move_aranha(int *x, int *y, int *direcao) {
    switch(*direcao) {
        case DIRECAO_0:
            (*y)++;

            if(checa_colisao(*x, *y, LARGURA_TELA, ALTURA_TELA)) {
                inverte_movimento(x, y, direcao);
            }

            break;
        case DIRECAO_1:
            (*x)++;
            (*y)++;

            if(checa_colisao(*x, *y, LARGURA_TELA, ALTURA_TELA)) {
                inverte_movimento(x, y, direcao);
            }

            break;
        case DIRECAO_2:
            (*x)++;

            if(checa_colisao(*x, *y, LARGURA_TELA, ALTURA_TELA)) {
                inverte_movimento(x, y, direcao);
            }

            break;
        case DIRECAO_3:
            (*x)++;
            (*y)--;

            if(checa_colisao(*x, *y, LARGURA_TELA, 0)) {
                inverte_movimento(x, y, direcao);
            }

            break;
        case DIRECAO_4:
            (*y)--;

            if(checa_colisao(*x, *y, 0, 0)) {
                inverte_movimento(x, y, direcao);
            }

            break;
        case DIRECAO_5:
            (*x)--;
            (*y)--;

            if(checa_colisao(*x, *y, 0, 0)) {
                inverte_movimento(x, y, direcao);
            }

            break;
        case DIRECAO_6:
            (*x)--;

            if(checa_colisao(*x, *y, 0, 0)) {
                inverte_movimento(x, y, direcao);
            }

            break;
        case DIRECAO_7:
            (*y)++;
            (*x)--;

            if(checa_colisao(*x, *y, 0, ALTURA_TELA)) {
                inverte_movimento(x, y, direcao);
            }

            break;
        default:
            break;
    }
}

void move_todas(int aranhas[][NUM_ARANHA], int direcao[]) {
    int i;

    while(!IsKeyDown(ESC)) {
        for (i = 0; i < NUM_ARANHA; i++) {
            move_aranha(&(aranhas[0, i]), &(aranhas[1, i]), &(direcao[i]));
            WaitTime(1000);
        }
    }
}

int main() {
    int aranhas[TAMANHO_POSICAO_ARANHA][NUM_ARANHA];
    int direcao[NUM_ARANHA];

    gera_aranha(aranhas);
    move_todas(aranhas, direcao);

    return 0;
}
