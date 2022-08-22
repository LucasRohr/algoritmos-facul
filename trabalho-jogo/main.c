#include <stdio.h>
#include "raylib.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define LARGURA_TELA 850
#define ALTURA_TELA 450

#define NUM_ARANHA 3

#define TIROS_INICIAIS 200
#define VIDAS_INICIAIS 3

#define TAMNOME 30

#define ESC 27

typedef enum {
    esq = 6,
    dir = 2,
    cima = 0,
    baixo = 4,
    dir_cima = 1,
    dir_baixo = 3,
    esq_cima = 7,
    esq_baixo = 5,
    null = -1,
} DIRECAO;

// Estruturas

typedef struct {
    Vector2 posicao; // Da RayLib, posicao.x e posicao.y
    int tamanho; // numero de segmentos
    DIRECAO dir; //usa valores da enumeração ESQ ou DIR ou BAIXO
} MILIPEDE; // não utilizada nessa aula

typedef struct {
    Vector2 posicao; // Da RayLib, posicao.x e posicao.y
    DIRECAO dir; // usa valores da enumeração
    int status; // no cenário, oculta - 1, 0
} ARANHA;

typedef struct {
    char nome_jogador[TAMNOME];
    Vector2 posicao;
    int vidas;
    DIRECAO direcao;
    int cogumelos_colhidos; //inicializa em zero
    int tiros; //inicializa em 200
    DIRECAO dirTiro;
    int doente; //qtos cogumelos para curar, zero se estiver sao
    int status; // Livre, Paralisado, ou Morto. Pode definir enumeracao
} FAZENDEIRO;

/*typedef struct {
    int x_elemento;
    int y_elemento;
    int x_obstaculo;
    int y_obstaculo;
} CHECAGEM_COLISAO;

typedef struct {
    ARANHA aranha;
    int direcao;
} MOVIMENTO_ARANHA;
*/


int GeraAranha(ARANHA *aranha) {
    float x_random = (float) (rand() / (double) RAND_MAX * LARGURA_TELA);
    float y_random = (float) (rand() / (double) RAND_MAX * ALTURA_TELA);

    if (x_random > 0 && x_random < LARGURA_TELA && y_random > 0 && y_random < ALTURA_TELA) {
        (*aranha).posicao.x = x_random;
        (*aranha).posicao.y = y_random;
        (*aranha).status = 1;
        (*aranha).dir = cima;

        return 1;
    } else {
        return 0;
    }
}

void inverte_movimento(ARANHA *aranha) {
    DIRECAO direcao_aranha = (*aranha).dir;

    switch(direcao_aranha) {
        case(cima):
            (*aranha).dir = (int) (rand() % (esq_baixo - dir_baixo + 1)) + dir_baixo;
            break;
        case(dir_cima):
            (*aranha).dir = (int) (rand() % (esq_cima - dir_baixo + 1)) + dir_baixo;
            break;
        case(dir):
            (*aranha).dir = (int) (rand() % (esq_cima - esq_baixo + 1)) + esq_baixo;
            break;
        case(dir_baixo):
            (*aranha).dir = (int) (rand() % (esq_cima - esq_baixo + 1)) + esq_baixo;
            break;
        case(baixo):
            (*aranha).dir = esq_cima;
            break;
        case(esq_baixo):
            (*aranha).dir = (int) (rand() % (dir_baixo - cima + 1)) + cima;
            break;
        case(esq):
            (*aranha).dir = (int) (rand() % (dir_baixo - dir_cima + 1)) + dir_cima;
            break;
        case(esq_cima):
            (*aranha).dir = (int) (rand() % (esq_baixo - dir_cima + 1)) + dir_cima;
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

void MoveAranha(ARANHA *aranha) {
    DIRECAO direcao_aranha = (*aranha).dir;

    switch(direcao_aranha) {
        case cima:
            (*aranha).posicao.y += 1.0;

            if(checa_colisao((*aranha).posicao.x, (*aranha).posicao.y, LARGURA_TELA, ALTURA_TELA)) {
                inverte_movimento(aranha);
            }

            break;
        case dir_cima:
            (*aranha).posicao.x += 1.0;
            (*aranha).posicao.y += 1.0;

            if(checa_colisao((*aranha).posicao.x, (*aranha).posicao.y, LARGURA_TELA, ALTURA_TELA)) {
                inverte_movimento(aranha);
            }

            break;
        case dir:
            (*aranha).posicao.x += 1.0;

            if(checa_colisao((*aranha).posicao.x, (*aranha).posicao.y, LARGURA_TELA, ALTURA_TELA)) {
                inverte_movimento(aranha);
            }

            break;
        case dir_baixo:
            (*aranha).posicao.x += 1.0;
            (*aranha).posicao.y -= 1.0;

            if(checa_colisao((*aranha).posicao.x, (*aranha).posicao.y, LARGURA_TELA, 0)) {
                inverte_movimento(aranha);
            }

            break;
        case baixo:
            (*aranha).posicao.y -= 1.0;

            if(checa_colisao((*aranha).posicao.x, (*aranha).posicao.y, 0, 0)) {
                inverte_movimento(aranha);
            }

            break;
        case esq_baixo:
            (*aranha).posicao.x -= 1.0;
            (*aranha).posicao.y -= 1.0;

            if(checa_colisao((*aranha).posicao.x, (*aranha).posicao.y, 0, 0)) {
                inverte_movimento(aranha);
            }

            break;
        case esq:
            (*aranha).posicao.x -= 1.0;

            if(checa_colisao((*aranha).posicao.x, (*aranha).posicao.y, 0, 0)) {
                inverte_movimento(aranha);
            }

            break;
        case esq_cima:
            (*aranha).posicao.y += 1.0;
            (*aranha).posicao.x -= 1.0;

            if(checa_colisao((*aranha).posicao.x, (*aranha).posicao.y, 0, ALTURA_TELA)) {
                inverte_movimento(aranha);
            }

            break;
        default:
            break;
    }
}

void GeraFazendeiro(FAZENDEIRO *fazendeiro) {
    (*fazendeiro).tiros = TIROS_INICIAIS;
    (*fazendeiro).vidas = VIDAS_INICIAIS;
    (*fazendeiro).cogumelos_colhidos = 0;
    (*fazendeiro).doente = 0;

    (*fazendeiro).posicao.x = (float) (rand() / (double) RAND_MAX * LARGURA_TELA);
    (*fazendeiro).posicao.y = (float) (rand() / (double) RAND_MAX * ALTURA_TELA);
}

int TestaColisaoAranha(ARANHA aranha, FAZENDEIRO fazendeiro) {
    float x_aranha = aranha.posicao.x;
    float y_aranha = aranha.posicao.y;

    float x_fazendeiro = fazendeiro.posicao.x;
    float y_fazendeiro = fazendeiro.posicao.y;

     if (x_aranha == x_fazendeiro && y_aranha == y_fazendeiro) {
        return 1;
    } else {
        return 0;
    }
}

void TestaColisaoAranhaBase(ARANHA *aranha) {
    if ((*aranha).posicao.y == 0) {
        (*aranha).status = 0;
    }
}

void MoveTodas(FAZENDEIRO *fazendeiro) {
    while(!IsKeyDown(ESC)) {
        ARANHA aranha;

        GeraAranha(&aranha);
        MoveAranha(&aranha);

        printf("\nPosicao atual da aranha X=%.2f e Y=%.2f\n", aranha.posicao.x, aranha.posicao.y);

        (*fazendeiro).doente += TestaColisaoAranha(aranha, *fazendeiro);

        printf("\nStatus de doente do fazendeiro = %d\n", (*fazendeiro).doente);

        TestaColisaoAranhaBase(&aranha);

        printf("\nStatus da aranha = %d\n", aranha.status);

        //WaitTime(20.0);
        getchar();
    }

    printf("\nParou de mover aranhas\n");
}

int main() {
    FAZENDEIRO jog;

    GeraFazendeiro(&jog);

    MoveTodas(&jog);

    return 0;
}
