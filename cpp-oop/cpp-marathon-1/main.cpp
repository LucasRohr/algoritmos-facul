#include <iostream>
#include <iomanip>

#define TAM 12

using namespace std;

int main() {
    float mat[TAM][TAM];
    float sum = 0;
    int total = 0;
    string option;

    cin >> option;

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cin >> mat[i][j];

            if (i <= (TAM - 1) && j > i) {
                sum += mat[i][j];
                total++;
            }
        }
    }

    if (option.compare("S") == 0) {
        cout << setiosflags(ios::fixed) << setprecision(1) << sum << endl;
    } else {
        cout << setiosflags(ios::fixed) << setprecision(1) << (sum / total) << endl;
    }
}
