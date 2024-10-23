#include <iostream>

using namespace std;

template <typename T> 
T max_function(T a, T b) {
    return (a > b) ? a : b; // Operador ternário
}

int main() {
    // Chama a função para um inteiro
    cout << max_function<int>(5, 3) << endl;

    // Chama a função para um double
    cout << max_function<double>(7.5, 9.3) << endl;

    return 0;
}

