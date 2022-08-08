#include <stdio.h>
#include "raylib.h"
#include <string.h>

#define LIMITE_ESQ 1
#define LIMITE_BAIXO 445
#define LIMITE_DIR 795
#define TAMANHO_NOME 100
#define ENTER 10

#define MOVIMENTO 10.0
#define ESC 27

void desenha_moldura() {
    int i;

    for(i = 0; i < LIMITE_DIR; i++) {
        DrawPixel(i + 1, 0, YELLOW);
    }

    for(i = 0; i < LIMITE_BAIXO; i++) {
        DrawPixel(0, i + 1, YELLOW);
    }

    for(i = 0; i < LIMITE_DIR; i++) {
        DrawPixel(i + 1, LIMITE_BAIXO, YELLOW);
    }

    for(i = 0; i < LIMITE_DIR; i++) {
        DrawPixel(LIMITE_DIR, i + 1, YELLOW);
    }
}

void movimenta_jogador(int *posicao_x, int *posicao_y) {
    switch(GetKeyPressed()) {
        case KEY_RIGHT:
            if (*posicao_x < LIMITE_DIR) {
                *posicao_x += MOVIMENTO;
            }

            break;
        case KEY_LEFT:
            if (*posicao_x > 0) {
                *posicao_x -= MOVIMENTO;
            }

            break;
        case KEY_UP:
            if (*posicao_y < LIMITE_BAIXO) {
                *posicao_y += MOVIMENTO;
            }

            break;
        case KEY_DOWN:
            if (*posicao_y > 0) {
                *posicao_y -= MOVIMENTO;
            }

            break;
        case ESC:
            CloseWindow();
            break;
        default:
            break;
    }
}

void escreve_texto (int x, int y) {
    DrawText("Jogador", x, y, 20, WHITE);
}

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    int x, y;
    int posicao_x = screenWidth / 2, posicao_y = screenHeight / 2;
    char nome [TAMANHO_NOME];

    printf("Forneca as coordenadas do nome:\n");

    scanf("%d", &x);
    scanf("%d", &y);

    gets(nome);

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        movimenta_jogador(&posicao_x, &posicao_y);

        BeginDrawing();
        ClearBackground(BLACK);

        desenha_moldura();
        escreve_texto(x, y);

        DrawCircle(posicao_x, posicao_y, 12, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
