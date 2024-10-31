#include <iostream>
#include <iomanip>
#include <vector>

#define TAM 4
#define UP "UP"
#define UP_SPACE "UP "
#define LEFT "LEFT"
#define LEFT_SPACE "LEFT "
#define RIGHT "RIGHT"
#define RIGHT_SPACE "RIGHT "
#define DOWN "DOWN"
#define DOWN_SPACE "DOWN "
#define NONE "NONE"

using namespace std;

int main() {
    int mat[TAM][TAM];
    int possible_plays = 0;
    int total_plays = 0;
    int n;
    vector<string> plays;
    vector<string> plays_space;
    bool has_2048 = false;

    cin >> n;

     // Processa n vezes
    for (int x = 0; x < n; x++) {
        plays.clear();
        plays_space.clear();
        total_plays = 0;
        possible_plays = 0;

        // Le matriz
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                cin >> mat[i][j];
            }
        }

        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                has_2048 = mat[i][j] == 2048;
            }
        }

        // Testa DOWN
        for (int i = 0; i < TAM - 1; i++) {
            for (int j = 0; j < TAM; j++) {
                if (mat[i][j] != 0 && (mat[i+1][j] == mat[i][j] || mat[i+1][j] == 0)) {
                    possible_plays++;
                }
            }
        }

        if (possible_plays > 0) {
            plays.push_back(DOWN);
            plays_space.push_back(DOWN_SPACE);
            total_plays++;
        }

        possible_plays = 0;

        // Testa LEFT
        for (int i = 0; i < TAM; i++) {
            for (int j = 1; j < TAM; j++) {
                if (mat[i][j] != 0 && (mat[i][j-1] == mat[i][j] || mat[i][j-1] == 0)) {
                    possible_plays++;
                }
            }
        }

        if (possible_plays > 0) {
            plays.push_back(LEFT);
            plays_space.push_back(LEFT_SPACE);
            total_plays++;
        }

        possible_plays = 0;

        // Testa RIGHT
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM - 1; j++) {
                if (mat[i][j] != 0 && (mat[i][j+1] == mat[i][j] || mat[i][j+1] == 0)) {
                    possible_plays++;
                }
            }
        }

        if (possible_plays > 0) {
            plays.push_back(RIGHT);
            plays_space.push_back(RIGHT_SPACE);
            total_plays++;
        }

        possible_plays = 0;

        // Testa UP
        for (int i = 1; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                if (mat[i][j] != 0 && (mat[i-1][j] == mat[i][j] || mat[i-1][j] == 0)) {
                    possible_plays++;
                }
            }
        }

        if (possible_plays > 0) {
            plays.push_back(UP);
            plays_space.push_back(UP_SPACE);
            total_plays++;
        }

        if (total_plays == 0 || has_2048) {
            plays.push_back(NONE);
            cout << plays[0] << endl;
        } else {
            // Printa resultados
            for (int i = 0; i < total_plays; i++) {
                if(i == total_plays - 1) {
                    cout << plays[i] << endl;
                } else {
                    cout << plays_space[i];
                }
            }
        }
    }
};
