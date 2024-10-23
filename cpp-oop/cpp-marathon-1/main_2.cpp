#include <iostream>
#include <iomanip>

#define TAM 9
#define SUM 45

using namespace std;

int main() {
    float mat[TAM][TAM];
    int n;

    int values [TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int found_values [TAM];
    int found_values_total = 0;
    bool valid = true;

    cin >> n;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            int* value = find(begin(values), end(values), mat[i][j]);
            int* value_in_found_list = find(begin(found_values), end(found_values), *value);

            if (value != end(values) && value_in_found_list == end(found_values)) {
                found_values[j] = *value;
                found_values_total++;
            }
        }

        cout << "busca linha " << i << " - " << found_values_total << endl;

        if (found_values_total != TAM) {
            valid = false;
        }

        found_values_total = 0;
        
        for (int i = 0; i < TAM; i++) {
            found_values[i] = 0;
        }
    }

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            int* value = find(begin(values), end(values), mat[j][i]);
            int* value_in_found_list = find(begin(found_values), end(found_values), *value);

            if (value != end(values) && value_in_found_list == end(found_values)) {
                found_values[j] = *value;
                found_values_total++;
            }
        }

        if (found_values_total != TAM) {
            valid = false;
        }

        found_values_total = 0;

        for (int i = 0; i < TAM; i++) {
            found_values[i] = 0;
        }
    }


    for (int x = 0; x < TAM; x++) {
        for (int i = (x * 3); i < (x * 3) + 2; i++) {
            for (int j = (x * 3); j < (x * 3) + 2; j++) {
                int* value = find(begin(values), end(values), mat[i][j]);
                int* value_in_found_list = find(begin(found_values), end(found_values), *value);

                if (value != end(values) && value_in_found_list == end(found_values)) {
                    found_values[j] = *value;
                    found_values_total++;
                }
            }
        }

        cout << "busca 3x3 " << x << " - " << found_values_total << endl;

        if (found_values_total != TAM) {
            valid = false;
        }

        found_values_total = 0;
        
        for (int i = 0; i < TAM; i++) {
            found_values[i] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Instancia " << n << endl;

        if (valid) {
            cout << "SIM" << endl << endl;
        } else {
            cout << "NAO" << endl << endl;
        }
    }
}