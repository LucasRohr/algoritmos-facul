#include <stdio.h>
#include "raylib.h"

#define ESC 27
#define MOVIMENTO 7.0

int main_2(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    int posicao_x = screenWidth / 2, posicao_y = screenHeight / 2;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        switch(GetKeyPressed()) {
            case KEY_RIGHT:
                posicao_x += MOVIMENTO;
                break;
            case KEY_LEFT:
                posicao_x -= MOVIMENTO;
                break;
            case KEY_UP:
                posicao_y -= MOVIMENTO;
                break;
            case KEY_DOWN:
                posicao_y += MOVIMENTO;
                break;
            case ESC:
                CloseWindow();
                break;
            default:
                break;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircle(posicao_x, posicao_y, 20, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
